/*
 * FILE: RTPSInterface.h 
 *
 */


/*e \file
 * \brief RTPS interface functions and types 
 *  
 * \details 
 * RTPS protocol defined types, implemented in C. 
 *  
 *  
 */
#ifndef rtps_rtps_h
#define rtps_rtps_h


#ifndef osapi_types_h
#include "osapi/osapi_types.h"
#endif
#ifndef reda_epoch_h
#include "reda/reda_epoch.h"
#endif
#ifndef reda_sequenceNumber_h
#include "reda/reda_sequenceNumber.h"
#endif
#ifndef osapi_time_h
#include "osapi/osapi_time.h"
#endif
#ifndef osapi_system_h
#include "osapi/osapi_system.h"
#endif
#ifndef rtps_dll_h
#include "rtps/rtps_dll.h"
#endif
#ifndef cdr_stream_h
#include "cdr/cdr_stream.h"
#endif
#ifndef netio_common_h
#include "netio/netio_common.h"
#endif
#ifndef netio_common_h
#include "netio/netio_common.h"
#endif
#ifndef netio_address_h
#include "netio/netio_address.h"
#endif
#ifndef netio_route_h
#include "netio/netio_route.h"
#endif
#ifndef netio_interface_h
#include "netio/netio_interface.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef OEI_CPP
#define RTPS_CPP_SUPPORT_METHODS_BASIC(T) \
    public:\
        T();\
        ~T();\
    private: \
        T(const T& from);\
        T& operator=(const T& from);\
        bool operator==(const T& other);\
        bool operator!=(const T& other);
#else /* ifdef OEI_CPP */
#define RTPS_CPP_SUPPORT_METHODS_BASIC(T)
#endif /* ifdef OEI_CPP */

/*ci \brief Maximum length of an RTPS serializable path name string */
#define RTPS_PATHNAME_LEN_MAX (255)


/*ci \ingroup RTPS_PidModule
 * \brief RTPS parameter ID, used to describe RTPS objects.
 */
typedef OEI_UINT16 RTPS_ParameterId;

/*ci \ingroup RTPS_PidModule
 * \brief Mask for ParameterId bit indicating subspace where 
 * unrecognized PIDs are either ignored or treated as 
 * incompatible QoS.
*/
#define RTPS_PID_INCOMPATIBLE_MASK              (0x4000)

/*ci \ingroup RTPS_PidModule
 * \brief Pad for parameter values in case they don't end on a 4-byte boundary
 */
#define RTPS_PID_PAD                             (0x0000)

/*ci \ingroup RTPS_PidModule
 * \brief Indicate end of parameter sequence.
 */
#define RTPS_PID_SENTINEL                        (0x0001)

/*ci \ingroup RTPS_PidModule
 * \brief Topic name parameter ID
 *  
 * \details 
 * Used for field Publication::topic: PathName, Subscription::topic : PathName
 */
#define RTPS_PID_TOPIC_NAME                      (0x0005)

/*ci \ingroup RTPS_PidModule
 * \brief Type name parameter ID
 *  
 * \details 
 * Used for field Publication::typeName : TypeName,
 * Subscription::typeName : TypeName
 */
#define RTPS_PID_TYPE_NAME                       (0x0007)

/*ci \ingroup RTPS_PidModule
 * \brief Durability Qos parameter ID
 *  
 * \details Used for field
 * Publication::durabilityQosPolicy : DurabilityQosPolicy, and
 * Subscription::durabilityQosPolicy : DurabilityQosPolicy
 */
#define RTPS_PID_DURABILITY         (0x001d)


/*ci \ingroup RTPS_PidModule 
 * \brief Deadline Qos parameter ID
 *
 * \details
 * Used for field Subscription::deadlineQosPolicy : DeadlineQosPolicy
 */
#define RTPS_PID_DEADLINE         (0x0023)

/*ci \ingroup RTPS_PidModule 
 * \brief Liveliness Qos parameter ID
 *
 * \details
 * Used for field Publication::livelinessQosPolicy : LivelinessQosPolicy, and
 * Subscription::livelinessQosPolicy : LivelinessQosPolicy
 */
#define RTPS_PID_LIVELINESS         (0x001b)

/*ci \ingroup RTPS_PidModule 
 * \brief Reliability Qos parameter ID
 *
 * \details
 * Used for field Publication::reliabilityOffered : OEI_UINT32, and
 * Subscription::reliabilityRequested : OEI_UINT32
 */
#define RTPS_PID_RELIABILITY        (0x001a)

/*ci \ingroup RTPS_PidModule 
 * \brief Ownership Qos parameter ID
 *
 * \details
 * Used for field Subscription::ownershipQosPolicy : OwnershipQosPolicy
 */
#define RTPS_PID_OWNERSHIP         (0x001f)

/*ci \ingroup RTPS_PidModule 
 * \brief Ownership Strength Qos parameter ID
 *
 * \details
 * Used for field Publication::strength : long
 */
#define RTPS_PID_OWNERSHIP_STRENGTH (0x0006)

/*ci \ingroup RTPS_PidModule
 * \brief Protocol Version paramater ID 
 *  
 * \details 
 * Used for field Application::protocolVersion : ProtocolVersion
 */
#define RTPS_PID_PROTOCOL_VERSION                (0x0015)

/*ci \ingroup RTPS_PidModule
 * \brief Vendor ID parameterID 
 *  
 * \details 
 * Used for field Application::vendorId : VendorId
 */
#define RTPS_PID_VENDOR_ID                       (0x0016)


/*ci \brief Maximum number of addresses per type, per entity */
#define RTPS_PID_USERDATA_IPADDRESS_COUNT_MAX   (4)

/*ci \ingroup RTPS_PidModule 
 * \brief Unicast locator parameter ID
 *
 * \details Array of max size RTPS_PID_USERDATA_UNICAST_IPADDRESS_COUNT_MAX
 */
#define RTPS_PID_UNICAST_LOCATOR6     (0x002f)

/*ci \ingroup RTPS_PidModule 
 * \brief Multicast locator parameter ID
 *
 * \details Array of max size RTPS_PID_USERDATA_UNICAST_IPADDRESS_COUNT_MAX
 */
#define RTPS_PID_MULTICAST_LOCATOR6     (0x0030)

/*ci \ingroup RTPS_PidModule 
 * \brief Default unicast locator parameter ID
 *
 * \details Array of max size RTPS_PID_USERDATA_UNICAST_IPADDRESS_COUNT_MAX
 */
#define RTPS_PID_DEFAULT_UNICAST_LOCATOR6     (0x0031)

