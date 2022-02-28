/*
 * FILE: cdr_dll.h - External linkage definitions
 *
 */
#ifndef cdr_dll_h
#define cdr_dll_h

#include "osapi/osapi_config.h"

#if defined(OEI_WIN32) || defined(OEI_WINCE)
 
#if defined(OEI_DLL_EXPORT)
#ifndef OEI_cdr_DLL_EXPORT
#define OEI_cdr_DLL_EXPORT
#endif
#ifndef OEI_cdr_DLL_VARIABLE
#define OEI_cdr_DLL_VARIABLE
#endif
#endif

#if defined(OEI_cdr_DLL_EXPORT)
#define CDRDllExport __declspec( dllexport )
#else
#define CDRDllExport
#endif /* OEI_cdr_DLL_EXPORT */

#if defined(OEI_cdr_DLL_VARIABLE)
#if defined(OEI_cdr_DLL_EXPORT)
#define CDRDllVariable __declspec( dllexport )
#else
#define CDRDllVariable __declspec( dllimport )
#endif /* OEI_cdr_DLL_EXPORT */
#else
#define CDRDllVariable
#endif /* OEI_cdr_DLL_VARIABLE */
#else
#define CDRDllExport
#define CDRDllVariable
#endif /* OEI_WIN32 || OEI_WINCE */


#endif /* cdr_dll_h */
