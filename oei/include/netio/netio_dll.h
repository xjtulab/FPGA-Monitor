/*
 * FILE: netio_dll.h - NETIO external linkage
 *
 */
/*ce
 * \file
 */
#ifndef netio_dll_h
#define netio_dll_h

#include "osapi/osapi_config.h"

#if defined(OEI_WIN32) || defined(OEI_WINCE30)

#if defined(OEI_DLL_EXPORT)
#ifndef OEI_netio_DLL_EXPORT
#define OEI_netio_DLL_EXPORT
#endif
#ifndef OEI_netio_DLL_VARIABLE
#define OEI_netio_DLL_VARIABLE
#endif
#endif

#if defined(OEI_netio_DLL_EXPORT)
#define NETIODllExport __declspec( dllexport )
#else
#define NETIODllExport
#endif /* OEI_netio_DLL_EXPORT */

#if defined(OEI_netio_DLL_VARIABLE)
#if defined(OEI_netio_DLL_EXPORT)
#define NETIODllVariable __declspec( dllexport )
#else
#define NETIODllVariable __declspec( dllimport )
#endif /* OEI_netio_DLL_EXPORT */
#else
#define NETIODllVariable
#endif /* OEI_netio_DLL_VARIABLE */
#else
#define NETIODllExport
#define NETIODllVariable
#endif /* OEI_WIN32 || OEI_WINCE30 */

#if defined(__cplusplus) && defined(OEI_USE_CPP_API)
#define OEI_CPP
#endif

#endif /* netio_dll_h */
