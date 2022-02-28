/*
 * FILE: dds_c_subscription.h - DDS subscription module
 *
 */
/*ce
 * \file
 * \brief DDS subscription module
 */
/*ce
  @addtogroup DDSSubscriptionModule
  @ingroup DDSCModule
  @brief Defines the \dds subscription package.
*/
#ifndef dds_c_subscription_h
#define dds_c_subscription_h

#include "dds_c_config.h"
#include "dds_c_sequence.h"

#ifndef dds_c_type_h
#include "dds_c/dds_c_type.h"
#endif

#ifndef dds_c_topic_h
#include "dds_c/dds_c_topic.h"
#endif

#ifndef dds_c_dll_h
#include "dds_c/dds_c_dll.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*ci
 * \brief Default name for the automatically registered DataReader NETIO
 *        interface.
 */
NETIODllVariable extern
const char* const DDS_DEFAULT_DATAREADER_NETIO_NAME;

/* ================================================================= */
/*                         Typedef for DataReader                    */
/* ================================================================= */

/*ce \dref_DataReader
 */
typedef struct DDS_DataReaderImpl DDS_DataReader;


/* ================================================================= */
/*                         Typedef for Subscriber                    */
/* ================================================================= */

/*ce \dref_Subscriber
 */
typedef struct DDS_SubscriberImpl DDS_Subscriber;

/* ================================================================= */
/*                            Status                                 */
/* ================================================================= */

/* -------------------------------------- */
/*    Requested Deadline Missed Status    */
/* -------------------------------------- */

/*ce \dref_RequestedDeadlineMissedStatus
 */
struct DDSCPPDllExport DDS_RequestedDeadlineMissedStatus
{
    /*ce \dref_RequestedDeadlineMissedStatus_total_count
     */
    DDS_Long total_count;

    /*ce \dref_RequestedDeadlineMissedStatus_total_count_change
     */
    DDS_Long total_count_change;

    /*ce \dref_RequestedDeadlineMissedStatus_last_instance_handle
     */
    DDS_InstanceHandle_t last_instance_handle;

    DDSC_CPP_STATUS_METHODS(DDS_RequestedDeadlineMissedStatus)
};

/*ce \dref_RequestedDeadlineMissedStatus_INITIALIZER 
  */
#define DDS_RequestedDeadlineMissedStatus_INITIALIZER \
{ 0L, 0L, DDS_HANDLE_NIL_NATIVE }


/*ci
 * \brief Reset the changed counters in DDS_RequestedDeadlineMissedStatus
 *
 * \param[in] s Structure to clear
 */
DDSCDllExport void
DDS_RequestedDeadlineMissedStatus_reset(struct DDS_RequestedDeadlineMissedStatus *s);

/* ------------------------------- */
/*    Liveliness Changed Status    */
/* ------------------------------- */

/*ce \dref_LivelinessChangedStatus
 */
struct DDSCPPDllExport DDS_LivelinessChangedStatus
{

    /*ce \dref_LivelinessChangedStatus_alive_count
     */
    DDS_Long alive_count;

    /*ce \dref_LivelinessChangedStatus_not_alive_count
     */
    DDS_Long not_alive_count;

    /*ce \dref_LivelinessChangedStatus_alive_count_change
     */
    DDS_Long alive_count_change;

    /*ce \dref_LivelinessChangedStatus_not_alive_count_change
     */
    DDS_Long not_alive_count_change;

    /*ce \dref_LivelinessChangedStatus_last_publication_handle
     */
    DDS_InstanceHandle_t last_publication_handle;

    DDSC_CPP_STATUS_METHODS(DDS_LivelinessChangedStatus)
};

/*ce \dref_LivelinessChangedStatus_INITIALIZER
 */
#define DDS_LivelinessChangedStatus_INITIALIZER { 0L, 0L, 0L, 0L, \
    DDS_HANDLE_NIL_NATIVE }

/*ci
 * \brief Reset the changed counters in DDS_LivelinessChangedStatus
 *
 * \param[in] s Structure to clear
 */
DDSCDllExport void
DDS_LivelinessChangedStatus_reset(struct DDS_LivelinessChangedStatus *s);

/* --------------------------------------- */
/*    Requested Incompatible QoS Status    */
/* --------------------------------------- */

/*ce \dref_RequestedIncompatibleQosStatus
 */
struct DDSCPPDllExport DDS_RequestedIncompatibleQosStatus
{
    /*ce \dref_RequestedIncompatibleQosStatus_total_count
     */
    DDS_Long total_count;

    /*ce \dref_RequestedIncompatibleQosStatus_total_count_change
     */
    DDS_Long total_count_change;

    /*ce \dref_RequestedIncompatibleQosStatus_last_policy_id
     */
    DDS_QosPolicyId_t last_policy_id;

    /*ce \dref_RequestedIncompatibleQosStatus_policies
     */
    struct DDS_QosPolicyCountSeq policies;

    DDSC_CPP_STATUS_METHODS(DDS_RequestedIncompatibleQosStatus)
};

/*ce \dref_RequestedIncompatibleQosStatus_INITIALIZER
 */
#define DDS_RequestedIncompatibleQosStatus_INITIALIZER \
        { 0L, 0L, DDS_INVALID_QOS_POLICY_ID, DDS_SEQUENCE_INITIALIZER }

/*ci
 * \brief Reset the changed counters in DDS_RequestedIncompatibleQosStatus
 *
 * \param[in] s Structure to clear
 */
DDSCDllExport void
DDS_RequestedIncompatibleQosStatus_reset(struct DDS_RequestedIncompatibleQosStatus *s);

/* ----------------------------------- */
/*  Sample Rejected Status Kind enum   */
/* ----------------------------------- */

/*ce \dref_SampleRejectedStatusKind
 */
typedef enum
{
    /*ce \dref_SampleRejectedStatusKind_NOT_REJECTED
     */
    DDS_NOT_REJECTED,

    /*ce \dref_SampleRejectedStatusKind_REJECTED_BY_INSTANCES_LIMIT
     */
    DDS_REJECTED_BY_INSTANCES_LIMIT,

    /*ce \dref_SampleRejectedStatusKind_REJECTED_BY_SAMPLES_LIMIT
     */
    DDS_REJECTED_BY_SAMPLES_LIMIT,

    /*ce \dref_SampleRejectedStatusKind_REJECTED_BY_SAMPLES_PER_INSTANCE_LIMIT
     */
    DDS_REJECTED_BY_SAMPLES_PER_INSTANCE_LIMIT,

    /*ce \dref_SampleRejectedStatusKind_REJECTED_BY_REMOTE_WRITERS_LIMIT
     */
    DDS_REJECTED_BY_REMOTE_WRITERS_LIMIT,

    /*ce \dref_SampleRejectedStatusKind_REJECTED_BY_SAMPLES_PER_REMOTE_WRITER_LIMIT
     */
    DDS_REJECTED_BY_SAMPLES_PER_REMOTE_WRITER_LIMIT
} DDS_SampleRejectedStatusKind;

