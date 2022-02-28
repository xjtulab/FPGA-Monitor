/*
 * FILE: dds_c_discovery.h - DDS discovery data definitions
 *
 */
/*ce
 * \file
 * \brief DDS discovery data definitions
 */
/*e
  @ingroup DDSDiscoveryModule
*/
#ifndef dds_c_discovery_h
#define dds_c_discovery_h

#ifndef dds_c_dll_h
#include "dds_c/dds_c_dll.h"
#endif
#ifndef dds_c_infrastructure_h
#include "dds_c/dds_c_infrastructure.h"
#endif
#ifndef dds_c_domain_h
#include "dds_c/dds_c_domain.h"
#endif
#ifndef dds_c_type_h
#include "dds_c/dds_c_type.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#define DDS_BUILTIN_ENDPOINT_PARTICIPANT_ANNOUNCER    0x00000001 << 0
#define DDS_BUILTIN_ENDPOINT_PARTICIPANT_DETECTOR     0x00000001 << 1
#define DDS_BUILTIN_ENDPOINT_PUBLICATION_ANNOUNCER    0x00000001 << 2
#define DDS_BUILTIN_ENDPOINT_PUBLICATION_DETECTOR     0x00000001 << 3
#define DDS_BUILTIN_ENDPOINT_SUBSCRIPTION_ANNOUNCER   0x00000001 << 4
#define DDS_BUILTIN_ENDPOINT_SUBSCRIPTION_DETECTOR    0x00000001 << 5

#define DDSC_PARTICIPANT_ADDRESS_COUNT_MAX RTPS_PID_USERDATA_IPADDRESS_COUNT_MAX

/*ci
 * \brief Array index for the object_id in a BuiltinTopicKey_t
 */
#define DDS_BUILTIN_TOPIC_KEY_OBJECT_ID 3

/*ci
 * \brief Determine if an object id is a built-in topic or
 *        a user-defined topic
 *
 * \param[in] oid Object id to test
 *
 * \return DDS_BOOLEAN_FALSE if the test is false, DDS_BOOLEAN_TRUE otherwise
 */
DDSCDllExport DDS_Boolean
DDS_ObjectId_is_builtin(DDS_Long oid);

/*ci
 * \brief Determine if a DDS_BuiltinTopicKey_t is a built-in topic or
 *        a user-defined topic
 *
 * \param[in] key DDS_BuiltinTopicKey_t to test
 *
 * \return DDS_BOOLEAN_FALSE if the test is false, DDS_BOOLEAN_TRUE otherwise
 */
DDSCDllExport DDS_Boolean
DDS_BuiltinTopicKey_is_builtin(const struct DDS_BuiltinTopicKey_t *const key);

DDSCDllExport DDS_Boolean
DDS_ObjectId_is_compatible(DDS_UnsignedLong dr_id,DDS_UnsignedLong dw_id);

/*e \dref_ParticipantBuiltinTopicData
 */
struct DDSCPPDllExport DDS_ParticipantBuiltinTopicData
{
    /*e \dref_ParticipantBuiltinTopicData_key
     */
    struct DDS_BuiltinTopicKey_t key;

    /*e \dref_ParticipantBuiltinTopicData_participant_name
     */
    struct DDS_EntityNameQosPolicy participant_name;

    /*e \dref_ParticipantBuiltinTopicData_dds_builtin_endpoints
     */
    DDS_UnsignedLong dds_builtin_endpoints;

    /*e \dref_ParticipantBuiltinTopicData_rtps_protocol_version
     */
    DDS_ProtocolVersion_t rtps_protocol_version;

    /*e \dref_ParticipantBuiltinTopicData_rtps_vendor_id
     */
    struct DDS_VendorId_t rtps_vendor_id;

    /*e \dref_ParticipantBuiltinTopicData_default_unicast_locators
     */
    struct DDS_LocatorSeq default_unicast_locators;

    /*e \dref_ParticipantBuiltinTopicData_default_multicast_locators
     */
    struct DDS_LocatorSeq default_multicast_locators;

    /*e \dref_ParticipantBuiltinTopicData_metatraffic_unicast_locators
     */
    struct DDS_LocatorSeq metatraffic_unicast_locators;

