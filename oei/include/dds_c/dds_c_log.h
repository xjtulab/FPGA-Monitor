/*
 * FILE: dds_c_log.h - DDS log definitions
 *
 */
/*ce
 * \file 
 * \brief DDS_C module log codes 
 */

#ifndef dds_c_log_h
#define dds_c_log_h

#include "dds_c/dds_c_config.h"

#ifndef osapi_log_h
#include "osapi/osapi_log.h"
#endif

/*ce
 * \defgroup DDSCLogCodesClass DDS_C 
 * \brief DDS C. ModuleID = 7 
 * \ingroup LoggingModule
 */

/*******************************************************************************
 *                       INFRASTRUCTURE LOG-CODES
 ******************************************************************************/
/*ce
 * \brief The specified duration is not valid.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_INVALID_DURATION_EC                         (DDSC_LOG_BASE + 1)
#define DDSC_LOG_INVALID_DURATION(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_INVALID_DURATION_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief An invalid participant name was specified with an unknown GUID.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_INVALID_PARTICIPANT_NAME_EC                 (DDSC_LOG_BASE + 2)
#define DDSC_LOG_INVALID_PARTICIPANT_NAME(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_INVALID_PARTICIPANT_NAME_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief An invalid participant GUID prefix was specified, typically the
 *        GUID prefix does not match an already detected participant.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_INVALID_PARTICIPANT_GUID_PREFIX_EC          (DDSC_LOG_BASE + 3)
#define DDSC_LOG_INVALID_PARTICIPANT_GUID_PREFIX(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_INVALID_PARTICIPANT_GUID_PREFIX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief A call to OSAPI_System_get_time failed.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SYS_GETTIME_EC                              (DDSC_LOG_BASE + 4)
#define DDSC_LOG_SYS_GETTIME(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_SYS_GETTIME_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to get the next automatically generated object ID for an
 *        entity's GUID. This typically means the object id pool has been
 *        exhausted.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_GET_NEXT_OBJECT_ID_EC                       (DDSC_LOG_BASE + 5)
#define DDSC_LOG_GET_NEXT_OBJECT_ID(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_GET_NEXT_OBJECT_ID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to set name string for a DDS entity in the DomainParticipantQos
 *        entity_name policy.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SET_ENTITY_NAME_EC                          (DDSC_LOG_BASE + 6)
#define DDSC_LOG_SET_ENTITY_NAME(level_,name_,len_,max_) \
OSAPI_LOG_ENTRY_CREATE((level_),DDSC_LOG_SET_ENTITY_NAME_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,OEI_FALSE)\
OSAPI_LOG_ENTRY_ADD_STRING("name",(name_),OEI_FALSE)\
OSAPI_LOG_ENTRY_ADD_INT("len",(len_),OEI_FALSE)\
OSAPI_LOG_ENTRY_ADD_INT("max",(max_),OEI_TRUE)

/*ce
 * \brief A call to OSAPI_System_get_hostname failed.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SYS_GET_HOSTNAME_EC                         (DDSC_LOG_BASE + 7)
#define DDSC_LOG_SYS_GET_HOSTNAME(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_SYS_GET_HOSTNAME_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief A call to OSAPI_Stdio_snprintf failed. Typically this means the
 *        destination buffer was too small.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_IO_SNPRINTF_FAILED_EC                       (DDSC_LOG_BASE + 8)
#define DDSC_LOG_IO_SNPRINTF_FAILED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_IO_SNPRINTF_FAILED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to find a topic created by a DomainParticipant.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TOPIC_FIND_EC                               (DDSC_LOG_BASE + 9)
#define DDSC_LOG_TOPIC_FIND(level_,topic_,dbrc_) \
OSAPI_LOG_ENTRY_CREATE((level_),DDSC_LOG_TOPIC_FIND_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,OEI_FALSE)\
OSAPI_LOG_ENTRY_ADD_STRING("topic",(topic_),OEI_FALSE)\
OSAPI_LOG_ENTRY_ADD_INT("dbrc",(dbrc_),OEI_TRUE)

/*ce
 * \brief Endpoint discovery failed because the name of the remote participant
 *        parent for an endpoint was not found.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_UNKNOWN_REMOTE_PARTICIPANT_NAME_EC         (DDSC_LOG_BASE + 10)
#define DDSC_LOG_UNKNOWN_REMOTE_PARTICIPANT_NAME(level_,name_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_UNKNOWN_REMOTE_PARTICIPANT_NAME_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"name",(name_))

/*ce
 * \brief Endpoint discovery failed because the key of the remote participant
 *        parent for an endpoint was not found. Note that the key is logged
 *        as 4 integers in host endianess format.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_UNKNOWN_REMOTE_PARTICIPANT_KEY_EC          (DDSC_LOG_BASE + 11)
#define DDSC_LOG_UNKNOWN_REMOTE_PARTICIPANT_KEY(level_,key0_,key1_,key2_,key3_) \
OSAPI_LOG_ENTRY_CREATE((level_),DDSC_LOG_UNKNOWN_REMOTE_PARTICIPANT_KEY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("key0",(key0_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("key1",(key1_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("key2",(key2_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("key3",(key3_),OEI_TRUE)

/*ce
 * \brief Failed endpoint discovery when key does not match the remote
 *        participant.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_REMOTE_PARTICIPANT_KEY_NOT_EQUAL_EC        (DDSC_LOG_BASE + 12)
#define DDSC_LOG_REMOTE_PARTICIPANT_KEY_NOT_EQUAL(level_,name_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_REMOTE_PARTICIPANT_KEY_NOT_EQUAL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"name",(name_))

/*ce
 * \brief Failed endpoint discovery due to an invalid or unknown endpoint GUID.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_INVALID_ENDPOINT_GUID_EC                   (DDSC_LOG_BASE + 13)
#define DDSC_LOG_INVALID_ENDPOINT_GUID(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_INVALID_ENDPOINT_GUID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed endpoint discovery when an endpoint is determined to belong to
 *        a different remote participant.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ENDPOINT_NOT_CHILD_OF_PARTICIPANT_EC       (DDSC_LOG_BASE + 14)
#define DDSC_LOG_ENDPOINT_NOT_CHILD_OF_PARTICIPANT(level_,participant_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_ENDPOINT_NOT_CHILD_OF_PARTICIPANT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"participant",(participant_))

/*ce
 * \brief Failed participant discovery because a remote participant that should
 *        have been already asserted locally was not found.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANT_DOES_NOT_EXIST_EC              (DDSC_LOG_BASE + 15)
#define DDSC_LOG_PARTICIPANT_DOES_NOT_EXIST(level_,participant_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_PARTICIPANT_DOES_NOT_EXIST_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"participant",(participant_))

/*ce
 * \brief Did not find a remote participant when asserting participant
 *        liveliness for it. Note that the key is logged as 4 integers in
 *        host endianess format.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_REFRESH_REM_PARTICIPANT_EC                 (DDSC_LOG_BASE + 16)
#define DDSC_LOG_REFRESH_REM_PARTICIPANT(level_,dbrc_,key0_,key1_,key2_,key3_) \
OSAPI_LOG_ENTRY_CREATE((level_),DDSC_LOG_REFRESH_REM_PARTICIPANT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("dbrc",(dbrc_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("key0",(key0_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("key1",(key1_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("key2",(key2_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("key3",(key3_),OEI_TRUE)

/*ce
 * \brief Failed to assert participant liveliness to a remote participant.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_REFRESH_REM_PARTICIPANT_TIMEOUT_EC         (DDSC_LOG_BASE + 17)
#define DDSC_LOG_REFRESH_REM_PARTICIPANT_TIMEOUT(level_,name_,ms_) \
OSAPI_LOG_ENTRY_ADD_1STRING_1INT((level_),DDSC_LOG_REFRESH_REM_PARTICIPANT_TIMEOUT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"name",(name_),"ms",(ms_))

/*ce
 * \brief Failed to find a remote participant as previously discovered.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANT_LOOKUP_EC                      (DDSC_LOG_BASE + 18)
#define DDSC_LOG_PARTICIPANT_LOOKUP(level_,name_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_PARTICIPANT_LOOKUP_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"name",(name_))

/*ce
 * \brief Failed to remove resources for a remote publication.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_REMOVE_PUBLICATION_EC                      (DDSC_LOG_BASE + 19)
#define DDSC_LOG_REMOVE_PUBLICATION(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_REMOVE_PUBLICATION_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to remove resources for a remote subscription.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_REMOVE_SUBSCRIPTION_EC                     (DDSC_LOG_BASE + 20)
#define DDSC_LOG_REMOVE_SUBSCRIPTION(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_REMOVE_SUBSCRIPTION_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Cannot determine the participant of a remote publication.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_FIND_PUBLICATION_PARENT_EC                 (DDSC_LOG_BASE + 21)
#define DDSC_LOG_FIND_PUBLICATION_PARENT(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_FIND_PUBLICATION_PARENT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Cannot determine the participant of a remote subscription.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_FIND_SUBSCRIPTION_PARENT_EC                (DDSC_LOG_BASE + 22)
#define DDSC_LOG_FIND_SUBSCRIPTION_PARENT(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_FIND_SUBSCRIPTION_PARENT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to create DomainParticipant due to running out of participant
 *        IDs. This is typically caused by all UDP ports being used.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_MAX_PARTICIPANT_ID_REACHED_EC              (DDSC_LOG_BASE + 23)
#define DDSC_LOG_MAX_PARTICIPANT_ID_REACHED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_MAX_PARTICIPANT_ID_REACHED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)


/*ce
 * \brief Failed to reserve endpoint locators.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RESERVE_LOCATORS_EC                        (DDSC_LOG_BASE + 24)
#define DDSC_LOG_RESERVE_LOCATORS(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_RESERVE_LOCATORS_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)


/*ce
 * \brief Failed to create a timeout.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TIMER_CREATE_TIMEOUT_EC                    (DDSC_LOG_BASE + 25)
#define DDSC_LOG_TIMER_CREATE_TIMEOUT(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_TIMER_CREATE_TIMEOUT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Illegal object id specified.
 *
 * \details
 *
 * Manually specifed object id must be in the range [0,0xffffff]
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ILLEGAL_OBJECTID_EC                        (DDSC_LOG_BASE + 26)
#define DDSC_LOG_ILLEGAL_OBJECTID(level_,oid_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_ILLEGAL_OBJECTID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"oid",(oid_))

/*ce
 * \brief Failed to narrow a TopicDescription to the named Topic.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TOPIC_NARROW_EC                            (DDSC_LOG_BASE + 27)
#define DDSC_LOG_TOPIC_NARROW(level_,topic_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_TOPIC_NARROW_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"topic",(topic_))

/*ce
 * \brief Failed to update state of StatusCondition.
 *
 * \details
 *
 * An error occurred when trying to update the state (i.e. the trigger value) of
 * a StatusCondition.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_FAILED_UPDATE_STATUS_CONDITION_EC          (DDSC_LOG_BASE + 28)
#define DDSC_LOG_FAILED_UPDATE_STATUS_CONDITION(level_,entity_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_FAILED_UPDATE_STATUS_CONDITION_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"entity",#entity_)

/*ce
 * \brief Failed to remove a condition reference from a waitset.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_WS_REMOVE_COND_REFERENCE_EC                (DDSC_LOG_BASE + 29)
#define DDSC_LOG_WS_REMOVE_COND_REFERENCE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_WS_REMOVE_COND_REFERENCE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to add a condition reference to a waitset.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_WS_ADD_COND_REFERENCE_EC                   (DDSC_LOG_BASE + 30)
#define DDSC_LOG_WS_ADD_COND_REFERENCE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_WS_ADD_COND_REFERENCE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to release resources for multicast discovery locators.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RELEASE_META_MC_EC                         (DDSC_LOG_BASE + 31)
#define DDSC_LOG_RELEASE_META_MC(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_RELEASE_META_MC_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to release resources for unicast discovery locators.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RELEASE_META_UC_EC                         (DDSC_LOG_BASE + 32)
#define DDSC_LOG_RELEASE_META_UC(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_RELEASE_META_UC_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to release resources for multicast user locators.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RELEASE_USER_MC_EC                         (DDSC_LOG_BASE + 33)
#define DDSC_LOG_RELEASE_USER_MC(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_RELEASE_USER_MC_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to release resources for unicast user locators.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RELEASE_USER_UC_EC                         (DDSC_LOG_BASE + 34)
#define DDSC_LOG_RELEASE_USER_UC(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_RELEASE_USER_UC_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief The domain ID specified exceeds what is allowed based on the
 *        parameters specified in dp_qos.protocol.rtps_well_known_ports
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_INVALID_DOMAINID_EC                        (DDSC_LOG_BASE + 35)
#define DDSC_LOG_INVALID_DOMAINID(level_,domainid_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_INVALID_DOMAINID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"domain_id",(domainid_))

/*******************************************************************************
 *                            DATABASE RELATED
 ******************************************************************************/
