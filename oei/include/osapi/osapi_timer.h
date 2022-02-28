/*
 * FILE: osapi_timer.h - Definition of Timer interface
 *
 */
/*ce
 * \file
 * \brief Timer interface definition
 *
 * \details
 * The Timer API provides a platform independent set of function to start
 * timers and be notified when the timer expires. The concrete implementation
 * of the platform dependent timer API are located in the platform specific
 * files, such as vxTimer.c
 *
 * \defgroup OSAPI_TimerClass OSAPI Timer
 * \ingroup OSAPIModule
 *
 *  \details
 */
#ifndef osapi_timer_h
#define osapi_timer_h


#ifndef osapi_dll_h
#include "osapi/osapi_dll.h"
#endif
#ifndef osapi_types_h
#include "osapi/osapi_types.h"
#endif
#ifndef osapi_thread_h
#include "osapi/osapi_thread.h"
#endif
#ifndef osapi_mutex_h
#include "osapi/osapi_mutex.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*e \defgroup OSAPI_TimerClass OSAPI Timer
 *  \ingroup OSAPIModule
*/

/*e \file
  \brief Timer API
*/

/*e \ingroup OSAPI_TimerClass
 *  \brief Create a periodic timer
 */
#define OSAPI_TIMER_PERIODIC (0x1)

/*e \ingroup OSAPI_TimerClass
 *  \brief Create a one-shot timer
 */
#define OSAPI_TIMER_ONE_SHOT (0x0)

/*e \ingroup OSAPI_TimerClass
 *  \brief Action taken by timer module when a timer callback returns.
 */
typedef enum
{
    OSAPI_TIMEOUT_OP_AUTOMATIC = 1,
    OSAPI_TIMEOUT_OP_MANUAL
} OSAPI_TimeoutOp_t;

/*e \ingroup OSAPI_TimerClass
 *  \brief User-data passed to timer-handler.
 */
struct OSAPI_TimeoutUserData
{
    OEI_UINT32 count[2];
    void *field[2];
};

struct OSAPI_TimerEntry;
struct OSAPI_TimeoutHandle
{
    /* In case an entry is re-used */
    struct OSAPI_TimerEntry *_entry;

    /* In case an entry is re-used */
    OEI_INT32 epoch;
};

typedef struct OSAPI_TimeoutHandle OSAPI_TimeoutHandle_T;

#define OSAPI_TimeoutHandle_INITIALIZER \
{\
    NULL,\
    -1\
}

/*e \ingroup OSAPI_TimerClass
 *  \brief Timer properies
 */
struct OSAPI_TimerProperty
{
    /*ci
     * \brief The maximum number of timeouts
     */
    OEI_INT32 max_entries;

    /*ci
     * \brief The maximum number slots in one round
     */
    OEI_INT32 max_slots;

    /*ci
     * \brief The thread settings for the timer thread, if a thread is created
     */
    struct OSAPI_ThreadProperty thread;
};

/*ci
 * \brief Initializer for the \ref OSAPI_TimerProperty
 */
#define OSAPI_TimerProperty_INITIALIZER \
{\
    128,\
    32,\
    {  /* OSAPI_ThreadProperty */ \
        OSAPI_THREAD_USE_OSDEFAULT_STACKSIZE,\
        OSAPI_THREAD_PRIORITY_NORMAL,\
        OSAPI_THREAD_DEFAULT_OPTIONS,\
    },\
}

struct OSAPI_Timer;
typedef struct OSAPI_Timer *OSAPI_Timer_T;

FUNCTION_MUST_TYPEDEF(
OSAPI_TimeoutOp_t
(*OSAPI_TimeoutFunction_T)(struct OSAPI_TimeoutUserData *user_data)
)

typedef void
(*OSAPI_TimerTickHandlerFunction)(OSAPI_Timer_T timer);

/*e \ingroup OSAPI_TimerClass
 *  \brief Create a Timer.
 *
 *  \details Create a new Timer. A Timer can manage multiple timeouts.
 *
 *  Example:
 *  \code
 *  OSAPI_Timer_t my_timer;
 *  struct OSAPI_TimerProperty timer_property = OSAPI_TimerProperty_INITIALIZER;
 *  timer = OSAPI_Timer_new(&timer_property);
 *  if (timer == NULL) {
 *      return error;
 *  }
 *  \endcode
 *
 *  The created Timer should be deleted with \ref OSAPI_Timer_delete.
 *
 *  @param[in] property Timer property.
 *  @param[in] mutex Shared mutex.
 *
 *  @return New timer on success, NULL on failure
 */
MUST_CHECK_RETURN OSAPIDllExport OSAPI_Timer_T
OSAPI_Timer_new(struct OSAPI_TimerProperty *property,struct OSAPI_Mutex *mutex);

#ifndef OEI_CERT
/*e \ingroup OSAPI_TimerClass
 *  \brief Delete a Timer.
 *
 *  \details Delete a previously created Timer. All timeouts are cancelled.
 *
 *  Example:
 *  \code
 *  OSAPI_Timer_t my_timer;
 *
 *  ......
 *
 *  OSAPI_Timer_delete(my_timer);
 *  if (timer == NULL) {
 *      return error;
 *  }
 *  \endcode
 *
 *  The created Timer should be deleted with \ref OSAPI_Timer_delete.
 *
 *  @param [in] timer Timer.
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure
 *
 *  @mtsafety SAFE
 */
