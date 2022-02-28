/*
 * FILE: osapi_system.h - Definition of System API
 *
 */
/*ce
 * \file 
 * \brief System API definition
 */
#ifndef osapi_system_h
#define osapi_system_h

#ifndef osapi_dll_h
#include "osapi/osapi_dll.h"
#endif
#ifndef osapi_time_h
#include "osapi/osapi_time.h"
#endif
#ifndef osapi_timer_h
#include "osapi/osapi_timer.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#define OSAPI_SYSTEM_MAX_HOSTNAME (64)

struct OSAPI_System;

/*ci
 * \brief The first object-id returned by OSAPI_System_get_next_object_id()
 */
#define OSAPI_SYSTEM_OBJECTID_START 0x01000000

/*ci
 * \brief The maximum returned valid object-id from
 *        OSAPI_System_get_next_object_id() is OSAPI_SYSTEM_OBJECTID_MAX-1.
 */
#define OSAPI_SYSTEM_OBJECTID_MAX   0x7fffffff

/*e \defgroup OSAPI_SystemClass OSAPI System
 *  \ingroup OSAPIModule
 *  \brief Abstract System API.
 *
 *  \details
 *
 *  The System is defined as the physical or virtual
 *  execution environment and implements functions that are not necessarily
 *  provided by the operating system. For example, a custom embedded board may
 *  include a special real-time clock which is synchronized via GPS, but is
 *  not available via a regular OS system call.
 */

/*e \ingroup OSAPI_SystemClass
 *
 *  start timer definition
 */
FUNCTION_MUST_TYPEDEF(
OEI_BOOL
(*OSAPI_System_start_timer_T)(OSAPI_Timer_T self,
                              OSAPI_TimerTickHandlerFunction tick_handler)
)

/*e \ingroup OSAPI_SystemClass
 *
 *  stop timer definition
 */
FUNCTION_SHOULD_TYPEDEF(
OEI_BOOL
(*OSAPI_System_stop_timer_T)(OSAPI_Timer_T self)
)

/*e \ingroup OSAPI_SystemClass
 *
 *  get timer resolution
 */
FUNCTION_SHOULD_TYPEDEF(
OEI_INT32
(*OSAPI_System_get_timer_resolution_T)(void)
)

/*e \ingroup OSAPI_SystemClass
 *
 * get time
 */
FUNCTION_SHOULD_TYPEDEF(
OEI_BOOL
(*OSAPI_System_get_time_T)(OSAPI_NtpTime *now)
)

/*e \ingroup OSAPI_SystemClass
 *
 * initialize
 */
FUNCTION_SHOULD_TYPEDEF(
OEI_BOOL
(*OSAPI_System_initialize_T)(void)
)

/*e \ingroup OSAPI_SystemClass
 *
 * finalize
 */
FUNCTION_SHOULD_TYPEDEF(
OEI_BOOL
(*OSAPI_System_finalize_T)(void)
)

/*e \ingroup OSAPI_SystemClass
 *
 * get_hostname
 */
FUNCTION_MUST_TYPEDEF(
OEI_BOOL
(*OSAPI_System_get_hostname_T)(char *const hostname)
)

struct OSAPI_SystemUUID;

FUNCTION_MUST_TYPEDEF(
OEI_BOOL
(*OSAPI_System_generate_uuid_T)(struct OSAPI_SystemUUID *uuid_out);
)

FUNCTION_MUST_TYPEDEF(
OEI_BOOL
(*OSAPI_System_get_ticktime_T)(OEI_INT32 *sec,OEI_UINT32 *nanosec);
)

/*e \ingroup OSAPI_SystemClass
 *
 *  System Interface class
 *
 *  The methods in this interface are called by the corresponding
 *  OSAPI_System function. For example, OSAPI_System_get_time() calls
 *  system->get_time().
 *
 */
struct OSAPI_SystemI
{
    /*e \ingroup OSAPI_SystemClass
     *
     * Refer to \ref OSAPI_System_start_timer for signature
     * and semantics.
     */
    OSAPI_System_start_timer_T start_timer;