    /*e \dref_ParticipantBuiltinTopicData_metatraffic_multicast_locators
     */
    struct DDS_LocatorSeq metatraffic_multicast_locators;

    /*e \dref_ParticipantBuiltinTopicData_liveliness_lease_duration
     */
    struct DDS_Duration_t liveliness_lease_duration;

    /*e \dref_ParticipantBuiltinTopicData_product_version
     */
    struct DDS_ProductVersion_t product_version;

    DDSC_CPP_QOS_METHODS(DDS_ParticipantBuiltinTopicData)
};

DDSC_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT_FULL(DDS_ParticipantBuiltinTopicData);

/*i \dref_DDS_ParticipantBuiltinTopicData_INITIALIZER
 */
#define DDS_ParticipantBuiltinTopicData_INITIALIZER { \
    DDS_BuiltinTopicKey_t_INITIALIZER, \
    DDS_ENTITY_NAME_QOS_POLICY_DEFAULT, \
    0, /* builtin endpoints */ \
    DDS_PROTOCOL_VERSION_DEFAULT, \
    DDS_VENDOR_ID_DEFAULT, \
    DDS_SEQUENCE_INITIALIZER, \
    DDS_SEQUENCE_INITIALIZER, \
    DDS_SEQUENCE_INITIALIZER, \
    DDS_SEQUENCE_INITIALIZER, \
    {100L,0L}, /* participant_liveliness_lease_duration */\
    DDS_PRODUCTVERSION_UNKNOWN   }

#define T struct DDS_ParticipantBuiltinTopicData
#define TSeq DDS_ParticipantBuiltinTopicDataSeq
#define REDA_SEQUENCE_USER_API
#include <reda/reda_sequence_decl.h>

#define DDS_ParticipantBuiltinTopicDataSeq_INITIALIZER \
DDS_SEQUENCE_INITIALIZER


/*e \dref_PublicationBuiltInTopicGroupDocs
 */

/*e \dref_PublicationBuiltinTopicData
 */
struct DDSCPPDllExport DDS_PublicationBuiltinTopicData
{
    /*e \dref_PublicationBuiltinTopicData_key
     */
    struct DDS_BuiltinTopicKey_t key;      

    /*e \dref_PublicationBuiltinTopicData_participant_key
     */
    struct DDS_BuiltinTopicKey_t participant_key;

    /*e \dref_PublicationBuiltinTopicData_topic_name
     */
    char *topic_name;

    /*e \dref_PublicationBuiltinTopicData_type_name
     */
    char *type_name;

    /*e \dref_PublicationBuiltinTopicData_deadline
     */
    struct DDS_DeadlineQosPolicy deadline;

    /*e \dref_PublicationBuiltinTopicData_ownership
     */
    struct DDS_OwnershipQosPolicy ownership;

    /*e \dref_PublicationBuiltinTopicData_ownership_strength
     */
    struct DDS_OwnershipStrengthQosPolicy ownership_strength;

    /*e \dref_PublicationBuiltinTopicData_reliability
     */
    struct DDS_ReliabilityQosPolicy reliability;

    /*e \dref_PublicationBuiltinTopicData_liveliness
     */
    struct DDS_LivelinessQosPolicy liveliness;

    /*e \dref_PublicationBuiltinTopicData_durability
     */
    struct DDS_DurabilityQosPolicy durability;

    /*e \dref_PublicationBuiltinTopicData_unicast_locator
     */
    struct DDS_LocatorSeq unicast_locator;

    DDSC_CPP_QOS_METHODS(DDS_PublicationBuiltinTopicData)
};

DDSC_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT_FULL(DDS_PublicationBuiltinTopicData);

/*i \dref_PublicationBuiltinTopicData_INITIALIZER
 */
