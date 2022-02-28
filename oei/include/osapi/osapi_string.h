/*
 * FILE: osapi_string.h - Definition of string interface
 *
 */
/*ce
 * \file 
 * \brief String interface definition
 */
#ifndef osapi_string_h
#define osapi_string_h

#ifndef osapi_dll_h
#include "osapi/osapi_dll.h"
#endif
#ifndef osapi_types_h
#include "osapi/osapi_types.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*e \file
 *   \brief Memory utilities.
 */

/*e \defgroup OSAPI_MemoryClass OSAPI Memory
 * \ingroup OSAPIModule
 *
 * \brief These are utilities for OS-independent memory manipulation such
 * as filling and copying.
 */

/*e \ingroup OSAPI_MemoryClass
 * \brief Copies size bytes from non-overlapping src to dest.
 *
 * \details
 * Valid dest and src >= size, where size >= 0.  The src
 * and dst memory regions should NOT overlap or the results will
 * be undetermined. On success move size number of bytes from in
 * [dest, dest+size) are identical to [src, src+size).
 *
 * @param dest \b Out. Pointer to destination memory region.
 * @param src \b In. Pointer to source memory region.
 * @param size \b In. Number of bytes to copy starting at dest.
 *
 * @exception None.
 *
 * @mtsafety src cannot be modified concurrently; dest cannot be
 * not modified or read concurrently.
*/
OSAPIDllExport void
OSAPI_Memory_copy(void *dest,const void *src, OEI_SIZE_T size);


/*e \ingroup OSAPI_MemoryClass
 * \brief Sets memory region to 0.
 *
 * \details
 * Clear a memory region. Valid memory >= size, where size >= 0. On On success
 * [mem, mem+size) is filled with 0.
 *
 * @param mem \b Out. Pointer to memory region to be modified.
 * @param size \b In. Number of bytes to fill with zeroes, starting at mem.
 *
 * @exception None.
 *
 * @mtsafety mem cannot be modified or read concurrently.
 */
OSAPIDllExport void
OSAPI_Memory_zero(void *mem, OEI_INT32 size);


/*e \ingroup OSAPI_MemoryClass
 * \brief Byte-wise compare of two memory regions.
 *
 * \details
 * This function performs a byte-wise comparison of two memory regions
 * of size bytes. left and right must be >= 0 and size >= 0. This function
 * does not alter any memory content.
 * *
 * @param left \b In. Pointer to logical "left" side of the inequality test.
 * @param right \b In. Pointer to logical "right" side of the inequality test.
 * @param size \b In. Number of bytes to compare, starting from left to right.
 *
 * @return less than, equal to, or greater than  0, according to whether left is
 * lexicographically less than, equal to, or greater than right when
 * taken as unsigned characters.
 *
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_INT32
OSAPI_Memory_compare(const void *left,const void *right, OEI_SIZE_T size);

/*e \ingroup OSAPI_MemoryClass
 * \brief Moves size bytes from non-overlapping src to dest.
 *
 * \details
 * Moves size bytes from non-overlapping src to dest. Valid dest and
 * src >= size, where size >= 0.  The src and dst memory regions may
 * overlap. On success size number of bytes from right is moved to
 * [dest, dest+size) and is identical to[src, src+size)
 *
 * @param dest \b Out. Pointer to destination memory region.
 * @param source \b In. Pointer to source memory region.
 * @param size \b In. Number of bytes to copy starting at dest.
 *
 * @exception None.
 *
 * @mtsafety src cannot be modified concurrently; dest cannot be
 * modified or read concurrently.
 */
OSAPIDllExport void
OSAPI_Memory_move(void *dest,const void *source, OEI_SIZE_T size);

/*e \ingroup OSAPI_MemoryClass
 * \brief Locate byte in byte string
 *
 * \details
 * Locate byte in byte string
 *
 * @param[in] s - Pointer to beginning of byte string
 * @param[in] c - Byte to search for
 * @param[in] n - Maximum search length
 *
 * @return pointer to first occurrence of c if found, NULL otherwise.
 */
MUST_CHECK_RETURN OSAPIDllExport void*
OSAPI_Memory_fndchr(const void *s, OEI_INT32 c, OEI_SIZE_T n);

/*e \ingroup OSAPI_MemoryClass
 * \brief Return length of ASCIIZ string
 *
 * \details
 * Return length of ASCIIZ string not including \0
 *
 * @param[in] s - Pointer to beginning of byte string
 *
 * @return Length of string not including \0
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_SIZE_T
OSAPI_String_length(const char *s);

/*e \ingroup OSAPI_MemoryClass
 * \brief Compare two ASCIIZ strings
 *
 * \details
 *
 * Lexicographically compare the null-terminated strings l and r. The
 * comparison is using unsigned arithmetic.
 *
 * @param[in] l - Left side string
 * @param[in] r - Right side string
 *
 * @return 0 if the strings are identical, a positive integer if l > r,
 *         and a negative integer if l < r.
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_INT32
OSAPI_String_cmp(const char *l,const char *r);

/*e \ingroup OSAPI_MemoryClass
 * \brief Compare two ASCIIZ strings
 *
 * \details
 *
 * Lexicographically compare null-terminated strings l and r,
 * including up to num characters (if the null terminator is not found before
 * the specified number of characters has been compared).
 * The comparison is using unsigned arithmetic.
 *
 * @param[in] l - Left side string
 * @param[in] r - Right side string
 * @param[in] num - Maximum number of characters to compare
 *
 * @return 0 if the strings are identical, a positive integer if l > r,
 *         and a negative integer if l < r.
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_INT32
OSAPI_String_ncmp(const char *l,const char *r, OEI_SIZE_T num);

/* pick up hidden performance boosting macros and optimizations */
#ifdef __cplusplus
}                               /* extern "C" */
#endif

#endif /* osapi_string_h */
