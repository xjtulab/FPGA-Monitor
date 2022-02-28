/*
 * FILE: dds_c_dll.h - External linkage definitions
 *
 */
/*ce
 * \file
 * \brief DDS_C external linkage definitions
 */
#ifndef dds_c_dll_h
#define dds_c_dll_h

#include "osapi/osapi_config.h"

#if defined(OEI_WIN32) || defined(OEI_WINCE)

#if defined(OEI_DLL_EXPORT)
#ifndef OEI_dds_c_DLL_EXPORT
#define OEI_dds_c_DLL_EXPORT
#endif
#ifndef OEI_dds_c_DLL_VARIABLE
#define OEI_dds_c_DLL_VARIABLE
#endif
#endif

#if defined(OEI_dds_c_DLL_EXPORT)
#define DDSCDllExport __declspec( dllexport )
#else
#define DDSCDllExport
#endif /* OEI_dds_c_DLL_EXPORT */

#if defined(OEI_dds_c_DLL_VARIABLE)
#if defined(OEI_dds_c_DLL_EXPORT)
#define DDSCDllVariable __declspec( dllexport )
#else
#define DDSCDllVariable __declspec( dllimport )
#endif /* OEI_dds_c_DLL_EXPORT */
#else
#define DDSCDllVariable
#endif /* OEI_dds_c_DLL_VARIABLE */
#else
#define DDSCDllExport
#define DDSCDllVariable
#endif /* OEI_WIN32 || OEI_WINCE */

#if defined(__cplusplus) && defined(OEI_USE_CPP_API)
#define OEI_CPP
#else
#define DDSCPPDllExport
#endif

#endif /* dds_c_dll_h */