/*i deprecated */
#define DDS_REJECTED_BY_INSTANCE_LIMIT DDS_REJECTED_BY_INSTANCES_LIMIT

/* --------------------------------- */
/*  Sample Rejected Status struct    */
/* --------------------------------- */

/*ce \dref_SampleRejectedStatus
 */
struct DDSCPPDllExport DDS_SampleRejectedStatus
{

    /*ce \dref_SampleRejectedStatus_total_count
     */
    DDS_Long total_count;

    /*ce \dref_SampleRejectedStatus_total_count_change
     */
    DDS_Long total_count_change;

    /*ce \dref_SampleRejectedStatus_last_reason
     */
    DDS_SampleRejectedStatusKind last_reason;

    /*ce \dref_SampleRejectedStatus_last_instance_handle
     */
    DDS_InstanceHandle_t last_instance_handle;

    DDSC_CPP_STATUS_METHODS(DDS_SampleRejectedStatus)
};

/*ce \dref_SampleRejectedStatus_INITIALIZER
 */
#define DDS_SampleRejectedStatus_INITIALIZER \
        { 0L, 0L, DDS_NOT_REJECTED,DDS_HANDLE_NIL_NATIVE }

/*ci
 * \brief Reset the changed counters in DDS_SampleRejectedStatus
 *
 * \param[in] s Structure to clear
 */
DDSCDllExport void
DDS_SampleRejectedStatus_reset(struct DDS_SampleRejectedStatus *s);

/* ----------------------------------------- */
/*  DataReaderInstanceReplaced Status struct */
/* ----------------------------------------- */

/*ce \dref_DataReaderInstanceReplacedStatus
 */
struct DDSCPPDllExport DDS_DataReaderInstanceReplacedStatus
{
    /*ce \dref_DataReaderInstanceReplacedStatus_total_count
     */
    DDS_Long total_count;

    /*ce \dref_DataReaderInstanceReplacedStatus_total_count_change
     */
    DDS_Long total_count_change;

    /*ce \dref_DataReaderInstanceReplacedStatus_last_instance_handle
     */
    DDS_InstanceHandle_t last_instance_handle;

    /*ce \dref_DataReaderInstanceReplacedStatus_last_replacement_instance
     */
    DDS_InstanceHandle_t last_replacement_instance;

    /*ce \dref_DataReaderInstanceReplacedStatus_publication_handle
     */
    DDS_InstanceHandle_t publication_handle;

    /*ce \dref_DataReaderInstanceReplacedStatus_lost_samples
     */
    DDS_Long lost_samples;

    DDSC_CPP_STATUS_METHODS(DDS_DataReaderInstanceReplacedStatus)
};

/*ce \dref_DataReaderInstanceReplacedStatus_INITIALIZER
 */
#define DDS_DataReaderInstanceReplacedStatus_INITIALIZER \
    { 0L, 0L, DDS_HANDLE_NIL_NATIVE, \
        DDS_HANDLE_NIL_NATIVE, DDS_HANDLE_NIL_NATIVE, 0L }

/*ci
 * \brief Reset the changed counters in DDS_DataReaderInstanceReplacedStatus
 *
 * \param[in] s Structure to clear
 */
DDSCDllExport void
DDS_DataReaderInstanceReplacedStatus_reset(struct DDS_DataReaderInstanceReplacedStatus *s);

/* --------------------------------- */
/*  Subscription Match Status struct */
/* --------------------------------- */

/*ce \dref_SubscriptionMatchedStatus
 */
struct DDSCPPDllExport DDS_SubscriptionMatchedStatus
{
    /*ce \dref_SubscriptionMatchedStatus_total_count
     */
    DDS_Long total_count;

    /*ce \dref_SubscriptionMatchedStatus_total_count_change
     */
    DDS_Long total_count_change;

    /*ce \dref_SubscriptionMatchedStatus_current_count
     */
    DDS_Long current_count;

    /*ce \dref_SubscriptionMatchedStatus_current_count_change
     */
    DDS_Long current_count_change;

    /*ce \dref_SubscriptionMatchedStatus_last_publication_handle
     */
    DDS_InstanceHandle_t last_publication_handle;

    DDSC_CPP_STATUS_METHODS(DDS_SubscriptionMatchedStatus)
};

/*ce \dref_SubscriptionMatchedStatus_INITIALIZER
 */
#define DDS_SubscriptionMatchedStatus_INITIALIZER \
        { 0L, 0L, 0L, 0L, DDS_HANDLE_NIL_NATIVE}

/*ci
 * \brief Reset the changed counters in DDS_SubscriptionMatchedStatus
 *
 * \param[in] s Structure to clear
 */
DDSCDllExport void
DDS_SubscriptionMatchedStatus_reset(struct DDS_SubscriptionMatchedStatus *s);

/*ci
 * \brief Initialize a DDS_RequestedDeadlineMissedStatus structure
 *
 * \param[in] self DDS_RequestedDeadlineMissedStatus to initialize.
 *
 * \return DDS_RETCODE_OK on success, one of the standard error codes on
 *         failure
 */
DDSCDllExport DDS_ReturnCode_t
DDS_RequestedDeadlineMissedStatus_initialize(
                            struct DDS_RequestedDeadlineMissedStatus *self);

/*ci
 * \brief Initialize a DDS_RequestedIncompatibleQosStatus structure
 *
 * \param[in] self DDS_RequestedIncompatibleQosStatus to initialize
 *
 * \return DDS_RETCODE_OK on success, one of the standard error codes on
 *         failure
 */
DDSCDllExport DDS_ReturnCode_t
DDS_RequestedIncompatibleQosStatus_initialize(
                            struct DDS_RequestedIncompatibleQosStatus *self);

struct DDS_SampleLostStatus;

/*ci
 * \brief Initialize a DDS_SampleLostStatus structure
 *
 * \param[in] self DDS_SampleLostStatus to initialize
 *
 * \return DDS_RETCODE_OK on success, one of the standard error codes on
 *         failure
 */
DDSCDllExport DDS_ReturnCode_t
DDS_SampleLostStatus_initialize(struct DDS_SampleLostStatus *self);

/*ci
 * \brief Initialize a DDS_SampleRejectedStatus structure
 *
 * \param[in] self DDS_SampleRejectedStatus to initialize
 *
 * \return DDS_RETCODE_OK on success, one of the standard error codes on
 *         failure
 */
DDSCDllExport DDS_ReturnCode_t
DDS_SampleRejectedStatus_initialize(
            struct DDS_SampleRejectedStatus *self);

/*ci
 * \brief Initialize a DDS_SubscriptionMatchedStatus structure
 *
 * \param[in] self DDS_SubscriptionMatchedStatus to initialize
 *
 * \return DDS_RETCODE_OK on success, one of the standard error codes on
 *         failure
 */
DDSCDllExport DDS_ReturnCode_t
DDS_SubscriptionMatchedStatus_initialize(
            struct DDS_SubscriptionMatchedStatus *self);