    /*e \ingroup OSAPI_SystemClass
     *
     * Refer to \ref OSAPI_System_stop_timer for signature
     * and semantics.
     */
    OSAPI_System_stop_timer_T stop_timer;

    /*e \ingroup OSAPI_SystemClass
     *
     * Refer to \ref OSAPI_System_get_timer_resolution for signature
     * and semantics.
     */
    OSAPI_System_get_timer_resolution_T get_timer_resolution;

    /*e \ingroup OSAPI_SystemClass
     *
     * Refer to \ref OSAPI_System_get_time for signature
     * and semantics.
     */
    OSAPI_System_get_time_T get_time;

    /*e \ingroup OSAPI_SystemClass
     *
     * Refer to \ref OSAPI_System_initialize for signature
     * and semantics.
     */
    OSAPI_System_initialize_T initialize;

    /*e \ingroup OSAPI_SystemClass
     *
     * Refer to \ref OSAPI_System_finalize for signature
     * and semantics.
     */
    OSAPI_System_finalize_T finalize;

    /*e \ingroup OSAPI_SystemClass
     *
     * Refer to \ref OSAPI_System_generate_uuid for signature
     * and semantics.
     */
    OSAPI_System_generate_uuid_T generate_uuid;

    /*e\ingroup OSAPI_SystemClass
     *
     * Refer to \ref OSAPI_System_get_hostname for signature
     * and semantics.
     */
    OSAPI_System_get_hostname_T get_hostname;

    /*e\ingroup OSAPI_SystemClass
     *
     * Refer to \ref OSAPI_System_get_ticktime for signature
     * and semantics.
     */
    OSAPI_System_get_ticktime_T get_ticktime;
};

#define OSAPI_SystemI_INITIALIZER \
{\
    NULL,\
    NULL,\
    NULL,\
    NULL,\
    NULL,\
    NULL,\
    NULL,\
    NULL,\
    NULL\
}

extern OSAPIDllVariable struct OSAPI_System *OSAPI_System_gv_System;

/*e \ingroup OSAPI_SystemClass
 *  \brief Set system interface
 *
 *  \details
 *  This function sets the system interface, overriding the current system
 *  interface.
 *
 *  \param [in] intf - The new system interface
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure.
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_set_interface(struct OSAPI_SystemI *intf);

/*e \ingroup OSAPI_SystemClass
 *  \brief Get the current system interface
 *
 *  \details
 *  This function returns the current system interface
 *
 *  \param [out] intf - The current system interface
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure.
 */
SHOULD_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_get_interface(struct OSAPI_SystemI *intf);

/*e \ingroup OSAPI_SystemClass
 *
 *  System listener
 */
FUNCTION_MUST_TYPEDEF(
OEI_BOOL
(*OSAPI_System_on_system_initialize_T)(void *listener_data,struct OSAPI_System *system)
)

typedef void
(*OSAPI_System_on_system_finalize_T)(void *listener_data,struct OSAPI_System *system);

/*e \ingroup OSAPI_SystemClass
 *
 *  System listener
 */
struct OSAPI_SystemListener
{
    void *listener_data;
    OSAPI_System_on_system_initialize_T on_system_initialize;
    OSAPI_System_on_system_finalize_T on_system_finalize;
};

#define OSAPI_SystemListener_INITIALIZER \
{\
    NULL,\
    NULL,\
    NULL,\
}

/*e \ingroup OSAPI_SystemClass
 *  \brief Install a system listeners
 *
 *  \details
 *
 *  The system listeners are called during the life-time of the system.
 *  Only listeners which are non-NULL are called, thus it is ok to install
 *  a partially set listener structure. System listeners can be installed
 *  until the system has been initialized by calling OSAPI_System_initialize.
 *  This function is not considered thread-safe. The listener value should
 *  always be initialized with OSAPI_SystemListener_DEFAULT before use.
 *
 *  \param [in] listener System listeners to call
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_set_listener(struct OSAPI_SystemListener *listener);

/*e \ingroup OSAPI_SystemClass
 *  \brief Get current system listeners
 *
 *  \details
 *  Return the current set of system listeners. This function is not thread-safe.
 *
 *  \param[in] listener System listener structure to fill in.
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure.
 */
