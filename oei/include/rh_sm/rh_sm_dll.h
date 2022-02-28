/*
 * FILE: rh_sm.dll - ReaderHistory DLL external linkage
 *
 */
/*ce
 * \file
 * \brief ReaderHistory DLL external linkage
 */
#ifndef rh_sm_dll_h
#define rh_sm_dll_h

#include "osapi/osapi_config.h"

#if defined(OEI_WIN32) || defined(OEI_WINCE)

#if defined(OEI_DLL_EXPORT)
#ifndef OEI_rh_sm_DLL_EXPORT
#define OEI_rh_sm_DLL_EXPORT
#endif
#ifndef OEI_rh_sm_DLL_VARIABLE
#define OEI_rh_sm_DLL_VARIABLE
#endif
#endif

#if defined(OEI_rh_sm_DLL_EXPORT)
#define RHSMDllExport __declspec( dllexport )
#else
#define RHSMDllExport
#endif /* OEI_rh_sm_DLL_EXPORT */

#if defined(OEI_rh_sm_DLL_VARIABLE)
#if defined(OEI_rh_sm_DLL_EXPORT)
#define RHSMDllVariable __declspec( dllexport )
#else
#define RHSMDllVariable __declspec( dllimport )
#endif /* OEI_rh_sm_DLL_EXPORT */
#else
#define RHSMDllVariable
#endif /* OEI_rh_sm_DLL_EXPORT */
#else
#define RHSMDllExport
#define RHSMDllVariable
#endif /* OEI_WIN32 || OEI_WINCE */




#if defined(__cplusplus) && defined(OEI_USE_CPP_API)
#define OEI_CPP
#endif


#endif /* rh_sm_dll_h */
