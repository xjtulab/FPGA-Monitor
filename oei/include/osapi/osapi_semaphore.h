/*
 * FILE: osapi_semaphore.h - Definition of semaphore interface
 *
 */
/*e \file
 *  \brief Semaphore interface definition
 */
#ifndef osapi_semaphore_h
#define osapi_semaphore_h

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

/*e \defgroup OSAPI_SemaphoreClass OSAPI Semaphore
    \ingroup OSAPIModule

    \brief Abstract Semaphore API.
 */

/*e
 * Infinite timeout
 */
#define OSAPI_SEMAPHORE_TIMEOUT_INFINITE -1

/*e
 * Semaphore ok
 */
#define OSAPI_SEMAPHORE_RESULT_OK          0

/*e
 * Semaphore timed out
 */
#define OSAPI_SEMAPHORE_RESULT_TIMEOUT     1

/*e
 * Semaphore error
 */
#define OSAPI_SEMAPHORE_RESULT_ERROR       2

struct OSAPI_Semaphore;

/*e \ingroup OSAPI_SemaphoreClass
 *
 * \brief Abstract semaphore object.
 */
typedef struct OSAPI_Semaphore OSAPI_Semaphore_T;

/*e \ingroup OSAPI_SemaphoreClass
 *
 * \brief Create a semaphore.
 *
 * \return Pointer to a semaphore with a value of 1 on success, NULL on failure.
 *
 * \sa \ref OSAPI_Semaphore_delete
 *
 */
MUST_CHECK_RETURN OSAPIDllExport OSAPI_Semaphore_T*
OSAPI_Semaphore_new(void);

#ifndef OEI_CERT
/*e \ingroup OSAPI_SemaphoreClass
 *
 *  \brief Delete a semaphore.
 *
 *  \param [in] self Semaphore created with \ref OSAPI_Semaphore_new.
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure.
 *
 *  \sa \ref OSAPI_Semaphore_new
 */
SHOULD_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Semaphore_delete(OSAPI_Semaphore_T *self);
#endif /* !OEI_CERT */

/*e \ingroup OSAPI_SemaphoreClass
 *
 *  \brief Take a semaphore.
 *
 *  \param [in] self Semaphore previously created with \ref OSAPI_Semaphore_new.
 *
 *  \param [in] timeout Timeout in ms. The `take` call will wait at most
 *                       `timeout` ms before returning. If \ref
 *                       OSAPI_SEMAPHORE_TIMEOUT_INFINITE is specified, the
 *                       call will not return until the semaphore has a value of
 *                       1 or higher.
 *
 *  \param [out] fail_reason This parameter is not used, but present for
 *                          compatibility reasons.
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure.
 *
 *  \sa \ref OSAPI_Semaphore_give
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Semaphore_take(OSAPI_Semaphore_T *self,OEI_INT32 timeout,
                    OEI_INT32 *fail_reason);

/*e \ingroup OSAPI_SemaphoreClass
 *
 *  \brief Give a semaphore.
 *
 *  \param [in] self Semaphore previously created with \ref OSAPI_Semaphore_new.
 *
 *  \return OEI_TRUE on success, OEI_FALSE on failure.
 *
 *  \sa \ref OSAPI_Semaphore_take
 *
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Semaphore_give(OSAPI_Semaphore_T *self);

#ifdef __cplusplus
}                               /* extern "C" */
#endif


#endif /* osapi_semaphore_h */
