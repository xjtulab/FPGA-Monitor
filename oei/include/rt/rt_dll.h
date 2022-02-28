/*
 * FILE: rt_dll.h - DB external linkage
 *
 */
/*ce
 * \file
 */
#ifndef rt_dll_h
#define rt_dll_h

#include "osapi/osapi_config.h"

#if defined(OEI_WIN32) || defined(OEI_WINCE30)

#if defined(OEI_DLL_EXPORT)

#ifndef OEI_rt_DLL_EXPORT
#define OEI_rt_DLL_EXPORT
#endif
#ifndef OEI_rt_DLL_VARIABLE
#define OEI_rt_DLL_VARIABLE
#endif

#endif

#if defined(OEI_rt_DLL_EXPORT)
#define RTDllExport __declspec( dllexport )
#else
#define RTDllExport
#endif /* OEI_rt_DLL_EXPORT */

#if defined(OEI_rt_DLL_VARIABLE)
#if defined(OEI_rt_DLL_EXPORT)
#define RTDllVariable __declspec( dllexport )
#else
#define RTDllVariable __declspec( dllimport )
#endif /* OEI_rt_DLL_EXPORT */
#else
#define RTDllVariable
#endif /* OEI_rt_DLL_VARIABLE */
#else
#define RTDllExport
#define RTDllVariable
#endif /* OEI_WIN32 || OEI_WINCE30 */

#if defined(__cplusplus) && defined(OEI_USE_CPP_API)
#define OEI_CPP
#else
#define DDSCPPDllExport
#endif

#endif /* rt_dll_h */
