/*
 * FILE: disc_dpse_dll.h - DPSE DLL external linkage
 *
 */
/*ce
 * \file
 * \brief DPSE DLL external linkage
 */
#ifndef disc_dpse_dll_h
#define disc_dpse_dll_h

#include "osapi/osapi_config.h"

#if defined(OEI_WIN32) || defined(OEI_WINCE)

#if defined(OEI_DLL_EXPORT)
#ifndef OEI_disc_dpse_DLL_EXPORT
#define OEI_disc_dpse_DLL_EXPORT
#endif
#ifndef OEI_disc_dpse_DLL_VARIABLE
#define OEI_disc_dpse_DLL_VARIABLE
#endif
#endif

#if defined(OEI_disc_dpse_DLL_EXPORT)
#define DISC_DPSEDllExport __declspec( dllexport )
#else
#define DISC_DPSEDllExport
#endif /* OEI_disc_dpse_DLL_EXPORT */

#if defined(OEI_disc_dpse_DLL_VARIABLE)
#if defined(OEI_disc_dpse_DLL_EXPORT)
#define DISC_DPSEDllVariable __declspec( dllexport )
#else
#define DISC_DPSEDllVariable __declspec( dllimport )
#endif /* OEI_disc_dpse_DLL_EXPORT */
#else
#define DISC_DPSEDllVariable
#endif /* OEI_disc_dpse_DLL_VARIABLE */
#else
#define DISC_DPSEDllExport
#define DISC_DPSEDllVariable
#endif /* OEI_WIN32 || OEI_WINCE */




#if defined(__cplusplus) && defined(OEI_USE_CPP_API)
#define OEI_CPP
#endif


#endif /* disc_dpse_dll_h */