/*ci \ingroup RTPS_PidModule 
 * \brief Discovery (meta-traffic) unicast locator parameter ID
 *
 * \details Array of max size RTPS_PID_USERDATA_UNICAST_IPADDRESS_COUNT_MAX
 */
#define RTPS_PID_METATRAFFIC_UNICAST_LOCATOR6 (0x0032)

/*ci \ingroup RTPS_PidModule 
 * \brief Discovery (meta-traffic) multicast locator parameter ID
 *
 * \details Array of max size RTPS_PID_USERDATA_UNICAST_IPADDRESS_COUNT_MAX
 */
#define RTPS_PID_METATRAFFIC_MULTICAST_LOCATOR6 (0x0033)

/*ci \ingroup RTPS_PidModule 
 * \brief Liveliness lease duration parameter ID
 */
#define RTPS_PID_LEASE_DURATION                (0x0002)

/*ci \ingroup RTPS_PidModule 
 * \brief Property Qos parameter ID 
 *  
 * \details Used for field Participant::propertyList
 */
#define RTPS_PID_PROPERTY_LIST                    (0x0059)

/*ci \ingroup RTPS_PidModule 
 * \brief Participant GUID parameter ID
 */
#define RTPS_PID_PARTICIPANT_GUID                 (0x0050)

/*ci \ingroup RTPS_ParameterSequenceClass 
 * \brief Builtin endpoint mask parameter ID 
 *  
 * \details Indicate builtin endpoint set inline Qos, 
 * PID_BUILTIN_ENDPOINT_SET from the RTPS spec
 */
#define RTPS_PID_BUILTIN_ENDPOINT_MASK     (0x0058)

/*ci \ingroup RTPS_ParameterSequenceClass 
 * \brief Endpoint GUID parameter ID
 */
#define RTPS_PID_ENDPOINT_GUID    (0x005A)

/*ci \ingroup RTPS_ParameterSequenceClass 
 * \brief Entity name parameter ID
 */
#define RTPS_PID_ENTITY_NAME     (0x0062)

/******************************************************************************/
/*ci \ingroup RTPS_ParameterSequenceClass 
 * \brief Key Hash parameter ID
 */
#define RTPS_PID_KEY_HASH     (0x0070)

/*ci \brief Key Hash parameter length */
#define RTPS_KEY_HASH_PARAM_LENGTH  (16)

/*ci \ingroup RTPS_ParameterSequenceClass
 * \brief Status info parameter ID
 */
#define RTPS_PID_STATUS_INFO    (0x0071)

/*ci \brief Status info parameter length */
#define RTPS_STATUS_INFO_PARAM_LENGTH (4)

/*ci \brief Send queue size parameter ID */
#define RTPS_PID_SEND_QUEUE_SIZE_DEPRECATED  (0x0013)

/******************************************************************************/
/*ci \ingroup RTPS_Class 
 * \brief Host ID of GUID
 */
typedef OEI_UINT32 RTPS_HostId;

/*ci \ingroup RTPS_Class 
 * \brief Unknown Host ID
 */
#define RTPS_HOST_ID_UNKNOWN (0x00000000)

/*ci \ingroup RTPS_Class 
 * \brief Application ID of GUID
 */
typedef OEI_UINT32 RTPS_AppId;

/*ci \ingroup RTPS_Class 
 * \brief Unknown Application ID
 */
#define RTPS_APP_ID_UNKNOWN (0x00000000)

/*ci \ingroup RTPS_Class 
 * \brief Instance ID of GUID
 */
typedef OEI_UINT32 RTPS_InstanceId;

/*ci \ingroup RTPS_Class 
 * \brief Unknown Instance ID
 */
#define RTPS_INSTANCE_ID_UNKNOWN (0x00000000)

/*ci \ingroup RTPS_Class 
 * \brief Object ID of GUID
 */
typedef OEI_UINT32 RTPS_ObjectId;

/*ci \ingroup RTPS_Class 
 * \brief Unknown Object ID
 */
#define RTPS_OBJECT_ID_UNKNOWN (0x00000000)

/*ci \ingroup RTPS_Class 
 * \brief Maximum Object ID
 */
#define RTPS_OBJECT_ID_MAX     (0xFFFFFFFF)

/******************************************************************************/
/*ci \ingroup RTPS_Class 
 * \brief Prefix portion of GUID. 
 *  
 * \details Uniquely identifies the DomainParticipant to which 
 * an RTPS's DDS entity belong
 */
struct RTPS_GuidPrefix
{
    /*ci \brief First field of GUID Prefix. 
     * \details Historically set to host IP address
     */
    RTPS_HostId host_id;

    /*ci \brief Second field of GUID Prefix. 
     * \details Historically set to process ID
     */
    RTPS_AppId app_id ;

    /*ci \brief Third field of GUID prefix. 
     * \details Historically set to instance counter
     */
    RTPS_InstanceId instance_id ;
};

/*ci \ingroup RTPS_Class 
 * \brief Unknonwn GUID prefix
 */
#define RTPS_GUID_PREFIX_UNKNOWN { \
    RTPS_HOST_ID_UNKNOWN,   \
    RTPS_APP_ID_UNKNOWN,    \
    RTPS_INSTANCE_ID_UNKNOWN}

/*ci \ingroup RTPS_Class 
 * \brief Length in bytes of GUID prefix
 */
#define RTPS_GUID_PREFIX_SIZE (12)

/*ci \ingroup RTPS_Class 
 * \brief GUID
 */
struct RTPS_Guid
{
    /*ci \brief GUID prefix */
    struct RTPS_GuidPrefix prefix;

    /*ci \brief Unique entity identifier */
    RTPS_ObjectId object_id;
};

/*ci \ingroup RTPS_Class 
 * \brief Unknown GUID
 */
#define RTPS_GUID_UNKNOWN {   \
    RTPS_GUID_PREFIX_UNKNOWN,   \
    RTPS_OBJECT_ID_UNKNOWN}

/******************************************************************************/
/*ci \brief Participant Object ID */
#define RTPS_OBJECT_ID_PARTICIPANT             (0x000001C1)

/*ci \brief Simple Discovery Protocol Participant Writer Object ID */
#define RTPS_OBJECT_ID_WRITER_SDP_PARTICIPANT  (0x000100C2)

/*ci \brief Simple Discovery Protocol Publication Writer Object ID */
#define RTPS_OBJECT_ID_WRITER_SDP_PUBLICATION  (0x000003C2)