SHOULD_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_get_listener(struct OSAPI_SystemListener *listener);

/*e \ingroup OSAPI_SystemClass
 *
 *  System properties
 */
struct OSAPI_SystemProperty
{
    /*e
     *  \brief Set the timer properties
     */
    struct OSAPI_TimerProperty timer_property;

    /*e
     *  \brief Set the hostname for the node.
     *
     *  \details
     *  \rtime uses this name when it announces itself on the
     *  network. This name is used by other OEI products. The
     *  hostname must not exceed OSAPI_SYSTEM_MAX_HOSTNAME,
     *  including the \0 character.
     */
    char hostname[OSAPI_SYSTEM_MAX_HOSTNAME];
};

#define OSAPI_SystemProperty_INITIALIZER \
{\
    OSAPI_TimerProperty_INITIALIZER,\
    {0}\
}

/*e \ingroup OSAPI_SystemClass
 * \brief UUID definition
 *
 *  Abstract UUID object,a 128-bit value.
 */
struct OSAPI_SystemUUID
{
    OEI_UINT32 value[4];
};

struct OSAPI_System;

/*e \ingroup OSAPI_SystemClass
 * \brief Generate a unique universal identifier (UUID)
 *
 * \param [out] uuid_out The generated UUID value
 *
 * \return OEI_TRUE on success, OEI_FALSE on failure
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_generate_uuid(struct OSAPI_SystemUUID *uuid_out);

/*e \ingroup OSAPI_SystemClass
 * \brief Get the current system time.
 *
 *  \details
 * In general, the system time is used by components to correlate both
 * internal and external events, such as data reception and ordering. Thus,
 * it is recommended that this function returns the real time. However, it is not
 * strictly required.
 *
 * Notes:
 * - It is assumed that the time returned by get_time is monotonically
 *   increasing. It is up to the implementation of this function to ensure
 *   this holds true.
 * - It is ok to return the same time as the last call.
 * - The clock used to report real-time can be different than the clock used to
 *   support start_timer and stop_timer.
 *
 * @param [out] now Time in NtpTime format.
 *
 * @return OEI_TRUE on success, OEI_FALSE on failure.
 *
 * @pre Initialized system.
 *
 * @exception None.
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_get_time(OSAPI_NtpTime *now);

/*e \ingroup OSAPI_SystemClass
 *  \brief Get the resolution of the clock driving the timer in nano seconds.
 *
 *  \details
 *
 *  This function must return the frequency of the system timer used to implement
 *  OSAPI_SystemI::start_timer and OSAPI_SystemI::stop_timer API.
 *
 *  @return timer resolution in nanoseconds.
 */
OSAPIDllExport OEI_INT32
OSAPI_System_get_timer_resolution(void);

/*e \ingroup OSAPI_SystemClass
 *
 * \brief Start the timer.
 *
 * @param [in] self         Timer object.
 * @param [in] tick_handler Timer handle.
 *
 * @pre Initialized system.
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_start_timer(OSAPI_Timer_T self,
                        OSAPI_TimerTickHandlerFunction tick_handler);

/*e \ingroup OSAPI_SystemClass
 * \brief Stop the timer.
 *
 * @param [in] self Timer
 *
 * @return OEI_TRUE on success, OEI_FALSE on failure.
 *
 * @pre Initialized system.
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_stop_timer(OSAPI_Timer_T self);

/*e \ingroup OSAPI_SystemClass
 *  \brief Initialize the system.
 *
 *  \details
 *
 *  This function initializes the system and calls the port specific initialize
 *  method first. The port specific initialization method must return OEI_TRUE
 *  on success and OEI_FALSE on failure. A system can only be initialized once.
 *
 *  @return OEI_TRUE on success, OEI_FALSE on failure.
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_initialize(void);

#ifndef OEI_CERT
/*e \ingroup OSAPI_SystemClass
    \brief Finalize the system.

    \details

    This function finalizes the system and calls the port specific finalize
    method last. The port specific initialization method must return OEI_TRUE
    on success and OEI_FALSE on failure.

    @return OEI_TRUE on success, OEI_FALSE on failure.
*/
SHOULD_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_finalize(void);
#endif /* !OEI_CERT */

