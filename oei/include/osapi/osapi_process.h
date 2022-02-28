/*
 * FILE: osapi_process.h - Process interface definition
 *
 */
/*ce
 * \file 
 * \brief Process interface definition 
 */
#ifndef osapi_process_h
#define osapi_process_h

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

/*e \file
  \brief process related utility
*/

/*e \ingroup OSAPI_ProcessClass
 *   \brief Return the process ID, which is unique for the application.
 *
 *  \details
 *   Return the process ID.
 *
 *  \return Process id
*/
OSAPIDllExport OSAPI_ProcessId
OSAPI_Process_getpid(void);

/*ci
 * \brief Convert a process ID to a string in decimal format
 * *
 * \param[inout] buffer      Buffer to store result in
 * \param[in]    max_length  Maximum length of the buffer
 * \param[in]    pid         Process ID to convert
 *
 * \return The number of characters placed in the buffer excluding the
 *         NULL termination. If there is insufficient space max_length
 *         is returned.
 */
OSAPIDllExport OEI_INT32
OSAPI_Process_pid_as_string(char *buffer,OEI_INT32 max_length,OSAPI_ProcessId pid);

#ifdef __cplusplus
}                               /* extern "C" */
#endif


#endif /* osapi_process_h */