/*ci
 * \brief Initialize a DDS_LivelinessChangedStatus structure
 *
 * \param[in] self DDS_LivelinessChangedStatus to initialize
 *
 * \return DDS_RETCODE_OK on success, one of the standard error codes on
 *         failure
 */
DDSCDllExport DDS_ReturnCode_t
DDS_LivelinessChangedStatus_initialize(
            struct DDS_LivelinessChangedStatus *self);

/*ci
 * \brief Initialize a DDS_DataReaderInstanceReplacedStatus structure
 *
 * \param[in] self DDS_DataReaderInstanceReplacedStatus to initialize
 *
 * \return DDS_RETCODE_OK on success, one of the standard error codes on
 *         failure
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReaderInstanceReplacedStatus_initialize(
            struct DDS_DataReaderInstanceReplacedStatus *self);

/* ================================================================= */
/*                      Sample States                                */
/* ================================================================= */

/* ---------------------------- */
/*    Sample State Kind enum    */
/* ---------------------------- */

/*ce \dref_SampleStateKind
 */
typedef enum
{
    /*ce \dref_SampleStateKind_READ_SAMPLE_STATE
     */
    DDS_READ_SAMPLE_STATE = 0x0001 << 0,

    /*ce \dref_SampleStateKind_NOT_READ_SAMPLE_STATE
     */
    DDS_NOT_READ_SAMPLE_STATE = 0x0001 << 1
} DDS_SampleStateKind;

/* ---------------------------- */
/* Sample State Mask            */
/* ---------------------------- */

/*ce \dref_SampleStateMask
 */
typedef DDS_UnsignedLong DDS_SampleStateMask;

/*ce \dref_ANY_SAMPLE_STATE
 */
extern DDSCDllVariable const DDS_SampleStateMask DDS_ANY_SAMPLE_STATE;

/* ================================================================= */
/*                           View States                             */
/* ================================================================= */

/* ---------------------------- */
/*    View State Kind enum      */
/* ---------------------------- */

/*ce \dref_ViewStateKind
 */
typedef enum
{
    /*ce \dref_ViewStateKind_NEW_VIEW_STATE
     */
    DDS_NEW_VIEW_STATE = 0x0001 << 0,

    /*ce \dref_ViewStateKind_NOT_NEW_VIEW_STATE
     */
    DDS_NOT_NEW_VIEW_STATE = 0x0001 << 1
} DDS_ViewStateKind;

/* ---------------------------- */
/* View State Mask              */
/* ---------------------------- */

/*ce \dref_ViewStateMask
 */
 typedef DDS_UnsignedLong DDS_ViewStateMask;

/*ce \dref_ANY_VIEW_STATE
 */
 extern DDSCDllVariable const DDS_ViewStateMask DDS_ANY_VIEW_STATE;

/* ================================================================= */
/*                           Instance States                         */
/* ================================================================= */

/* ---------------------------- */
/*    Instance State Kind enum  */
/* ---------------------------- */

/*ce \dref_InstanceStateKind
 */
 typedef enum
 {
     /*ce \dref_InstanceStateKind_ALIVE_INSTANCE_STATE
      */
     DDS_ALIVE_INSTANCE_STATE = 0x0001 << 0,

     /*ce \dref_InstanceStateKind_NOT_ALIVE_DISPOSED_INSTANCE_STATE
      */
     DDS_NOT_ALIVE_DISPOSED_INSTANCE_STATE = 0x0001 << 1,

     /*ce \dref_InstanceStateKind_NOT_ALIVE_NO_WRITERS_INSTANCE_STATE
      */
     DDS_NOT_ALIVE_NO_WRITERS_INSTANCE_STATE = 0x0001 << 2
 } DDS_InstanceStateKind;

/* ---------------------------- */
/* Instance State Mask          */
/* ---------------------------- */

/*ce \dref_InstanceStateMask
 */
typedef DDS_UnsignedLong DDS_InstanceStateMask;

/*ce \dref_ANY_INSTANCE_STATE
 */
extern DDSCDllVariable const DDS_InstanceStateMask DDS_ANY_INSTANCE_STATE;

/*ce \dref_NOT_ALIVE_INSTANCE_STATE
 */
extern DDSCDllVariable const DDS_InstanceStateMask DDS_NOT_ALIVE_INSTANCE_STATE;


/* ================================================================= */
/*                           Sample Info                             */
/* ================================================================= */

/* --------------------------- */
/*    Sample Info struct       */
/* --------------------------- */

/*ce \dref_SampleInfo
 */
struct DDS_SampleInfo
{
    /*ce \dref_SampleInfo_sample_state
     */
    DDS_SampleStateKind sample_state;

    /*ce \dref_SampleInfo_view_state
     */
    DDS_ViewStateKind view_state;

    /*ce \dref_SampleInfo_instance_state
     */
    DDS_InstanceStateKind instance_state;

    /*ce \dref_SampleInfo_source_timestamp
     */
    struct DDS_Time_t source_timestamp;

    /*ce \dref_SampleInfo_instance_handle
     */
    DDS_InstanceHandle_t instance_handle;

    /*ce \dref_SampleInfo_publication_handle
     */
    DDS_InstanceHandle_t publication_handle;

#if DDS_INCLUDE_SAMPLE_INFO_RANKS
    /*i \dref_SampleInfo_disposed_generation_count
     */
    DDS_Byte disposed_generation_count;

    /*i \dref_SampleInfo_no_writers_generation_count
     */
    DDS_Byte no_writers_generation_count;

    /*i \dref_SampleInfo_sample_rank
     */
    DDS_Byte sample_rank;

    /*i \dref_SampleInfo_generation_rank
     */
    DDS_Byte generation_rank;

    /*i \dref_SampleInfo_absolute_generation_rank
     */
    DDS_Byte absolute_generation_rank;
#endif

    /*ce \dref_SampleInfo_valid_data
     */
    DDS_Boolean valid_data;

    /*ce \dref_SampleInfo_reception_timestamp
     */
    struct DDS_Time_t reception_timestamp;

    /*i \dref_SampleInfo_publication_sequence_number
     */
    struct DDS_SequenceNumber_t publication_sequence_number;

    /*i Reserved, for internal use 
     */
    void *reserved_data;
};

#if DDS_INCLUDE_SAMPLE_INFO_RANKS
#define DDS_SampleInfo_INITIALIZE_RANKS 0,0,0,0,0,
#else
#define DDS_SampleInfo_INITIALIZE_RANKS
#endif

/*ci
 * \brief Initialized for the DDS_SampleInfo structure
 */
#define DDS_SampleInfo_INITIALIZER \
{\
    DDS_NOT_READ_SAMPLE_STATE,\
    DDS_NEW_VIEW_STATE,\
    DDS_ALIVE_INSTANCE_STATE,\
    {0,0},DDS_HANDLE_NIL_NATIVE,\
    DDS_HANDLE_NIL_NATIVE, \
    DDS_SampleInfo_INITIALIZE_RANKS \
    OEI_FALSE,{0,0},\
    REDA_SEQUENCE_NUMBER_ZERO,\
    NULL\
}

