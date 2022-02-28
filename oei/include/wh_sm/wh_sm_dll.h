/*
 * FILE: wh_sm.dll - WriterHistory DLL external linkage
 *
 */
/*ce
 * \file
 * \brief WriterHistory DLL external linkage
 */
#ifndef wh_sm_dll_h
#define wh_sm_dll_h

#include "osapi/osapi_config.h"

#if defined(OEI_WIN32) || defined(OEI_WINCE)

#if defined(OEI_DLL_EXPORT)
#ifndef OEI_wh_sm_DLL_EXPORT
#define OEI_wh_sm_DLL_EXPORT
#endif
#ifndef OEI_wh_sm_DLL_VARIABLE
#define OEI_wh_sm_DLL_VARIABLE
#endif
#endif

#if defined(OEI_wh_sm_DLL_EXPORT)
#define WHSMDllExport __declspec( dllexport )
#else
#define WHSMDllExport
#endif /* OEI_history_DLL_EXPORT */

#if defined(OEI_wh_sm_DLL_VARIABLE)
#if defined(OEI_history_DLL_EXPORT)
#define WHSMDllVariable __declspec( dllexport )
#else
#define WHSMDllVariable __declspec( dllimport )
#endif /* OEI_history_DLL_EXPORT */
#else
#define WHSMDllVariable
#endif /* OEI_history_DLL_VARIABLE */
#else
#define WHSMDllExport
#define WHSMDllVariable
#endif /* OEI_WIN32 || OEI_WINCE */




#if defined(__cplusplus) && defined(OEI_USE_CPP_API)
#define OEI_CPP
#endif


#endif /* wh_sm_dll_h */