/*ce
 * \brief Failed to create database.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATABASE_CREATE_EC                        (DDSC_LOG_BASE + 100)
#define DDSC_LOG_DATABASE_CREATE(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_DATABASE_CREATE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to delete database.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATABASE_DELETE_EC                        (DDSC_LOG_BASE + 101)
#define DDSC_LOG_DATABASE_DELETE(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_DATABASE_DELETE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to create database table of the specified name.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TABLE_CREATE_EC                           (DDSC_LOG_BASE + 102)
#define DDSC_LOG_TABLE_CREATE(level_,name_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1STRING_1INT((level_),DDSC_LOG_TABLE_CREATE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "name",(name_),"dbrc",(dbrc_))

/*ce
 * \brief Failed to delete a database table because it is not empty.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TABLE_INUSE_EC                            (DDSC_LOG_BASE + 103)
#define DDSC_LOG_TABLE_INUSE(level_,table_,count_) \
OSAPI_LOG_ENTRY_ADD_1STRING_1INT((level_),DDSC_LOG_TABLE_INUSE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "table",DB_Table_get_name((table_)),"count",(count_))

/*ce
 * \brief Failed to delete a database table.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TABLE_DELETE_EC                           (DDSC_LOG_BASE + 104)
#define DDSC_LOG_TABLE_DELETE(level_,table_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1STRING_1INT((level_),DDSC_LOG_TABLE_DELETE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "table",DB_Table_get_name((table_)),"dbrc",(dbrc_))

/*ce
 * \brief A selection operation failed on the specified database table.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TABLE_SELECT_EC                           (DDSC_LOG_BASE + 105)
#define DDSC_LOG_TABLE_SELECT(level_,table_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1STRING_1INT((level_),DDSC_LOG_TABLE_SELECT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "table",DB_Table_get_name((table_)),"dbrc",(dbrc_))

/*ce
 * \brief Failed to create an index on a database table.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CREATE_INDEX_EC                           (DDSC_LOG_BASE + 106)
#define DDSC_LOG_CREATE_INDEX(level_,table_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1STRING_1INT((level_),DDSC_LOG_CREATE_INDEX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "table",DB_Table_get_name((table_)),"dbrc",(dbrc_))

/*ce
 * \brief Failed to delete an index on a database table.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DELETE_INDEX_EC                           (DDSC_LOG_BASE + 107)
#define DDSC_LOG_DELETE_INDEX(level_,table_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1STRING_1INT((level_),DDSC_LOG_DELETE_INDEX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "table",DB_Table_get_name((table_)),"dbrc",(dbrc_))


/*ce
 * \brief A database table cursor was invalidated while in use.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DB_CURSOR_INVALIDATED_EC                  (DDSC_LOG_BASE + 108)
#define DDSC_LOG_DB_CURSOR_INVALIDATED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_DB_CURSOR_INVALIDATED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Database record for a Subscription.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SUBSCRIPTION_RECORD              1

/*ce
 * \brief Database record for a Publication.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PUBLICATION_RECORD               2

/*ce
 * \brief Database record for a Remote Participant.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANT_RECORD               3

/*ce
 * \brief Database record for a Topic.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TOPIC_RECORD                     4

/*ce
 * \brief Database record for a DataWriter.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAWRITER_RECORD                5

/*ce
 * \brief Database record for a DataReader.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAREADER_RECORD                6

/*ce
 * \brief Database record for a Publisher.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PUBLISHER_RECORD                 7

/*ce
 * \brief Database record for a Subscriber.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SUBSCRIBER_RECORD                8

/*ce
 * \brief Database record for a route record.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ROUTE_RECORD                     9

/*ce
 * \brief Database record for a bind record.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_BIND_RECORD                      10

/*ce
 * \brief Database record for a type plugin.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_RECORD                      11

/*ce
 * \brief Failed to create route record of the specified kind.
 *
 * \details
 * The creation of an internal database record failed The failure may
 * have been caused by insufficient resources based on the record kind.
 * The following resource-limits may apply:
 *
 *
 * DomainParticipantQos.resource_limit.local_publisher_allocation
 *          limits the number of DDS Publishers.
 *
 * DomainParticipantQos.resource_limit.local_subscriber_allocation
 *          limits the number of DDS Subscribers
 *
 * DomainParticipantQos.resource_limit.local_topic_allocation
 *          limits the number of DDS Topics.
 *
 * DomainParticipantQos.resource_limits.local_reader_allocation
 *          limits the number of DDS DataReader records.
 *
 * DomainParticipantQos.resource_limits.local_writer_allocation
 *          limits the number of DDS DataWriter records.
 *
 * DomainParticipantQos.resource_limits.remote_writer_allocation
 *          limits the number of remote publication records
 *
 * DomainParticipantQos.resource_limits.remote_reader_allocation
 *          limits the number of remote subscription records.
 *
 * DomainParticipantQos.resource_limits.remote_participant_allocation
 *          limits the number of remote participant records.
 *
 * DataWriterQos.writer_resource_limits.max_remote_readers
 *          limits of the number of DDS DataReaders a DDS DataWriter can
 *          communicate with.
 *
 * DataReaderQos.reader_resource_limits.max_remote_writers
 *          limits of the number of DDS DataWriter a DDS DataReader can
 *          communicate with.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RECORD_CREATE_EC                          (DDSC_LOG_BASE + 109)
#define DDSC_LOG_RECORD_CREATE(level_,kind_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_RECORD_CREATE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_),"dbrc",(dbrc_))

/*ce
 * \brief Failed to delete a database record of the specified kind.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RECORD_DELETE_EC                          (DDSC_LOG_BASE + 110)
#define DDSC_LOG_RECORD_DELETE(level_,kind_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_RECORD_DELETE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_),"dbrc",(dbrc_))


/*ce
 * \brief Failed to insert a database record of the specified kind.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RECORD_INSERT_EC                          (DDSC_LOG_BASE + 111)
#define DDSC_LOG_RECORD_INSERT(level_,kind_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_RECORD_INSERT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_),"dbrc",(dbrc_))

/*ce
 * \brief Unknown error for database record of the specified kind.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RECORD_ERROR_EC                           (DDSC_LOG_BASE + 112)
#define DDSC_LOG_RECORD_ERROR(level_,kind_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_RECORD_ERROR_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_),"dbrc",(dbrc_))

/*ce
 * \brief A database record of the specified kind already exists.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RECORD_EXISTS_EC                          (DDSC_LOG_BASE + 113)
#define DDSC_LOG_RECORD_EXISTS(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_RECORD_EXISTS_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief A lookup of a database record of the specified kind failed.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RECORD_LOOKUP_EC                          (DDSC_LOG_BASE + 114)
#define DDSC_LOG_RECORD_LOOKUP(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_RECORD_LOOKUP_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief A database record of the specified kind does not exist.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RECORD_NOT_EXISTS_EC                      (DDSC_LOG_BASE + 115)
#define DDSC_LOG_RECORD_NOT_EXISTS(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_RECORD_NOT_EXISTS_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief A database select on the specified record kind failed.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RECORD_SELECT_EC                          (DDSC_LOG_BASE + 116)
#define DDSC_LOG_RECORD_SELECT(level_,kind_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_RECORD_SELECT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_),"dbrc",(dbrc_))

/*ce
 * \brief Removal a database record of the specified kind failed.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RECORD_REMOVE_EC                          (DDSC_LOG_BASE + 117)
#define DDSC_LOG_RECORD_REMOVE(level_,kind_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_RECORD_REMOVE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_),"dbrc",(dbrc_))

/*ce
 * \brief A database record of the specified kind could not be initialized
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RECORD_INITIALIZE_EC                      (DDSC_LOG_BASE + 118)
#define DDSC_LOG_RECORD_INITIALIZE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_RECORD_INITIALIZE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief A database record of the specified kind could not be finalized
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RECORD_FINALIZE_EC                        (DDSC_LOG_BASE + 119)
#define DDSC_LOG_RECORD_FINALIZE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_RECORD_FINALIZE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*******************************************************************************
 *                              OBJECT RELATED
 ******************************************************************************/