#define DDS_PublicationBuiltinTopicData_INITIALIZER { \
    DDS_BuiltinTopicKey_t_INITIALIZER, \
    DDS_BuiltinTopicKey_t_INITIALIZER, \
    NULL,\
    NULL,\
    DDS_DEADLINE_QOS_POLICY_DEFAULT, \
    DDS_OWNERSHIP_QOS_POLICY_DEFAULT,\
    DDS_OWNERSHIP_STRENGTH_QOS_POLICY_DEFAULT, \
    DDS_RELIABILITY_QOS_POLICY_DEFAULT,\
    DDS_LIVELINESS_QOS_POLICY_DEFAULT, \
    DDS_DURABILITY_QOS_POLICY_DEFAULT, \
    DDS_SEQUENCE_INITIALIZER \
}

#define T struct DDS_PublicationBuiltinTopicData
#define TSeq DDS_PublicationBuiltinTopicDataSeq
#define REDA_SEQUENCE_USER_API
#include <reda/reda_sequence_decl.h>

#define DDS_PublicationBuiltinTopicDataSeq_INITIALIZER \
DDS_SEQUENCE_INITIALIZER

/*e \dref_SubscriptionBuiltInTopicGroupDocs
 */

/*e \dref_SubscriptionBuiltinTopicData
 */
struct DDSCPPDllExport DDS_SubscriptionBuiltinTopicData
{
    /*e \dref_SubscriptionBuiltinTopicData_key
     * Key GUID must be first
     */
    struct DDS_BuiltinTopicKey_t key;

    /*e \dref_SubscriptionBuiltinTopicData_participant_key
     */
    struct DDS_BuiltinTopicKey_t participant_key;

    /*e \dref_SubscriptionBuiltinTopicData_topic_name
     */
    char *topic_name;

    /*e \dref_SubscriptionBuiltinTopicData_type_name
     */
    char *type_name;

    /*e \dref_SubscriptionBuiltinTopicData_deadline
     */
    struct DDS_DeadlineQosPolicy deadline;

    /*e \dref_SubscriptionBuiltinTopicData_ownership
     */
    struct DDS_OwnershipQosPolicy ownership;

    /*e \dref_SubscriptionBuiltinTopicData_reliability
     */
    struct DDS_ReliabilityQosPolicy reliability;

    /*e \dref_SubscriptionBuiltinTopicData_liveliness
     */
    struct DDS_LivelinessQosPolicy liveliness;

    /*e \dref_SubscriptionBuiltinTopicData_durability
     */
    struct DDS_DurabilityQosPolicy durability;

    /*e \dref_SubscriptionBuiltinTopicData_unicast_locator
     */
    struct DDS_LocatorSeq unicast_locator;

    /*e \dref_SubscriptionBuiltinTopicData_multicast_locator
     */
    struct DDS_LocatorSeq multicast_locator;

    DDSC_CPP_QOS_METHODS(DDS_SubscriptionBuiltinTopicData)
};

DDSC_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT_FULL(DDS_SubscriptionBuiltinTopicData);

/*i \dref_DDS_SubscriptionBuiltinTopicData_INITIALIZER
 */
#define DDS_SubscriptionBuiltinTopicData_INITIALIZER { \
    DDS_BuiltinTopicKey_t_INITIALIZER, \
    DDS_BuiltinTopicKey_t_INITIALIZER, \
    NULL,\
    NULL,\
    DDS_DEADLINE_QOS_POLICY_DEFAULT, \
    DDS_OWNERSHIP_QOS_POLICY_DEFAULT ,\
    DDS_RELIABILITY_QOS_POLICY_DEFAULT,\
    DDS_LIVELINESS_QOS_POLICY_DEFAULT, \
    DDS_DURABILITY_QOS_POLICY_DEFAULT, \
    DDS_SEQUENCE_INITIALIZER,\
    DDS_SEQUENCE_INITIALIZER,\
}

#define T struct DDS_SubscriptionBuiltinTopicData
#define TSeq DDS_SubscriptionBuiltinTopicDataSeq
#define REDA_SEQUENCE_USER_API
#include <reda/reda_sequence_decl.h>

#define DDS_SubscriptionBuiltinTopicDataSeq_INITIALIZER \
DDS_SEQUENCE_INITIALIZER

struct NDDS_RemoteEntityImpl;
typedef struct NDDS_RemoteEntityImpl NDDS_RemoteEntity;
struct DDS_RemotePublicationImpl;
typedef struct DDS_RemotePublicationImpl DDS_RemotePublication;
typedef struct DDS_RemoteSubscriptionImpl DDS_RemoteSubscription;
typedef struct DDS_RemoteParticipantImpl DDS_RemoteParticipant;

