/*
 * FILE: netio_logger_config.h - NETIO_Logger Configuration API
 *
 */
/*ce
 * \file
 */
/*ci
 * \defgroup NETIOTestIntfConfig NETIO_TestIF Configuration
 * \ingroup NETIOModule
 * \brief NETIO Configuration API
 */
/*ci \addtogroup NETIOTestIntfConfig
 * @{
 */
#ifndef netio_tintf_config_h
#define netio_tintf_config_h

/* The global configuration is read first. Local definitions must
 * check if the global configuration has set an option or not. Note that
 * a module cannot disable a feature.
 */
#ifdef HAVE_GLOBAL_CONFIG
#include "OEI_config.h"
#endif
  

#endif /* netio_tintf_config_h */

/*ci @} */