/*ci \brief Simple Discovery Protocol Subscription Writer Object ID */
#define RTPS_OBJECT_ID_WRITER_SDP_SUBSCRIPTION (0x000004C2)

/*ci \brief Simple Discovery Protocol Participant Reader Object ID */
#define RTPS_OBJECT_ID_READER_SDP_PARTICIPANT  (0x000100C7)

/*ci \brief Simple Discovery Protocol Subscription Reader Object ID */
#define RTPS_OBJECT_ID_READER_SDP_PUBLICATION  (0x000003C7)

/*ci \brief Simple Discovery Protocol Subscription Reader Object ID */
#define RTPS_OBJECT_ID_READER_SDP_SUBSCRIPTION (0x000004C7)

/******************************************************************************/
/*ci \brief Key Hash max length */
#define RTPS_KEY_HASH_MAX_LENGTH 16

/*ci \brief Hash of instance key */
struct RTPS_KeyHash
{
    /*ci \brief Key hash value */
    OEI_UINT8 value[RTPS_KEY_HASH_MAX_LENGTH];

    /*ci \brief Key hash length */
    OEI_UINT32 length;
};

/*ci \brief Nil Key Hash value */
#define RTPS_KEY_HASH_NIL {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

/*ci \brief Default Key Hash Initializer */
#define RTPS_KEY_HASH_DEFAULT {     \
RTPS_KEY_HASH_NIL,  /* value */\
RTPS_KEY_HASH_MAX_LENGTH/* length */\
}

/******************************************************************************/
/*ci \ingroup RTPS_Class
 * \brief Returns OEI_TRUE if GUIDs are equal 
 *  
 * \param[in] a First GUID 
 * \param[in] b Second GUID 
 *  
 * \return OEI_TRUE if GUIDs are equal, OEI_FALSE otherwise 
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_Guid_equals(struct RTPS_Guid *a, struct RTPS_Guid *b);

/*ci \ingroup RTPS_Class
 * \brief Returns OEI_TRUE if GUID prefixes are equal 
 *  
 * \param[in] a First GUID 
 * \param[in] b Second GUID 
 *  
 * \return OEI_TRUE if prefixes of GUIDs are equal, OEI_FALSE otherwise 
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_Guid_prefix_equals(
        struct RTPS_Guid *a,
        struct RTPS_Guid *b);

/*ci \ingroup RTPS_Class
 * \brief Returns OEI_TRUE if GUID suffixes are equal 
 *  
 * \param[in] a First GUID 
 * \param[in] b Second GUID 
 *  
 * \return OEI_TRUE if suffixes of GUIDs are equal, OEI_FALSE otherwise 
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_Guid_suffix_equals(
        struct RTPS_Guid *a,
        struct RTPS_Guid *b);

/******************************************************************************/
/*ci \brief RTPS Protocol Version type */
typedef OEI_UINT16 RTPS_ProtocolVersion_T;

/*ci \brief Major version of supported RTPS protocol */
#define RTPS_PROTOCOL_VERSION_MAJOR (0x02)

/*ci \brief Minor version of supported RTPS protocol */
#define RTPS_PROTOCOL_VERSION_MINOR (0x01)  

/*ci \brief RTPS Vendor ID type */
typedef OEI_UINT16 RTPS_VendorId;

/*ci \brief Major version of vendor ID */
#define RTPS_VENDOR_ID_MAJOR (0x01)

/*ci \brief Minor version of vendor ID */
#define RTPS_VENDOR_ID_MINOR (0x0A)

/*ci \brief Connext DDS Vendor ID */
#define RTPS_VENDOR_ID_OEI_DDS (0x0101)

/*ci \brief  Vendor ID */
#define RTPS_VENDOR_ID_OEI_MICRO   (0x010A)

/*ci 
 * \brief Get major number of vendor ID
 *  
 * \param[in] me Vendor ID 
 *  
 * \return Major number of vendor ID 
 */
RTPS_VendorId
RTPS_VendorId_get_major(RTPS_VendorId *me);

/*ci 
 * \brief Get minor number of vendor ID
 *  
 * \param[in] me Vendor ID 
 *  
 * \return Minor number of vendor ID 
 */
RTPS_VendorId
RTPS_VendorId_get_minor(RTPS_VendorId *me);

/*****************************************************************************/
/*ci \brief RTPS Status Info type */
typedef OEI_UINT32 RTPS_StatusInfo;

/*ci \brief Default empty status info */
#define RTPS_NO_STATUS_INFO (0x00000000)

/*ci \brief Dispose status info bit */
#define RTPS_DISPOSE_STATUS_INFO (0x00000001)

/*ci \brief Unregister status info bit */
#define RTPS_UNREGISTER_STATUS_INFO (0X00000002)

/*ci \brief RTPS submessage header endian flag */
#define RTPS_ENDIAN_FLAG (0x01)

/*****************************************************************************/

/*ci \ingroup RTPS_Class
 * \brief Denotes the built-in object types
 *
 * \details
 * RTPSObject is categorized into (normal/reserved) x (user/meta) quadrant.
 * Within each quadrant, there are several built-in (provided for at the RTPS
 *  protocol level) objects, such as application, publication/subscription,
 * CST (keyed) writer/reader.
 */
typedef enum
{
    RTPS_OBJECT_NORMAL_USER_UNKNOWN = 0x00,
    RTPS_OBJECT_NORMAL_USER_APPLICATION = 0x01,
    /*ci \brief Use this suffix for writers of data with a key. */
    RTPS_OBJECT_NORMAL_USER_CST_WRITER = 0x02,
    /*ci \brief Use this suffix for writers of data with no key. */
    RTPS_OBJECT_NORMAL_USER_PUBLICATION = 0x03,
    /*ci \brief Use this suffix for readers of data with no key. */
    RTPS_OBJECT_NORMAL_USER_SUBSCRIPTION = 0x04,
    /*ci \brief Use this suffix for readers of data with a key. */
    RTPS_OBJECT_NORMAL_USER_CST_READER = 0x07,
    RTPS_OBJECT_NORMAL_USER_VIRTUAL_SUBSCRIPTION = 0x3C,
    RTPS_OBJECT_NORMAL_USER_VIRTUAL_CST_READER = 0x3D,
    RTPS_OBJECT_RESERVED_USER_UNKNOWN = 0x40,
    RTPS_OBJECT_RESERVED_USER_APPLICATION = 0x41,
    RTPS_OBJECT_RESERVED_USER_CST_WRITER = 0x42,
    RTPS_OBJECT_RESERVED_USER_PUBLICATION = 0x43,
    RTPS_OBJECT_RESERVED_USER_SUBSCRIPTION = 0x44,
    RTPS_OBJECT_RESERVED_USER_CST_READER = 0x47,
    RTPS_OBJECT_NORMAL_META_UNKNOWN = 0x80,
    RTPS_OBJECT_NORMAL_META_APPLICATION = 0x81,
    RTPS_OBJECT_NORMAL_META_CST_WRITER = 0x82,
    RTPS_OBJECT_NORMAL_META_PUBLICATION = 0x83,
    RTPS_OBJECT_NORMAL_META_SUBSCRIPTION = 0x84,
    RTPS_OBJECT_NORMAL_META_CST_READER = 0x87,
    RTPS_OBJECT_RESERVED_META_UNKNOWN = 0xc0,
    RTPS_OBJECT_RESERVED_META_APPLICATION = 0xc1,
    RTPS_OBJECT_RESERVED_META_CST_WRITER = 0xc2,
    RTPS_OBJECT_RESERVED_META_PUBLICATION = 0xc3,
    RTPS_OBJECT_RESERVED_META_SUBSCRIPTION = 0xc4,
    RTPS_OBJECT_RESERVED_META_CST_READER = 0xc7
} RTPS_ObjectSuffix;