#ifdef __cplusplus
}                               /* extern "C" */
#endif

#define T struct DDS_SampleInfo
#define TSeq DDS_SampleInfoSeq
#define REDA_SEQUENCE_API REDA_SEQUENCE_API_FULL
#include <reda/reda_sequence_decl.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef DOXYGEN_DOCUMENTATION_ONLY

/*ce \dref_SampleInfoSeq
 */
struct DDS_SampleInfoSeq {};
#endif

#ifdef __cplusplus
}                               /* extern "C" */
#endif

/* ------------------------- */
/*   Sample Lost Status      */
/* ------------------------- */

/*ce \dref_SampleLostStatusKind
 */
typedef enum
{
    /*ce \dref_SampleLostStatusKind_NOT_LOST
     */
    DDS_SAMPLE_LOST_NOT_LOST,

    /*ce \dref_SampleLostStatusKind_BY_DATAWRITER
     */
    DDS_SAMPLE_LOST_BY_DATAWRITER,

    /*ce \dref_SampleLostStatusKind_BY_MAX_SAMPLES_LIMIT
     */
    DDS_SAMPLE_LOST_BY_MAX_SAMPLES_LIMIT,

    /*ce \dref_SampleLostStatusKind_BY_HISTORY_DEPTH_LIMIT
     */
    DDS_SAMPLE_LOST_BY_HISTORY_DEPTH_LIMIT,

    /*ce \dref_SampleLostStatusKind_BY_META_SAMPLE_LIMIT
     */
    DDS_SAMPLE_LOST_BY_META_SAMPLE_LIMIT,

    /*ce \dref_SampleLostStatusKind_BY_NOT_READ_ON_CACHE_DELETION
     */
    DDS_SAMPLE_LOST_BY_NOT_READ_ON_CACHE_DELETION
} DDS_SampleLostStatusKind;

/*ce \dref_SampleLostStatus
 */
struct DDSCPPDllExport DDS_SampleLostStatus
{
    /*ce  \dref_SampleLostStatus_total_count
     */
    DDS_Long total_count;

    /*ce  \dref_SampleLostStatus_total_count_change
     */
    DDS_Long total_count_change;

    /*ce \dref_SampleLostStatus_reason
     */
    DDS_SampleLostStatusKind reason;

    /*ce \dref_SampleLostStatus_sample_info
     */
    struct DDS_SampleInfo sample_info;

    DDSC_CPP_STATUS_METHODS(DDS_SampleLostStatus)
};

/*ce \dref_SampleLostStatus_INITIALIZER
 */
#define DDS_SampleLostStatus_INITIALIZER \
{ \
    0L, 0L,DDS_SAMPLE_LOST_NOT_LOST,DDS_SampleInfo_INITIALIZER \
}

/*ci
 * \brief Reset the changed counters in DDS_SampleLostStatus
 *
 * \param[in] s Structure to clear
 */
DDSCDllExport void
DDS_SampleLostStatus_reset(struct DDS_SampleLostStatus *s);

/* ================================================================= */
/*                          QoS                                      */
/* ================================================================= */

/* --------------------- */
/* DataReader QoS struct */
/* --------------------- */

/*i \dref_DataReaderData
 */
struct DDS_DataReaderData
{
    /*ci
     * \brief Pointer to the datareader specific unicast locators, if any
     */
    struct DDS_LocatorSeq *unicast_locator;

    /*ci
     * \brief Pointer to the DataReader specific multicast locators, if any
     */
    struct DDS_LocatorSeq *multicast_locator;
};

/*ce \dref_DataReaderQos
 */
struct DDSCPPDllExport DDS_DataReaderQos
{
    /*ce \dref_DataReaderQos_deadline
     */
    struct DDS_DeadlineQosPolicy deadline;

    /*ce \dref_DataReaderQos_liveliness
     */
    struct DDS_LivelinessQosPolicy liveliness;

    /*ce \dref_DataReaderQos_history
     */
    struct DDS_HistoryQosPolicy history;

    /*ce \dref_DataReaderQos_resource_limits
     */
    struct DDS_ResourceLimitsQosPolicy resource_limits;

    /*ce \dref_DataReaderQos_ownership
     */
    struct DDS_OwnershipQosPolicy ownership;

    /*ce \dref_DataReaderQos_reliability
     */
    struct DDS_ReliabilityQosPolicy reliability;

    /*ce \dref_DataReaderQos_durability
     */
    struct DDS_DurabilityQosPolicy durability;

    /* --- Extensions: ---------------------------------------------------- */
    /*i \dref_DataWriterQos_type_support
     */
    struct DDS_TypeSupportQosPolicy type_support;

    /*ce \dref_DataReaderQos_protocol
     */
    struct DDS_DataReaderProtocolQosPolicy protocol;

    /*ce \dref_DataReaderQos_transport
     */
    struct DDS_TransportQosPolicy transport;

    /*ce \dref_DataReaderQos_reader_resource_limits
     */
    struct DDS_DataReaderResourceLimitsQosPolicy reader_resource_limits;

    /*i \dref_DataReaderQos_management
     */
    struct OEI_ManagementQosPolicy management;

    /*i \dref_DataReaderQos_data
     */
    struct DDS_DataReaderData *data;

    DDSC_CPP_QOS_METHODS(DDS_DataReaderQos)
};

#ifdef __cplusplus
extern "C" {
#endif

/*ce \dref_DataReaderQos_initialize
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReaderQos_initialize(struct DDS_DataReaderQos *self);

/*ce \dref_DataReaderQos_copy
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReaderQos_copy(
        struct DDS_DataReaderQos *self,
        const struct DDS_DataReaderQos *source);


/*ci
 * \brief Compare two DDS_DataReaderQos policies for equality
 *
 * \param[in] left  The left side of the comparison
 * \param[in] right The right side of the comparison
 *
 * \return DDS_BOOLEAN_TRUE if the structures are equal,
 *         DDS_BOOLEAN_TRUE otherwise
 */
MUST_CHECK_RETURN DDSCDllExport DDS_Boolean
DDS_DataReaderQos_is_equal(const struct DDS_DataReaderQos *left,
                            const struct DDS_DataReaderQos *right);

#ifndef OEI_CERT
/*ce \dref_DataReaderQos_finalize
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReaderQos_finalize(struct DDS_DataReaderQos *self);
#endif

/*ce \dref_DataReaderQos_INITIALIZER
 */
#define DDS_DataReaderQos_INITIALIZER {                   \
    DDS_DEADLINE_QOS_POLICY_DEFAULT,                      \
    DDS_LIVELINESS_QOS_POLICY_DEFAULT,                    \
    DDS_HISTORY_QOS_POLICY_DEFAULT,                       \
    DDS_RESOURCE_LIMITS_QOS_POLICY_DEFAULT,               \
    DDS_OWNERSHIP_QOS_POLICY_DEFAULT,                     \
    DDS_RELIABILITY_QOS_POLICY_DEFAULT,                   \
    DDS_DURABILITY_QOS_POLICY_DEFAULT,                    \
    DDS_TYPESUPPORT_QOS_POLICY_DEFAULT,                   \
    DDS_DATA_READER_PROTOCOL_QOS_POLICY_DEFAULT,          \
    DDS_TRANSPORT_QOS_POLICY_DEFAULT,                     \
    DDS_DATAREADERRESOURCE_LIMITS_QOS_POLICY_DEFAULT,     \
    OEI_MANAGEMENT_QOS_POLICY_DEFAULT,                    \
    NULL                                                  \
}