/*ci
 * \brief Assert a remote participant into a participant
 *
 * \details
 * Assert a remote participant into the participant. This is typically
 * done as part of the discovery process where a discovery plugin has
 * discovered a remote participant via some means. It is legal to assert a
 * remote participant multiple times. If the remote participant does not
 * yet exist in the participant is_new is set to TRUE, otherwise if it does
 * exit is_new is set to FALSE. Note that asserting a remote participant
 * does not automatically enable it. Either \ref
 * NDDS_DomainParticipant_enable_remote_participant_name or \ref
 * NDDS_DomainParticipant_enable_remote_participant_guid must be called for
 * that. Matching of a remote participant's endpoints with local endpoints
 * does not occur until the remote participant is enabled.
 *
 * \param[in]    participant The participant to assert the remote participant in
 * \param[in]    data        Discovery data for the remote participant
 * \param[inout] is_new      TRUE is the participant already has seen this
 *                           participant, FALSE otherwise.
 *
 * \return DDS_RETCODE_OK on success,one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
NDDS_DomainParticipant_assert_remote_participant(
        DDS_DomainParticipant *const participant,
        struct DDS_ParticipantBuiltinTopicData *const data,
        DDS_Boolean *const is_new);

/*ci
 * \brief Refresh the liveliness for a remote participant
 *
 * \details
 * This function informs the participant that the remote participant with
 * a key is still alive. How this is determined is outside the scope of this
 * function. If a remote participant fails to refresh its liveliness it will
 * be reset/removed from the participant.
 *
 * \param[in] participant The participant to refresh the liveliness in
 * \param[in] key         The key of the remote participant that has refreshed
 *                        its liveliness.
 *
 * \return DDS_RETCODE_OK on success,one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
NDDS_DomainParticipant_refresh_remote_participant_liveliness(
        DDS_DomainParticipant * const participant,
        const struct DDS_BuiltinTopicKey_t *const key);

/*ci
 * \brief Reset a remote participant from a participant
 *
 * \details
 * This function resets a remote participant and all its endpoints in the
 * participant. When the remote endpoints are reset they are also unmatched
 * from local endpoints. However, the remote participants and remote endpoints
 * are not removed from the participant. This feature is typically used in
 * static discovery where remote participants and endponts are statically
 * asserted. After they have been reset they can be re-enabled with one the
 * remote participant enable functions
 * \ref NDDS_DomainParticipant_enable_remote_participant_guid or
 * \ref NDDS_DomainParticipant_enable_remote_participant_name
 *
 * \param[in] participant The participant to remove the remote participant from
 * \param[in] key         The key of the remote participant to remove
 *
 * \return DDS_RETCODE_OK on success,one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
NDDS_DomainParticipant_reset_remote_participant(
        DDS_DomainParticipant *const participant,
        const struct DDS_BuiltinTopicKey_t *const key);

#ifndef OEI_CERT
/*ci
 * \brief Remove a remote participant from a participant
 *
 * \details
 * This function removes a remote participant and all its endpoints from the
 * participant. When the remote endpoints are removed they are also unmatched
 * from local endpoints.
 *
 * \param[in] participant The participant to remove the remote participant from
 * \param[in] key         The key of the remote participant to remove
 *
 * \return DDS_RETCODE_OK on success,one of the standard error codes on failure
 */
SHOULD_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
NDDS_DomainParticipant_remove_remote_participant(
        DDS_DomainParticipant *const participant,
        const DDS_BuiltinTopicKey_t *const key);
#endif /* !OEI_CERT */