/*ce
 * \brief DDS PublicationBuiltinTopicData object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PUBLICATIONDATA_OBJECT                     1

/*ce
 * \brief DDS SubscriptionBuiltinTopicData object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SUBSCRIPTIONDATA_OBJECT                    2

/*ce
 * \brief DDS ParticipantBuiltinTopicData object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANTDATA_OBJECT                     3

/*ce
 * \brief DDS DataReaderQos object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAREADERQOS_OBJECT                       4

/*ce
 * \brief DDS DataWriterQos object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAWRITERQOS_OBJECT                       5

/*ce
 * \brief DDS TopicQos object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TOPICQOS_OBJECT                            6

/*ce
 * \brief DDS PublisherQos object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PUBLISHERQOS_OBJECT                        7

/*ce
 * \brief DDS SubscriberQos object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SUBSCRIBERQOS_OBJECT                       8

/*ce
 * \brief DDS DomainParticipantQos object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANTQOS_OBJECT                      9

/*ce
 * \brief DDS Entity object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ENTITY_OBJECT                             10

/*ce
 * \brief DDS DomainParticipantFactoryQos object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANTFACTORYQOS_OBJECT              11

/*ce
 * \brief A DDS Type object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_OBJECT                               12

/*ce
 * \brief A NETIO BindResolver object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_BINDRESOLVER_OBJECT                       13

/*ce
 * \brief A NETIO RouteResolver object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ROUTERESOLVER_OBJECT                      14

/*ce
 * \brief A NETIO AddressResolver object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ADDRESSRESOLVER_OBJECT                    15

/*ce
 * \brief A NETIO DataWriterInterface object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAWRITERIO_OBJECT                       16

/*ce
 * \brief A NETIO DataReaderInterface object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAREADERIO_OBJECT                       17

/*ce
 * \brief A OSAPI Log object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_LOG_OBJECT                                18

/*ce
 * \brief A OSAPI system object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SYSTEM_OBJECT                             19

/*ce
 * \brief A OSAPI mutex object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_MUTEX_OBJECT                              20

/*ce
 * \brief A DDS Waitset condition reference object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CONDREF_OBJECT                            21

/*ce
 * \brief A DDS Condition waitset reference object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_WSREF_OBJECT                              22

/*ce
 * \brief A MD5 stream object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_MD5STREAM_OBJECT                          23

/*ce
 * \brief A DDS Condition object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CONDITION_OBJECT                          24

/*ce
 * \brief A RT Condition object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RT_OBJECT                                 25

/*ce
 * \brief A Participant pool object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANT_POOL_OBJECT                   26

/*ce
 * \brief A OSAPI_Timer object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TIMER_OBJECT                              27

/*ce
 * \brief A OSAPI_Timer timeout object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TIMEROUT_OBJECT                           28

/*ce
 * \brief A DDS Topic object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TOPIC_OBJECT                              29

/*ce
 * \brief A DDS WaitSet object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_WAITSET_OBJECT                            30

/*ce
 * \brief A UUID object
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_UUID_OBJECT                               31

/*ce
 * \brief Out of resources to initialize object of the specified kind.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_OBJECT_INITIALIZE_EC                      (DDSC_LOG_BASE + 200)
#define DDSC_LOG_OBJECT_INITIALIZE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_OBJECT_INITIALIZE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Out of resources to allocate an object of the specified kind.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_OBJECT_ALLOCATE_EC                        (DDSC_LOG_BASE + 201)
#define DDSC_LOG_OBJECT_ALLOCATE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_OBJECT_ALLOCATE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to finalize object of specified kind.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_OBJECT_FINALIZE_EC                        (DDSC_LOG_BASE + 202)
#define DDSC_LOG_OBJECT_FINALIZE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_OBJECT_FINALIZE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to delete object of specified kind.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_OBJECT_DELETE_EC                          (DDSC_LOG_BASE + 203)
#define DDSC_LOG_OBJECT_DELETE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_OBJECT_DELETE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to copy object of specified kind.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_OBJECT_COPY_EC                            (DDSC_LOG_BASE + 204)
#define DDSC_LOG_OBJECT_COPY(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_OBJECT_COPY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to delete/finalize an object because other objects are
 *        referencing it.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_OBJECT_REFCOUNT_EC                        (DDSC_LOG_BASE + 205)
#define DDSC_LOG_OBJECT_REFCOUNT(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_OBJECT_REFCOUNT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to get the object properties.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_OBJECT_GET_PROPERTY_EC                    (DDSC_LOG_BASE + 206)
#define DDSC_LOG_OBJECT_GET_PROPERTY(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_OBJECT_GET_PROPERTY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to set the object properties.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_OBJECT_SET_PROPERTY_EC                    (DDSC_LOG_BASE + 207)
#define DDSC_LOG_OBJECT_SET_PROPERTY(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_OBJECT_SET_PROPERTY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief An object is empty, typically applies only to buffer-pool objects
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_OBJECT_EMPTY_EC                           (DDSC_LOG_BASE + 208)
#define DDSC_LOG_OBJECT_EMPTY(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_OBJECT_EMPTY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief An object is empty, typically applies only to buffer-pool objects
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_OBJECT_NOT_EMPTY_EC                       (DDSC_LOG_BASE + 208)
#define DDSC_LOG_OBJECT_NOT_EMPTY(level_,kind_,count_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_OBJECT_NOT_EMPTY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "kind",(kind_),"count",(count_))

/*ce
 * \brief Failed to delete/finalize an object because other objects are
 *        using it.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_OBJECT_INUSECOUNT_EC                      (DDSC_LOG_BASE + 209)
#define DDSC_LOG_OBJECT_INUSECOUNT(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_OBJECT_INUSECOUNT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*******************************************************************************
 *                              SEQUENCE RELATED
 ******************************************************************************/

