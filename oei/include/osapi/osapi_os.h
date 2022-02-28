/*
 * FILE: osapi_config.h - OS configuration common for all OSs
 *
 */
/*ce \file
 *   \brief OS API Configuration
 */
#ifndef OSAPI_OS_H
#define OSAPI_OS_H

#ifndef OSAPI_OS_DEF_H
/* If the platform has not been specified, attempt to determine it.
 */
#if defined(__APPLE__) && defined(__MACH__)
#define OSAPI_OS_DEF_H "osapi_os_posix.h"
#elif defined(__linux__)
#define OSAPI_OS_DEF_H "osapi_os_posix.h"
#elif defined(__VOS__)
#define OSAPI_OS_DEF_H "osapi_os_posix.h"
#elif defined(_MSC_VER) || defined(WIN32)
#define OSAPI_OS_DEF_H "osapi_os_windows.h"
#elif defined(__vxworks)
#define OSAPI_OS_DEF_H "osapi_os_vxworks.h"
#elif defined(__QNXNTO__)
#define OSAPI_OS_DEF_H "osapi_os_posix.h"
#else
#error "Unable to detect OS. Please define OSAPI_OS_DEF_H."
#endif
#endif

#include OSAPI_OS_DEF_H

#if !defined(OSAPI_ThreadId) && !defined(OSAPI_ThreadHandle)
#error "OSAPI_ThreadId and/or OSAPI_ThreadHandle not defined in "##OSAPI_OS_DEF_H
#endif

/* This is to maintain backwards compatability with Micro <= 2.4.8 */
#ifndef OSAPI_ProcessId
#define OSAPI_ProcessId OEI_UINT32
#endif

#endif /* osapi_os_h */