SHOULD_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Timer_delete(OSAPI_Timer_T timer);
#endif /* !OEI_CERT */

/*e \ingroup OSAPI_TimerClass
 *   \brief Schedule a timeout.
 *
 *  \details This function schedules a timeout with the specified period. The
 *   timeout can either be rescheduled automatically or a new timeout must
 *  be created.
 *
 *  Example:
 *  \code
 *  OSAPI_Timer_t my_timer;
 *  OSAPITimeoutHandle_t my_handle = OSAPITimeoutHandle_t_INITIALIZER;
 *  OEI_BOOL result;
 *  struct OSAPI_TimerEntryUserData user_data;
 *
 *  result = OSAPI_Timer_create_timeout(my_timer,
 *                                  &my_handle,
 *                                  1000,0,
 *                                  OSAPI_TIMER_PERIODIC,
 *                                  &user_data);
 *
 *  if (!result) {
 *      report error;
 *  }
 *
 *  ......
 *
 *  \endcode
 *
 *  A timeout can cancelled  with \ref OSAPI_Timer_delete_timeout or the timeout
 *  can be modified with \ref OSAPI_Timer_update_timeout.
 *
 *  @param[in]  timer Timer object. Cannot be NULL.
 *  @param[out] out_handle Reference to the timeout. Cannot be NULL.
 *  @param[in]  timeout_sec  The number of seconds before timeout
 *  @param[in]  timeout_nsec Additional number of nanoseconds before timeout
 *  @param[in]  flags Flags OSAPI_TIMER_PERIODIC or OSAPI_TIMER_ONE_SHOT
 *  @param[in]  timeout_handler Function to call at timeout. Cannot be NULL.
 *  @param[in]  user_data User data associated with the timeout. Can be NULL.
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure
 *
 *  @mtsafety SAFE
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Timer_create_timeout(OSAPI_Timer_T timer,
                          OSAPI_TimeoutHandle_T *out_handle,
                          OEI_INT32 timeout_sec,
                          OEI_INT32 timeout_nsec,
                          OEI_INT32 flags,
                          OSAPI_TimeoutFunction_T timeout_handler,
                          struct OSAPI_TimeoutUserData *user_data);

/*e \ingroup OSAPI_TimerClass
 *  \brief Reschedule a timeout.
 *
 *  \details This function reschedules a previously scheduled timeout with
 *  the specified period.
 *
 *  Example:
 *  \code
 *  OSAPI_Timer_t my_timer;
 *  OSAPITimeoutHandle_t my_handle = OSAPITimeoutHandle_t_INITIALIZER;
 *  OEI_BOOL result;
 *  struct OSAPI_TimerEntryUserData user_data;
 *
 *  result = OSAPI_Timer_update_timeout(my_timer,
 *                                      &my_handle,
 *                                      2000,0);
 *
 *  if (!result) {
 *      report error;
 *  }
 *
 *  ......
 *
 *  \endcode
 *
 *  @param [in]  timer Timer object. Cannot be NULL.
 *  @param [out] out_handle Reference to the timeout. Cannot be NULL.
 *  @param[in]   timeout_sec  The number of seconds before timeout
 *  @param[in]   timeout_nsec Additional number of nanoseconds before timeout
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Timer_update_timeout(OSAPI_Timer_T timer,
                           OSAPI_TimeoutHandle_T *out_handle,
                           OEI_INT32 timeout_sec,
                           OEI_INT32 timeout_nsec);

/*e \ingroup OSAPI_TimerClass
 *  \brief Stop a previously scheduled timeout
 *
 *  \details This function stops a previously scheduled timeout.
 *
 *  Example:
 *  \code
 *  OSAPI_Timer_t my_timer;
 *  OSAPITimeoutHandle_t my_handle = OSAPITimeoutHandle_t_INITIALIZER;
 *  OEI_BOOL result;
 *
 *  ....
 *
 *  result = OSAPI_Timer_stop_timer(my_timer,&my_handle);
 *
 *  if (!result) {
 *      report error;
 *  }
 *
 *  ......
 *
 *  \endcode
 *
 *  @param [in] timer Timer object. Cannot be NULL.
 *  @param [in] handle Reference to the timeout. Cannot be NULL.
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure
 *
 *  @mtsafety SAFE
 */
SHOULD_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Timer_delete_timeout(OSAPI_Timer_T timer, OSAPI_TimeoutHandle_T *handle);

/*e \ingroup OSAPI_TimerClass
 *  \brief Get the user_data from a handle.
 *
 *  Example:
 *  \code
 *  OSAPI_Timer_t my_timer;
 *  OSAPITimeoutHandle_t my_handle = OSAPITimeoutHandle_t_INITIALIZER;
 *  OEI_BOOL result;
 *  struct OSAPI_TimerEntryUserData user_data;
 *
 *  ....
 *
 *  result = OSAPITimeoutHandle_get_user_data(&user_data,&my_handle);
 *
 *  if (!result) {
 *      report error;
 *  }
 *
 *  ......
 *
 *  \endcode
 *
 *  @param [out] user_data User-data associated with handle. Cannot be NULL.
 *  @param [in]  handle Timer handle.
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_TimeoutHandle_get_user_data(struct OSAPI_TimeoutUserData *user_data,
                                  OSAPI_TimeoutHandle_T *handle);

#ifdef __cplusplus
}                               /* extern "C" */
#endif


#endif /* osapi_timer_h */
