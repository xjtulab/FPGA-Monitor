/*
 * FILE: osapi_cc_stdc.h - Specific compiler related definitions
 *
 */
/*ce \file
 *   \brief OS API Configuration
 */
#ifndef osapi_cc_stdc_h
#define osapi_cc_stdc_h

/* NOTE: We (OEI) build for Windows using a cygwin cpp.exe to generate
 * the dependencies. In addition, MSC only defines __STDC__ when using the /Za
 * option. Thus, check for more than just __STDC__ as we test MSC
 */
#if !defined(__STDC__) && !defined(_MSC_VER) && !defined(OEI_WIN32)
#error "osapi_cc_stdc.h used used with a non-standard C compiler"
#endif

#ifdef __reworks__
#include <reworks/types.h>
#endif

#include <limits.h>
#include <stddef.h>

/*******************************************************************************
 * Define types for for MS VS. The supported types can be found here:
 *
 * https://msdn.microsoft.com/en-us/library/s3f49ktz.aspx
 ******************************************************************************/
#if defined(_MSC_VER) || defined(OEI_WIN32)

typedef signed char   OEI_INT8;
typedef unsigned char OEI_UINT8;
typedef signed short  OEI_INT16;
typedef unsigned short OEI_UINT16;
typedef signed int OEI_INT32;
typedef unsigned int OEI_UINT32;
typedef signed long long  OEI_INT64;
typedef unsigned long long OEI_UINT64;

#define OEI_HAVE_FLOAT
typedef float OEI_FLOAT32;

#define OEI_HAVE_DOUBLE
typedef double OEI_DOUBLE64;

#if OSAPI_ENABLE_LONG_DOUBLE
#error "Native long double is not supported on Win32."
#else
typedef struct OEI_DOUBLE128
{
    char bytes[16];
} OEI_DOUBLE128;
#endif

#else /* checks when __STDC__ is defined */

/*******************************************************************************
 *                   Define/Check STDC compiler integer mappings
 ******************************************************************************/
#if SCHAR_MAX == 127
/*i
 */
typedef signed char OEI_INT8;

/*i
 */
typedef unsigned char OEI_UINT8;
#else
#error "SCHAR_MAX is unknown, could not determine OEI_INT8/UINT8."
#endif /* SCHAR_MAX */

#if SHRT_MAX == 32767
/*i
 */
typedef signed short OEI_INT16;

/*i
 */
typedef unsigned short OEI_UINT16;
#else
#error "SHRT_MAX is unknown, could not determine OEI_INT16/UINT16."
#endif /* SHRT_MAX */

#if INT_MAX == 2147483647
/*i
 */
typedef signed int OEI_INT32;

/*i
 */
typedef unsigned int OEI_UINT32;
#else
#error "INT_MAX is unknown, could not determine  OEI_INT32/UINT32."
#endif /* INT_MAX */

#ifdef LLONG_MAX
#if LLONG_MAX == 9223372036854775807LL
/*i
 */
 typedef signed long long int OEI_INT64;

 /*i
  */
 typedef unsigned long long int OEI_UINT64;
#else
 #error "LLONG_MAX is unknown, could not determine  OEI_INT64/UINT64."
#endif /* LLONG_MAX has unknown size */
#elif defined(__LONG_LONG_MAX__)
#if __LONG_LONG_MAX__ == 9223372036854775807LL
/*i
 */
 typedef signed long long int OEI_INT64;

 /*i
  */
 typedef unsigned long long int OEI_UINT64;
#else /* __LONG_LONG_MAX__ has unknown size */
#error "__LONG_LONG_MAX__ is unknown, could not determine OEI_INT64/UINT64."
#endif
#else /* no size defined */
#error "Could not determine OEI_INT64/OEI_UINT64 type"
#endif

/*******************************************************************************
 *                  Define compiler floating point mappings
 ******************************************************************************/
#if (__SIZEOF_FLOAT__ == 4) || (__FLT_MAX_EXP__ == 128)
typedef float OEI_FLOAT32;
#define OEI_HAVE_FLOAT
#else
#error "__SIZEOF_FLOAT__ is unknown (GCC), could not determine OEI_FLOAT32."
#endif

#if (__SIZEOF_DOUBLE__ == 8) || (__DBL_MAX_EXP__ == 1024)
typedef double OEI_DOUBLE64;
#define OEI_HAVE_DOUBLE
#else
#error "__SIZEOF_DOUBLE__ is unknown (GCC), could not determine OEI_DOUBLE64."
#endif

#if OSAPI_ENABLE_LONG_DOUBLE
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 2))
typedef __float128 OEI_DOUBLE128;
#define OEI_HAVE_LONG_DOUBLE
#else
#error "Could not determine if long double is supported."
#endif
#else
typedef struct OEI_DOUBLE128
{
    char bytes[16];
} OEI_DOUBLE128;
#endif

#endif /* __STDC__ */

/*******************************************************************************
 *                          Define CPU endian
 ******************************************************************************/
#if !defined(OEI_ENDIAN_LITTLE) && !defined(OEI_ENDIAN_BIG)
#ifdef __GNUC__
#if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) || \
    defined(__LITTLE_ENDIAN__) || (__BYTE_ORDER == __LITTLE_ENDIAN)
#define OEI_ENDIAN_LITTLE 1
#undef  OEI_ENDIAN_BIG
#elif (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) || \
    defined(__BIG_ENDIAN__) || (__BYTE_ORDER == __BIG_ENDIAN)
#define OEI_ENDIAN_BIG    1
#undef  OEI_ENDIAN_LITTLE
#else
#error "Unable to determine GCC byte-order"
#endif /* __BYTE_ORDER__ */
#elif defined(_MSC_VER)
#if defined(_M_IX86) || defined(_M_X64)
#define OEI_ENDIAN_LITTLE 1
#undef  OEI_ENDIAN_BIG
#else
#error "Unable to determine MSC byte-order"
#endif
#else
#error "Unable to determine endianess."
#endif /* !_M_IX86 */
#endif

/*******************************************************************************
 *                   Define various compiler compile options
 ******************************************************************************/

/* Function attributes */
#if defined(__GNUC__) && (__GNUC__ >= 4)
#define MUST_CHECK_RETURN __attribute__((warn_unused_result))
#define SHOULD_CHECK_RETURN
#define FUNCTION_SHOULD_TYPEDEF(ftdef_) \
typedef SHOULD_CHECK_RETURN ftdef_;
#define FUNCTION_MUST_TYPEDEF(ftdef_) \
typedef MUST_CHECK_RETURN ftdef_;
#elif defined(_MSC_VER) || defined(WIN32)
#if _MSC_VER >= 1900
#define MUST_CHECK_RETURN _Check_return_
#else
#include <CodeAnalysis\SourceAnnotations.h>
#define MUST_CHECK_RETURN [returnvalue:SA_Post(MustCheck=SA_Yes)]
#endif
#define SHOULD_CHECK_RETURN
#define FUNCTION_SHOULD_TYPEDEF(ftdef_) \
typedef ftdef_;
#define FUNCTION_MUST_TYPEDEF(ftdef_) \
typedef ftdef_;
#else
#define SHOULD_CHECK_RETURN
#define FUNCTION_SHOULD_TYPEDEF(ftdef_) \
typedef ftdef_;
#define FUNCTION_MUST_TYPEDEF(ftdef_) \
typedef ftdef_;
#endif

#endif /* osapi_cc_stdc_h */

