/*e \file
 * \brief RTPS Configuration
 *  
 * \details 
 * Configurable build flags for RTPS functionality 
 */

#ifndef rtps_config_h
#define rtps_config_h

/* The global configuration is read first. Local definitions must
 * check if the global configuration has set an option or not. Note that
 * a module cannot disable a feature.
 */
#ifdef HAVE_GLOBAL_CONFIG
#include "OEI_config.h"
#endif
  
/*ci
 * \def RTPS_RELIABILITY
 * \brief Set RTPS_RELIABILITY to enable reliable RTPS communication.
 */
#ifndef RTPS_RELIABILITY
#define RTPS_RELIABILITY  1
#endif


#endif /* rtps_config_h */
