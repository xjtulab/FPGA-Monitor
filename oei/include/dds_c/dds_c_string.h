/*
 * FILE: dds_c_string.h - DDS string definitions
 *
 */
/*ce
 * \file
 * \brief DDS string definitions
 */

/* ================================================================== */
/*                 Class: String                                      */
/* ================================================================== */
/*e @addtogroup DDSStringClass String Support
  @ingroup DDSInfrastructureModule
  @brief String creation, cloning, assignment, and deletion.

   The \methods in this class ensure consistent cross-platform
   implementations for string creation (DDS_String_alloc()), deletion
   (DDS_String_free()), and cloning (DDS_String_dup()) that preserve the
   mutable value type semantics. These are to be viewed as \methods that
   define a \p string class whose data is represented by a \c 'char*'.

   @section DDSStringClass_conventions Conventions

   The following conventions govern the memory management of strings in \ndds.

   <ul>
     <li>The \dds implementation ensures that when value types containing
         strings are passed back and forth to the DDS APIs, the strings
         are created/deleted/assigned/cloned using the \p string class
         \methods.
         <ul>
           <li>Value types containing strings have ownership of the
               contained string. Thus, when a value type is deleted, the
               contained string field is also deleted.</li>
         </ul></li>
     <li>The user must ensure that when value types containing
         strings are passed back and forth to the DDS APIs, the strings
         are created/deleted/assigned/cloned using the String class \methods.
         </li>
   </ul>

   The representation of a string in C/C++ unfortunately does not allow
   programs to detect how much memory has been allocated for a string. \ndds
   must therefore make some assumptions when a user requests that a string be
   copied into. The following rules apply when \ndds is copying into a string
   or string sequence:

   \li If the 'char*' is NULL, \ndds will log a warning and allocate a new
       string on behalf of the user. <i>To avoid leaking memory, you must
       ensure that the string will be freed (see \ref DDSStringClass_usage
       below)</i>.
   \li If the 'char*' is not NULL, \ndds will assume that you are managing the
       string's memory yourself and have allocated enough memory to store the
       string to be copied. <i>\ndds will copy into your memory; to avoid
       memory corruption, be sure to allocate enough of it.</i> Also, <i>do
       not pass structures containing junk pointers into \ndds</i>; you are
       likely to crash.

   @section DDSStringClass_usage Usage

   This requirement can generally be assured by adhering
   to the following \em idiom for manipulating strings.

   \code
     Always use
          DDS_String_alloc() to create,
          DDS_String_dup() to clone,
          DDS_String_free() to delete
      a string 'char*' that is passed back and forth between
      user code and the DDS C/C++ APIs.
   \endcode

   Not adhering to this idiom can result in bad pointers, and incorrect
   memory being freed.

   In addition, the user code should be vigilant to avoid memory leaks.
   It is good practice to:

   \li Balance occurrences of DDS_String_alloc(), DDS_String_dup(),
       with matching occurrences of DDS_String_free() in the code.
   \li Finalize value types containing strings. In C++ the destructor
       accomplishes this automatically. in C, explicit "destructor" functions
       are provided; these functions are typically called "finalize."

*/

/* ================================================================= */
/*i @file
  @ingroup String
  @brief Defines the String facilities.
*/
#ifndef dds_c_string_h
#define dds_c_string_h



#ifndef dds_c_dll_h
#include "dds_c/dds_c_dll.h"
#endif
#ifndef dds_c_common_h
#include "dds_c/dds_c_common.h"
#endif
#ifndef dds_c_sequence_h
#include "dds_c/dds_c_sequence.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/* ----------------------------------------------------------------- */
/*e @ingroup DDSStringClass
 * 
 * @brief Create a new empty string that can hold up to \p length
 *        characters.
 * 
 * @details
 * A string created by this \method must be deleted using
 * DDS_String_free().
 *
 * This function will allocate enough memory to hold a string of
 * \p length characters, \b plus one additional byte to hold the NULL
 * terminating character.
 * 
 * @param length \st_in Capacity of the string. 
 * 
 * @return A newly created non-NULL string upon success or
 *         NULL upon failure.
 */
DDSCDllExport char*
DDS_String_alloc(DDS_UnsignedLong length);

#define DDS_String_alloc(l_) REDA_String_alloc(l_)

