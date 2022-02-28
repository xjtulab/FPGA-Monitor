/*
 * FILE: osapi_dll.h - External linkage definitions
 *
 */
#ifndef osapi_dll_h
#define osapi_dll_h

#include "osapi/osapi_config.h"

#if defined(OEI_WIN32) || defined(OEI_WINCE30)

#if defined(OEI_DLL_EXPORT)
#ifndef OEI_osapi_DLL_EXPORT
#define OEI_osapi_DLL_EXPORT
#endif
#ifndef OEI_osapi_DLL_VARIABLE
#define OEI_osapi_DLL_VARIABLE
#endif
#endif

#if defined(OEI_osapi_DLL_EXPORT)
#define OSAPIDllExport __declspec( dllexport )
#else
#define OSAPIDllExport
#endif /* OEI_osapi_DLL_EXPORT */

#if defined(OEI_osapi_DLL_VARIABLE)
#if defined(OEI_osapi_DLL_EXPORT)
#define OSAPIDllVariable __declspec( dllexport )
#else
#define OSAPIDllVariable __declspec( dllimport )
#endif /* OEI_osapi_DLL_EXPORT */
#else
#define OSAPIDllVariable
#endif /* OEI_osapi_DLL_VARIABLE */
#else
#define OSAPIDllExport
#define OSAPIDllVariable
#endif /* OEI_WIN32 || OEI_WINCE30 */


#endif /* osapi_dll_h */
