/*
 * FILE: db_dll.h - DB external linkage
 *
 */
/*ce
 * \file
 * \brief External linkage definitions for DB API
 */
#ifndef db_dll_h
#define db_dll_h

#include "osapi/osapi_config.h"

#if defined(OEI_WIN32) || defined(OEI_WINCE)
#if defined(OEI_db_DLL_EXPORT)
#define DBDllExport __declspec( dllexport )
#else
#define DBDllExport
#endif /* OEI_db_DLL_EXPORT */

#if defined(OEI_db_DLL_VARIABLE)
#if defined(OEI_db_DLL_EXPORT)
#define DBDllVariable __declspec( dllexport )
#else
#define DBDllVariable __declspec( dllimport )
#endif /* OEI_db_DLL_EXPORT */
#else
#define DBDllVariable
#endif /* OEI_db_DLL_VARIABLE */
#else
#define DBDllExport
#define DBDllVariable
#endif /* OEI_WIN32 || OEI_WINCE */

#if defined(__cplusplus) && defined(OEI_USE_CPP_API)
#define OEI_CPP
#endif


#endif /* db_dll_h */
