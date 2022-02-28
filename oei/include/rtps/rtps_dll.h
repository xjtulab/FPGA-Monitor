/*e \file
 * \brief RTPS Configuration
 *  
 * \details 
 * Configurable build flags for RTPS functionality 
 */

#ifndef rtps_dll_h
#define rtps_dll_h

#include "osapi/osapi_config.h"


#if defined(OEI_WIN32) || defined(OEI_WINCE30)

#if defined(OEI_DLL_EXPORT)
#ifndef OEI_rtps_DLL_EXPORT
#define OEI_rtps_DLL_EXPORT
#endif
#ifndef OEI_rtps_DLL_VARIABLE
#define OEI_rtps_DLL_VARIABLE
#endif
#endif

#if defined(OEI_rtps_DLL_EXPORT)
#define RTPSDllExport __declspec( dllexport )
#else
#define RTPSDllExport
#endif /* OEI_RTPS_DLL_EXPORT */

#if defined(OEI_rtps_DLL_VARIABLE)
#if defined(OEI_rtps_DLL_EXPORT)
#define RTPSDllVariable __declspec( dllexport )
#else
#define RTPSDllVariable __declspec( dllimport )
#endif /* OEI_RTPS_DLL_EXPORT */
#else
#define RTPSDllVariable
#endif /* OEI_RTPS_DLL_VARIABLE */
#else
#define RTPSDllExport
#define RTPSDllVariable
#endif /* OEI_WIN32 || OEI_WINCE30 */

#if defined(__cplusplus) && defined(OEI_USE_CPP_API)
#define OEI_CPP
#endif

#endif /* rtps_dll_h */
