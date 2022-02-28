/*
 * FILE: reda_indexer.h - Indexer interface
 *
 */
/*ci
 * \file
 *
 * \brief The REDA Indexer interface provides a implementation independent API
 *        for searching and finding elements.
 *
 * \defgroup REDAIndexerClass REDA Indexer
 * \ingroup REDAModule
 *
 * \details
 *
 * The REDA Indexer indexes elements based on a compare function and
 * provides function to search and iterate over the elements in the index.
 * The API is defined so that the underlying data-structures are not exposed.
 */
#ifndef reda_indexer_h
#define reda_indexer_h
#ifndef reda_dll_h
#include "reda/reda_dll.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*ci
 * \addtogroup REDAIndexerClass
 * @{
 */
struct REDA_Indexer;

/*ci
 * \brief Abstract Indexer type
 */
typedef struct REDA_Indexer REDA_Indexer_T;

/*ci
 * \brief The properties an index can be created with.
 */
struct REDA_IndexerProperty
{
    /*ci
     * \brief The maximum number of elements the index can handle
     */
    OEI_INT32 max_entries;
};

/*ci
 * \def REDA_IndexerProperty_INITIALIZER
 * \brief \ref REDA_IndexerProperty initializer
 */
#define REDA_IndexerProperty_INITIALIZER \
{\
    1\
}

/*ci
 * \brief A generic record compare function
 *
 * \details
 *
 * The compare function must maintain an ordered relationship.
 *
 * \param[in] record        Already indexed element to compare against
 * \param[in] key_is_record Whether the key is a complete record or the user
 *                          defined key
 * \param[in] key           Key to compare against
 *
 * \return The function must return zero if record == key,
 *         a negative integer if record < key,
 *         and a positive integer if record > key
 */
FUNCTION_MUST_TYPEDEF(
OEI_INT32
(*REDA_Indexer_compare_T)(const void *const record, OEI_BOOL key_is_record,
                          const void *const key)
)

/*ci
 * \brief Create a new indexer
 *
 * \param[in] compare Compare function that determines the ordering of the
 *                    indexed elements as defined for
 *                    \ref REDA_Indexer_compare_T
 *
 * \param[in] property Indexer property. Refer to \ref
 *                     REDA_IndexerProperty for details.
 *
 * \return Pointer to new indexer on success, NULL on failure
 *
 * \sa REDA_Indexer_delete
 */
MUST_CHECK_RETURN REDADllExport REDA_Indexer_T*
REDA_Indexer_new(REDA_Indexer_compare_T compare,
                 struct REDA_IndexerProperty *property);

#ifndef OEI_CERT
/*ci
 * \brief Delete an indexer
 *
 * \details
 *
 * Delete an index. It is legal to delete an index which contains elements.
 * It is the callers responsibility to make sure that the elements in the
 * index can be properly deleted.
 *
 * \param[in] indexer Indexer to delete
 *
 * \return OEI_TRUE on success, OEI_FALSE on failure
 *
 * \sa REDA_Indexer_new
 */
SHOULD_CHECK_RETURN REDADllExport OEI_BOOL
REDA_Indexer_delete(REDA_Indexer_T *indexer);
#endif /* !OEI_CERT */

/*ci
 * \brief Add an element to an index
 *
 * \details
 *
 * Add an element to the indexer. The indexer is not responsible for managing
 * the memory owner the entry.
 *
 * \param[in] indexer Indexer to add the element to
 * \param[in] entry   Entry to add to indexer
 *
 * \return OEI_TRUE on success, OEI_FALSE on failure
 *
 * \sa REDA_Indexer_remove_entry
 */
MUST_CHECK_RETURN REDADllExport OEI_BOOL
REDA_Indexer_add_entry(REDA_Indexer_T *indexer,void *entry);

/*ci
 * \brief Remove an element from an index
 *
 * \details
 *
 * Remove an element from an indexer based on the key. The indexer is not
 * responsible for managing the memory used by the removed entry.
 *
 * \param[in] indexer Indexer to add the element to
 * \param[in] key     Key to remove
 *
 * \return pointer to removed entry if it existed, NULL otherwise.
 *
 * \sa REDA_Indexer_add_entry
 */
SHOULD_CHECK_RETURN REDADllExport void*
REDA_Indexer_remove_entry(REDA_Indexer_T *indexer,const void *const key);

/*ci
 * \brief Find an entry based on the key
 *
 * \details
 *
 * Search for an entry based on the key.
 *
 * \param[in] indexer Indexer to search for element in
 * \param[in] key     Key to search for
 *
 * \return pointer to entry if it existed, NULL otherwise.
 *
 * \sa REDA_Indexer_find_entry_eq_or_gt
 */
MUST_CHECK_RETURN REDADllExport void*
REDA_Indexer_find_entry(REDA_Indexer_T *indexer,const void *const key);

/*ci
 * \brief Find an entry with a key greater or equal to the key
 *
 * \details
 *
 * Find an entry with a key greater or equal to the key.
 *
 * \param[in] indexer Indexer to search for element in
 * \param[in] key     Key to search for
 *
 * \return pointer to entry if it existed, NULL otherwise.
 *
 * \sa REDA_Indexer_find_entry
 */
MUST_CHECK_RETURN REDADllExport void*
REDA_Indexer_find_entry_eq_or_gt(REDA_Indexer_T *indexer,const void *const key);

/*ci
 * \brief Return the number of elements in the index
 *
 * \details
 *
 * Return the number of elements in the index
 *
 * \param[in] indexer Indexer to return count for. Indexer cannot be NULL,
 *                    and it is the callers responsibility to ensure it is not.
 *
 * \return Number of elements in the index.
 *
 * \sa REDA_Indexer_get_entry
 */
MUST_CHECK_RETURN REDADllExport OEI_INT32
REDA_Indexer_get_count(REDA_Indexer_T *indexer);

/*ci
 * \brief Return the index'th element in the index
 *
 * \details
 *
 * Return the index'th element in the index.
 *
 * \param[in] indexer Indexer to return the element from
 * \param[in] index   Which element to return, starting at 0
 *
 * \return The index'th element in the indexer
 *
 * \sa REDA_Indexer_get_count
 */
MUST_CHECK_RETURN REDADllExport void*
REDA_Indexer_get_entry(REDA_Indexer_T *indexer,OEI_INT32 index);

/*ci
 * \brief Return the first element in the index
 *
 * \details
 *
 * Return the first element in the index
 *
 * \param[in] indexer Indexer to return the the first element from
 *
 * \return The first element in the index, NULL if the index is empty.
 *
 * \sa
 */
MUST_CHECK_RETURN REDADllExport void*
REDA_Indexer_get_first_entry(REDA_Indexer_T *indexer);

/*ci
 * \brief Return the last element in the index
 *
 * \details
 *
 * Return the last element in the index
 *
 * \param[in] indexer Indexer to return the the last element from
 *
 * \return The last element in the index, NULL if the index is empty.
 *
 * \sa
 */
MUST_CHECK_RETURN REDADllExport void*
REDA_Indexer_get_last_entry(REDA_Indexer_T *indexer);

#ifdef __cplusplus
}         /* extern "C" */
#endif

#endif /* reda_indexer_h */

/*ci @} */
