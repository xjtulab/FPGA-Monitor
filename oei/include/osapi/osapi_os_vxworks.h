/*
 * FILE: osapi_os_vxworks.h - OS configuration file for VxWorks
 *
 */
/*ce \file
 *   \brief OS API Configuration
 */
#ifndef osapi_os_vxworks_h
#define osapi_os_vxworks_h

#define OSAPI_INCLUDE_VXWORKS 1

#ifndef OEI_VXWORKS
#define OEI_VXWORKS
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>
#ifdef CERT
#ifndef OEI_CERT
#define OEI_CERT
#endif
#endif
#ifdef OEI_RTP
#include <strings.h>
#include <string.h>
#else
#include <string.h>
#endif
#include <vxWorks.h>
#ifdef OEI_RTP
#define USE_TIMER_THREAD_RT
#else
#define USE_WD_TIMER
#define USE_TIMER_THREAD_SEMAPHORE
#include <wdLib.h>
#include <logLib.h>
#endif

#define HAVE_SOCKET_API
#define OSAPI_ENABLE_STDC_FREE 1
#define OSAPI_ENABLE_STDC_REALLOC 1


#define VXWORKS_VERSION_6_9_OR_BETTER \
  (  ((VXWORKS_MAJOR_VERSION == 6) && (VXWORKS_MINOR_VERSION >= 9)) || \
     (VXWORKS_MAJOR_VERSION > 6) \
  )

/* 64-Bit supported in VxWorks 6.9 and later */
#if VXWORKS_VERSION_6_9_OR_BETTER
#include <vsbConfig.h>
#endif


#define VXWORKS_VERSION_6_8_OR_BETTER \
  (  ((VXWORKS_MAJOR_VERSION == 6) && (VXWORKS_MINOR_VERSION >= 8)) || \
     (VXWORKS_MAJOR_VERSION > 6) \
  )

#define VXWORKS_VERSION_6_3_OR_BETTER \
  (  ((VXWORKS_MAJOR_VERSION == 6) && (VXWORKS_MINOR_VERSION >= 3)) || \
     (VXWORKS_MAJOR_VERSION > 6) \
  )

#define VXWORKS_VERSION_6_0_OR_BETTER \
  (  ((VXWORKS_MAJOR_VERSION == 6) && (VXWORKS_MINOR_VERSION >= 0)) || \
     (VXWORKS_MAJOR_VERSION > 6) \
  )

#define VXWORKS_VERSION_5_4_OR_BETTER \
  (  ((VXWORKS_MAJOR_VERSION == 5) && (VXWORKS_MINOR_VERSION >= 4)) || \
     (VXWORKS_MAJOR_VERSION > 5) \
  )


#if VXWORKS_VERSION_6_9_OR_BETTER
#define OSAPI_ThreadHandle TASK_ID
#define OSAPI_UserArg _Vx_usr_arg_t
#define OSAPI_IoctlArg _Vx_ioctl_arg_t
#else
#define OSAPI_ThreadHandle int
#define OSAPI_UserArg int
#define OSAPI_IoctlArg int
#endif

#if defined(OEI_RTP)
#define OSAPI_ProcessId pid_t
#define OSAPI_ThreadId pid_t
#else
#if VXWORKS_VERSION_6_9_OR_BETTER
#define OSAPI_ProcessId TASK_ID
#define OSAPI_ThreadId TASK_ID
#else
#define OSAPI_ProcessId int
#define OSAPI_ThreadId int
#endif /* VXWORKS_VERSION_6_9_OR_BETTER */
#endif /* defined(OEI_RTP)*/

#ifndef OSAPI_LOG_WRITE_BUFFER
#define OSAPI_LOG_WRITE_BUFFER(buf_,len_) UNUSED_ARG(len_); if (printf("%s",buf_)){}
#endif

#endif /* osapi_os_vxworks_h */