/* ===========================================================================*/
/*                              RTPS types                                    */
/* ===========================================================================*/
/*ci \brief RTPS locator address max length */
#define RTPS_LOCATOR_ADDRESS_LENGTH_MAX 16

/*ci \brief 
 * RTPS locator address offset to UDPv4 address (elements 12-15 of array)
 */
#define RTPS_LOCATOR_ADDRESS_UDPV4_OFFSET 12

/*ci \brief RTPS Locator type */
struct RTPS_Locator_t
{
    /*ci \brief Locator kind */
    OEI_INT32 kind;

    /*ci \brief Locator port */
    OEI_UINT32 port;

    /*ci \brief Locator address */
    OEI_UINT8 address[RTPS_LOCATOR_ADDRESS_LENGTH_MAX];
};

/* ci \brief Default locator kind */
#define RTPS_LOCATOR_DEFAULT_KIND (-1)

/*ci \brief Default locator initializer */
#define RTPS_LOCATOR_DEFAULT {\
    RTPS_LOCATOR_DEFAULT_KIND,        /* kind    */\
    0,                                /* port    */\
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} /* address */\
}

/*ci \brief RTPS Locator type */
#define RTPS_Locator RTPS_Locator_t

/*ci \brief UDPv4 locator type */
struct RTPS_LocatorUdpv4_t
{
    /*ci \brief Locator kind */
    OEI_INT32 kind;

    /*ci \brief Locator port */
    OEI_UINT32 port;

    /*ci \brief Locator address */
    OEI_UINT32 address;
};

/*ci \brief Default UDPv4 locator initializer */
#define RTPS_LOCATOR_UDPV4_DEFAULT {\
    RTPS_LOCATOR_DEFAULT_KIND,        /* kind    */\
    0,                                /* port    */\
    0                                 /* address */\
}

/*ci \brief Invalid Locator */
extern RTPSDllVariable const struct RTPS_Locator_t RTPS_LOCATOR_INVALID;

/*ci \brief Invalid Locator kind */
extern RTPSDllVariable const OEI_INT32 RTPS_LOCATOR_KIND_INVALID;

/*ci \brief Invalid Locator port */
extern RTPSDllVariable const OEI_UINT32 RTPS_LOCATOR_PORT_INVALID;

/*ci \brief Invalid Locator address */
extern RTPSDllVariable const OEI_UINT8
    RTPS_LOCATOR_ADDRESS_INVALID[RTPS_LOCATOR_ADDRESS_LENGTH_MAX];

/*ci \brief UDPv4 Locator kind */
extern RTPSDllVariable const OEI_INT32 RTPS_LOCATOR_KIND_UDPv4;

/*ci \brief UDPv6 Locator kind */
extern RTPSDllVariable const OEI_INT32 RTPS_LOCATOR_KIND_UDPv6;

/*ci \brief Reserved Locator kind */
extern RTPSDllVariable const OEI_INT32 RTPS_LOCATOR_KIND_RESERVED;

/*ci \brief Shared Memory Locator kind */
extern RTPSDllVariable const OEI_INT32 RTPS_LOCATOR_KIND_SHMEM;


/* ===========================================================================*/
/*                           RTPS Sequence Number                             */
/* ===========================================================================*/


/*ci \ingroup RTPS_SequenceNumberClass
 * \brief Deserialize sequence number from stream buffer
 * 
 * \details
 * Post-condition: sequenceNumber is packed and stream pointer is moved forward.
 * 
 * \param[inout] src_buffer Deserialization stream buffer
 * \param[out] instance Deserialized instance
 * \param[in] byte_swap OEI_TRUE if byte swapping is necessary,
 * OEI_FALSE otherwise.
 *
 */
RTPSDllExport void
RTPS_SequenceNumber_deserialize(char **src_buffer,
                                struct REDA_SequenceNumber *instance,
                                OEI_BOOL byte_swap);


/*ci \ingroup RTPS_SequenceNumberClass
 * \brief Calculate the distance between two sequence numbers.
 *
 * \param[in] s1 First sequence number
 * \param[in] s2 Second sequence number
 *
 * \return The distance, possibly saturated to RTPS_BITMAP_DISTANCE_MAX.
 * -1 on failure.
 */
MUST_CHECK_RETURN RTPSDllExport OEI_INT32
RTPS_SequenceNumber_get_distance(
        const struct REDA_SequenceNumber *s1,
        const struct REDA_SequenceNumber *s2);

/*ci \brief Bitmap array max size 
 * \details Bitmap has maximum 256 bits, using (256/32 =) 8 ints 
 */
#define RTPS_BITMAP_32BITS_ARRAY_SIZE_MAX (8)       

/*ci 
 * \brief Bitmap of sequence numbers received 
 *  
 * \details 
 * Tracks sequence numbers of samples sent or received.  Used in send and 
 * window implementations. 
 */
struct RTPS_Bitmap
{
    /*ci \brief Starting sequence number of bitmap */
    struct REDA_SequenceNumber lead;

    /*ci \brief Number of valid bits or sequence numbers, starting from lead */
    OEI_INT32 bit_count;

