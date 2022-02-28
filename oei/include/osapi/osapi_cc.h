/*
 * FILE: osapi_cc.h - Common compiler related definitions
 *
 */
/*ce \file
 *   \brief OS API Configuration
 */
#ifndef osapi_cc_h
#define osapi_cc_h

/*******************************************************************************
 *                   Include compiler definitions
 ******************************************************************************/
#ifndef OSAPI_CC_DEF_H
#if defined(__STDC__) || defined(_MSC_VER) || defined(OEI_WIN32)
#define OSAPI_CC_DEF_H "osapi_cc_stdc.h"
#else
#error "Unable to determine compiler, please define OSAPI_CC_DEF_H"
#endif
#endif

#include OSAPI_CC_DEF_H

/*ce
 * \brief If the compiler does not support static override it here.
 */
#ifndef OSAPI_CC_STATIC
#define OEI_PRIVATE static
#endif

/* This is used to prevent the compiler from issuing warnings for variables
 * not used on purpose (for example interface variables).
 */
#if OSAPI_ENABLE_PRECONDITION
#define PRECOND_ARG(x_)
#else
#define PRECOND_ARG(x_) (void)(x_);
#endif
#define UNUSED_ARG(x) (void)(x)
#define IGNORE_RETVAL(x) (void)(x)

#ifndef MUST_CHECK_RETURN
#define MUST_CHECK_RETURN
#endif

#ifndef SHOULD_CHECK_RETURN
#define SHOULD_CHECK_RETURN
#endif

#ifndef FUNCTION_SHOULD_TYPEDEF
#define FUNCTION_SHOULD_TYPEDEF(ftdef_) \
typedef SHOULD_CHECK_RETURN ftdef_;
#endif

#ifndef FUNCTION_MUST_TYPEDEF
#define FUNCTION_MUST_TYPEDEF(ftdef_) \
typedef MUST_CHECK_RETURN ftdef_;
#endif

/*i
 */
typedef OEI_INT32 OEI_BOOL;

/* Include this for convenient compatibility with OEI Connext Core
 */
typedef OEI_BOOL OEIBool;

#define OEI_FALSE   ((OEI_BOOL) 0)
#define OEI_TRUE    ((OEI_BOOL) 1)

typedef OEI_UINT32 OEI_SIZE_T;

#define OEI_SIZE_INVALID 0xffffffff

#if !defined(OEI_ENDIAN_LITTLE) && !defined(OEI_ENDIAN_BIG)
#error "OEI_ENDIAN_LITTLE or OEI_ENDIAN_BIG not defined"
#endif

#endif /* osapi_config_h */