/*ci
 * \brief Enable a remote participant by name
 *
 * \details
 * When a remote participant is asserted it is initially in a disabled state.
 * Any endpoint asserted as part of the remote participant is also disabled
 * and no matching occur. This function enables a remote participant which
 * causes matching with local entities. In addition the liveliness timer
 * is started and the remote participant must maintain its liveliness to
 * avoid being reset/removed. This function is called when a participant has
 * been asserted statically and is only known by name. On successful
 * return the remote participant has been updated with a GUID (taken from the
 * data input argument) and all its remote endpoints have been matched with
 * local endpoints.
 *
 * \param[in] participant The participant to enable the remote participant in
 * \param[in] data        The discovery data to enable the remote participant
 *                        with
 *
 * \return DDS_RETCODE_OK on success,one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
NDDS_DomainParticipant_enable_remote_participant_name(
        DDS_DomainParticipant * const participant,
        const struct DDS_ParticipantBuiltinTopicData *const data);

/*ci
 * \brief Enable a remote participant by GUID
 *
 * \details
 * When a remote participant is asserted it is initially in a disabled state.
 * Any endpoint asserted as part of the remote participant is also disabled
 * and no matching occur. This function enables a remote participant which
 * causes matching with local entities. In addition the liveliness timer
 * is started and the remote participant must maintain its liveliness to
 * avoid being reset/removed. This function is called when participant has
 * been detected based on discovery data with a valid GUID. On successful
 * return the remote participant is enabled and all its remote endpoints have
 * been matched with local endpoints.
 *
 * \param[in] participant The participant to enable the remote participant in
 * \param[in] data        The discovery data to enable the remote participant
 *                        with
 *
 * \return DDS_RETCODE_OK on success,one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
NDDS_DomainParticipant_enable_remote_participant_guid(
         DDS_DomainParticipant * const participant,
         const struct DDS_ParticipantBuiltinTopicData *const data);

/*ci
 * \brief Assert a remote publication into a participant
 *
 * \details
 * This function adds a remote publication as an endpoint in a remote
 * participant. Either the name or the GUID of the participant must be
 * specified, but not both. The name is used for static discovery
 * when the GUID of the participant is not known, while the participant
 * key in the data input is used for dynamic discovery.
 *
 * If the remote participant is already enabled the remote publication is
 * also enabled automatically. Otherwise the remote publication is created
 * in a disabled state and enabled when the remote participant is enabled.
 *
 * \param[in] participant The participant to assert the remote publication in
 * \param[in] participant_name The name of the remote publication's parent
 * \param[in] data        Discovery data for the remote publication
 * \param[in] key_kind    The type of key for the topic published by the remote
 *                        publication
 *
 * \return DDS_RETCODE_OK on success,one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
NDDS_DomainParticipant_assert_remote_publication(
        DDS_DomainParticipant *const participant,
        const char *const participant_name,
        const struct DDS_PublicationBuiltinTopicData *const data,
       NDDS_TypePluginKeyKind key_kind);

#ifndef OEI_CERT
/*ci
 * \brief Remove a remote publication from a participant
 *
 * \details
 * This function removes a remote publication as an endpoint from a remote
 * participant. It is unmatched from local endpoints before removal.
 *
 * \param[in] participant The participant to remove the remote publication from
 * \param[in] key         The key for the remote publication that is removed
 *
 * \return DDS_RETCODE_OK on success,one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
NDDS_DomainParticipant_remove_remote_publication(
        DDS_DomainParticipant *const participant,
        const DDS_BuiltinTopicKey_t *const key);
#endif /* !OEI_CERT */

/*ci
 * \brief Assert a remote subscription into a participant
 *
 * \details
 * This function adds a remote subscription as an endpoint in a remote
 * participant. Either the name or the GUID of the participant must be
 * specified, but not both. The name is typically used for static discovery
 * when the GUID of the participant is not known, while the participant
 * key in the data input is used for dynamic discovery.
 *
 * If the remote participant is already enabled the remote subscription is
 * also enabled automatically. Otherwise the remote subscription is created
 * in a disabled state and enabled when the remote participant is enabled.
 *
 * \param[in] participant The participant to assert the remote publication in
 * \param[in] participant_name The name of the remote subscription's parent
 * \param[in] data        Discovery data for the remote subscription
 * \param[in] key_kind    The type of key for the topic subscribed to by the
 *                        remote subscription
 *
 * \return DDS_RETCODE_OK on success,one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
NDDS_DomainParticipant_assert_remote_subscription(
        DDS_DomainParticipant* const participant,
        const char *const participant_name,
        const struct DDS_SubscriptionBuiltinTopicData *const data,
        NDDS_TypePluginKeyKind key_kind);

#ifndef OEI_CERT
/*ci
 * \brief Remove a remote subscription from a participant
 *
 * \details
 * This function removes a remote subscription as an endpoint from a remote
 * participant. It is unmatched from local endpoints before removal.
 *
 * \param[in] participant The participant to remove the remote subscription from
 * \param[in] key         The key for the remote subscription that is removed
 *
 * \return DDS_RETCODE_OK on success,one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
NDDS_DomainParticipant_remove_remote_subscription(
        DDS_DomainParticipant* const participant,
        const DDS_BuiltinTopicKey_t* const key);
#endif /* !OEI_CERT */