/*ce
 * \brief A NETIO Netmask sequence
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETMASK_SEQUENCE                                         1

/*ce
 * \brief A NETIO Route sequence
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ROUTE_SEQUENCE                                           2

/*ce
 * \brief A NETIO Reserved address sequence
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RESERVED_SEQUENCE                                        3

/*ce
 * \brief A DDS sequence of enabled user NETIO transports
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ENABLED_USER_TRANSPORT_SEQUENCE                          4

/*ce
 * \brief A DDS sequence of enabled transports
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ENABLED_TRANSPORT_SEQUENCE                               5

/*ce
 * \brief A DDS sequence of enabled discovery transports
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ENABLED_DISCVOERY_TRANSPORT_SEQUENCE                     6

/*ce
 * \brief A DDS sequence of initial peers
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_INITIAL_PEER_SEQUENCE                                    7

/*ce
 * \brief A NETIO sequence of destinations to send to
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DESTINATION_SEQUENCE                                     8

/*ce
 * \brief A DDS sequence of meta-traffic unicast locators
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_METAUNICAST_SEQUENCE                                     9

/*ce
 * \brief A DDS sequence of meta-traffic multicast locators
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_METAMULTICAST_SEQUENCE                                  10

/*ce
 * \brief A DDS sequence of user-traffic unicast locators
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_USERUNICAST_SEQUENCE                                    11

/*ce
 * \brief A DDS sequence of user-traffic multicast locators
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_USERMULTICAST_SEQUENCE                                  12

/*ce
 * \brief A DDS sequence used in a read/take call
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_READTAKE_SEQUENCE                                       13

/*ce
 * \brief Failed to set the maximum length of a sequence of the specified kind.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SEQUENCE_SETMAX_EC                        (DDSC_LOG_BASE + 300)
#define DDSC_LOG_SEQ_SETMAX(level_,kind_,length_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_SEQUENCE_SETMAX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "kind",(kind_),"length",(length_))

/*ce
 * \brief Failed to set the length of a sequence of the specified kind.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SEQUENCE_SETLENGTH_EC                     (DDSC_LOG_BASE + 301)
#define DDSC_LOG_SEQ_SETLENGTH(level_,kind_,length_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_SEQUENCE_SETLENGTH_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "kind",(kind_),"length",(length_))

/*ce
 * \brief Failed to get a reference at the specified index for a sequence of
 *        the specified kind.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SEQUENCE_GETREF_EC                        (DDSC_LOG_BASE + 302)
#define DDSC_LOG_SEQ_GETREF(level_,kind_,index_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_SEQUENCE_GETREF_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "kind",(kind_),"index",(index_))

/*ce
 * \brief Failed to initialize a sequence of the specified kind.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SEQUENCE_INITIALIZE_EC                    (DDSC_LOG_BASE + 303)
#define DDSC_LOG_SEQ_INITIALIZE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_SEQUENCE_INITIALIZE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to finalize a sequence of the specified kind.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SEQUENCE_FINALIZE_EC                      (DDSC_LOG_BASE + 304)
#define DDSC_LOG_SEQ_FINALIZE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_SEQUENCE_FINALIZE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to copy a sequence of the specified kind.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SEQUENCE_COPY_EC                          (DDSC_LOG_BASE + 305)
#define DDSC_LOG_SEQ_COPY(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_SEQUENCE_COPY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief The sequence of the specified kind was invalid in the context it is
 *        used.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SEQUENCE_INVALID_EC                       (DDSC_LOG_BASE + 306)
#define DDSC_LOG_SEQ_INVALID(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_SEQUENCE_INVALID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*******************************************************************************
 *                              COMPONENT RELATED
 ******************************************************************************/
/*ce
 * \brief A component of discovery kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DISCOVERY_COMPONENT                                        1

/*ce
 * \brief A component of RTPS kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RTPS_COMPONENT                                             2

/*ce
 * \brief A component of reader-history kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_READERHISTORY_COMPONENT                                    3

/*ce
 * \brief A component of writer-history kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_WRITERHISTORY_COMPONENT                                    4

/*ce
 * \brief A component of DataReaderInterface kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAREADERIO_COMPONENT                                     5

/*ce
 * \brief A component of DataWriterInterface kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAWRITERIO_COMPONENT                                     6

/*ce
 * \brief A component of NETIO kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_COMPONENT                                            7

/*ce
 * \brief A component of transport kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TRANSPORT_COMPONENT                                        8

/*ce
 * \brief Did not find a component factory with the given name in the registry
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_COMPONENT_LOOKUP_EC                       (DDSC_LOG_BASE + 400)
#define DDSC_LOG_COMPONENT_LOOKUP(level_,factory_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_COMPONENT_LOOKUP_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"factory",(factory_))

/*ce
 * \brief Could not create a component of the specified kind using the specified
 *        factory
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_COMPONENT_CREATE_EC                       (DDSC_LOG_BASE + 401)
#define DDSC_LOG_COMPONENT_CREATE(level_,kind_,factory_) \
OSAPI_LOG_ENTRY_ADD_1STRING_1INT((level_),DDSC_LOG_COMPONENT_CREATE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"factory",(factory_),"kind",(kind_))

/*ce
 * \brief Could not delete a component of the specified kind using the specified
 *        factory
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_COMPONENT_DELETE_EC                       (DDSC_LOG_BASE + 402)
#define DDSC_LOG_COMPONENT_DELETE(level_,factory_,kind_) \
OSAPI_LOG_ENTRY_ADD_1STRING_1INT((level_),DDSC_LOG_COMPONENT_DELETE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "factory",(factory_),"kind",(kind_))


/*******************************************************************************
 *                              QOS & LISTENER RELATED
 ******************************************************************************/
/*ce
 * \brief Exceeded resource limits for writer history queue.
 *
 * \details
 *  A DataWriter failed to get a queue entry for a new sample it is
 *  attempting to send, due to exceeding a limit:
 *      - When the sample is for new instance:
 *          DataWriterQos.resource_limits.max_instances may have been exceeded
 *      - When the sample is for an existing instance, and History kind is
 *        KEEP_ALL:
 *          DataWriterQos.resource_limits.max_samples_per_instance
 *          may have been exceeded.
 *      - The limit on the total number of samples in the queue:
 *          DataWriterQos.resource_limits.max_samples, may have been exceeded.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_HISTORY_RESOURCE        1

/*ce
 * \brief Failed to get resource for new sample due to resource limit.
 *
 * \details
 *  A DataWriter failed to get a buffer for a new sample being written
 *  because the limit DataWriterQos.resource_limits.max_samples was
 *  exceeded.
 *
 *  A DataReader failed in getting a buffer for a newly received sample
 *  because DataReaderQos.resource_limits.max_samples was exceeded.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SAMPLE_RESOURCES        2

/*ce
 * \brief Failed to allocate a new participant
 *
 * \details
 * The DomainParticipantFactoryfailed to get a buffer for a new
 * DomainParticipant because
 * DomainParticipantFactoryQos.system_resource.max_participants
 * because was exceeded.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANT_RESOURCES   3

/*ce
 * \brief Could not allocate a resource of the specified kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RESOURCE_EXCEEDED_EC                      (DDSC_LOG_BASE + 500)
#define DDSC_LOG_RESOURCE_EXCEEDED(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_RESOURCE_EXCEEDED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief The TopicQos kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TOPIC_QOS                                    1

/*ce
 * \brief The DataReaderQos kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAREADER_QOS                               2

/*ce
 * \brief The DataWriterQos kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAWRITER_QOS                               3

/*ce
 * \brief The SubscriberQos kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SUBSCRIBER_QOS                               4

/*ce
 * \brief The PublisherQos kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PUBLISHER_QOS                                5

/*ce
 * \brief The DomainParticipantQos kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANT_QOS                              6

/*ce
 * \brief The DomainParticipantFactoryQos kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANTFACTORY_QOS                       7

/*ce
 * \brief The default TopicQos kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DEFAULTTOPIC_QOS                             8

/*ce
 * \brief The default DataReaderQos kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DEFAULTDATAREADER_QOS                        9

/*ce
 * \brief The default DataWriterQos kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DEFAULTDATAWRITER_QOS                       10

/*ce
 * \brief The default SubscriberQos kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DEFAULTSUBSCRIBER_QOS                       11

/*ce
 * \brief The default PublisherQos kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DEFAULTPUBLISHER_QOS                        12

/*ce
 * \brief The default PublisherQos kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DEFAULTPARTICIPANT_QOS                      13

/*ce
 * \brief The deadline qos policy kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DEADLINE_QOS_POLICY                         14

/*ce
 * \brief The liveliness qos policy kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_LIVELINESS_QOS_POLICY                       15

/*ce
 * \brief The history qos policy kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_HISTORY_QOS_POLICY                          16

/*ce
 * \brief The resource limits qos policy kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RESOURCE_LIMIT_QOS_POLICY                   17

/*ce
 * \brief The protocol qos policy kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PROTOCOL_QOS_POLICY                         18

/*ce
 * \brief The type-support qos policy kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_SUPPORT_QOS_POLICY                     19

/*ce
 * \brief The reliability qos policy kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RELIABILITY_QOS_POLICY                      20

/*ce
 * \brief The durability qos policy kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DURABILITY_QOS_POLICY                       21

/*ce
 * \brief The ownership qos policy kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_OWNERSHIP_QOS_POLICY                        22

/*ce
 * \brief The ownership-strength qos policy kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_OWNERSHIP_STRENGTH_QOS_POLICY               23

/*ce
 * \brief The transport qos policy kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TRANSPORT_QOS_POLICY                        24

/*ce
 * \brief The participant id qos policy kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANT_ID_QOS_POLICY                   25

/*ce
 * \brief The heartbeat qos policy kind
 * \ingroup DDSCLogCodesClass
 *
 * \details When configured for reliable communication,
 * heartbeats_per_max_samples must be fit within max_samples
 */
