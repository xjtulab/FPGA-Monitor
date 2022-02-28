/*
 * FILE: osapi_os_windows.h - OS configuration file for MS Windows
 *
 */
/*ce \file
 *   \brief OS API Configuration
 */
#ifndef osapi_os_windows_h
#define osapi_os_windows_h

#define OSAPI_INCLUDE_WINDOWS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <windows.h>
#include <process.h>
#include <io.h>

#define _WINSOCKAPI_
#define HAVE_SOCKET_API
#define OSAPI_ThreadHandle HANDLE
#define OSAPI_ThreadId DWORD
#define OSAPI_ProcessId DWORD
#define OSAPI_LOG_WRITE_BUFFER(buf_,len_) if (_write(1,buf_,len_)){}

#ifndef OEI_WIN32
#define OEI_WIN32 (1)
#endif

#endif /* osapi_os_windows_h */