#ifdef __cplusplus
}                               /* extern "C" */
#endif

/* --------------------- */
/* Subscriber QoS struct */
/* --------------------- */

/*ce \dref_SubscriberQos
 */
struct DDSCPPDllExport DDS_SubscriberQos
{
    /*ce \dref_SubscriberQos_entity_factory
     */
    struct DDS_EntityFactoryQosPolicy entity_factory;

    /*i \dref_SubscriberQos_management
     */
    struct OEI_ManagementQosPolicy management;

    DDSC_CPP_QOS_METHODS(DDS_SubscriberQos)
};


#ifdef __cplusplus
extern "C" {
#endif

/*ce \dref_SubscriberQos_initialize
 */
DDSCDllExport DDS_ReturnCode_t
DDS_SubscriberQos_initialize(struct DDS_SubscriberQos *self);

/*ce \dref_SubscriberQos_copy
 */
DDSCDllExport DDS_ReturnCode_t
DDS_SubscriberQos_copy(
        struct DDS_SubscriberQos *self,
        const struct DDS_SubscriberQos *source);

/*ci
 * \brief Compare two DDS_SubscriberQos policies for equality
 *
 * \param[in] self   The left side of the comparison
 * \param[in] source The right side of the comparison
 *
 * \return DDS_BOOLEAN_TRUE if the structures are equal,
 *         DDS_BOOLEAN_TRUE otherwise
 */
MUST_CHECK_RETURN DDSCDllExport DDS_Boolean
DDS_SubscriberQos_is_equal(const struct DDS_SubscriberQos *self,
                           const struct DDS_SubscriberQos *source);

#ifndef OEI_CERT
/*ce \dref_SubscriberQos_finalize
 */
DDSCDllExport DDS_ReturnCode_t
DDS_SubscriberQos_finalize(struct DDS_SubscriberQos *self);
#endif

/*ce \dref_SubscriberQos_INITIALIZER
 */
#define DDS_SubscriberQos_INITIALIZER   {   \
    DDS_ENTITY_FACTORY_QOS_POLICY_DEFAULT,  \
    OEI_MANAGEMENT_QOS_POLICY_DEFAULT       \
}

/* ================================================================= */
/*                       Listeners                                   */
/* ================================================================= */

/*ci @ingroup DDSReaderModule
  @brief Pointer to DDS_DataReader
 */
typedef DDS_DataReader *DDS_DataReader_ptr;

/* -------------------------------------- */
/* DataReader Listener callback typedefs  */
/* -------------------------------------- */

/*ce \dref_DataReaderListener_RequestedDeadlineMissedCallback
 */
typedef void
(*DDS_DataReaderListener_RequestedDeadlineMissedCallback)(
        void *listener_data,
        DDS_DataReader* reader,
        const struct DDS_RequestedDeadlineMissedStatus *status);


/*ce \dref_DataReaderListener_LivelinessChangedCallback
 */
typedef void
(*DDS_DataReaderListener_LivelinessChangedCallback)(
        void *listener_data,
        DDS_DataReader *reader,
        const struct DDS_LivelinessChangedStatus *status);

/*ce \dref_DataReaderListener_RequestedIncompatibleQosCallback
 */
typedef void
(*DDS_DataReaderListener_RequestedIncompatibleQosCallback)(
        void *listener_data,
        DDS_DataReader *reader,
        const struct DDS_RequestedIncompatibleQosStatus *status);

/*ce \dref_DataReaderListener_SampleRejectedCallback
 */
typedef void
(*DDS_DataReaderListener_SampleRejectedCallback)(
        void *listener_data,
        DDS_DataReader *reader,
        const struct DDS_SampleRejectedStatus *status);

/*ce \dref_DataReaderListener_DataAvailableCallback
 */
typedef void
(*DDS_DataReaderListener_DataAvailableCallback)(
        void *listener_data,
        DDS_DataReader *reader);

/*ce \dref_DataReaderListener_SubscriptionMatchedCallback
 */
typedef void
(*DDS_DataReaderListener_SubscriptionMatchedCallback)(
        void *listener_data,
        DDS_DataReader *reader,
        const struct DDS_SubscriptionMatchedStatus *status);

/*ce \dref_DataReaderListener_SampleLostCallback
 */
typedef void
(*DDS_DataReaderListener_SampleLostCallback)(
        void *listener_data,
        DDS_DataReader *reader,
        const struct DDS_SampleLostStatus *status);

/*ce \dref_DataReaderListener_InstanceReplacedCallback
 */
typedef void
(*DDS_DataReaderListener_InstanceReplacedCallback)(
                    void *listener_data,
                    DDS_DataReader *reader,
                    const struct DDS_DataReaderInstanceReplacedStatus *status);

#if DOXYGEN_DOCUMENTATION_ONLY
/*ce \dref_DataReaderListener_BeforeSampleDeserializeCallback
 */
typedef DDS_Boolean
(*DDS_DataReaderListener_BeforeSampleDeserializeCallback)(
        void *listener_data,
        DDS_DataReader *reader,
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream,
        DDS_Boolean *dropped);
#else

FUNCTION_MUST_TYPEDEF(
DDS_Boolean
(*DDS_DataReaderListener_BeforeSampleDeserializeCallback)(
        void *listener_data,
        DDS_DataReader *reader,
        struct NDDS_Type_Plugin *plugin,
        struct CDR_Stream_t *stream,
        DDS_Boolean *dropped)
)
#endif

#if DOXYGEN_DOCUMENTATION_ONLY
/*ce \dref_DataReaderListener_BeforeSampleCommitCallback
 */
typedef DDS_Boolean
(*DDS_DataReaderListener_BeforeSampleCommitCallback)(
        void *listener_data,
        DDS_DataReader *reader,
        const void *const sample,
        DDS_Boolean *dropped);
#else

FUNCTION_MUST_TYPEDEF(
DDS_Boolean
(*DDS_DataReaderListener_BeforeSampleCommitCallback)(
        void *listener_data,
        DDS_DataReader *reader,
        const void *const sample,
        const struct DDS_SampleInfo *const sample_info,
        DDS_Boolean *dropped)
)
#endif

/* -------------------------- */
/* DataReader Listener struct */
/* -------------------------- */

/*ce \dref_DataReaderListener
 */
struct DDS_DataReaderListener
{
    /*ce \dref_DataReaderListener_as_listener
     */
    struct DDS_Listener as_listener;

    /*ce \dref_DataReaderListener_on_requested_deadline_missed
     */
    DDS_DataReaderListener_RequestedDeadlineMissedCallback
    on_requested_deadline_missed;