#define DDSC_LOG_HEARTBEATS_QOS_POLICY                       26

/*ce
 * \brief The DataWriterQos writer_resource_limits policy
 *
 * \details An invalid value has been set for a limit of
 *          DataWriterQos.writer_resource_limits.  Each value must be positive
 *          and finite.
 *          May be logged by Discovery writers with no initial_peers set.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAWRITER_RESOURCE_QOS_POLICY              27

/*ce
 * \brief The DataReaderQos reader_resource_limits policy
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAREADER_RESOURCE_QOS_POLICY              28

/*ce
 * \brief An inconsistent Qos policy for the specified Qos kind was found.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_QOS_INCONSISTENT_POLICY_EC                (DDSC_LOG_BASE + 501)
#define DDSC_LOG_QOS_INCONSISTENT_POLICY(level_,kind_,policy_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_QOS_INCONSISTENT_POLICY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "kind",(kind_),"policy",(policy_))

/*ce
 * \brief Inconsistency between two Qos policies for the specified Qos kind was
 *        found.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_QOS_INCONSISTENT_POLICIES_EC              (DDSC_LOG_BASE + 502)
#define DDSC_LOG_QOS_INCONSISTENT_POLICIES(level_,kind_,policy1_,policy2_) \
OSAPI_LOG_ENTRY_ADD_3INT((level_),DDSC_LOG_QOS_INCONSISTENT_POLICIES_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "kind",(kind_),"policy1",(policy1_),"policy2",(policy2_))
/*ce
 * \brief Failed to create an entity or set a qos due to inconsistent policy
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_QOS_INCONSISTENT_EC                       (DDSC_LOG_BASE + 503)
#define DDSC_LOG_QOS_INCONSISTENT(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_QOS_INCONSISTENT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to copy a Qos of the specified kind.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_QOS_COPY_EC                               (DDSC_LOG_BASE + 504)
#define DDSC_LOG_QOS_COPY(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_QOS_COPY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"kind",(kind_))

/*ce
 * \brief Failed to initialize a Qos of the specified kind.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_QOS_INITIALIZE_EC                         (DDSC_LOG_BASE + 505)
#define DDSC_LOG_QOS_INITIALIZE(level_,kind_,ddsrc_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_QOS_INITIALIZE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "kind",(kind_),"ddsrc",(ddsrc_))

/*ce
 * \brief Failed to finalize a Qos of the specified kind.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_QOS_FINALIZE_EC                           (DDSC_LOG_BASE + 506)
#define DDSC_LOG_QOS_FINALIZE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_QOS_FINALIZE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"kind",(kind_))

/*ce
 * \brief Failed to set a Qos of the specified kind.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_QOS_SET_EC                                (DDSC_LOG_BASE + 507)
#define DDSC_LOG_QOS_SET(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_QOS_SET_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"kind",(kind_))

/*ce
 * \brief Failed to set a Qos of the specified kind because the entity is
 *        already enabled.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_QOS_SET_ON_ENABLED_EC                     (DDSC_LOG_BASE + 508)
#define DDSC_LOG_QOS_SET_ON_ENABLED(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_QOS_SET_ON_ENABLED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to set a Qos of the specified kind the immutable Qos policies
 *        have been changed.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_QOS_IMMUTABLE_EC                          (DDSC_LOG_BASE + 509)
#define DDSC_LOG_QOS_IMMUTABLE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_QOS_IMMUTABLE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief A discovered Qos changed (the entity already existed)
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_QOS_CHANGED_EC                            (DDSC_LOG_BASE + 510)
#define DDSC_LOG_QOS_CHANGED(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_QOS_CHANGED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to get a Qos of the specified kind.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_QOS_GET_EC                                (DDSC_LOG_BASE + 511)
#define DDSC_LOG_QOS_GET(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_QOS_GET_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief The topic listener kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TOPIC_LISTENER                                        1

/*ce
 * \brief The datareader listener kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAREADER_LISTENER                                   2

/*ce
 * \brief The datawriter listener kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAWRITER_LISTENER                                   3

/*ce
 * \brief The subscriber listener kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SUBSCRIBER_LISTENER                                   4

/*ce
 * \brief The publisher listener kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PUBLISHER_LISTENER                                    5

/*ce
 * \brief The participant listener kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANT_LISTENER                                  6

/*ce
 * \brief The participant-factory listener kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANTFACTORY_LISTENER                           7

/*ce
 * \brief Failed to create an entity due to inconsistent listener and
 *        status mask.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_LISTENER_INCONSISTENT_EC                  (DDSC_LOG_BASE + 512)
#define DDSC_LOG_LISTENER_INCONSISTENT(level_,kind_,mask_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_LISTENER_INCONSISTENT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "kind",(kind_),"mask",(mask_))

/*ce
 * \brief Failed to set the listener of the specified kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_LISTENER_SET_EC                           (DDSC_LOG_BASE + 513)
#define DDSC_LOG_LISTENER_SET(level_,kind_,mask_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_LISTENER_SET_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "kind",(kind_),"mask",(mask_))

/*ce
 * \brief Failed to get the listener of the specified kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_LISTENER_GET_EC                           (DDSC_LOG_BASE + 514)
#define DDSC_LOG_LISTENER_GET(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_LISTENER_GET_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "kind",(kind_))

/*ce
 * \brief Illegal combination of NULL listener and non-NONE status mask when
 *        setting a listener for an Entity
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_LISTENER_SET_ILLEGAL_NULL_EC              (DDSC_LOG_BASE + 515)
#define DDSC_LOG_SET_LISTENER_ILLEGAL_NULL(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_SET_LISTENER_ILLEGAL_NULL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)


/*******************************************************************************
 *                              ENTITY RELATED
 ******************************************************************************/

/*ce
 * \brief The topic entity kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TOPIC_ENTITY                                        1

/*ce
 * \brief The datawriter entity kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAWRITER_ENTITY                                   2

/*ce
 * \brief The datareader entity kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAREADER_ENTITY                                   3

/*ce
 * \brief The publisher entity kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PUBLISHER_ENTITY                                    4

/*ce
 * \brief The subscriber entity kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SUBSCRIBER_ENTITY                                   5

/*ce
 * \brief The participant entity kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PARTICIPANT_ENTITY                                  6

/*ce
 * \brief The publication entity kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PUBLICATION_ENTITY                                  7

/*ce
 * \brief The subscription entity kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_SUBSCRIPTION_ENTITY                                 8

/*ce
 * \brief Failed to enable an entity of the specified kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ENTITY_ENABLE_EC                          (DDSC_LOG_BASE + 600)
#define DDSC_LOG_ENTITY_ENABLE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_ENTITY_ENABLE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to an delete/finalize an entity of the specified kind because
 *        it is not empty.
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ENTITY_NOT_EMPTY_EC                       (DDSC_LOG_BASE + 601)
#define DDSC_LOG_ENTITY_NOT_EMPTY(level_,kind_,count_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_ENTITY_NOT_EMPTY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_),"count",(count_))

/*ce
 * \brief Failed to finalize an entity of the specified kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ENTITY_FINALIZE_EC                        (DDSC_LOG_BASE + 602)
#define DDSC_LOG_ENTITY_FINALIZE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_ENTITY_FINALIZE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"kind",(kind_))

/*ce
 * \brief Failed to initialize an entity of the specified kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ENTITY_INITIALIZE_EC                      (DDSC_LOG_BASE + 603)
#define DDSC_LOG_ENTITY_INITIALIZE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_ENTITY_INITIALIZE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"kind",(kind_))

/*ce
 * \brief An operation was attempted on an entity that is not enabled
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ENTITY_NOT_ENABLED_EC                     (DDSC_LOG_BASE + 604)
#define DDSC_LOG_ENTITY_NOT_ENABLED(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_ENTITY_NOT_ENABLED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Entities are in different factories
 *
 * \details
 *
 * A entity tried to use an entity created by a different factory.
 * For example, it is illegal to create a datawriter using a topic
 * from a different participant.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_ENTITY_DIFFERENT_FACTORY_EC               (DDSC_LOG_BASE + 605)
#define DDSC_LOG_ENTITY_DIFFERENT_FACTORY(level_,factory_kind_,entity_kind_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_ENTITY_DIFFERENT_FACTORY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "factory_kind",(factory_kind_),"entity_kind",(entity_kind_))

/*******************************************************************************
 *                              CDR RELATED
 ******************************************************************************/
