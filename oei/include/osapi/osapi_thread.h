/*
 * FILE: osapi_thread.h - Definition of System API
 *
 */
/*e \file
  * \brief Thread interface definition
  */
#ifndef osapi_thread_h
#define osapi_thread_h

#include "osapi/osapi_config.h"
#ifndef osapi_dll_h
#include "osapi/osapi_dll.h"
#endif
#ifndef osapi_types_h
#include "osapi/osapi_types.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*e \defgroup OSAPI_ThreadClass OSAPI Thread
 *  \ingroup OSAPIModule
*/

/* these are #defined so users can pass in any int they want for priority as well
 *  i.e., OS-native thread priorities
 */
#define OSAPI_THREAD_PRIORITY_LOW               -1
#define OSAPI_THREAD_PRIORITY_BELOW_NORMAL      -2
#define OSAPI_THREAD_PRIORITY_NORMAL            -3
#define OSAPI_THREAD_PRIORITY_ABOVE_NORMAL      -4
#define OSAPI_THREAD_PRIORITY_HIGH              -5

#define OSAPI_THREAD_USE_OSDEFAULT_STACKSIZE    0

/*e \ingroup OSAPI_ThreadClass
 *  Thread options
 */
typedef OEI_UINT32 OSAPI_ThreadOptions;

/*e \ingroup OSAPI_ThreadClass
  Use only the default options the OS gives you.
*/
#define OSAPI_THREAD_DEFAULT_OPTIONS     0x00
/*e \ingroup OSAPI_ThreadClass
  Support floating point.
*/
#define OSAPI_THREAD_FLOATING_POINT      0x01
/*e \ingroup OSAPI_ThreadClass
  Support standard I/O.
*/
#define OSAPI_THREAD_STDIO               0x02
/*e \ingroup OSAPI_ThreadClass
  Run in real-time priority mode.
*/
#define OSAPI_THREAD_REALTIME_PRIORITY   0x08
/*e \ingroup OSAPI_ThreadClass
  Insist on the specified priority and fail if the OS doesn't like it.
*/
#define OSAPI_THREAD_PRIORITY_ENFORCE    0x10
/*e \ingroup OSAPI_ThreadClass
  Support the ability to asynchronously cancel the thread.
*/
#define OSAPI_THREAD_CANCEL_ASYNCHRONOUS 0x20

/*e \ingroup OSAPI_ThreadClass
 *
 */
struct OSAPI_ThreadProperty
{
    /*e Hint on required stack-size */
    OEI_UINT32 stack_size;

    /*e Hint on required priority */
    OEI_INT32 priority;

    /*e Hint on thread priorites if support by the OS */
    OSAPI_ThreadOptions options;
};

/*e \ingroup OSAPI_ThreadClass
 * Initializer for thread properties
 */
#define OSAPI_THREAD_PROPERTY_DEFAULT \
{ \
    OSAPI_THREAD_USE_OSDEFAULT_STACKSIZE, \
    OSAPI_THREAD_PRIORITY_NORMAL, \
    OSAPI_THREAD_DEFAULT_OPTIONS \
}

#define OSAPI_ThreadProperty_INITIALIZER OSAPI_THREAD_PROPERTY_DEFAULT
/*e
 * \ingroup OSAPI_ThreadClass
 * \brief Thread info
 *
 */
struct OSAPI_ThreadInfo
{
    /*e Stop executing thread */
    OEI_BOOL stop_thread;

    /*e Whether or not the created thread is preemptive */
    OEI_BOOL is_premptive;

    /*e Parameter passed by thread creator. Passed to thread. */
    void *user_data;
};

/*e \ingroup OSAPI_ThreadClass
 *
 * \brief Thread task signature.
 *
 * \param[in] thread_info Thread information structure
 *
 * \return OEI_TRUE on successful execution, OEI_FALSE on failure.
 */
FUNCTION_SHOULD_TYPEDEF(
OEI_BOOL
(*OSAPI_ThreadRoutine)(struct OSAPI_ThreadInfo *thread_info)
)

/*e \ingroup OSAPI_ThreadClass
 *
 * \brief Abstract thread class.
 */
struct OSAPI_Thread;


/*e \ingroup OSAPI_ThreadClass
 *
 *  \brief Wakeup user-thread
 *
 *  \details
 *
 *  If a user-defined thread function is blocking, e.g. waiting for
 *  data, and the user wants to delete the thread, it is necessary to
 *  unblock the user-thread. The user must provide a function which can
 *  unblock a thread. This function calls the wake up function to wake up a
 *  blocked user thread.
 *
 *  \param [in] self OSAPI_Thread to wakeup
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure.
 *
 *  \sa \ref OSAPI_Thread_start
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Thread_wakeup(struct OSAPI_Thread *self);

/*e \ingroup OSAPI_ThreadClass
 *
 *  \brief Start a specific thread.
 *
 *  \param [in] me Thread to wake up
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure.
 *
 *  \sa \ref OSAPI_Thread_create
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Thread_start(struct OSAPI_Thread *me);


/*e \ingroup OSAPI_ThreadClass
 *  \brief Destroy a specific thread.
 *
 *  \param [in] self Thread.
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure.
 *
 *  \sa \ref OSAPI_Thread_create
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Thread_destroy(struct OSAPI_Thread *self);

/*e \ingroup OSAPI_ThreadClass
 *  \brief Suspend a thread for a specified amount of time.
 *
 *  \param [in] ms Sleep time.
 *
 */
OSAPIDllExport void
OSAPI_Thread_sleep(OEI_UINT32 ms);

/*e \ingroup OSAPI_ThreadClass
 *
 *  \brief Create a thread.
 *
 *  \param [in] name The name of the thread.
 *
 *  \param [in] properties Thread properties. These properties are hints.
 *
 *  \param [in] user_routine  Thread task. The thread task cannot assume that
 *                          it can block; thus it must be written such that
 *                          it can be called repeatedly.
 *
 *  \param [in] user_data Parameters passed to the thread task.
 *
 *  \param [in] wakeup_routine Routine to wake up a thread, called to delete
 *                            a thread.
 *
 *  \return Handle to stopped thread on success, NULL on failure.
 *
 *  \sa \ref OSAPI_Thread_destroy
 */
MUST_CHECK_RETURN OSAPIDllExport struct OSAPI_Thread*
OSAPI_Thread_create(const char *name,
                   const struct OSAPI_ThreadProperty *properties,
                   OSAPI_ThreadRoutine user_routine,
                   void *user_data,
                   OSAPI_ThreadRoutine wakeup_routine);


/*e \ingroup OSAPI_ThreadClass
 *
 *  \brief Return thread ID.
 *
 *  \return thread ID of the calling thread.
 *
 *  \sa \ref OSAPI_Thread_create
 */
OSAPIDllExport OSAPI_ThreadId
OSAPI_Thread_self(void);

#ifdef __cplusplus
}                               /* extern "C" */
#endif


#endif /* osapi_thread_h */
