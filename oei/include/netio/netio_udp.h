/*
 * FILE: netio_udp.h - UDP API
 *
 */
/*ci
 * \file
 * \defgroup NETIO_UDPInterfaceClass UDP Interface
 * \ingroup NETIOModule
 * \brief NETIO UDP Interface
 *
 * \details
 *
 * The UDP interface is implemented as a NETIO interface and NETIO interface
 * factory.
 */
/*ci \addtogroup NETIO_UDPInterfaceClass
 * @{
 */
#ifndef netio_udp_h
#define netio_udp_h

#ifndef OEI_EXPORT_REDA_SEQUENCE
#define OEI_EXPORT_REDA_SEQUENCE
#endif

#ifndef osapi_config_h
#include "osapi/osapi_config.h"
#endif
#ifndef osapi_thread_h
#include "osapi/osapi_thread.h"
#endif
#ifndef rt_rt_h
#include "rt/rt_rt.h"
#endif
#ifndef reda_string_h
#include "reda/reda_string.h"
#endif
#ifndef reda_sequence_h
#include "reda/reda_sequence.h"
#endif
#ifndef netio_dll_h
#include "netio/netio_dll.h"
#endif
#ifndef netio_config_h
#include "netio/netio_config.h"
#endif
#ifndef netio_address_h
#include "netio/netio_address.h"
#endif
#ifndef netio_route_h
#include "netio/netio_route.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef OEI_CERT
struct UDP_NatEntry
{
    struct NETIO_Address local_address;
    struct NETIO_Address public_address;
};

#define UDP_NatEntry_INITIALIZER \
{\
    NETIO_Address_INITIALIZER,\
    NETIO_Address_INITIALIZER,\
}

#define T struct UDP_NatEntry
#define TSeq UDP_NatEntrySeq
#include <reda/reda_sequence_decl.h>

#define UDP_NatEntrySeq_INITIALIZER \
                        REDA_DEFINE_SEQUENCE_INITIALIZER(struct UDP_NatEntry)

#define UDP_NAT_INITIALIZER UDP_NatEntrySeq_INITIALIZER,

#else /* !OEI_CERT */
#define UDP_NAT_INITIALIZER
#endif

/*ci
 * \def UDP_INTERFACE_MAX_IFNAME
 * \brief Maximum length of a UDP network interface
 */
#define UDP_INTERFACE_MAX_IFNAME 64

/*ci
 * \def UDP_INTERFACE_INTERFACE_UP_FLAG
 * \brief Generic flag to indicate if a network stack is up
 */
#define UDP_INTERFACE_INTERFACE_UP_FLAG        0x1

/*ci
 * \def UDP_INTERFACE_INTERFACE_MULTICAST_FLAG
 * \brief Generic flag to indicate if a network stack supports multicast
 */
#define UDP_INTERFACE_INTERFACE_MULTICAST_FLAG 0x2

/*ci
 * \brief The maximum number of bits in a UDP netmask
 */
#define UDP_INTERFACE_MAX_NETMASK_BITS (32)

/*ci
 * \brief Generic structure to describe a network interface
 */
struct DDSCPPDllExport UDP_InterfaceTableEntry
{
    /*ci
     * \brief Flags to indicate if the interface is up etc.
     */
    OEI_UINT32 flags;

    /*ci
     * \brief The address of the interface as configured by the OS
     */
    OEI_UINT32 address;

    /*ci
     * \brief The netmask of the interface as configured by the OS
     */
    OEI_UINT32 netmask;

    /*ci
     * \brief The name of the interface as configured by the OS
     */
    char ifname[UDP_INTERFACE_MAX_IFNAME];
};

/*ci
 * \def UDP_InterfaceTableEntry_INITIALIZER
 * \brief Constant to initialize \ref UDP_InterfaceTableEntry
 */
#define UDP_InterfaceTableEntry_INITIALIZER \
{\
    0,\
    0,\
    0,\
    {0}\
}

#define T struct UDP_InterfaceTableEntry
#define TSeq UDP_InterfaceTableEntrySeq
#include <reda/reda_sequence_decl.h>

#define UDP_InterfaceTableEntrySeq_INITIALIZER \
               REDA_DEFINE_SEQUENCE_INITIALIZER(struct UDP_InterfaceTableEntry)

/*e \dref_UDP_InterfaceTable_add_entry
 */
MUST_CHECK_RETURN NETIODllExport OEI_BOOL
UDP_InterfaceTable_add_entry(struct UDP_InterfaceTableEntrySeq *seq,
                             OEI_UINT32 address,
                             OEI_UINT32 netmask,
                             const char *ifname,
                             OEI_UINT32 flags);

#ifdef __cplusplus
}                               /* extern "C" */
#endif