/*ce
 * \brief The datawriter CDR kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAWRITER_CDR                                      1

/*ce
 * \brief The datareader CDR kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAREADER_CDR                                      2

/*ce
 * \brief Failed to allocate a pool of the specified kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_POOL_ALLOC_EC                         (DDSC_LOG_BASE + 700)
#define DDSC_LOG_CDR_POOL_ALLOC(level_,kind_,size_,count_) \
OSAPI_LOG_ENTRY_ADD_3INT((level_),DDSC_LOG_CDR_POOL_ALLOC_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "kind",(kind_),"size",(size_),"count",(count_))

/*ce
 * \brief Failed to set the CDR buffer for a packet
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_BUFFER_SET_EC                         (DDSC_LOG_BASE + 701)
#define DDSC_LOG_CDR_BUFFER_SET(level_,kind_,stream_,buf_,length_) \
OSAPI_LOG_ENTRY_CREATE((level_),DDSC_LOG_CDR_BUFFER_SET_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("kind",(kind_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("stream",(stream_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("buf",(buf_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("length",(length_),OEI_TRUE)

/*ce
 * \brief Failed to delete the CDR pool
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_POOL_DELETE_EC                        (DDSC_LOG_BASE + 702)
#define DDSC_LOG_CDR_POOL_DELETE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_CDR_POOL_DELETE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to serialize a parameter ID
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_SERIALIZE_PID_EC                      (DDSC_LOG_BASE + 703)
#define DDSC_LOG_CDR_SERIALIZE_PID(level_,kind_,pid_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_CDR_SERIALIZE_PID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_),"pid",(pid_))

/*ce
 * \brief Failed to serialize a parameter length
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_SERIALIZE_PID_LENGTH_EC               (DDSC_LOG_BASE + 704)
#define DDSC_LOG_CDR_SERIALIZE_PID_LENGTH(level_,kind_,length_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_CDR_SERIALIZE_PID_LENGTH_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "kind",(kind_),"length",(length_))

/*ce
 * \brief Failed to serialize a key-hash
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_SERIALIZE_KEYHASH_EC                  (DDSC_LOG_BASE + 705)
#define DDSC_LOG_CDR_SERIALIZE_KEYHASH(level_,kind_,length_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_CDR_SERIALIZE_KEYHASH_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "kind",(kind_),"length",(length_))

/*ce
 * \brief Failed to serialize payload data
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_SERIALIZE_DATA_EC                     (DDSC_LOG_BASE + 706)
#define DDSC_LOG_CDR_SERIALIZE_DATA(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_CDR_SERIALIZE_DATA_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Deserialized an invalid parameter length for a specific parameter ID
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DESERIALIZE_BAD_PID_LENGTH_EC             (DDSC_LOG_BASE + 707)
#define DDSC_LOG_DESERIALIZE_BAD_PID_LENGTH(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_DESERIALIZE_BAD_PID_LENGTH_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to deserialize the ID of an inline parameter
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_DESERIALIZE_PID_EC                    (DDSC_LOG_BASE + 708)
#define DDSC_LOG_CDR_DESERIALIZE_PID(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_CDR_DESERIALIZE_PID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to deserialize the length of an inline parameter
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_DESERIALIZE_PID_LENGTH_EC             (DDSC_LOG_BASE + 709)
#define DDSC_LOG_CDR_DESERIALIZE_PID_LENGTH(level_,kind_,pid_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_CDR_DESERIALIZE_PID_LENGTH_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "kind",(kind_),"pid",(pid_))

/*ce
 * \brief Failed to increment to the position of the next inline parameter
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_INCREMENT_POS_EC                      (DDSC_LOG_BASE + 710)
#define DDSC_LOG_CDR_INCREMENT_POS(level_,kind_,adjust_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_CDR_INCREMENT_POS_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "kind",(kind_),"adjust",(adjust_))

/*ce
 * \brief Failed to set the reception stream position
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_SET_POS_EC                            (DDSC_LOG_BASE + 711)
#define DDSC_LOG_CDR_SET_POS(level_,kind_,pos_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_CDR_SET_POS_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "kind",(kind_),"pos",(pos_))

/*ce
 * \brief Failed to deserialize the encapsulation header
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_DESERIALIZE_HEADER_EC                 (DDSC_LOG_BASE + 712)
#define DDSC_LOG_CDR_DESERIALIZE_HEADER(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_CDR_DESERIALIZE_HEADER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to deserialize CDR payload data
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_DESERIALIZE_DATA_EC                   (DDSC_LOG_BASE + 713)
#define DDSC_LOG_CDR_DESERIALIZE_DATA(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_CDR_DESERIALIZE_DATA_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"kind",(kind_))

/*ce
 * \brief Failed to initialize CDR sample
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_INITIALIZE_SAMPLE_EC                  (DDSC_LOG_BASE + 714)
#define DDSC_LOG_CDR_INITIALIZE_SAMPLE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_CDR_INITIALIZE_SAMPLE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"kind",(kind_))

/*ce
 * \brief Failed to finalize sample
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_FINALIZE_SAMPLE_EC                    (DDSC_LOG_BASE + 715)
#define DDSC_LOG_CDR_FINALIZE_SAMPLE(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_CDR_FINALIZE_SAMPLE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to serialize the status info parameter
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_SERIALIZE_STATUS_INFO_EC              (DDSC_LOG_BASE + 716)
#define DDSC_LOG_CDR_SERIALIZE_STATUS_INFO(level_,kind_,info_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_CDR_SERIALIZE_STATUS_INFO_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_),"status",(info_))

/*ce
 * \brief Failed to deserialize a key-hash
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_DESERIALIZE_KEYHASH_EC                (DDSC_LOG_BASE + 717)
#define DDSC_LOG_CDR_DESERIALIZE_KEYHASH(level_,kind_,length_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_CDR_DESERIALIZE_KEYHASH_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "kind",(kind_),"length",(length_))

/*ce
 * \brief Failed to deserialize CDR payload key
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_CDR_DESERIALIZE_KEY_EC                    (DDSC_LOG_BASE + 718)
#define DDSC_LOG_CDR_DESERIALIZE_KEY(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_CDR_DESERIALIZE_KEY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"kind",(kind_))


/*******************************************************************************
 *                              NETIO RELATED
 ******************************************************************************/