#ifndef OEI_CERT

/*ci
 * \brief Remove a remote DDS DataWriter as a peer for a local DDS datareader
 *
 * \param[in] datareader The local datareader
 * \param[in] dp_key     The peer's participant key
 * \param[in] entity_id  The peer's entity id (The prefix is the same as dp_key)
 *
 * \return DDS_RETCODE_OK on success, one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_remove_peer(DDS_DataReader *const datareader,
                           const DDS_BuiltinTopicKey_t *const dp_key,
                           OEI_INT32 entity_id);

/*ci
 * \brief Remove a remote DDS DataReader as a peer for a local DDS datawriter
 *
 * \param[in] datawriter The local datawriter
 * \param[in] dp_key     The peer's participant key
 * \param[in] entity_id  The peer's entity id (The prefix is the same as dp_key)
 *
 * \return DDS_RETCODE_OK on success, one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
DDS_DataWriter_remove_peer(DDS_DataWriter *const datawriter,
                           const DDS_BuiltinTopicKey_t *const dp_key,
                           OEI_INT32 entity_id);

/*ci
 * \brief Remove all remote DDS DataWriters with the entity_id as a peer
 *        from all discovered participants
 *
 * \param[in] datareader The local datareader
 * \param[in] entity_id  The peer's entity id (The prefix is the same as dp_key)
 *
 * \return DDS_RETCODE_OK on success, one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_remove_all_peers(DDS_DataReader *const datareader,
                                OEI_INT32 entity_id);

/*ci
 * \brief Remove all remote DDS DataReaders with the entity_id as a peer
 *        from all discovered participants
 *
 * \param[in] datawriter The local datawriter
 * \param[in] entity_id  The peer's entity id (The prefix is the same as dp_key)
 *
 * \return DDS_RETCODE_OK on success, one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
DDS_DataWriter_remove_all_peers(DDS_DataWriter *const datawriter,
                                OEI_INT32 entity_id);

/*ci
 * \brief Add a remote DDS DataReader with the entity_id as a peer to a local
 *        DDS DataWriter
 *
 * \param[in] datawriter The local datawriter
 * \param[in] dp_key     The peer's participant key
 * \param[in] dr_qos     The peer's Qos policy
 * \param[in] entity_id  The peer's entity id (The prefix is the same as dp_key)
 *
 * \return DDS_RETCODE_OK on success, one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
DDS_DataWriter_add_peer(DDS_DataWriter *const datawriter,
                        const DDS_BuiltinTopicKey_t *const dp_key,
                        const struct DDS_DataReaderQos *const dr_qos,
                        OEI_INT32 entity_id);

/*ci
 * \brief Add a remote DDS DataWriter with the entity_id as a peer to a local
 *        DDS Datareader
 *
 * \param[in] datareader The local datareader
 * \param[in] dp_key     The peer's participant key
 * \param[in] dw_qos     The peer's Qos policy
 * \param[in] entity_id  The peer's entity id (The prefix is the same as dp_key)
 *
 * \return DDS_RETCODE_OK on success, one of the standard error codes on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_add_peer(DDS_DataReader *const datareader,
                        const DDS_BuiltinTopicKey_t *const dp_key,
                        const struct DDS_DataWriterQos *const dw_qos,
                        OEI_INT32 entity_id);

#endif

#ifdef __cplusplus
}                               /* extern "C" */
#endif


#endif /* dds_c_discovery_h */
