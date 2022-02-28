/*
 * FILE: dds_c_config.h - DDS C configuration file
 *
 */
/*e \file
  \brief DDS C configuration file
*/
#ifndef dds_c_config_h
#define dds_c_config_h

/* Product version:
 */
/* If any of the version numbers exceed 9,
 * DDS_DomainParticipant_initialize must be updated to handle it
 */
#define OEI_DDS_VERSION_MAJOR    2
#define OEI_DDS_VERSION_MINOR    4
#define OEI_DDS_VERSION_REVISION 9
#define OEI_DDS_VERSION_RELEASE  0

#define OEI_NAME "OEI Connext Micro"


/*i \brief The OMG Vendor id used by Micro
 */
#define OEI_VENDOR_ID_MAJOR  (0x01)
#define OEI_VENDOR_ID_MINOR  (0x0a)

/* The global configuration is read first. Local definitions must
 * check if the global configuration has set an option or not. Note that
 * a module cannot disable a feature.
 */
#ifdef HAVE_GLOBAL_CONFIG
#include "OEI_config.h"
#endif

/* RTPS_RELIABILITY
 *
 * Set RTPS_RELIABILITY to enable reliable RTPS communication.
 *
 */
#ifndef RTPS_RELIABILITY
#define RTPS_RELIABILITY  1
#endif

#ifdef OEI_CERT
#undef INCLUDE_API_LOOKUP 
#else
#ifndef INCLUDE_API_LOOKUP
#define INCLUDE_API_LOOKUP 1
#endif
#endif

#ifdef OEI_CERT
#undef INCLUDE_API_QOS 
#else
#ifndef INCLUDE_API_QOS
#define INCLUDE_API_QOS 1
#endif
#endif

#ifndef ENABLE_STATUS_LISTENER
#define ENABLE_STATUS_LISTENER 1
#endif

#ifndef ENABLE_QOS_DEADLINE
#define ENABLE_QOS_DEADLINE 1
#endif

#ifdef OEI_CERT
#undef INCLUDE_API_LISTENER
#else
#ifndef INCLUDE_API_LISTENER
#define INCLUDE_API_LISTENER 1
#endif
#endif

#ifndef INCLUDE_API_INSTANCE
#define INCLUDE_API_INSTANCE 1
#endif

#ifndef INCLUDE_API_DELETE
#define INCLUDE_API_DELETE 1
#endif

#endif /* dds_c_config_h */
