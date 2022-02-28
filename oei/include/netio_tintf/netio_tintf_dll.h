/*
 * FILE: netio_tintf_dll.h - NETIO external linkage
 *
 */
/*ce
 * \file
 */
#ifndef netio_tintf_dll_h
#define netio_tintf_dll_h

#include "osapi/osapi_config.h"

#if defined(OEI_WIN32) || defined(OEI_WINCE30)

#if defined(OEI_DLL_EXPORT)
#ifndef OEI_netio_tintf_DLL_EXPORT
#define OEI_netio_tintf_DLL_EXPORT
#endif
#ifndef OEI_netio_tintf_DLL_VARIABLE
#define OEI_netio_tintf_DLL_VARIABLE
#endif
#endif

#if defined(OEI_netio_tintf_DLL_EXPORT)
#define NETIO_TINTFDllExport __declspec( dllexport )
#else
#define NETIO_TINTFDllExport
#endif /* OEI_netio_tintf_DLL_EXPORT */

#if defined(OEI_netio_tintf_DLL_VARIABLE)
#if defined(OEI_netio_tintf_DLL_EXPORT)
#define NETIO_TINTFDllVariable __declspec( dllexport )
#else
#define NETIO_TINTFDllVariable __declspec( dllimport )
#endif /* OEI_netio_tintf_DLL_EXPORT */
#else
#define NETIO_TINTFDllVariable
#endif /* OEI_netio_tintf_DLL_VARIABLE */
#else
#define NETIO_TINTFDllExport
#define NETIO_TINTFDllVariable
#endif /* OEI_WIN32 || OEI_WINCE30 */

#if defined(__cplusplus) && defined(OEI_USE_CPP_API)
#define OEI_CPP
#endif

#endif /* netio_tintf_dll_h */
