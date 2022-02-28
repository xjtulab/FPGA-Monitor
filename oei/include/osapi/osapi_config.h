/*
 * FILE: osapi_os.h - OS Configuration
 *
 */
/*ce \file
 *   \brief OS API Configuration
 */
#ifndef osapi_config_h
#define osapi_config_h

#include <stdlib.h>	// reworks: NULL is 0 OR (void *)0

/* The global configuration is read first. Local definitions must
 * check if the global configuration has set an option or not. Note that
 * a module cannot disable a feature.
 */
#ifdef HAVE_GLOBAL_CONFIG
#include "OEI_config.h"
#endif

/*
 * ENABLE_FACE_COMPLIANCE:
 * 0 - No compliance with FACE is required
 * 1 - Comply with the SECURITY profile (not supported)
 * 2 - Comply with the SAFTEY_BASE profile (supported)
 * 3 - Comply with the SAFETY_EXTENDED profile (supported)
 * 4 - Comply with the GENERAL profile (supported)
 */
#define FACE_COMPLIANCE_LEVEL_NONE             0
#define FACE_COMPLIANCE_LEVEL_SECURITY         1
#define FACE_COMPLIANCE_LEVEL_SAFETY_BASE      2
#define FACE_COMPLIANCE_LEVEL_SAFETY_EXTENDED  3
#define FACE_COMPLIANCE_LEVEL_GENERAL          4

#ifndef ENABLE_FACE_COMPLIANCE
#define ENABLE_FACE_COMPLIANCE                 FACE_COMPLIANCE_LEVEL_NONE
#endif

#if (ENABLE_FACE_COMPLIANCE > FACE_COMPLIANCE_LEVEL_NONE) && \
      (ENABLE_FACE_COMPLIANCE < FACE_COMPLIANCE_LEVEL_SAFTEY_EXTENDED)
#error "OEI  only support FACE profile Safety Extended and higher"
#endif

/* Enable/Disable default logging unless already defined */
#ifndef OSAPI_ENABLE_LOG
#if NDEBUG && defined(OEI_CERT)
#define OSAPI_ENABLE_LOG 0
#else
#define OSAPI_ENABLE_LOG 1
#endif
#endif

/* Enable/Disable default tracing unless already defined */
#ifndef OSAPI_ENABLE_TRACE
#if NDEBUG || defined(OEI_CERT)
#define OSAPI_ENABLE_TRACE 0
#else
#define OSAPI_ENABLE_TRACE 1
#endif
#endif

#if OSAPI_ENABLE_TRACE && !OSAPI_ENABLE_LOG
#warning "OSAPI_ENABLE_TRACE=1 requires OSAPI_ENABLE_LOG=1, but OSAPI_ENABLE_LOG=0. Forcing OSAPI_ENABLE_LOG=1"
#ifdef OSAPI_ENABLE_LOG
#undef OSAPI_ENABLE_LOG
#endif
#define OSAPI_ENABLE_LOG 1
#endif

/* Enable/Disable default precondition unless already defined */
#ifndef OSAPI_ENABLE_PRECONDITION
#if NDEBUG || defined(OEI_CERT)
#define OSAPI_ENABLE_PRECONDITION 0
#else
#define OSAPI_ENABLE_PRECONDITION 1
#endif
#endif

/* Enable native long double (128 bit float). This is not supported on
 * all platforms. The default is to implement it as a 16 byte octet array
 * since Micro does not actually use the value.
 */
#ifndef OSAPI_ENABLE_LONG_DOUBLE
#define OSAPI_ENABLE_LONG_DOUBLE 0
#endif

/*******************************************************************************
 *                   Include OS definitions
 ******************************************************************************/
#include "osapi_os.h"

/*******************************************************************************
 *                   Include compiler definitions
 ******************************************************************************/
#include "osapi_cc.h"

#ifdef __reworks__
#define TARGET "reworks"
#endif

#endif /* osapi_config_h */