    /*ci \brief The bitmap stored as an array of integers.
     *  
     * \details 
     * Maximum of 256 (=8*32) bits or sequence numbers. 
     * This must be unsigned in order to apply the >> operator.
     * There are two approaches to handle bits outside bitCount:
     * 1) They must always be zeroed.
     * 2) They can be anything.
     * The first approach puts the burden on otherwise simple
     * methods such as truncate to zero out truncated bits, whereas
     * the second approach puts the burden on methods such as shift
     * to make sure bits beyond the bitCount are not shifted in.
     * In our implementation, we have opted for the second approach. 
     */ 
    OEI_UINT32 bits[RTPS_BITMAP_32BITS_ARRAY_SIZE_MAX];
};

/*ci \brief Maximum number of bits in bitmap */
#define RTPS_BITMAP_SIZE_MAX              (256)

/*ci \brief Maximum bitmap sequence number distance */
#define RTPS_BITMAP_DISTANCE_MAX          (0x7FFFFFFF)

/*ci \brief Reset bitmap to specified lead and bitCount 
 *
 * \details Post condition: bitmap has its lead and bit count assigned, and
 * all bits are reset to zero.
 *
 * \param[in] me Bitmap
 * \param[in] sn New lead sequence number
 * \param[in] bit_count New bit count. Must be <= RTPS_BITMAP_SIZE_MAX.
 * 
 */
RTPSDllExport void
RTPS_Bitmap_reset(
        struct RTPS_Bitmap *me,
        const struct REDA_SequenceNumber *sn,
        OEI_INT32 bit_count);

/*ci \ingroup RTPS_BitmapClass
 * \brief Set specified bit in bitmap.
 *
 * \details
 * The bit corresponding to the input sequence number is set to either
 * 0 or 1 as specified in input param.
 *
 * \param[in] me Bitmap
 * \param[out] existed OEI_TRUE if bit is already set, OEI_FALSE otherwise.
 * \param[in] num The sequence number of interest.
 * \param[in] bit OEI_TRUE if bit is to be turned on, OEI_FALSE otherwise.
 *
 * \return OEI_FALSE on failure, which includes the sequence not in bitmap.
 * OEI_TRUE on success.
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_Bitmap_set_bit(struct RTPS_Bitmap *me,
                    OEI_BOOL *existed,
                    const struct REDA_SequenceNumber *num,
                    OEI_BOOL bit);

/*ci \ingroup RTPS_BitmapClass
 * \brief Get specified bit in bitmap.
 *
 * \details
 * The bit corresponding to the input sequence number is set to either
 * 0 or 1 as specified in input param.
 *
 * \param[in] me Bitmap
 * \param[in] bit Pointer to the answer, whose value will be OEI_TRUE
  if bit is on and OEI_FALSE otherwise.
 * \param[in] num The sequence number of interest.
 *
 * \return OEI_FALSE on failure, which includes the sequence not in bitmap.
 * OEI_TRUE on success.
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_Bitmap_get_bit(
        const struct RTPS_Bitmap *me,
        OEI_BOOL *bit,
        const struct REDA_SequenceNumber *num);

/*ci
 * \brief
 * Get the sequence number of the first bit in bitmap that matches the input 
 * value 
 * 
 * \param[in] me Bitmap
 * \param[out] position Sequence number of first bit matching searchBit.  If 
 * no match found, position is one greater than last valid bit of bitmap. 
 * \param[in] search_bit Value of bit for which to search 
 * 
 * \return OEI_TRUE on successfully finding matching bit, OEI_FALSE on failure
 */
SHOULD_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_Bitmap_get_first_bit(
        const struct RTPS_Bitmap *me,
        struct REDA_SequenceNumber *position,
        OEI_BOOL search_bit);

/*ci
 * \brief
 * Get the sequence number of the last bit in bitmap that matches the input 
 * value 
 * 
 * \param[in] me Bitmap
 * \param[out] position Sequence number of last bit matching searchBit.  If 
 * no match found, position is zero. 
 * \param[in] search_bit Value of bit for which to search 
 * 
 * \return OEI_TRUE on successfully finding matching bit, OEI_FALSE on failure
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_Bitmap_get_last_bit(
        const struct RTPS_Bitmap *me,
        struct REDA_SequenceNumber *position,
        OEI_BOOL search_bit);

/*ci
 * \brief
 * Fill a range of bits in bitmap with specified value
 * 
 * \param[in] me Bitmap
 * \param[in] first_seq_num  First sequence number in range to fill
 * \param[in] last_seq_num Last sequence number in range to fill 
 * \param[in] bit Value to set bits in range 
 * 
 * \return OEI_TRUE on success, OEI_FALSE on failure
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_Bitmap_fill(
        struct RTPS_Bitmap *me,
        const struct REDA_SequenceNumber *first_seq_num,
        const struct REDA_SequenceNumber *last_seq_num,
        OEI_BOOL bit);


/*ci
 * \brief
 * Merge another bitmap with self bitmap 
 *  
 * \details 
 * Copies '1' bits from source bitmap whose sequence numbers overlap with self 
 * bitmap.  Bitcount and lead SN of self bitmap are preserved. 
 * 
 * \param[in] me Self bitmap
 * \param[in] source Bitmap to merge with self
 * 
 */
RTPSDllExport void
RTPS_Bitmap_merge(
        struct RTPS_Bitmap *me,
        const struct RTPS_Bitmap *source);

/*ci
 * \brief
 * Shift lead sequence number of bitmap to new value
 *  
 * \details 
 * Preserves bitcount of bitmap, setting new shifted-in bits to zero.
 * 
 * \param[in] me Self bitmap
 * \param[in] seq_num New lead sequence number
 * 
 * \return OEI_TRUE on success, OEI_FALSE on failure
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_Bitmap_shift(
        struct RTPS_Bitmap *me,
        const struct REDA_SequenceNumber *seq_num);

/*ci
 * \brief
 * Truncates bitmap to end at specified sequence number
 *  
 * \details 
 * Updates bitcount of bitmap to reflect number of valid bits up to truncated 
 * sequence number.  If truncation sequence number is greater than current last 
 * sequence number of bitmap, no truncation is done and bitcount stays the same.
 * 
 * \param[in] me Self bitmap
 * \param[in] seq_num Sequence number after which bitmap is truncated. 
 * 
 */
RTPSDllExport void
RTPS_Bitmap_truncate(
        struct RTPS_Bitmap *me,
        const struct REDA_SequenceNumber *seq_num);

/*ci
 * \brief
 * Toggle bits of bitmap 
 *  
 * \details 
 * Change '1' to '0' and vice versa. 
 *  
 * \param[inout] me Self bitmap
 * 
 */
RTPSDllExport void
RTPS_Bitmap_invert(struct RTPS_Bitmap *me);

