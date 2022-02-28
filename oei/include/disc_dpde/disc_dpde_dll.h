/*
 * FILE: disc_dpde_dll.h - DPDE DLL external linkage
 *
 */
/*ce
 * \file
 * \brief DPDE DLL external linkage
 */
#ifndef disc_dpde_dll_h
#define disc_dpde_dll_h

#include "osapi/osapi_config.h"

#if defined(OEI_WIN32) || defined(OEI_WINCE)

#if defined(OEI_DLL_EXPORT)
#ifndef OEI_disc_dpde_DLL_EXPORT
#define OEI_disc_dpde_DLL_EXPORT
#endif
#ifndef OEI_disc_dpde_DLL_VARIABLE
#define OEI_disc_dpde_DLL_VARIABLE
#endif
#endif

#if defined(OEI_disc_dpde_DLL_EXPORT)
#define DISC_DPDEDllExport __declspec( dllexport )
#else
#define DISC_DPDEDllExport
#endif /* OEI_disc_dpde_DLL_EXPORT */

#if defined(OEI_disc_dpde_DLL_VARIABLE)
#if defined(OEI_disc_dpde_DLL_EXPORT)
#define DISC_DPDEDllVariable __declspec( dllexport )
#else
#define DISC_DPDEDllVariable __declspec( dllimport )
#endif /* OEI_disc_dpde_DLL_EXPORT */
#else
#define DISC_DPDEDllVariable
#endif /* OEI_disc_dpde_DLL_VARIABLE */
#else
#define DISC_DPDEDllExport
#define DISC_DPDEDllVariable
#endif /* OEI_WIN32 || OEI_WINCE */




#if defined(__cplusplus) && defined(OEI_USE_CPP_API)
#define OEI_CPP
#endif


#endif /* disc_dpde_dll_h */
