/*
 * FILE: wh_sm_log.h - Writer Log definitions
 *
 */

/*ce
 * \file 
 * \brief WH module log codes 
 */
#ifndef wh_sm_log_h
#define wh_sm_log_h

#ifndef osapi_log_h
#include "osapi/osapi_log.h"
#endif

/*ce
 * \defgroup WHLogCodesClass WH 
 * \brief Writer History. ModuleID = 9 
 * \ingroup LoggingModule
 */

/*ce
 * \brief KEEP_ALL History kind is not supported  
 * \ingroup WHLogCodesClass
 */
#define WHSM_LOG_KEEP_ALL_HISTORY_NOT_SUPPORTED_EC           (WHSM_LOG_BASE + 1)
#define WHSM_LOG_KEEP_ALL_HISTORY_NOT_SUPPORTED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),WHSM_LOG_KEEP_ALL_HISTORY_NOT_SUPPORTED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Unlimited length resource limits unsupported 
 * \details Ensure that max_samples, max_samples_per_instance, and max_instances 
 * resource limits are all finite values 
 * \ingroup WHLogCodesClass
 */
#define WHSM_LOG_UNLIMITED_HISTORY_NOT_SUPPORTED_EC          (WHSM_LOG_BASE + 2)
#define WHSM_LOG_UNLIMITED_HISTORY_NOT_SUPPORTED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),WHSM_LOG_UNLIMITED_HISTORY_NOT_SUPPORTED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief DataWriterQos.resource_limits.max_samples set too small
 *  
 * \details DataWriterQos.resource_limits.max_samples must be 
 *        no less than max_instances * max_samples_per_instance 
 * \ingroup WHLogCodesClass
 */
#define WHSM_LOG_MAX_SAMPLES_TOO_SMALL_EC                    (WHSM_LOG_BASE + 3)
#define WHSM_LOG_MAX_SAMPLES_TOO_SMALL(level_) \
OSAPI_LOG_ENTRY_ADD((level_),WHSM_LOG_MAX_SAMPLES_TOO_SMALL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief A history object
 */
#define WHSM_LOG_HISTORY_OBJECT                                         1

/*ce
 * \brief A key object
 */
#define WHSM_LOG_KEY_OBJECT                                             2

/*ce
 * \brief A sample object
 */
#define WHSM_LOG_SAMPLE_OBJECT                                          2

/*ce
 * \brief A key-pool object
 */
#define WHSM_LOG_KEYPOOL_OBJECT                                         3

/*ce
 * \brief A sample-pool object
 */
#define WHSM_LOG_SAMPLEPOOL_OBJECT                                      4

/*ce
 * \brief A key index pool
 */
#define WHSM_LOG_KEYINDEX_OBJECT                                        5

/*ce
 * \brief A key index pool
 */
#define WHSM_LOG_HISTORYINDEX_OBJECT                                    6

/*ce
 * \brief A key index pool
 */
#define WHSM_LOG_SAMPLEINDEX_OBJECT                                     5

/*ce
 * \brief Failed to allocate object of the specified kind
 *
 * \ingroup WHLogCodesClass
 */
#define WHSM_LOG_OBJECT_ALLOCATE_EC                          (WHSM_LOG_BASE + 4)
#define WHSM_LOG_OBJECT_ALLOCATE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),WHSM_LOG_OBJECT_ALLOCATE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to delete object of the specified kind
 *
 * \ingroup WHLogCodesClass
 */
#define WHSM_LOG_OBJECT_DELETE_EC                            (WHSM_LOG_BASE + 5)
#define WHSM_LOG_OBJECT_DELETE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),WHSM_LOG_OBJECT_DELETE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to index an object of the specified kind
 *
 * \ingroup WHLogCodesClass
 */
#define WHSM_LOG_OBJECT_INDEX_EC                             (WHSM_LOG_BASE + 6)
#define WHSM_LOG_OBJECT_INDEX(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),WHSM_LOG_OBJECT_INDEX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief No property when creating a writer history instance
 *
 * \ingroup WHLogCodesClass
 */
#define WHSM_LOG_NO_PROPERTY_EC                              (WHSM_LOG_BASE + 7)
#define WHSM_LOG_NO_PROPERTY(level_) \
OSAPI_LOG_ENTRY_ADD((level_),WHSM_LOG_NO_PROPERTY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

#endif