/*ci
 * \brief
 * Deserialize from buffer a bitmap 
 *  
 * \details 
 * Change '1' to '0' and vice versa. 
 *  
 * \param[in] me Self bitmap 
 * \param[in] stream_ptr Pointer to serialized buffer 
 * \param[in] max_bits_len Remaining space of submessage to deserialize 
 * the variable length bits of bitmap 
 * \param[in] need_byte_swap Flag whether byte swap is necessary for 
 * deserialization 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 * 
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_Bitmap_deserialize(
        struct RTPS_Bitmap *me,
        const char **stream_ptr,
        OEI_UINT32 max_bits_len,
        OEI_BOOL need_byte_swap);

/******************************************************************************/
/*ci
 * \brief
 * Serialize GUID to stream buffer 
 *  
 * \param[inout] stream Serialization stream 
 * \param[in] guid GUID to serialize 
 * \param[in] param Unused
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_Guid_serialize(
    struct CDR_Stream_t *stream,
    const struct RTPS_Guid *guid,
    void * param);

/*ci
 * \brief
 * Deserialize GUID from stream buffer 
 *  
 * \param[in] stream Deserialization stream 
 * \param[inout] guid Deserialized GUID 
 * \param[in] param Unused
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_Guid_deserialize(
    struct CDR_Stream_t *stream,
    struct RTPS_Guid *guid,
    void * param);

/*ci
 * \brief
 * Length in bytes of serialized GUID
 *  
 * \param[in] size Current length of serialized buffer
 *  
 * \return Number of bytes of serialized GUID
 */
MUST_CHECK_RETURN RTPSDllExport OEI_UINT32
RTPS_Guid_get_max_size_serialized(OEI_UINT32 size);

/* -------------------------------------------------------------------------- */
/*ci
 * \brief
 * Serialize NTP time to stream buffer 
 *  
 * \param[inout] stream Serialization stream 
 * \param[in] time NTP time to serialize 
 * \param[in] param Unused
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_serialize_ntp_time(
    struct CDR_Stream_t *stream,
    const OSAPI_NtpTime *time,
    void * param);

/*ci
 * \brief
 * Deserialize NTP time from stream buffer 
 *  
 * \param[in] stream Deserialization stream 
 * \param[inout] time Deserialized NTP time 
 * \param[in] param Unused
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_deserialize_ntp_time(
    struct CDR_Stream_t *stream,
    OSAPI_NtpTime *time,
    void * param);

/*ci
 * \brief
 * Length in bytes of serialized NTP time
 *  
 * \param[in] size Current length of serialized buffer
 *  
 * \return Number of bytes of serialized NTP time
 */
MUST_CHECK_RETURN RTPSDllExport OEI_UINT32
RTPS_get_ntp_time_max_size_serialized(OEI_UINT32 size);

/* -------------------------------------------------------------------------- */
/*ci
 * \brief
 * Serialize unsigned short to stream buffer 
 *  
 * \param[inout] stream Serialization stream 
 * \param[in] in Value to serialize 
 * \param[in] param Unused
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_serialize_2_octets(
    struct CDR_Stream_t *stream,
    const OEI_UINT16 * in,
    void * param);

/*ci
 * \brief
 * Deserialize unsigned short from stream buffer 
 *  
 * \param[in] stream Deserialization stream 
 * \param[inout] out Deserialized value 
 * \param[in] param Unused
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_deserialize_2_octets(
    struct CDR_Stream_t *stream,
    OEI_UINT16 *out,
    void * param);

/*ci
 * \brief
 * Length in bytes of serialized unsigned short
 *  
 * \param[in] size Current length of serialized buffer
 *  
 * \return Number of bytes of serialized unsigned short
 */
MUST_CHECK_RETURN RTPSDllExport OEI_UINT32
RTPS_get_2_octets_max_size_serialized(OEI_UINT32 size);

/* -------------------------------------------------------------------------- */
/*ci
 * \brief
 * Serialize locator to stream buffer 
 *  
 * \param[inout] stream Serialization stream 
 * \param[in] loc Locator to serialize 
 * \param[in] param Unused
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_serialize_ipv6_locator(
    struct CDR_Stream_t *stream,
    const struct RTPS_Locator_t *loc,
    void * param);

/*ci
 * \brief
 * Deserialize locator from stream buffer 
 *  
 * \param[in] stream Deserialization stream 
 * \param[inout] loc Deserialized locator 
 * \param[in] param Unused
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN RTPSDllExport OEI_BOOL
RTPS_deserialize_ipv6_locator(
    struct CDR_Stream_t *stream,
    struct RTPS_Locator_t *loc,
    void * param);

/*ci
 * \brief
 * Length in bytes of serialized locator
 *  
 * \param[in] size Current length of serialized buffer
 *  
 * \return Number of bytes of serialized locator
 */
MUST_CHECK_RETURN RTPSDllExport OEI_UINT32
RTPS_get_ipv6_locator_max_size_serialized(OEI_UINT32 size);

/* -------------------------------------------------------------------------- */
/*ci \brief Deserialize epoch from stream buffer 
 *
 * \param[inout] me Deserialized epoch
 * \param[in] stream Deserialization stream
 * \param[in] need_byte_swap Flags whether to byte swap byte order on
 * deserialization
 * 
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
RTPSDllExport void
RTPS_Epoch_deserialize(REDA_Epoch_T * me,
                       const char **stream,
                       OEI_BOOL need_byte_swap);


/*ci \brief RTPS GUID type */
typedef struct NETIO_Guid RTPS_GUID; 

/*ci \brief RTPS GuidPrefix type */
typedef struct NETIO_GuidPrefix RTPS_GuidPrefix_T;

/*ci \brief RTPS Entity type */
typedef struct NETIO_GuidEntity RTPS_Entity_T;

/*ci \brief Default unknown GUID prefix initializer */
#define RTPS_GUIDPREFIX_UNKNOWN {{0,0,0,0,0,0,0,0,0,0,0,0}}

/*ci \brief Default unknown Entity ID initializer */
#define RTPS_ENTITY_UNKNOWN {{0,0,0,0}}

/* -------------------------------------------------------------------------- */
/*ci \brief RTPS Timestamp type */
struct RTPS_Time 
{
    /*ci \brief Seconds */
    OEI_INT32 seconds;

    /*ci \brief Fractional part */
    OEI_UINT32 fractions;
};

/*ci \brief RTPS Vendor ID type */
struct RTPS_Vendor 
{
    /*ci \brief Vendor ID value */
    OEI_UINT8 value[2];
};