    /*ce \dref_DataReaderListener_on_requested_incompatible_qos
     */
    DDS_DataReaderListener_RequestedIncompatibleQosCallback
    on_requested_incompatible_qos;

    /*ce \dref_DataReaderListener_on_sample_rejected
     */
    DDS_DataReaderListener_SampleRejectedCallback
    on_sample_rejected;

    /*ce \dref_DataReaderListener_on_liveliness_changed
     */
    DDS_DataReaderListener_LivelinessChangedCallback
    on_liveliness_changed;

    /*ce \dref_DataReaderListener_on_data_available
     */
    DDS_DataReaderListener_DataAvailableCallback
    on_data_available;

    /*ce \dref_DataReaderListener_on_subscription_matched
     */
    DDS_DataReaderListener_SubscriptionMatchedCallback
    on_subscription_matched;

    /*ce \dref_DataReaderListener_on_sample_lost
     */
    DDS_DataReaderListener_SampleLostCallback
    on_sample_lost;

    /*ce \dref_DataReaderListener_on_before_sample_deserialize
     */
    DDS_DataReaderListener_BeforeSampleDeserializeCallback
    on_before_sample_deserialize;

    /*ce \dref_DataReaderListener_on_before_sample_commit
     */
    DDS_DataReaderListener_BeforeSampleCommitCallback
    on_before_sample_commit;

    /*ce \dref_DataReaderListener_on_instance_replaced
     */
    DDS_DataReaderListener_InstanceReplacedCallback
    on_instance_replaced;
};

/*ce \dref_DataReaderListener_INITIALIZER
 */
#define DDS_DataReaderListener_INITIALIZER \
{\
  DDS_Listener_INITIALIZER, \
  (DDS_DataReaderListener_RequestedDeadlineMissedCallback)NULL, \
  (DDS_DataReaderListener_RequestedIncompatibleQosCallback)NULL, \
  (DDS_DataReaderListener_SampleRejectedCallback)NULL, \
  (DDS_DataReaderListener_LivelinessChangedCallback)NULL, \
  (DDS_DataReaderListener_DataAvailableCallback)NULL, \
  (DDS_DataReaderListener_SubscriptionMatchedCallback)NULL, \
  (DDS_DataReaderListener_SampleLostCallback)NULL,\
  (DDS_DataReaderListener_BeforeSampleDeserializeCallback)NULL,\
  (DDS_DataReaderListener_BeforeSampleCommitCallback)NULL,\
  (DDS_DataReaderListener_InstanceReplacedCallback)NULL\
}

/* -------------------------------------- */
/* Subscriber Listener callback typedefs  */
/* -------------------------------------- */

/*ce \dref_SubscriberListener_DataOnReadersCallback
 */
typedef void
(*DDS_SubscriberListener_DataOnReadersCallback)(
        void *listener_data,
        DDS_Subscriber *sub);


/* ----------------------------- */
/* Subscriber Listener struct    */
/* ----------------------------- */

/*ce \dref_SubscriberListener
 */
struct DDS_SubscriberListener
{

    /*ce \dref_SubscriberListener_as_datareaderlistener
     */
    struct DDS_DataReaderListener as_datareaderlistener;

    /*ce \dref_SubscriberListener_on_data_on_readers
     */
    DDS_SubscriberListener_DataOnReadersCallback on_data_on_readers;
};

/*ce \dref_SubscriberListener_INITIALIZER
 */
#define DDS_SubscriberListener_INITIALIZER  \
    { DDS_DataReaderListener_INITIALIZER, \
      (DDS_SubscriberListener_DataOnReadersCallback)NULL }

/* ================================================================= */
/*                           Subscriber                              */
/* ================================================================= */

/*ce \dref_DATAREADER_QOS_DEFAULT
 */
extern DDSCDllVariable const struct DDS_DataReaderQos
    DDS_DATAREADER_QOS_DEFAULT;

/*ce \dref_DATAREADER_QOS_USE_TOPIC_QOS
 */
extern DDSCDllVariable const struct DDS_DataReaderQos
    DDS_DATAREADER_QOS_USE_TOPIC_QOS;

/* ----------------------------------------------------------------- */
#define DDS_Subscriber_as_entity(subscriberPtr) \
            ((DDS_Entity*) subscriberPtr)

/* ----------------------------------------------------------------- */
#ifdef DOXYGEN_DOCUMENTATION_ONLY

/*ce \dref_Subscriber_as_entity
 */
DDS_Entity *DDS_Subscriber_as_entity(DDS_Subscriber * subscriber);

#endif                          /*DOXYGEN_DOCUMENTATION_ONLY */

/* ----------------------------------------------------------------- */
/*ce \dref_Subscriber_get_default_datareader_qos
 */
/* #if INCLUDE_API_QOS */
DDSCDllExport DDS_ReturnCode_t
DDS_Subscriber_get_default_datareader_qos(
        DDS_Subscriber *self,
        struct DDS_DataReaderQos *qos);

/* ----------------------------------------------------------------- */
/*ce \dref_Subscriber_set_default_datareader_qos
 */
/* #if INCLUDE_API_QOS */
DDSCDllExport DDS_ReturnCode_t
DDS_Subscriber_set_default_datareader_qos(
        DDS_Subscriber *self,
        const struct DDS_DataReaderQos *qos);

/* ----------------------------------------------------------------- */
/*ce \dref_Subscriber_create_datareader
 */
DDSCDllExport DDS_DataReader*
DDS_Subscriber_create_datareader(DDS_Subscriber *self,
        DDS_TopicDescription *topic,
        const struct DDS_DataReaderQos *qos,
        const struct DDS_DataReaderListener *listener,
        DDS_StatusMask mask);

/* ----------------------------------------------------------------- */
#ifndef OEI_CERT
/*ce \dref_Subscriber_delete_datareader
 */
DDSCDllExport DDS_ReturnCode_t
DDS_Subscriber_delete_datareader(
        DDS_Subscriber *self,
        DDS_DataReader *a_datareader);
#endif

/* ----------------------------------------------------------------- */
/*ce \dref_Subscriber_enable
 */
DDSCDllExport DDS_ReturnCode_t
DDS_Subscriber_enable(DDS_Entity *self);

/* ----------------------------------------------------------------- */
#ifndef OEI_CERT
/*ce \dref_Subscriber_delete_contained_entities
 */
DDSCDllExport DDS_ReturnCode_t
DDS_Subscriber_delete_contained_entities(DDS_Subscriber * self);
#endif

/* ----------------------------------------------------------------- */
/* #ifdef INCLUDE_API_LOOKUP */
/*ce \dref_Subscriber_lookup_datareader
 */
DDSCDllExport DDS_DataReader*
DDS_Subscriber_lookup_datareader(
        DDS_Subscriber *self,
        const char *topic_name);

/* ----------------------------------------------------------------- */
/*ce \dref_Subscriber_get_participant
 */
DDSCDllExport DDS_DomainParticipant*
DDS_Subscriber_get_participant(DDS_Subscriber * self);