/*e \ingroup OSAPI_SystemClass
 *  \brief Get the system properties
 *
 * @param [out] property
 *
 * @return OEI_TRUE on success, OEI_FALSE on failure.
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_get_property(struct OSAPI_SystemProperty *property);

/*e \ingroup OSAPI_SystemClass
 * \brief Set the system properties.
 *
 * \details
 * The system properties can be set until the system is initialized by
 * calling \ref OSAPI_System_initialize()
 *
 * @param [in] property
 *
 * @return OEI_TRUE on success, OEI_FALSE on failure.
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_set_property(struct OSAPI_SystemProperty *property);

/*e \ingroup OSAPI_SystemClass
 * \brief Get the native system interface
 *
 *  \details
 *
 * This function must fill in the interface structure and assign the
 * following methods:
 *
 * <ul>
 *   <li> \ref OSAPI_SystemI::get_timer_resolution
 *   <li> \ref OSAPI_SystemI::get_time
 *   <li> \ref OSAPI_SystemI::start_timer
 *   <li> \ref OSAPI_SystemI::stop_timer
 *   <li> \ref OSAPI_SystemI::generate_uuid
 *   <li> \ref OSAPI_SystemI::get_hostname
 *   <li> \ref OSAPI_SystemI::initialize
 *   <li> \ref OSAPI_SystemI::finalize
 *   <li> \ref OSAPI_SystemI::get_ticktime
 * </ul>
 *
 * @param [out] intf The native system interface
 */
OSAPIDllExport void
OSAPI_System_get_native_interface(struct OSAPI_SystemI *intf);

/*e \ingroup OSAPI_SystemClass
 *
 *  \brief Return next object ID
 *
 *  \details
 *  This function return the next available object if. Object Id are never
 *  reused, thus it is possible to run out of object ids.
 *
 * \return new object on success, -1 on failure
 */
OSAPIDllExport OEI_INT32
OSAPI_System_get_next_object_id(void);

/*e \ingroup OSAPI_SystemClass
 * \brief Get the hostname
 *
 * \details
 * Get the hostname
 *
 * @param [out] hostname  The buffer to store the hostname. Must be at
 *                        least OSAPI_SYSTEM_MAX_HOSTNAME bytes. If the
 *                        actual hostname is longer than
 *                        OSAPI_SYSTEM_MAX_HOSTNAME bytes (including \0) the
 *                        hostname is truncated.
 *
 * @pre Initialized system.
 *
 * @exception None.
 *
 * @return OEI_TRUE on success, OEI_FALSE on failure.
 *
 * @mtsafety SAFE
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_get_hostname(char *const hostname);


/*e \ingroup OSAPI_SystemClass
 *
 * \brief Get current tick time
 *
 * \details
 *
 * The ticktime is a time measurement used by Micro to determine how much
 * time has elapsed in a period. It does not have to be an absolute time,
 * but it _must_ be monotonically increasing. For this reason it is important
 * to choose the time source with care. For example, the system time may
 * mbe adjusted backward or forward and this could affect the measure time
 * lapse. The resolution of the tick time is expected to be no less than the
 * system timer, although it is not a requirement.
 *
 * @param[out] sec     The current ticktime in seconds
 *
 * @param[out] nanosec Additional nanoseconds in the current ticktime
 *
 * @pre Initialized system.
 *
 * @return OEI_TRUE on success, OEI_FALSE on failure.
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_System_get_ticktime(OEI_INT32 *sec,OEI_UINT32 *nanosec);


#ifdef __cplusplus
}                               /* extern "C" */
#endif

#endif /* osapi_system_h */