/*ci \brief RTPS Protocol Version type */
struct RTPS_ProtocolVersion 
{
    /*ci \brief Major */
    OEI_UINT8 major;

    /*ci \brief Minor */
    OEI_UINT8 minor;
};

/*ci \brief RTPS message header 
 * \details 
 * Fields are ordered exactly as defined by RTPS specification 
 */
struct RTPS_Header 
{
    /*ci \brief 'R''T''P''S' protocol identifier */
    OEI_UINT32 rtps;

    /*ci \brief Protocol version */
    struct RTPS_ProtocolVersion protocol_version;

    /*ci \brief Vendor ID */
    struct RTPS_Vendor vendor_id;

    /*ci \brief Sender's GUID Prefix*/
    RTPS_GuidPrefix_T guid_prefix;
};

/*ci \brief RTPS message header's RTPS identifier, in host order */
#ifdef OEI_ENDIAN_LITTLE
#define VALID_RTPS_HEADER 0x53505452    /* RTPS backwards */
#else
#define VALID_RTPS_HEADER 0x52545053    /* RTPS in big endian */
#endif /* OEI_ENDIAN_LITTLE */

/******************************************************************************/

/* RTPS Submessage IDs */
/*ci \brief PAD submessage ID */
#define RTPS_PAD_KIND            (0x01)

/*ci \brief ACKNACK submessage ID */
#define RTPS_ACKNACK_KIND        (0x06)

/*ci \brief HEARTBEAT submessage ID */
#define RTPS_HEARTBEAT_KIND      (0x07)

/*ci \brief GAP submessage ID */
#define RTPS_GAP_KIND            (0x08)

/*ci \brief INFO_TS submessage ID */
#define RTPS_INFO_TS_KIND        (0x09)

/*ci \brief INFO_SRC submessage ID */
#define RTPS_INFO_SRC_KIND       (0x0c)

/*ci \brief INFO_REPLY_IP4 submessage ID */
#define RTPS_INFO_REPLY_IP4_KIND (0x0d)

/*ci \brief INFO_DST submessage ID */
#define RTPS_INFO_DST_KIND       (0x0e)

/*ci \brief INFO_REPLY submessage ID */
#define RTPS_INFO_REPLY_KIND     (0x0f)

/*ci \brief DATA submessage ID */
#define RTPS_DATA_KIND           (0x15)


#define RTPS_LARGEST_SUBMSG_KIND    RTPS_DATA_KIND

/*ci \brief Length of RTPS submessage header */
#define RTPS_SUBMESSAGE_HEADER_LENGTH   4



/*ci \brief RTPS submessage header 
 * 
 * \details 
 * Fields ordered exactly as defined by RTPS specification 
  */
struct RTPS_SubmsgHdr
{
    /*ci \brief Submessage kind ID */
    OEI_UINT8 kind;

    /*ci \brief Submessage flags */
    OEI_UINT8 flags;

    /*ci \brief Submessage length */
    OEI_UINT16 length;
};

/*ci \brief Submessage little endianness flag */
#define RTPS_SUBMSG_FLAG_E 0x1

/******************************************************************************/
/*ci \brief ACKNACK submessage, over-the-wire layout */
struct RTPS_ACKNACK 
{
    /*ci \brief Submesage header */
    struct RTPS_SubmsgHdr hdr;

    /*ci \brief Source reader's entity ID */
    RTPS_Entity_T reader;

    /*ci \brief Destination writer's entity ID */
    RTPS_Entity_T writer;

    /*ci \brief Bitmap (variable length) */
    struct RTPS_Bitmap bitmap;

    /*ci \brief Epoch count */
    OEI_UINT32 count;
};

/*ci \brief ACKNACK Final flag */
#define RTPS_ACKNACKFLAGS_F 0x2

/******************************************************************************/
/*ci \brief RTPS DATA submessage 
 * 
 * \details 
 * Fixed length fields declared in type.  Variable length fields (inline QoS, 
 * DATA payload) accounted for later when setting DATA submessage. 
  */
struct RTPS_DATA 
{
    /*ci \brief Submessage header */
    struct RTPS_SubmsgHdr hdr;

    /*ci \brief Submessage flags */
    OEI_UINT16 flags;

    /*ci \brief Inline Qos offset */
    OEI_UINT16 qos_offset;

    /*ci \brief Destination reader entity ID */
    RTPS_Entity_T reader;

    /*ci \brief Source writer entity ID */
    RTPS_Entity_T writer;

    /*ci \brief Sequence number */
    struct REDA_SequenceNumber sn; 
};

/*ci \brief Default empty DATA submessage flag */
#define RTPS_FLAGS_NONE  0x0

/*ci \brief Inline Qos Q-flag for DATA submessage */
#define RTPS_DATAFLAGS_Q 0x2

/*ci \brief Data D-flag for DATA submessage */
#define RTPS_DATAFLAGS_D 0x4

/*ci \brief Data K-flag for DATA submessage */
#define RTPS_DATAFLAGS_K 0x8

/*ci \brief Default Inline Qos offset */
#define RTPS_DATA_INLINEQOS_OFFSET 16

/******************************************************************************/
/*ci \brief GAP submessage */
struct RTPS_GAP 
{
    /*ci \brief Submessage header */
    struct RTPS_SubmsgHdr hdr;

    /*ci \brief Destination reader entity ID */
    RTPS_Entity_T reader;

    /*ci \brief Source writer entity ID */
    RTPS_Entity_T writer;

    /*ci \brief Sequence number of start of GAP */
    struct REDA_SequenceNumber sn_start;

    /*ci \brief Bitmap */
    struct RTPS_Bitmap bitmap; /* variable length */
};

/******************************************************************************/
/*ci \brief HEARTBEAT submessage */
struct RTPS_HEARTBEAT 
{
    /*ci \brief Submessage header */
    struct RTPS_SubmsgHdr hdr;

    /*ci \brief Destination reader entity ID */
    RTPS_Entity_T reader;

    /*ci \brief Source writer entity ID */
    RTPS_Entity_T writer;

    /*ci \brief First sequence number */
    struct REDA_SequenceNumber sn_first;
    
    /*ci \brief Last sequence number */ 
    struct REDA_SequenceNumber sn_last; 

    /*ci \brief Epoch count */
    OEI_INT32 count;
};

/*ci \brief Final HEARTBEAT submesasge flag */
#define RTPS_HBFLAGS_F 0x02

/*ci \brief Liveliness HEARTBEAT submessage flag */
#define RTPS_HBFLAGS_L 0x04