/* ----------------------------------------------------------------- */
#if INCLUDE_API_QOS
/*ce  \dref_Subscriber_set_qos
 */
DDSCDllExport DDS_ReturnCode_t
DDS_Subscriber_set_qos(
        DDS_Subscriber* self,
        const struct DDS_SubscriberQos *qos);

/* ----------------------------------------------------------------- */
/*ce \dref_Subscriber_get_qos
 */
DDSCDllExport DDS_ReturnCode_t
DDS_Subscriber_get_qos(
        DDS_Subscriber *self,
        struct DDS_SubscriberQos *qos);
#endif

/* ----------------------------------------------------------------- */

#ifndef OEI_CERT 
/*ce \dref_Subscriber_set_listener
 */
DDSCDllExport DDS_ReturnCode_t
DDS_Subscriber_set_listener(
        DDS_Subscriber * self,
        const struct DDS_SubscriberListener *l,
        DDS_StatusMask mask);
#endif 

#ifndef OEI_CERT 
/*ce \dref_Subscriber_get_listener
 */
DDSCDllExport struct DDS_SubscriberListener
DDS_Subscriber_get_listener(DDS_Subscriber * self);
#endif 

/* ================================================================= */
/*                           Data Reader                             */
/* ================================================================= */
#define DDS_DataReader_as_entity(dataReaderPtr) \
            ((DDS_Entity*) dataReaderPtr)

/* ----------------------------------------------------------------- */
#ifdef DOXYGEN_DOCUMENTATION_ONLY
/*ce \dref_DataReader_as_entity
 */
DDS_Entity *
DDS_DataReader_as_entity(DDS_DataReader * dataReader);
#endif                          /*DOXYGEN_DOCUMENTATION_ONLY */

/* ----------------------------------------------------------------- */
/*ce \dref_DataReader_enable
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_enable(DDS_Entity *self);

/* ----------------------------------------------------------------- */
#if INCLUDE_API_LOOKUP
/*ce \dref_DataReader_get_matched_publications
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_get_matched_publications(
        DDS_DataReader *self,
        struct DDS_InstanceHandleSeq *publication_handles);
#endif /* INCLUDE_API_LOOKUP */

struct DDS_PublicationBuiltinTopicData;
/* ----------------------------------------------------------------- */
#if INCLUDE_API_LOOKUP
/*ce \dref_DataReader_get_matched_publication_data
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_get_matched_publication_data(
        DDS_DataReader *self,
        struct DDS_PublicationBuiltinTopicData *publication_data,
        const DDS_InstanceHandle_t *publication_handle);
#endif /* INCLUDE_API_LOOKUP */

/* ----------------------------------------------------------------- */
/*ce \dref_DataReader_get_topicdescription
 */
DDSCDllExport DDS_TopicDescription*
DDS_DataReader_get_topicdescription(DDS_DataReader * self);

/* ----------------------------------------------------------------- */
/*ce \dref_DataReader_get_subscriber
 */
DDSCDllExport DDS_Subscriber*
DDS_DataReader_get_subscriber(DDS_DataReader * self);


/* ----------------------------------------------------------------- */
/*ce \dref_DataReader_get_sample_rejected_status
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_get_sample_rejected_status(
        DDS_DataReader *self,
        struct DDS_SampleRejectedStatus *status);

/* ----------------------------------------------------------------- */
/*ce \dref_DataReader_get_liveliness_changed_status
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_get_liveliness_changed_status(
        DDS_DataReader *self,
        struct DDS_LivelinessChangedStatus *status);

/* ----------------------------------------------------------------- */
/*ce \dref_DataReader_get_requested_deadline_missed_status
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_get_requested_deadline_missed_status(
        DDS_DataReader *self,
        struct DDS_RequestedDeadlineMissedStatus *status);

/* ----------------------------------------------------------------- */
/*ce \dref_DataReader_get_requested_incompatible_qos_status
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_get_requested_incompatible_qos_status(
        DDS_DataReader *self,
        struct DDS_RequestedIncompatibleQosStatus *status);

/* ----------------------------------------------------------------- */
/*ce \dref_DataReader_get_subscription_matched_status
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_get_subscription_matched_status(
        DDS_DataReader *self,
        struct DDS_SubscriptionMatchedStatus *status);

/* ----------------------------------------------------------------- */
/*ce \dref_DataReader_get_sample_lost_status
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_get_sample_lost_status(
        DDS_DataReader *self,
        struct DDS_SampleLostStatus *status);

/* ----------------------------------------------------------------- */
/*ce \dref_DataReader_get_instance_replaced_status
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_get_instance_replaced_status(
        DDS_DataReader *self,
        struct DDS_DataReaderInstanceReplacedStatus *status);

/*ci
 * \brief Get a pointer to the DataReader's Qos policy
 *
 * \details
 * NOTE: It is up to the caller to ensure the datareader is not deleted while
 *       the Qos is being accessed.
 *
 * \return Pointer to DDS_DataReaderQos*
 */
DDSCDllExport struct DDS_DataReaderQos*
DDS_DataReader_get_qos_ref(DDS_DataReader *self);

/* ----------------------------------------------------------------- */
#if INCLUDE_API_QOS
/*ce \dref_DataReader_set_qos
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_set_qos(
        DDS_DataReader* self,
        const struct DDS_DataReaderQos *qos);

/* ----------------------------------------------------------------- */
/*ce \dref_DataReader_get_qos
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_get_qos(DDS_DataReader *self,
        struct DDS_DataReaderQos *qos);
#endif

/* ----------------------------------------------------------------- */
#ifndef OEI_CERT 
/*ce \dref_DataReader_set_listener
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_set_listener(
        DDS_DataReader * self,
        const struct DDS_DataReaderListener *l,
        DDS_StatusMask mask);
#endif 

/* ----------------------------------------------------------------- */
#ifndef OEI_CERT 
/*ce \dref_DataReader_get_listener
 */
DDSCDllExport struct DDS_DataReaderListener
DDS_DataReader_get_listener(DDS_DataReader *self);
#endif 
/* ----------------------------------------------------------------- */

/*ce \dref_DataReader_get_instance_replaced_status
 */
DDS_ReturnCode_t
DDS_DataReader_get_instance_replaced_status(DDS_DataReader *reader,
                           struct DDS_DataReaderInstanceReplacedStatus *status);