/*ce
 * \brief Failed to add a route to an anonymous participant discovery
 *        datawriter
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_ADD_ANON_TOPIC_ROUTE_EC             (DDSC_LOG_BASE + 800)
#define DDSC_LOG_NETIO_ADD_ANON_TOPIC_ROUTE(level_,topic_,oid_) \
OSAPI_LOG_ENTRY_ADD_1STRING_1INT((level_),DDSC_LOG_NETIO_ADD_ANON_TOPIC_ROUTE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "topic",(topic_),"object_id",(oid_))

/*ce
 * \brief Failed to add a route to a topic from a datawriter
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_ADD_TOPIC_ROUTE_EC                  (DDSC_LOG_BASE + 801)
#define DDSC_LOG_NETIO_ADD_TOPIC_ROUTE(level_,topic_,oid_) \
OSAPI_LOG_ENTRY_ADD_1STRING_1INT((level_),DDSC_LOG_NETIO_ADD_TOPIC_ROUTE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "topic",(topic_),"object_id",(oid_))

/*ce
 * \brief Failed to delete a route to a topic
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_DELETE_TOPIC_ROUTE_EC               (DDSC_LOG_BASE + 802)
#define DDSC_LOG_NETIO_DELETE_TOPIC_ROUTE(level_,topic_,oid_) \
OSAPI_LOG_ENTRY_ADD_1STRING_1INT((level_),DDSC_LOG_NETIO_DELETE_TOPIC_ROUTE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "topic",(topic_),"object_id",(oid_))

/*ce
 * \brief Failed to forward a topic
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_FORWARD_TOPIC_EC                    (DDSC_LOG_BASE + 803)
#define DDSC_LOG_NETIO_FORWARD_TOPIC(level_,topic_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_NETIO_FORWARD_TOPIC_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"topic",(topic_))


/*ce \brief Any NETIO interface kind, typically UDP
 *   \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_NETIO_KIND                                    1

/*ce \brief The intra interface kind
 *   \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_INTRA_NETIO_KIND                                    2

/*ce \brief The RTPS interface kind
 *   \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_RTPS_NETIO_KIND                                     3

/*ce \brief The DataReader interface kind
 *   \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAREADER_NETIO_KIND                               4

/*ce \brief The DataWriter interface kind
 *   \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DATAWRITER_NETIO_KIND                               5

/*ce
 * \brief Failed to bind two external interface of the specified kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_BIND_EXTERNAL_EC                    (DDSC_LOG_BASE + 804)
#define DDSC_LOG_NETIO_BIND_EXTERNAL(level_,from_,to_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_NETIO_BIND_EXTERNAL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"from",(from_),"to",(to_))

/*ce
 * \brief Failed to unbind two external interfaces of the specified kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_UNBIND_EXTERNAL_EC                  (DDSC_LOG_BASE + 805)
#define DDSC_LOG_NETIO_UNBIND_EXTERNAL(level_,from_,to_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_NETIO_UNBIND_EXTERNAL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"from",(from_),"to",(to_))

/*ce
 * \brief Failed to bind an interface to a peer interface
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_BIND_EC                             (DDSC_LOG_BASE + 806)
#define DDSC_LOG_NETIO_BIND(level_,src_,dst_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_NETIO_BIND_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"src",(src_),"dst",(dst_))

/*ce
 * \brief Failed to unbind an interface from a peer interface
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_UNBIND_EC                           (DDSC_LOG_BASE + 807)
#define DDSC_LOG_NETIO_UNBIND(level_,src_,dst_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_NETIO_UNBIND_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"src",(src_),"dst",(dst_))

/*ce
 * \brief Failed to add a route from an interface to a peer interface
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_ADD_ROUTE_EC                        (DDSC_LOG_BASE + 808)
#define DDSC_LOG_NETIO_ADD_ROUTE(level_,src_,dst_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_NETIO_ADD_ROUTE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"src",(src_),"dst",(dst_))

/*ce
 * \brief  Failed to delete a route from an interface to a peer interface
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_DELETE_ROUTE_EC                     (DDSC_LOG_BASE + 809)
#define DDSC_LOG_NETIO_DELETE_ROUTE(level_,src_,dst_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_NETIO_DELETE_ROUTE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"src",(src_),"dst",(dst_))

/*ce
 * \brief Failed to get an external interface for the specified interface kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_GET_EXTERNAL_INTF_EC                (DDSC_LOG_BASE + 810)
#define DDSC_LOG_NETIO_GET_EXTERNAL_INTF(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_NETIO_GET_EXTERNAL_INTF_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief A DataReader failed a bind due to no existing route
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_NO_ROUTE_EC                         (DDSC_LOG_BASE + 811)
#define DDSC_LOG_NETIO_NO_ROUTE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_NETIO_NO_ROUTE_EC,\
                        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Lookup a route to a destination failed
 *
 * \details
 *
 * A failure was encountered when trying to lookup a route to a destination,
 * this log message is preceded by a more specific message. Failure to lookup
 * a route does not mean the route does not exist, it means it failed to
 * determine if a route did exist.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_ROUTE_LOOKUP_FAILED_EC              (DDSC_LOG_BASE + 812)
#define DDSC_LOG_NETIO_ROUTE_LOOKUP_FAILED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_NETIO_ROUTE_LOOKUP_FAILED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to get the route table for an interface
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_GET_ROUTE_TABLE_FAILED_EC           (DDSC_LOG_BASE + 813)
#define DDSC_LOG_NETIO_GET_ROUTE_TABLE_FAILED(level_,name_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_NETIO_GET_ROUTE_TABLE_FAILED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"name",(name_))

/*ce
 * \brief Failure when sending on an interface
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_SEND_FAILED_EC                      (DDSC_LOG_BASE + 814)
#define DDSC_LOG_NETIO_SEND_FAILED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_NETIO_SEND_FAILED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to set an interface state
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_SET_STATE_EC                        (DDSC_LOG_BASE + 815)
#define DDSC_LOG_NETIO_SET_STATE(level_,kind_,state_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_NETIO_SET_STATE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "kind",(kind_),"state",(state_))

/*ce
 * \brief Datawriter did not find a peer
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_PEER_LOOKUP_EC                      (DDSC_LOG_BASE + 816)
#define DDSC_LOG_NETIO_PEER_LOOKUP(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_NETIO_PEER_LOOKUP_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Forced removal of sample downstream failed
 *
 * \details
 *
 * The datawriter failed to force a sample removal downstream
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_NETIO_FORCED_REMOVE_EC                    (DDSC_LOG_BASE + 817)
#define DDSC_LOG_NETIO_FORCED_REMOVE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_NETIO_FORCED_REMOVE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to initialize a packet
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PACKET_INIT_EC                            (DDSC_LOG_BASE + 818)
#define DDSC_LOG_PACKET_INIT(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_PACKET_INIT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to set the head of a packet
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PACKET_SET_HEAD_EC                        (DDSC_LOG_BASE + 819)
#define DDSC_LOG_PACKET_SET_HEAD(level_,kind_,adjust_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_PACKET_SET_HEAD_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_),"adjust",(adjust_))

/*ce
 * \brief Failed to set the tail of a packet
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_PACKET_SET_TAIL_EC                        (DDSC_LOG_BASE + 820)
#define DDSC_LOG_PACKET_SET_TAIL(level_,kind_,adjust_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_PACKET_SET_TAIL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_),"adjust",(adjust_))

/*******************************************************************************
 *                              DATAWRITER RELATED
 ******************************************************************************/
/*ce
 * \brief Failed to ACKNACK sample in the writer history
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DW_ACKNACK_FAILED_EC                      (DDSC_LOG_BASE + 900)
#define DDSC_LOG_DW_ACKNACK_FAILED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_DW_ACKNACK_FAILED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM )

/*ce
 * \brief Failed to commit a sample to the writer queue
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DW_COMMIT_EC                              (DDSC_LOG_BASE + 901)
#define DDSC_LOG_DW_COMMIT(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_DW_COMMIT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to create keyhash of instance handle
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DW_KEYHASH_CREATE_EC                      (DDSC_LOG_BASE + 902)
#define DDSC_LOG_DW_KEYHASH_CREATE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_DW_KEYHASH_CREATE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed a write due to an invalid key kind for the type being written
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DW_ILLEGAL_KEY_KIND_EC                    (DDSC_LOG_BASE + 903)
#define DDSC_LOG_DW_ILLEGAL_KEY_KIND(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_DW_ILLEGAL_KEY_KIND_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))


/*ce
 * \brief Failed to create a typed writer
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DW_CREATE_TYPED_WRITER_EC                 (DDSC_LOG_BASE + 904)
#define DDSC_LOG_DW_CREATE_TYPED_WRITER(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_DW_CREATE_TYPED_WRITER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to register the key of an instance
 *
 * \details A DataWriter failed to register the key of a new instance
 *          because DataWriterQos.resource_limits.max_instances was exceeded.
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DW_HISTORY_REGISTER_KEY_EC                (DDSC_LOG_BASE + 905)
#define DDSC_LOG_DW_HISTORY_REGISTER_KEY(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_DW_HISTORY_REGISTER_KEY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)


/*******************************************************************************
 *                              DATAREADER RELATED
 ******************************************************************************/
/*ce
 * \brief Failed to create a typed datareader
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DR_CREATE_TYPED_READER_EC                (DDSC_LOG_BASE + 1000)
#define DDSC_LOG_DR_CREATE_TYPED_READER(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_DR_CREATE_TYPED_READER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to copy a sample upon reception, read, or take
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DR_COPY_DATA_SAMPLE_EC                   (DDSC_LOG_BASE + 1001)
#define DDSC_LOG_DR_COPY_DATA_SAMPLE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_DR_COPY_DATA_SAMPLE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to commit a sample to be made available to be read or taken
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DR_COMMIT_SAMPLE_EC                      (DDSC_LOG_BASE + 1002)
#define DDSC_LOG_DR_COMMIT_SAMPLE(level_,sn_high_,sn_low_,rc_) \
OSAPI_LOG_ENTRY_ADD_3INT((level_),DDSC_LOG_DR_COMMIT_SAMPLE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "sn_high",(sn_high_),"sn_low",(sn_low_),"rc=%d",(rc_))

/*ce
 * \brief A datareader filter function failed
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DR_FILTER_ERROR_EC                       (DDSC_LOG_BASE + 1003)
#define DDSC_LOG_DR_FILTER_ERROR(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_DR_FILTER_ERROR_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to deserialize a key-hash parameter
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DR_DESERIALIZE_KEYHASH_EC                (DDSC_LOG_BASE + 1004)
#define DDSC_LOG_DR_DESERIALIZE_KEYHASH(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_DR_DESERIALIZE_KEYHASH_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to get a Reader History entry for a received sample
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DR_GET_ENTRY_FAILED_EC                   (DDSC_LOG_BASE + 1005)
#define DDSC_LOG_DR_GET_ENTRY_FAILED(level_,reason_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_DR_GET_ENTRY_FAILED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"reason",(reason_))

/*ce
 * \brief Failed to commit a receive sample to Reader History to be read or 
 *        taken
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DR_COMMIT_ENTRY_EC                       (DDSC_LOG_BASE + 1006)
#define DDSC_LOG_DR_COMMIT_ENTRY(level_,sn_high_,sn_low_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),DDSC_LOG_DR_COMMIT_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "sn_high",(sn_high_),"sn_low",(sn_low_))

/*ce
 * \brief A DataReader failed to unregister an instance 
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DR_UNREGISTER_KEY_EC                     (DDSC_LOG_BASE + 1007)
#define DDSC_LOG_DR_UNREGISTER_KEY(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_DR_UNREGISTER_KEY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief A DataReader failed to dispose an instance
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DR_DISPOSE_KEY_EC                        (DDSC_LOG_BASE + 1008)
#define DDSC_LOG_DR_DISPOSE_KEY(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_DR_DISPOSE_KEY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief A call to a reader/take function failed
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DR_READ_TAKE_FAILURE_EC                  (DDSC_LOG_BASE + 1009)
#define DDSC_LOG_DR_READ_TAKE_FAILURE(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_DR_READ_TAKE_FAILURE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"retcode",(dbrc_))

/*ce
 * \brief Failed to create keyhash of instance handle
 *
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DR_INSTANCE_TO_KEYHASH_EC                (DDSC_LOG_BASE + 1010)
#define DDSC_LOG_DR_INSTANCE_TO_KEYHASH(level_) \
OSAPI_LOG_ENTRY_ADD((level_),DDSC_LOG_DR_INSTANCE_TO_KEYHASH_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*******************************************************************************
 *                      TOPIC, TYPE & TYPE PLUGIN RELATED
 ******************************************************************************/
