#ifndef dds_cpp_dll_hxx
#define dds_cpp_dll_hxx

#include "osapi/osapi_config.h"

#if defined(OEI_WIN32) || defined(OEI_WINCE)
  #if defined(OEI_dds_cpp_DLL_EXPORT)
    #define DDSCPPDllExport __declspec( dllexport )
  #else
    #define DDSCPPDllExport
  #endif /* OEI_dds_cpp_DLL_EXPORT */

  #if defined(OEI_dds_cpp_DLL_VARIABLE) 
    #if defined(OEI_dds_cpp_DLL_EXPORT)
      #define DDSCPPDllVariable __declspec( dllexport )
    #else
      #define DDSCPPDllVariable __declspec( dllimport )
    #endif /* OEI_dds_cpp_DLL_EXPORT */
  #else 
    #define DDSCPPDllVariable
  #endif /* OEI_dds_cpp_DLL_VARIABLE */
#else
  #define DDSCPPDllExport
  #define DDSCPPDllVariable
#endif /* OEI_WIN32 || OEI_WINCE */

/* Use the C++ constructs that are included in the DDS/C interfaces. */
#ifndef OEI_USE_CPP_API
#define OEI_USE_CPP_API
#endif

#endif /* dds_cpp_dll_hxx */