#ifdef __cplusplus
extern "C" 
{
#endif

struct UDP_InterfaceFactoryProperty;
NETIODllExport OEI_BOOL
UDP_InterfaceFactoryProperty_initialize(
            struct UDP_InterfaceFactoryProperty* self);

#ifndef OEI_CERT
NETIODllExport OEI_BOOL
UDP_InterfaceFactoryProperty_finalize(
        struct UDP_InterfaceFactoryProperty *p);
#endif /* !OEI_CERT */

#ifdef __cplusplus
}
#endif

/*ce \dref_UDP_InterfaceFactoryProperty
 * \brief Properties the UDP interface can be registered with.
 */
struct DDSCPPDllExport UDP_InterfaceFactoryProperty
{
    /*ci
     * \brief Inherited property struct
     */
    struct NETIO_InterfaceFactoryProperty _parent;

    /*ce \dref_UDP_InterfaceFactoryProperty_allow_interface
     * \brief Sequence of allowed interface names
     */
    struct REDA_StringSeq allow_interface;

    /*ce \dref_UDP_InterfaceFactoryProperty_deny_interface
     * \brief Sequence of denied interface names. This list is checked
     *        after the allow_interface list.
     */
    struct REDA_StringSeq deny_interface;

    /*ce \dref_UDP_InterfaceFactoryProperty_max_send_buffer_size
     * \brief The size of the send socket buffer
     */
    OEI_INT32 max_send_buffer_size;

    /*ce \dref_UDP_InterfaceFactoryProperty_max_receive_buffer_size
     * \brief The size of the receive socket buffer
     */
    OEI_INT32 max_receive_buffer_size;
    
    /*ce \dref_UDP_InterfaceFactoryProperty_max_message_size
     * \brief The maximum size of the message which can be received
     */
    OEI_INT32 max_message_size;

    /*ce \dref_UDP_InterfaceFactoryProperty_multicast_ttl
     * \brief The maximum TTL
     */
    OEI_INT32 multicast_ttl;

#ifndef OEI_CERT
    /*ce \dref_UDP_InterfaceFactoryProperty_nat
     */
    struct UDP_NatEntrySeq nat;
#endif /* !OEI_CERT */

    /*ce \dref_UDP_InterfaceFactoryProperty_if_table
     * \brief The interface table if interfaces are added manually
     */
    struct UDP_InterfaceTableEntrySeq if_table;

    /*ce \dref_UDP_InterfaceFactoryProperty_multicast_interface
     * \brief The network interface to use to send to multicast
     */
    REDA_String_T multicast_interface;

    /*ce \dref_UDP_InterfaceFactoryProperty_is_default_interface
     * \brief If this should be considered the default UDP interfaces if
     *        no other UDP interface is found to handle a route
     */
    OEI_BOOL is_default_interface;

    /*ce \dref_UDP_InterfaceFactoryProperty_disable_auto_interface_config
     * \brief Disable reading of available network interfaces using system
     *        information and instead rely on the manually configured
     *        interface table
     */
    OEI_BOOL disable_auto_interface_config;

    /*ce \dref_UDP_InterfaceFactoryProperty_recv_thread
     * \brief Thread properties for each receive thread created by this
     *        NETIO interface.
     */
    struct OSAPI_ThreadProperty recv_thread;

#ifdef OEI_CPP
     public:
        UDP_InterfaceFactoryProperty()
        {
            UDP_InterfaceFactoryProperty_initialize(this);
        }
#endif
};

#ifdef __cplusplus
extern "C"
{
#endif

/*ci
 * \def UDP_InterfaceFactoryProperty_INITIALIZER
 * \brief Constant to initialize UDP_InterfaceFactoryProperty
 *
 * NOTE: Do not add a comma (,) after UDP_NAT_INITIALIZER, it is
 * part of the definition based on the OEI_CERT definition.
 */
#define UDP_InterfaceFactoryProperty_INITIALIZER \
{\
    NETIO_InterfaceFactoryProperty_INITIALIZER,\
    REDA_StringSeq_INITIALIZER,\
    REDA_StringSeq_INITIALIZER,\
    (256*1024),\
    (256*1024),\
    (8*1024),\
    1,\
    UDP_NAT_INITIALIZER \
    UDP_InterfaceTableEntrySeq_INITIALIZER,\
    NULL,\
    OEI_TRUE,\
    OEI_FALSE, \
    OSAPI_THREAD_PROPERTY_DEFAULT \
}

#define UDP_INTERFACE_INTERFACE_ID RT_MKINTERFACEID(\
            RT_COMPONENT_CLASS_NETIO,RT_COMPONENT_INSTANCE_UDP)

extern NETIODllVariable struct UDP_InterfaceFactoryProperty UDP_INTERFACE_FACTORY_PROPERTY_DEFAULT;

/*ce \dref_UDP_InterfaceFactory_get_interface
 */
MUST_CHECK_RETURN NETIODllExport struct RT_ComponentFactoryI*
UDP_InterfaceFactory_get_interface(void);

#ifdef __cplusplus
}                               /* extern "C" */
#endif

#undef OEI_EXPORT_REDA_SEQUENCE

#endif /* netio_udp_h */

/*ci @} */