/*ce
 * \brief Two type names are incompatible
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_NAME_CMP_EC                         (DDSC_LOG_BASE + 1100)
#define DDSC_LOG_TYPE_NAME_CMP(level_,left_,right_) \
OSAPI_LOG_ENTRY_ADD_2STRING((level_),DDSC_LOG_TYPE_NAME_CMP_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "left",(left_),"right",(right_))

/*ce
 * \brief Two topic names are incompatible
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TOPIC_NAME_CMP_EC                        (DDSC_LOG_BASE + 1101)
#define DDSC_LOG_TOPIC_NAME_CMP(level_,left_,right_) \
OSAPI_LOG_ENTRY_ADD_2STRING((level_),DDSC_LOG_TOPIC_NAME_CMP_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "left",(left_),"right",(right_))

/*ce
 * \brief The get_serialized_sample_max_size function kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_FUNCTION_GET_SERIALIZED_SAMPLE_MAX_SIZE        1

/*ce
 * \brief The serialize_data function kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_FUNCTION_SERIALIZE_DATA                        2

/*ce
 * \brief The deserialize_data function kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_FUNCTION_DESERIALIZE_DATA                      3

/*ce
 * \brief The create_sample function kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_FUNCTION_CREATE_SAMPLE                         4

/*ce
 * \brief The copy_sample function kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_FUNCTION_COPY_SAMPLE                           5

/*ce
 * \brief The delete_sample function kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_FUNCTION_DELETE_SAMPLE                         6


/*ce
 * \brief The get_key_kind function kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_FUNCTION_GET_KEY_KIND                          7


/*ce
 * \brief The instance_to_keyhash function kind
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_FUNCTION_INSTANCE_TO_KEYHASH                   8

/*ce
 * \brief Invalid type plugin, The specified function pointer is NULL
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_FUNCTION_NULL_EC                    (DDSC_LOG_BASE + 1102)
#define DDSC_LOG_type_function_null(level_,kind_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),\
        DDSC_LOG_TYPE_FUNCTION_NULL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"kind",(kind_))

/*ce
 * \brief Failed to create a topic because the name exceeded the maximum
 *        length of 255 octets (excluding the terminating NUL)
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TOPIC_TOO_LONG_EC                        (DDSC_LOG_BASE + 1103)
#define DDSC_LOG_TOPIC_TOO_LONG(level_,length_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_TOPIC_TOO_LONG_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"length",(length_))

/*ce
 * \brief Failed to create a type because the name exceeded the maximum
 *        length of 255 octets (excluding the terminating NUL)
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_TOO_LONG_EC                         (DDSC_LOG_BASE + 1104)
#define DDSC_LOG_TYPE_TOO_LONG(level_,length_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),DDSC_LOG_TYPE_TOO_LONG_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"length",(length_))

/*ce
 * \brief A type-plugin for the given type could not be found
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_LOOKUP_TYPE_PLUGIN_EC                    (DDSC_LOG_BASE + 1105)
#define DDSC_LOG_LOOKUP_TYPE_PLUGIN(level_,name_) \
OSAPI_LOG_ENTRY_ADD_1POINTER((level_),DDSC_LOG_LOOKUP_TYPE_PLUGIN_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM, "type",(name_))

/*ce
 * \brief Two types have incompatible keys
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_TYPE_KEY_TYPE_EC                         (DDSC_LOG_BASE + 1106)
#define DDSC_LOG_TYPE_KEY_TYPE(level_,topic_,type_) \
OSAPI_LOG_ENTRY_ADD_2STRING((level_),DDSC_LOG_TYPE_KEY_TYPE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"topic",(topic_),"type",(type_))

/*******************************************************************************
 *                     DISCOVERY PLUGIN RELATED
 ******************************************************************************/
/*ce
 * \brief Discovery plugin failed its update after a local DomainParticipant 
 *        was enabled
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DISC_LOCAL_PARTICIPANT_ENABLED_EC        (DDSC_LOG_BASE + 1200)
#define DDSC_LOG_DISC_LOCAL_PARTICIPANT_ENABLED(level_,plugin_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_DISC_LOCAL_PARTICIPANT_ENABLED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"plugin",(plugin_))

/*ce
 * \brief Discovery plugin failed its update before a local DomainParticipant 
 *        was created
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DISC_BEFORE_LOCAL_PARTICIPANT_CREATED_EC (DDSC_LOG_BASE + 1201)
#define DDSC_LOG_DISC_BEFORE_LOCAL_PARTICIPANT_CREATED(level_,plugin_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_DISC_BEFORE_LOCAL_PARTICIPANT_CREATED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"plugin",(plugin_))

/*ce
 * \brief Discovery plugin failed its update after a local DomainParticipant 
 *        was created
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DISC_AFTER_LOCAL_PARTICIPANT_CREATED_EC  (DDSC_LOG_BASE + 1202)
#define DDSC_LOG_DISC_AFTER_LOCAL_PARTICIPANT_CREATED(level_,plugin_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_DISC_AFTER_LOCAL_PARTICIPANT_CREATED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"plugin",(plugin_))

/*ce
 * \brief Discovery plugin failed its update after a local DataReader 
 *        was enabled
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DISC_AFTER_LOCAL_DATAREADER_ENABLED_EC   (DDSC_LOG_BASE + 1203)
#define DDSC_LOG_DISC_AFTER_LOCAL_DATAREADER_ENABLED(level_,plugin_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_DISC_AFTER_LOCAL_DATAREADER_ENABLED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"plugin",(plugin_))

/*ce
 * \brief Discovery plugin failed its update after a local DataReader 
 *        was deleted
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DISC_AFTER_LOCAL_DATAREADER_DELETED_EC   (DDSC_LOG_BASE + 1204)
#define DDSC_LOG_DISC_AFTER_LOCAL_DATAREADER_DELETED(level_,plugin_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_DISC_AFTER_LOCAL_DATAREADER_DELETED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"plugin",(plugin_))

/*ce
 * \brief Discovery plugin failed its update after a local DataWriter 
 *        was enabled
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DISC_AFTER_LOCAL_DATAWRITER_ENABLED_EC   (DDSC_LOG_BASE + 1205)
#define DDSC_LOG_DISC_AFTER_LOCAL_DATAWRITER_ENABLED(level_,plugin_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_DISC_AFTER_LOCAL_DATAWRITER_ENABLED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"plugin",(plugin_))

/*ce
 * \brief Discovery plugin failed its update after a local DataWriter 
 *        was deleted
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DISC_AFTER_LOCAL_DATAWRITER_DELETED_EC   (DDSC_LOG_BASE + 1206)
#define DDSC_LOG_DISC_AFTER_LOCAL_DATAWRITER_DELETED(level_,plugin_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_DISC_AFTER_LOCAL_DATAWRITER_DELETED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"plugin",(plugin_))

/*ce
 * \brief Discovery plugin failed its update after a remote DomainParticipant's 
 *        liveliness expired
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DISC_REMOTE_PARTICIPANT_EXPIRED_EC       (DDSC_LOG_BASE + 1207)
#define DDSC_LOG_DISC_REMOTE_PARTICIPANT_EXPIRED(level_,plugin_) \
OSAPI_LOG_ENTRY_ADD_1STRING((level_),DDSC_LOG_DISC_REMOTE_PARTICIPANT_EXPIRED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"plugin",(plugin_))

/*ce
 * \brief Failed to add a peer with discovery plugin
 * \ingroup DDSCLogCodesClass
 */
#define DDSC_LOG_DISC_ADD_PEER_EC                         (DDSC_LOG_BASE + 1208)
#define DDSC_LOG_DISC_ADD_PEER(level_,plugin_,peer_) \
OSAPI_LOG_ENTRY_ADD_2STRING((level_),DDSC_LOG_DISC_ADD_PEER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"plugin",(plugin_),"peer",(peer_))

#endif