/******************************************************************************/
/*ci \brief INFO_DST submessage */
struct RTPS_INFO_DST 
{
    /*ci \brief Submessage header */
    struct RTPS_SubmsgHdr hdr;

    /*ci \brief Destination GUID prefix */
    RTPS_GuidPrefix_T guid_prefix;
};

/******************************************************************************/
/*ci \brief INFO_TS submessage */
struct RTPS_INFO_TS 
{
    /*ci \brief Submessage header */
    struct RTPS_SubmsgHdr hdr;

    /*ci \brief Source timestamp */
    struct RTPS_Time timestamp;
};

/*ci \brief Invalid Timestamp INFO_TS flag */
#define RTPS_INFO_TSFLAGS_I (0x2)

/******************************************************************************/
/*ci \brief RTPS headers and submessages 
 * 
 * \details 
 * Used to typecast serialized/deserialized stream buffer 
 */
union RTPS_MESSAGES
{
    /*ci \brief Submessage header */
    struct RTPS_SubmsgHdr submsg;

    /*ci \brief Message header */
    struct RTPS_Header header;

    /*ci \brief DATA submessage */
    struct RTPS_DATA data;

    /*ci \brief GAP submessage */
    struct RTPS_GAP gap;

    /*ci \brief HEARTBEAT submessage */
    struct RTPS_HEARTBEAT hb;

    /*ci \brief ACKNACK submessage */
    struct RTPS_ACKNACK acknack;
  
    /*ci \brief INFO_TS submessage */
    struct RTPS_INFO_TS info_ts;

    /*ci \brief INFO_DST submessage */
    struct RTPS_INFO_DST info_dst;
};

/******************************************************************************/
/*ci \brief RTPS interface mode */
typedef enum
{
    /*ci \brief Default undefined mode */
    RTPS_INTERFACEMODE_UNDEFINED,

    /*ci \brief Writer mode */
    RTPS_INTERFACEMODE_WRITER,

    /*ci \brief Reader mode */
    RTPS_INTERFACEMODE_READER,

    /*ci \brief External receiver mode */
    RTPS_INTERFACEMODE_EXTERNAL_RECEIVER
} RTPS_InterfaceMode_t;

/*ci \brief RTPS interface property */
struct RTPS_InterfaceProperty
{
    /*ci \brief Base NETIO interface property */
    struct NETIO_InterfaceProperty _parent;

    /*ci \brief RTPS interface mode */
    RTPS_InterfaceMode_t mode;

    /*ci \brief RTPS interface GUID address */
    struct NETIO_Address intf_address;

    /*ci \brief Maximum number of peers */
    OEI_INT32 max_peer_count;

    /*ci \brief OEI_TRUE for reliable writer or reader */
    OEI_BOOL reliable;

    /*ci \brief OEI_TRUE for anonymous writer or reader */
    OEI_BOOL anonymous;

    /*ci \brief HEARTBEAT period for reliable writer */
    struct OSAPI_NtpTime hb_period; 

    /*ci \brief Piggyback HEARTBEAT rate for reliable writer 
     * 
     * \details 
     * A HEARTBEAT submessage is appended to every Nth new DATA submessage 
     * sent, where N is sample_per_hb. 
      */
    OEI_SIZE_T samples_per_hb;

    /*ci \brief Maximum window size for writer or reader */
    OEI_UINT32 max_window_size;

    /*ci \brief Maximum HEARTBEAT retries for reliable writer 
     * 
     * \details 
     * A peer reader must respond to a reliable writer's HEARTBEATs to be 
     * considered active. If N periodic HEARTBEATs have been sent without 
     * reciving an ACKNACK, where N is maxhb_retries, the peer reader is 
     * then considered inactive and will stay inactive until an ACKNACK is 
     * received.
     */
    OEI_INT32 max_hb_retries;

    /*ci \brief Maximum number of samples of upstream interface */
    OEI_INT32 max_samples;
#if OSAPI_ENABLE_TRACE
    const char *session_name;
#endif
};

#if OSAPI_ENABLE_TRACE
#define RTPS_SESSION_NAME_INIT ,NULL
#else
#define RTPS_SESSION_NAME_INIT
#endif

/*ci \brief Unlimited max HEARTBEAT retries */
#define RTPS_RETRIES_UNLIMITED (-1)

/*ci \brief Maximum receive window size */
#define RTPS_RECEIVE_WINDOW_MAX_SIZE (256)

/*ci \brief Default RTPS interface property initializer */
#define RTPS_InterfaceProperty_INITIALIZER \
{\
    NETIO_InterfaceProperty_INITIALIZER,\
    RTPS_INTERFACEMODE_UNDEFINED,\
    NETIO_Address_INITIALIZER, \
    4, /* max_peer_count */ \
    OEI_FALSE, /* reliable */ \
    OEI_FALSE, /* anonymous */ \
    {3,0}, /* hb_period */ \
    8, /* samples_per_hb */ \
    256, /* window_size */ \
    RTPS_RETRIES_UNLIMITED, /* max_hb_retries */\
    256 /* max_samples */ \
    RTPS_SESSION_NAME_INIT \
}

/*ci \brief Property for an RTPS route */
struct RTPS_RouteProperty 
{
    /*ci \brief Base NETIO route property */
    struct NETIORouteProperty _parent; 

    /*ci \brief Reliable flag of peer reachable over route */
    OEI_BOOL reliable;

    /*ci \brief First sequence number of upstream interface creating the 
     *   route
     */
    struct REDA_SequenceNumber first_sn;

    /*ci \brief Last sequence number of upstream interface creating the 
     *   route
     */
    struct REDA_SequenceNumber last_sn;

    /*ci \brief Last acknowledged sequence number of upstream interface 
     *   creating the route
     */
    struct REDA_SequenceNumber last_acked_sn;
};

/*ci \brief Default RTPS route property initializer */
#define RTPSRouteProperty_INITIALIZER \
{\
    NETIORouteProperty_INITIALIZER, \
    OEI_FALSE, /* reliable */ \
    REDA_SEQUENCE_NUMBER_ZERO,\
    REDA_SEQUENCE_NUMBER_ZERO, \
    REDA_SEQUENCE_NUMBER_ZERO \
}

/*ci \brief Get RTPS inteface factory 
 * \return Pointer to RTPS interface factory
 */
MUST_CHECK_RETURN RTPSDllExport struct RT_ComponentFactoryI*
RTPS_InterfaceFactory_get_interface(void);

#ifdef __cplusplus
}                               /* extern "C" */
#endif

#include "rtps/rtps_rtps_impl.h"

#endif /* rtps_rtps_h */