/* ----------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#include "dds_c/dds_c_rh_plugin.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* REDA_SEQUENCE_API is always assumed to be FULL for DDS_UntypedSampleSeq */
#define DDS_UntypedSampleSeq                       REDA_Sequence
#define DDS_UntypedSampleSeq_initialize            REDA_Sequence_initialize
#ifndef OEI_CERT
#define DDS_UntypedSampleSeq_finalize              REDA_Sequence_finalize
#endif /* !OEI_CERT */
#define DDS_UntypedSampleSeq_get_maximum           REDA_Sequence_get_maximum
#define DDS_UntypedSampleSeq_set_maximum           REDA_Sequence_set_maximum
#define DDS_UntypedSampleSeq_get_length            REDA_Sequence_get_length
#define DDS_UntypedSampleSeq_set_length            REDA_Sequence_set_length
#define DDS_UntypedSampleSeq_get_reference         REDA_Sequence_get_reference
#define DDS_UntypedSampleSeq_copy                  REDA_Sequence_copy
#define DDS_UntypedSampleSeq_is_equal              REDA_Sequence_is_equal
#define DDS_UntypedSampleSeq_loan_contiguous       REDA_Sequence_loan_contiguous
#define DDS_UntypedSampleSeq_loan_discontiguous    REDA_Sequence_loan_discontiguous
#define DDS_UntypedSampleSeq_unloan                REDA_Sequence_unloan
#define DDS_UntypedSampleSeq_has_ownership         REDA_Sequence_has_ownership
#define DDS_UntypedSampleSeq_get_contiguous_buffer REDA_Sequence_get_buffer
#define DDS_UntypedSampleSeq_set_contiguous_buffer REDA_Sequence_set_buffer
#define DDS_UntypedSampleSeq_has_discontiguous_buffer REDA_Sequence_has_discontiguous_buffer
#define DDS_UntypedSampleSeq_get_token             REDA_Sequence_get_token
#define DDS_UntypedSampleSeq_set_token             REDA_Sequence_set_token

/********************* (Untyped) DataReader API ****************************/
/*ce \dref_DataReader_read
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_read(
        DDS_DataReader *self,
        struct DDS_UntypedSampleSeq *received_data,
        struct DDS_SampleInfoSeq *info_seq,
        DDS_Long max_samples,
        DDS_SampleStateMask sample_states,
        DDS_ViewStateMask view_states,
        DDS_InstanceStateMask instance_states);

/*ce \dref_DataReader_take
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_take(
        DDS_DataReader *self,
        struct DDS_UntypedSampleSeq *received_data,
        struct DDS_SampleInfoSeq *info_seq,
        DDS_Long max_samples,
        DDS_SampleStateMask sample_states,
        DDS_ViewStateMask view_states,
        DDS_InstanceStateMask instance_states);

/*ce \dref_DataReader_read_next_sample
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_read_next_sample(
        DDS_DataReader *self,
        void *received_data,
        struct DDS_SampleInfo *sample_info);

/*ce \dref_DataReader_take_next_sample
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_take_next_sample(
        DDS_DataReader *self,
        void *received_data,
        struct DDS_SampleInfo *sample_info);

/*ce \dref_DataReader_read_instance
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_read_instance(
        DDS_DataReader *self,
        struct DDS_UntypedSampleSeq *received_data,
        struct DDS_SampleInfoSeq *info_seq,
        DDS_Long max_samples,
        const DDS_InstanceHandle_t *a_handle,
        DDS_SampleStateMask sample_states,
        DDS_ViewStateMask view_states,
        DDS_InstanceStateMask instance_states);

/*ce \dref_DataReader_take_instance
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_take_instance(
        DDS_DataReader *self,
        struct DDS_UntypedSampleSeq *received_data,
        struct DDS_SampleInfoSeq *info_seq,
        DDS_Long max_samples,
        const DDS_InstanceHandle_t *a_handle,
        DDS_SampleStateMask sample_states,
        DDS_ViewStateMask view_states,
        DDS_InstanceStateMask instance_states);


/*ce \dref_DataReader_return_loan
 */
DDSCDllExport DDS_ReturnCode_t
DDS_DataReader_return_loan(
        DDS_DataReader *self,
        struct DDS_UntypedSampleSeq *received_data,
        struct DDS_SampleInfoSeq *info_seq);

/*ce \dref_DataReader_lookup_instance
 */
DDSCDllExport DDS_InstanceHandle_t
DDS_DataReader_lookup_instance(DDS_DataReader *self,
                               const void *key_holder);

/*ci
 * \brief Inform a data-reader that liveliness has been lost on a remote writer
 *
 * \details
 * Inform a data-reader that liveliness has been lost on a remote writer.
 * This causes the remote writer to be deleted from the data-reader's history
 * cache if it is known to the data-reader and exists in the history cache.
 *
 * \param[in] self               The data-reader the liveliness is lost for
 * \param[in] publication_handle The publication handle for the remote writer
 *                               that has lost liveliness.
 */
DDSCDllExport void
DDS_DataReader_liveliness_lost(DDS_DataReader *self,
                               DDS_InstanceHandle_t *publication_handle);

/*ci
 * \brief Add an anonymous route to a DDS DataReader
 *
 * \details
 * This function adds an anonymous route to a DataWriter. An anonymous
 * route is a route with no state information and is typically used
 * by a DDS participant reader to listen to discovery traffic from other
 * participants in a domain.
 *
 * \param[in] self         The datareader to add the route to
 * \param[in] src_writer   The peer writer to listen to
 * \param[in] from_address The address to listen for traffic on
 *
 * \return DDS_BOOLEAN_TRUE on success, DDS_BOOLEAN_FALSE on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_Boolean
DDS_DataReader_add_anonymous_route(DDS_DataReader *self,
                                   struct NETIO_Address *src_writer,
                                   struct NETIO_Address *from_address);

#ifndef OEI_CERT
/*ci
 * \brief Remove an anonymous route from a DDS DataReader
 *
 * \details
 * This function removes an anonymous route from a DataReader. An anonymous
 * route is a route with no state information and is typically used
 * by a DDS participant to listen to discovery traffic from other
 * participants in a domain. This function stops listening on traffic
 * from a particular address.
 *
 * \param[in] self         The datareader to remove the route from
 * \param[in] src_writer   The peer writer to stop listening to
 * \param[in] from_address The address to stop listening on
 *
 * \return DDS_BOOLEAN_TRUE on success, DDS_BOOLEAN_FALSE on failure
 */
MUST_CHECK_RETURN DDSCDllExport DDS_Boolean
DDS_DataReader_delete_anonymous_route(DDS_DataReader *self,
                                      struct NETIO_Address *src_writer,
                                      struct NETIO_Address *from_address);
#endif /* !OEI_CERT */

struct DDS_DataWriterQos;
MUST_CHECK_RETURN DDSCDllExport DDS_Boolean
DDS_DataReader_add_route(DDS_DataReader *self,
                         const DDS_BuiltinTopicKey_t *key,
                         const struct DDS_DataWriterQos *const qos,
                         const struct DDS_LocatorSeq *uc_locator,
                         const struct DDS_LocatorSeq *mc_locator,
                         OEI_BOOL *route_existed);

MUST_CHECK_RETURN DDSCDllExport DDS_Boolean
DDS_DataReader_delete_route(DDS_DataReader *self,
                            const DDS_BuiltinTopicKey_t *key,
                            const struct DDS_LocatorSeq *uc_locator,
                            const struct DDS_LocatorSeq *mc_locator,
                            OEI_BOOL *route_existed);

/* ----------------------------------------------------------------- */


#ifdef __cplusplus
}                               /* extern "C" */
#endif


#endif /* dds_c_subscription_h */