/* ----------------------------------------------------------------- */
/*e @ingroup DDSStringClass
 * 
 * @brief Clone a string. Creates a new string that duplicates 
 *        the value of \p string. 
 * 
 * @details
 * A string created by this \method must be deleted using
 * DDS_String_free()
 * 
 * @param str \st_in The string to duplicate.
 * 
 * @return If \p string == NULL, this \method always returns NULL.
 *         Otherwise, upon success it returns a newly created string
 *         whose value is \p string; upon failure it returns NULL.
 */
DDSCDllExport char*
DDS_String_dup(const char *str);

#define DDS_String_dup(str_) REDA_String_dup(str_)

/* ----------------------------------------------------------------- */
/*i @ingroup DDSStringClass
 * 
 * @brief Assign a string to a new value.
 *
 * @details
 * Replaces the string
 * pointed to by \p string_ptr, with a string whose value
 * is \p new_value.
 * 
 * A string created by this \method must be deleted using
 * DDS_String_free().
 *  
 * @pre \p string_ptr be a non-NULL pointer. *string_ptr must be 
 *      either NULL, or a string created using DDS_String_alloc() 
 *      or DDS_String_dup(), or DDS_String_replace().
 * 
 * @param string_ptr \st_inout Pointer to the string to replace.
 * 
 * @param new_value \st_in The value of the replacement string.
 * 
 * @return If \p new_value = NULL, this \method always returns NULL.
 *         Otherwise, upon success it returns *string_ptr whose value 
 *         is \p new_value; upon failure it returns NULL. 
 *
 * @post If \p new_value = NULL, *string_ptr == NULL.
 *       Otherwise, upon success \p string_ptr contains a pointer 
 *       to a string whose value is \p new_value; upon failure, 
 *       \p string_ptr is left unchanged.
 */
DDSCDllExport char*
DDS_String_replace(char **string_ptr, const char *new_value);

#define DDS_String_replace(str_,val_) REDA_String_replace(str_,val_)

/* ----------------------------------------------------------------- */
#ifndef OEI_CERT
/*e @ingroup DDSStringClass
 * 
 * @brief Delete a string.
 * 
 * @pre \p string must be either NULL, or must have been created 
 *       using DDS_String_alloc(), DDS_String_dup()
 * 
 * @param str \st_in The string to delete.
 * @internal String could also have been created with DDS_String_replace()
 */
DDSCDllExport void
DDS_String_free(char *str);
#endif /* !OEI_CERT */

#ifndef OEI_CERT
#define DDS_String_free(str_) REDA_String_free(str_)
#else
#define DDS_String_free(str_) 
#endif /* !OEI_CERT */
/* ----------------------------------------------------------------- */
/*e @ingroup DDSStringClass
 * 
 * @brief Compare two strings.
 * 
 * @pre \p s1 and s2 can be NULL or non-NULL.
 * 
 * @param s1 \st_in String 1 to compare.
 * @param s2 \st_in String 2 to compare.
 *
 * @return 0 if s1 equals s2,
 *           positive integer if s1 is greater than s2,
 *           negative integer if s1 is less than s2
 */
DDSCDllExport int
DDS_String_cmp(const char *s1, const char *s2);
#define DDS_String_cmp(str1_,str2_) REDA_String_compare(str1_,str2_)

/*e @ingroup DDSStringClass
 *
 * @brief Compare two strings.
 *
 * \details
 *
 * This function compares two strings for lexicographic equivalence, but only
 * up to num bytes.

 * \param[in] s1  \st_in Left side of comparison
 * \param[in] s2  \st_in Right side of comparison
 * \param[in] num Maximum number of bytes to compare
 *
 * @return 0 if s1 equals s2,
 *           positive integer if s1 is greater than s2,
 *           negative integer if s1 is less than s2
 */
DDSCDllExport int
DDS_String_ncmp(const char *s1, const char *s2, DDS_UnsignedLong num);
#define DDS_String_ncmp(str1_,str2_,num_) REDA_String_ncompare(str1_,str2_,num_)

/* ----------------------------------------------------------------- */
/*e @ingroup DDSStringClass
 * 
 * @brief Return the length of a string
 * 
 * @pre \p string must be non-NULL
 * 
 * @param string \st_in String to return length of
 *
 * @return length of string. Does not include the NUL-termination character.
 * If a NULL value is passed as argument, OEI_SIZE_INVALID will be returned.
 */
DDSCDllExport int
DDS_String_length(const char *string);
#define DDS_String_length(str1_) REDA_String_length(str1_)

#ifdef __cplusplus
}                               /* extern "C" */
#endif


#endif /* dds_c_string_h */
