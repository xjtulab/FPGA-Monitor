/*
 * FILE: netio_rtps.h - RTPS API
 *
 */
/*ce
 * \file
 * \brief RTPS API
 */
/*ci \addtogroup NETIOUtility
 * @{
 */
#ifndef netio_rtps_h
#define netio_rtps_h

#ifndef osapi_types_h
#include "osapi/osapi_types.h"
#endif
#ifndef reda_epoch_h
#include "reda/reda_epoch.h"
#endif
#ifndef osapi_time_h
#include "osapi/osapi_time.h"
#endif
#ifndef osapi_system_h
#include "osapi/osapi_system.h"
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

/*ci
 * \brief Parameters used by RTPS port resolvers
 */
struct NETIO_RtpsPortParam
{
    /*ci
     * \brief The base port for the port calculation, typically 7400
     */
    OEI_INT32 port_base;

    /*ci
     * \brief Number of ports are reserved for a domain
     */
    OEI_INT32 domain_id_gain;

    /*ci
     * \brief Number of ports are reserved for a participant
     */
    OEI_INT32 participant_id_gain;

    /*ci
     * \brief The port offset for meta-traffic multicast addresses
     */
    OEI_INT32 builtin_multicast_port_offset;

    /*ci
     * \brief The port offset for meta-traffic unicast addresses
     */
    OEI_INT32 builtin_unicast_port_offset;

    /*ci
     * \brief The port offset for user-traffic multicast addresses
     */
    OEI_INT32 user_multicast_port_offset;

    /*ci
     * \brief The port offset for user-traffic unicast addresses
     */
    OEI_INT32 user_unicast_port_offset;
};

/*ci
 * \brief Structure passed to RTPS port resolvers
 */
struct NETIO_RtpsPortData
{
    /*e \dref_RtpsWellKnownPorts_t_domain_id
     */
    OEI_INT32 domain_id;

    /*e \dref_RtpsWellKnownPorts_t_port_param
     */
    struct NETIO_RtpsPortParam port_param;

    /*ci
     * \brief The maximum allowed participant_id/index
     */
    OEI_INT32 max_participant_id;
};

/*ci
 * \brief Calculate RTPS port numbers
 *
 * \details
 *
 * This function is typically registered with NETIO address resolvers top
 * calculate port numbers for address strings passed in as strings.
 *
 * \param[in]  param     Should be type \ref NETIO_RtpsPortData
 * \param[in]  kind      The type of address to resolve
 * \param[in]  port_base The base port
 * \param[in]  index     The port index
 * \param[out] address   Contains the resolved port number on successful return
 *
 * \return This function always returns OEI_TRUE
 */
MUST_CHECK_RETURN NETIODllExport OEI_BOOL
NETIO_rtps_calculate_port(void *param,NETIO_RouteKind_T kind,
                          OEI_UINT32 port_base,OEI_INT32 index,
                          struct NETIO_Address *address);

#ifdef __cplusplus
}                               /* extern "C" */
#endif

#endif /* netio_rtps_h */

/*ci @} */
