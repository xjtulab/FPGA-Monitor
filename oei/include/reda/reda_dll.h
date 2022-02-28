/*
 * FILE: reda_dll.h - REDA external linkage
 *
 */
/*ce
 * \file
 */
#ifndef reda_dll_h
#define reda_dll_h

#include "osapi/osapi_config.h"

#if defined(OEI_WIN32) || defined(OEI_WINCE30)

#if defined(OEI_DLL_EXPORT)
#ifndef OEI_reda_DLL_EXPORT
#define OEI_reda_DLL_EXPORT
#endif
#ifndef OEI_reda_DLL_VARIABLE
#define OEI_reda_DLL_VARIABLE
#endif
#endif

#if defined(OEI_reda_DLL_EXPORT)
#define REDADllExport __declspec( dllexport )
#else
#define REDADllExport
#endif /* OEI_reda_DLL_EXPORT */

#if defined(OEI_reda_DLL_VARIABLE)
#if defined(OEI_reda_DLL_EXPORT)
#define REDADllVariable __declspec( dllexport )
#else
#define REDADllVariable __declspec( dllimport )
#endif /* OEI_reda_DLL_EXPORT */
#else
#define REDADllVariable
#endif /* OEI_reda_DLL_VARIABLE */
#else
#define REDADllExport
#define REDADllVariable
#endif /* OEI_WIN32 || OEI_WINCE30 */

#if defined(__cplusplus) && defined(OEI_USE_CPP_API)
#define OEI_CPP
#endif

#endif /* reda_dll_h */
