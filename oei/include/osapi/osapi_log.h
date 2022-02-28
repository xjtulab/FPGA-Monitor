/*
 * FILE: osapi_log.h - Logging API
 *
 */
/*ci
 * \file
 * \brief OSAPI Log API
 * \addtogroup OSAPILogClass OSAPI Logging
 */
#ifndef osapi_log_h
#define osapi_log_h

#ifndef osapi_dll_h
#include "osapi/osapi_dll.h"
#endif /*  */
#ifndef osapi_thread_h
#include "osapi/osapi_thread.h"
#endif /*  */
#ifndef osapi_heap_h
#include "osapi/osapi_heap.h"
#endif /*  */
#ifndef osapi_system_h
#include "osapi/osapi_system.h"
#endif /*  */

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
 *                            OSAPI Error codes
 ******************************************************************************/

#ifndef OEI_MODULE_NAME
#define OEI_MODULE_NAME "undefined"
#endif

#define OSAPI_LOG_MSG_PN_X2_STD_PARAM OEI_MODULE_NAME,\
                                            __FILE__,__FUNCTION__, __LINE__

#if OSAPI_ENABLE_LOG
#define OSAPI_LOG_ENTRY_CREATE(kind_,error_code_,p_,is_finale_)\
        OSAPI_Log_entry_create(kind_,error_code_,p_,is_finale_);

#define OSAPI_LOG_ENTRY_ADD(kind_,error_code_,p_)\
    OSAPI_Log_entry_add(kind_,error_code_,p_);

#define OSAPI_LOG_ENTRY_ADD_INT(name_,value_,is_final_)\
        OSAPI_Log_entry_add_int(name_,value_,is_final_);

#define OSAPI_LOG_ENTRY_ADD_STRING(name_,value_,is_final_)\
    OSAPI_Log_entry_add_string(name_,value_,is_final_);

#define OSAPI_LOG_ENTRY_ADD_POINTER(name_,value_,is_final_)\
    OSAPI_Log_entry_add_pointer(name_,value_,is_final_);\

#define OSAPI_LOG_ENTRY_ADD_1STRING_1INT(kind_,error_code_,p_,s_name_,s_value_,i_name_,i_value_)\
        OSAPI_Log_entry_add_1string_1int(kind_,error_code_,p_,s_name_,s_value_,i_name_,i_value_);

#define OSAPI_LOG_ENTRY_ADD_1POINTER(kind_,error_code_,p_,name_,value_)\
    OSAPI_Log_entry_add_1pointer(kind_,error_code_,p_,name_,value_);

#define OSAPI_LOG_ENTRY_ADD_1STRING(kind_,error_code_,p_,name_,value_)\
    OSAPI_Log_entry_add_1string(kind_,error_code_,p_,name_,value_);

#define OSAPI_LOG_ENTRY_ADD_2STRING(kind_,error_code_,p_,name1_,value1_,name2_,value2_)\
    OSAPI_Log_entry_add_2string(kind_,error_code_,p_,name1_,value1_,name2_,value2_);

#define OSAPI_LOG_ENTRY_ADD_1INT(kind_,error_code_,p_,name1_,value1_)\
        OSAPI_Log_entry_add_1int(kind_,error_code_,p_,name1_,value1_);

#define OSAPI_LOG_ENTRY_ADD_2INT(kind_,error_code_,p_,name1_,value1_,name2_,value2_)\
    OSAPI_Log_entry_add_2int(kind_,error_code_,p_,name1_,value1_,name2_,value2_);

#define OSAPI_LOG_ENTRY_ADD_3INT(kind_,error_code_,p_,name1_,value1_,name2_,value2_,name3_,value3_)\
    OSAPI_Log_entry_add_3int(kind_,error_code_,p_,name1_,value1_,name2_,value2_,name3_,value3_);
#else
#define OSAPI_LOG_ENTRY_CREATE(kind_,error_code_,p_,is_finale_)
#define OSAPI_LOG_ENTRY_ADD_INT(name_,value_,is_final_)
#define OSAPI_LOG_ENTRY_ADD_STRING(name_,value_,is_final_)
#define OSAPI_LOG_ENTRY_ADD_POINTER(name_,value_,is_final_)
#define OSAPI_LOG_ENTRY_ADD_1STRING_1INT(kind_,error_code_,p_,s_name_,s_value_,i_name_,i_value_)
#define OSAPI_LOG_ENTRY_ADD_1POINTER(kind_,error_code_,p_,name_,value_)
#define OSAPI_LOG_ENTRY_ADD_1STRING(kind_,error_code_,p_,name_,value_)
#define OSAPI_LOG_ENTRY_ADD_2STRING(kind_,error_code_,p_,name1_,value1_,name2_,value2_)
#define OSAPI_LOG_ENTRY_ADD_1INT(kind_,error_code_,p_,name1_,value1_)
#define OSAPI_LOG_ENTRY_ADD_2INT(kind_,error_code_,p_,name1_,value1_,name2_,value2_)
#define OSAPI_LOG_ENTRY_ADD_3INT(kind_,error_code_,p_,name1_,value1_,name2_,value2_,name3_,value3_)
#define OSAPI_LOG_ENTRY_ADD(kind_,error_code_,p_)
#endif

/*ce
 * \defgroup OSAPILogCodesClass OSAPI
 * \ingroup LoggingModule
 *
 * \details
 * The logging API provides a number of functions for logging different
 * types of events. There are 3 types of events:
 *
 * info    - This type is for informational purposes
 *
 * warning - This type does not necessarily cause any functional behavior,
 *           but could indicate an unexpected situation has been handled
 *           or performance could be affected.
 *
 * error   - This indicated an error condition that has functional impact
 *           and could not be dealt with.
 *
 * \brief OS API. ModuleID = 0
 */

/******************************************************************************
 *                            OSAPI Log Modules
 ******************************************************************************/
/*ce \def OSAPI_LOG_BASE
 *   \brief Log Id base-number
 */
#define OSAPI_LOG_BASE                                      (0)

/*ce \def REDA_LOG_BASE
 *   \brief REDA Module
 */
#define REDA_LOG_BASE                                       (1 << 16)

/*ce \def DB_LOG_BASE
 *   \brief DB Module
 */
#define DB_LOG_BASE                                         (2 << 16)

/*ce \def RT_LOG_BASE
 *   \brief RT Module
 */
#define RT_LOG_BASE                                         (3 << 16)

/*ce \def NETIO_LOG_BASE
 *   \brief NETIO Module
 */
#define NETIO_LOG_BASE                                      (4 << 16)

/*ce \def UDP_LOG_BASE
 *   \brief UDP Module, same as NETIO
 */
#define UDP_LOG_BASE                                        NETIO_LOG_BASE

/*ce \def CDR_LOG_BASE
 *   \brief CDR Module
 */
#define CDR_LOG_BASE                                        (5 << 16)

/*ce \def RTPS_LOG_BASE
 *   \brief RTPS Module
 */
#define RTPS_LOG_BASE                                       (6 << 16)

/*ce \def DDSC_LOG_BASE
 *   \brief DDS_C Module
 */
#define DDSC_LOG_BASE                                       (7 << 16)

/*ce \def RHSM_LOG_BASE
 *   \brief RHSM Module
 */
#define RHSM_LOG_BASE                                       (8 << 16)

/*ce \def WHSM_LOG_BASE
 *   \brief WHSM Module
 */
#define WHSM_LOG_BASE                                       (9 << 16)

/*ce \def DPSE_LOG_BASE
 *   \brief DPSE Module
 */
#define DPSE_LOG_BASE                                       (10 << 16)

/*ce \def DPDE_LOG_BASE
 *   \brief DPDE Module
 */
#define DPDE_LOG_BASE                                       (11 << 16)

/*ce
 * \brief Retrieving the next error code failed
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_GET_NEXT_OBJECT_ID_EC                     (OSAPI_LOG_BASE + 1)
#define OSAPI_LOG_GET_NEXT_OBJECT_ID(level_) \
OSAPI_LOG_ENTRY_ADD((level_),OSAPI_LOG_GET_NEXT_OBJECT_ID_EC ,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/* System messages */

/*ce
 * \brief An error occured while setting the system properties
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_SYSTEM_SET_PROPERTY_EC                    (OSAPI_LOG_BASE + 2)
#define OSAPI_LOG_SYSTEM_SET_PROPERTY(level_) \
OSAPI_LOG_ENTRY_ADD((level_),OSAPI_LOG_SYSTEM_SET_PROPERTY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief An error occured when starting the system timer
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_SYSTEM_TIMER_START_EC                     (OSAPI_LOG_BASE + 4)
#define OSAPI_LOG_SYSTEM_TIMER_START(level_) \
OSAPI_LOG_ENTRY_ADD((level_),OSAPI_LOG_SYSTEM_TIMER_START_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief An error occured when stopping the system timer
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_SYSTEM_TIMER_STOP_EC                      (OSAPI_LOG_BASE + 5)
#define OSAPI_LOG_SYSTEM_TIMER_STOP(level_) \
OSAPI_LOG_ENTRY_ADD((level_),OSAPI_LOG_SYSTEM_TIMER_STOP_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/* THREAD message */
/*ce
 * \brief An error when allocating the a thread object
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_NEW_EC                             (OSAPI_LOG_BASE + 6)
#define OSAPI_LOG_THREAD_NEW(level_) \
OSAPI_LOG_ENTRY_ADD((level_),OSAPI_LOG_THREAD_NEW_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief An error when creating the a thread object
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_CREATE_EC                          (OSAPI_LOG_BASE + 7)
#define OSAPI_LOG_THREAD_CREATE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),OSAPI_LOG_THREAD_CREATE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief An error when creating thread sync semaphore
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_SEM_EC                             (OSAPI_LOG_BASE + 8)
#define OSAPI_LOG_THREAD_SEM(level_,cs_,ss_) \
OSAPI_LOG_ENTRY_CREATE((level_),OSAPI_LOG_THREAD_SEM_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("cs",(cs_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("ss",(ss_),OEI_TRUE)

/*ce
 * \brief Failed to signal that a thread has been created
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_EXEC_CREATE_EC                     (OSAPI_LOG_BASE + 9)
#define OSAPI_LOG_THREAD_EXEC_CREATE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),OSAPI_LOG_THREAD_EXEC_CREATE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to signal the start a created thread 
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_EXEC_START_EC                     (OSAPI_LOG_BASE + 10)
#define OSAPI_LOG_THREAD_EXEC_START(level_,ss_) \
OSAPI_LOG_ENTRY_ADD_1POINTER((level_),OSAPI_LOG_THREAD_EXEC_START_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"ss",(ss_))

/*ce
 * \brief Failed to start a thread
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_START_EC                          (OSAPI_LOG_BASE + 11)
#define OSAPI_LOG_THREAD_START(level_,ss_) \
OSAPI_LOG_ENTRY_ADD_1POINTER((level_),OSAPI_LOG_THREAD_START_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"ss",(ss_))

/*ce
 * \brief Failed to destroy a thread
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_DESTROY_EC                        (OSAPI_LOG_BASE + 12)
#define OSAPI_LOG_THREAD_DESTROY(level_,ss_) \
OSAPI_LOG_ENTRY_ADD_1POINTER((level_),OSAPI_LOG_THREAD_DESTROY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"ss",(ss_))

/*ce
 * \brief Failed to start an unstarted thread being destroyed
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_DESTROY_NO_START_EC               (OSAPI_LOG_BASE + 13)
#define OSAPI_LOG_THREAD_DESTROY_NO_START(level_,ss_) \
OSAPI_LOG_ENTRY_ADD_1POINTER((level_),OSAPI_LOG_THREAD_DESTROY_NO_START_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"ss",(ss_))

/*ce
 * \brief Failed wakeup of a thread being destroyed
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_DESTROY_NO_WAKEUP_EC              (OSAPI_LOG_BASE + 14)
#define OSAPI_LOG_THREAD_DESTROY_NO_WAKEUP(level_,ss_) \
OSAPI_LOG_ENTRY_ADD_1POINTER((level_),OSAPI_LOG_THREAD_DESTROY_NO_WAKEUP_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"ss",(ss_))

/*ce
 * \brief Failed initializing a thread
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_INIT_EC                           (OSAPI_LOG_BASE + 15)
#define OSAPI_LOG_THREAD_INIT(level_,sysrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),OSAPI_LOG_THREAD_INIT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"sysrc",(sysrc_))


/*ce
 * \brief Failed to set scheduling policy of a thread
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_SCHEDPARAM_EC                     (OSAPI_LOG_BASE + 16)
#define OSAPI_LOG_THREAD_SCHEDPARAM(level_,sysrc_,prio_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),OSAPI_LOG_THREAD_SCHEDPARAM_EC ,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "sysrc",(sysrc_),"prio",(prio_))

/*ce
 * \brief Failed to get the scheduling policy of a thread
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_GET_POLICY_EC                     (OSAPI_LOG_BASE + 17)
#define OSAPI_LOG_THREAD_GET_POLICY(level_,sysrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),OSAPI_LOG_THREAD_GET_POLICY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"sysrc",(sysrc_))

/*ce
 * \brief Mismatch of scheduling policy of a created thread and the application 
 * thread 
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_POLICY_DIFFER_EC                  (OSAPI_LOG_BASE + 18)
#define OSAPI_LOG_THREAD_POLICY_DIFFER(level_,get_policy_,set_policy_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),OSAPI_LOG_THREAD_POLICY_DIFFER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "get_policy",(get_policy_),"set_policy",(set_policy_))

/*ce
 * \brief Failed to map to native thread priority values
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_THREAD_PRIORITY_MAP_EC                   (OSAPI_LOG_BASE + 19)
#define OSAPI_LOG_THREAD_PRIORITY_MAP(level_,min_,max_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),OSAPI_LOG_THREAD_PRIORITY_MAP_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "min",(min_),"max",(max_))

/* TIMER messages */

/*ce
 * \brief Failed to delete the Timer object
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_TIMER_DELETE_EC                          (OSAPI_LOG_BASE + 20)
#define OSAPI_LOG_TIMER_DELETE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),OSAPI_LOG_TIMER_DELETE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

#define OSAPI_LOG_TIMER_TICK_EC                            (OSAPI_LOG_BASE + 21)

/*ce
 * \brief Failed taking or giving the Timer mutex
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_TIMER_TICK_MUTEX_EC                      (OSAPI_LOG_BASE + 22)
#define OSAPI_LOG_TIMER_TICK_MUTEX(level_,mutex_,take_) \
OSAPI_LOG_ENTRY_CREATE((level_),OSAPI_LOG_TIMER_TICK_MUTEX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,OEI_FALSE)\
OSAPI_LOG_ENTRY_ADD_POINTER("mutex",(mutex_),OEI_FALSE)\
OSAPI_LOG_ENTRY_ADD_INT("take",(take_),OEI_TRUE)

#define OSAPI_LOG_TIMER_CREATE_TIMEOUT_EC                  (OSAPI_LOG_BASE + 23)

#define OSAPI_LOG_TIMER_UPDATE_TIMEOUT_EC                  (OSAPI_LOG_BASE + 24)

#define OSAPI_LOG_TIMER_DELETE_TIMEOUT_EC                  (OSAPI_LOG_BASE + 25)


/*ce
 * \brief Failed to return user data for a timeout due to mismatched epochs
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_TIMER_GET_USER_DATA_EPOCH_EC             (OSAPI_LOG_BASE + 27)
#define OSAPI_LOG_TIMER_GET_USER_DATA_EPOCH(level_,h_,e_,e1_,e2_) \
OSAPI_LOG_ENTRY_CREATE( (level_),OSAPI_LOG_TIMER_GET_USER_DATA_EPOCH_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("h",(h_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("e",(e_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("e1",(e1_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("e2",(e2_),OEI_TRUE)
/*ce
 * \brief Failed to allocate memory for a new Timer
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_TIMER_NEW_EC                             (OSAPI_LOG_BASE + 28)
#define OSAPI_LOG_TIMER_NEW(level_) \
OSAPI_LOG_ENTRY_ADD((level_),OSAPI_LOG_TIMER_NEW_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to allocate memory for a new Timer entry
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_TIMER_NEW_ENTRY_EC                       (OSAPI_LOG_BASE + 29)
#define OSAPI_LOG_TIMER_NEW_ENTRY(level_) \
OSAPI_LOG_ENTRY_ADD((level_),OSAPI_LOG_TIMER_NEW_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to allocate memory for a new Timer wheel
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_TIMER_NEW_WHEEL_EC                       (OSAPI_LOG_BASE + 30)
#define OSAPI_LOG_TIMER_NEW_WHEEL(level_,slots_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),OSAPI_LOG_TIMER_NEW_WHEEL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"slots",(slots_))

/*ce
 * \brief Failed to create a new Timer mutex
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_TIMER_NEW_MUTEX_EC                       (OSAPI_LOG_BASE + 31)
#define OSAPI_LOG_TIMER_NEW_MUTEX(level_) \
OSAPI_LOG_ENTRY_ADD((level_),OSAPI_LOG_TIMER_NEW_MUTEX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to start a new Timer being created
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_TIMER_NEW_START_TIMER_EC                 (OSAPI_LOG_BASE + 32)
#define OSAPI_LOG_TIMER_NEW_START_TIMER(level_,timer_,ticr_) \
OSAPI_LOG_ENTRY_CREATE((level_),OSAPI_LOG_TIMER_NEW_START_TIMER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("timer",(timer_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("ticr",(ticr_),OEI_TRUE)

/*ce
 * \brief Failed to stop a Timer being deleted
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_TIMER_DELETE_STOP_TIMER_EC               (OSAPI_LOG_BASE + 33)
#define OSAPI_LOG_TIMER_DELETE_STOP_TIMER(level_,timer_) \
OSAPI_LOG_ENTRY_ADD_1POINTER((level_),OSAPI_LOG_TIMER_DELETE_STOP_TIMER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"timer",(timer_))

/*ce
 * \brief Failed to delete the Timer mutex
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_TIMER_DELETE_MUTEX_EC                    (OSAPI_LOG_BASE + 34)
#define OSAPI_LOG_TIMER_DELETE_MUTEX(level_,timer_) \
OSAPI_LOG_ENTRY_ADD_1POINTER((level_),OSAPI_LOG_TIMER_DELETE_MUTEX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"timer",(timer_))

/*ce
 * \brief Failed to take or give a Timer mutex
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_TIMER_MUTEX_EC                           (OSAPI_LOG_BASE + 35)
#define OSAPI_LOG_TIMER_MUTEX(level_,mutex_,take_) \
        OSAPI_LOG_ENTRY_CREATE((level_),OSAPI_LOG_TIMER_MUTEX_EC,OSAPI_LOG_MSG_PN_X2_STD_PARAM,OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("mutex",(mutex_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("take",(take_),OEI_TRUE)

/* Semaphore messages */

/*ce
 * \brief Failed to delete a semaphore
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_SEMAPHORE_DELETE_EC                      (OSAPI_LOG_BASE + 36)
#define OSAPI_LOG_SEMAPHORE_DELETE(level_,sysrc_) \
OSAPI_LOG_ENTRY_ADD_1INT( (level_),OSAPI_LOG_SEMAPHORE_DELETE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"sysrc",(sysrc_))

/*ce
 * \brief Failed to create a semaphore
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_SEMAPHORE_NEW_EC                         (OSAPI_LOG_BASE + 37)
#define OSAPI_LOG_SEMAPHORE_NEW(level_) \
OSAPI_LOG_ENTRY_ADD( (level_),OSAPI_LOG_SEMAPHORE_NEW_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to initialize a new semaphore
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_SEMAPHORE_NEW_INIT_EC                    (OSAPI_LOG_BASE + 38)
#define OSAPI_LOG_SEMAPHORE_NEW_INIT(level_,sysrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),OSAPI_LOG_SEMAPHORE_NEW_INIT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"sysrc",(sysrc_))

/*ce
 * \brief Failed to give a semaphore
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_SEMAPHORE_GIVE_EC                        (OSAPI_LOG_BASE + 39)
#define OSAPI_LOG_SEMAPHORE_GIVE(level_,sysrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),OSAPI_LOG_SEMAPHORE_GIVE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"sysrc",(sysrc_))

/*ce
 * \brief Failed to take a semaphore
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_SEMAPHORE_TAKE_EC                        (OSAPI_LOG_BASE + 40)
#define OSAPI_LOG_SEMAPHORE_TAKE(level_,sysrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),OSAPI_LOG_SEMAPHORE_TAKE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"sysrc",(sysrc_))

/* Mutex messages */

/*ce
 * \brief Failed to delete a mutex
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_MUTEX_DELETE_EC                          (OSAPI_LOG_BASE + 41)
#define OSAPI_LOG_MUTEX_DELETE(level_,sysrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),OSAPI_LOG_MUTEX_DELETE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"sysrc",(sysrc_))

/*ce
 * \brief Failed to create a mutex
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_MUTEX_NEW_EC                             (OSAPI_LOG_BASE + 42)
#define OSAPI_LOG_MUTEX_NEW(level_) \
OSAPI_LOG_ENTRY_ADD((level_),OSAPI_LOG_MUTEX_NEW_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to take a mutex
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_MUTEX_TAKE_EC                            (OSAPI_LOG_BASE + 43)
#define OSAPI_LOG_MUTEX_TAKE(level_,sysrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),OSAPI_LOG_MUTEX_TAKE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"sysrc",(sysrc_))

/*ce
 * \brief Failed to give a mutex
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_MUTEX_GIVE_EC                            (OSAPI_LOG_BASE + 44)
#define OSAPI_LOG_MUTEX_GIVE(level_,sysrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),OSAPI_LOG_MUTEX_GIVE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"sysrc",(sysrc_))

/*ce
 * \brief Failed to initialize a mutex
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_MUTEX_INIT_EC                            (OSAPI_LOG_BASE + 45)
#define OSAPI_LOG_MUTEX_INIT(level_,sysrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),OSAPI_LOG_MUTEX_INIT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"sysrc",(sysrc_))

/* HEAP */

/*ce
 * \brief Failed to allocate a buffer from the heap
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_HEAP_INTERNAL_ALLOCATE_EC                (OSAPI_LOG_BASE + 46)
#define OSAPI_LOG_HEAP_INTERNAL_ALLOCATE(level_,s_,a_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),OSAPI_LOG_HEAP_INTERNAL_ALLOCATE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,\
        "s",(s_),"a",(a_))

#define OSAPI_LOG_HEAP_FREE_EC                             (OSAPI_LOG_BASE + 47)

/*ce
 * \brief Failed to get current system time
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_SYSTEM_GET_TIME_EC                       (OSAPI_LOG_BASE + 48)
#define OSAPI_LOG_SYSTEM_GET_TIME(level_,sysrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),OSAPI_LOG_SYSTEM_GET_TIME_EC,\
    OSAPI_LOG_MSG_PN_X2_STD_PARAM,"sysrc",(sysrc_))

/*ce
 * \brief Return the last recorded error-code for the calling thread
 *
 * \details
 * This log-messages retrieves the last recorded error-code for the
 * calling thread. It is used a function calls another function that
 * fails.
 *
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_LAST_RECORDED_ERROR_EC                   (OSAPI_LOG_BASE + 49)
#define OSAPI_LOG_LAST_RECORDED_ERROR(level_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),OSAPI_LOG_LAST_RECORDED_ERROR_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"rc",OSAPI_Log_get_last_error_code())

/*ce
 * \brief Failed to set the thread name in the OS
 *
 * \details
 * When OSAPI starts a thread it also calls the OS to set the thread name. If this 
 * fails this warning message indicates why.
 *
 * \ingroup OSAPILogCodesClass
 */
#define OSAPI_LOG_SET_THREAD_NAME_EC                       (OSAPI_LOG_BASE + 50)
#define OSAPI_LOG_SET_THREAD_NAME(level_,rc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),OSAPI_LOG_SET_THREAD_NAME_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,"rc",(rc_))

/******************************************************************************/

#if OSAPI_ENABLE_LOG
/******************************************************************************
 *                                Log types
 ******************************************************************************/
/*ci
 * \ingroup OSAPILogClass
 * \brief Log message as an error
 */
typedef enum
{
    OSAPI_LOGKIND_ERROR   = 0,
    OSAPI_LOGKIND_WARNING,
    OSAPI_LOGKIND_INFO,
    OSAPI_LOGKIND_PRECONDITION
} OSAPI_LogKind_T;

typedef OEI_UINT32 OSAPI_LogEntryHeader_T;
typedef OEI_UINT32 OSAPI_LogEntryPayloadElement_T;

/*  31  30  29   28-27   26-16   15 14-0
 * +---+---+---+------+--------+--------+
 * | X | E | T | TYPE | MODULE | F | EC |
 * +---+---+---+------+--------+--------+
 */
#define OSAPI_LOG_HEADER_GET_X(hdr_)      ((hdr_)>>31)
#define OSAPI_LOG_HEADER_GET_E(hdr_)      ((hdr_)>>30 & 0x1)
#define OSAPI_LOG_HEADER_GET_T(hdr_)      ((hdr_)>>29 & 0x1)
#define OSAPI_LOG_HEADER_GET_TYPE(hdr_)   (((hdr_) >>27) & 0x3)
#define OSAPI_LOG_HEADER_GET_MODULE(hdr_) (((hdr_) >>16) & 0x7ff)
#define OSAPI_LOG_HEADER_GET_EC(hdr_)     ((hdr_) & 0x7fff)
#define OSAPI_LOG_HEADER_GET_F(hdr_)      ((hdr_)>>15 & 0x1)

#define OSAPI_LOG_HEADER_SET_X(hdr_)          ((hdr_) |= 0x80000000)
#define OSAPI_LOG_HEADER_CLR_X(hdr_)          ((hdr_) &= ~0x80000000)
#define OSAPI_LOG_HEADER_SET_E(hdr_)          ((hdr_) |= 0x40000000)
#define OSAPI_LOG_HEADER_SET_T(hdr_)          ((hdr_) |= 0x20000000)
#define OSAPI_LOG_HEADER_CLR_T(hdr_)          ((hdr_) &= ~0x20000000)
#define OSAPI_LOG_HEADER_SET_TYPE(hdr_,type_) ((hdr_) |= ((type_) << 27))
#define OSAPI_LOG_HEADER_SET_MODULE(hdr_,m_)  ((hdr_) |= ((m_) << 16))
#define OSAPI_LOG_HEADER_SET_EC(hdr_,ec)      ((hdr_) |= (ec_))
#define OSAPI_LOG_HEADER_SET_F(hdr_)          ((hdr_) |= 0x8000)
#define OSAPI_LOG_HEADER_CLR_F(hdr_)          ((hdr_) &= ~0x8000)

#define OSAPI_LOG_STATUS_MN (0x80000000)
#define OSAPI_LOG_STATUS_SF (0x40000000)
#define OSAPI_LOG_STATUS_FN (0x20000000)
#define OSAPI_LOG_STATUS_LN (0x10000000)
#define OSAPI_LOG_STATUS_F  (0x08000000)

#define OSAPI_LOG_STATUS_ALL \
        (OSAPI_LOG_STATUS_MN | \
         OSAPI_LOG_STATUS_SF | \
         OSAPI_LOG_STATUS_FN | \
         OSAPI_LOG_STATUS_LN)

#define OSAPI_LOG_STATUS_NO_DATA \
        (OSAPI_LOG_STATUS_MN | \
         OSAPI_LOG_STATUS_SF | \
         OSAPI_LOG_STATUS_FN | \
         OSAPI_LOG_STATUS_LN)

typedef enum
{
    OSAPI_LOGTYPE_INTEGER,
    OSAPI_LOGTYPE_STRING,
    OSAPI_LOGTYPE_POINTER
} OSAPI_LogType_T;

typedef struct OSAPI_LogDataEntry
{
    OSAPI_LogType_T type;
    char *name;
    union
    {
        OEI_INT32 int_value;
        char *string_value;
        void *ptr_value;
    } value;
} OSAPI_LogDataEntry_T;

#define OSAPI_LOGDATA_SET_F(hdr_)          ((hdr_) |= 0x80000000)
#define OSAPI_LOGDATA_GET_F(hdr_)          ((hdr_)>>31 & 0x1)
#define OSAPI_LOGDATA_SET_TYPE(hdr_,type_) ((hdr_) |= ((type_)<<27))
#define OSAPI_LOGDATA_GET_TYPE(hdr_)       (((hdr_)>>27) & 0xf)

#if OSAPI_ENABLE_TRACE
typedef enum
{
    OSAPI_TRACETYPE_HEADER,
    OSAPI_TRACETYPE_INT32,
    OSAPI_TRACETYPE_STRING,
    OSAPI_TRACETYPE_GUID,
    OSAPI_TRACETYPE_V4_AS_INT32,
    OSAPI_TRACETYPE_V12_AS_INT32
} OSAPI_TraceType_T;
#endif

/*ci
 * \brief A log-entry in the log-buffer
 *
 * \details
 * Each log-entry in the log-buffer has a fixed sized buffer followed
 * by a variable length part that depends on the log-information stored.
 * The following notation is commonly used in the code:
 *
 * data_ptr = (char*)&log_entry[1]
 *
 * The data-pointer now points to the beginning of the variable length
 * data part that follows the fixed size header.
 *
 * \verbatim
 * +-----------------+ Log-buffer
 * |  OSAPI_LogEntry |
 * |                 |
 * +- - - - - - - - -+ <- data_ptr
 * |                 |
 * | log-data        |
 * |                 |
 * +-----------------+ Log-buffer
 * |  OSAPI_LogEntry |
 * |                 |
 * +- - - - - - - - -+
 * |                 |
 * | log-data        |
 * |                 |
 * +-----------------+
 *
 * \endverbatim
 */
typedef struct OSAPI_LogEntry
{
    /*ci
     * \brief time this message was logged
     */
    OSAPI_NtpTime timestamp;

    /*ci
     * \brief The error code
     */
    OEI_UINT32 error_code;

} OSAPI_LogEntry_T;

/*e
 */
typedef enum
{
    /* e \dref_LogVerbosity_OSAPI_LOG_VERBOSITY_SILENT */
    OSAPI_LOG_VERBOSITY_SILENT  = 0,
    /* e \dref_LogVerbosity_OSAPI_LOG_VERBOSITY_ERROR */
    OSAPI_LOG_VERBOSITY_ERROR   = 1,
    /* e \dref_LogVerbosity_OSAPI_LOG_VERBOSITY_WARNING */
    OSAPI_LOG_VERBOSITY_WARNING = 2,
    /* e \dref_LogVerbosity_OSAPI_LOG_VERBOSITY_DEBUG */
    OSAPI_LOG_VERBOSITY_DEBUG   = 3
} OSAPI_LogVerbosity_T;

typedef void
(*OSAPI_Log_write_buffer_T)(const char *buffer,OEI_INT32 length);

/*ce 
 * \ingroup OSAPILogClass
 * \brief Configuration of logging functionality
 */
struct OSAPI_LogProperty
{
    /*ce 
     *  
     * \brief The maximum number of bytes allocated to the log buffer. 
     *  
     * \details 
     * Log entries are of variable length.  When this limit has been reached, 
     * no more log entries can be stored unless the buffer is cleared.
     */
    OEI_SIZE_T max_buffer_size;

    /*ce \brief Bitmap to control the fidelity of what is stored in the log 
     * entry
     */
    OEI_UINT32 log_detail;

    /*ce \brief Function pointer to output a log/trace buffer
     */
    OSAPI_Log_write_buffer_T write_buffer;
};


#define OSAPI_LOG_DETAIL_MODULENAME                             (0x80000000UL)
#define OSAPI_LOG_DETAIL_SOURCEFILE                             (0x40000000UL)
#define OSAPI_LOG_DETAIL_LINENUMBER                             (0x20000000UL)
#define OSAPI_LOG_DETAIL_FUNCTIONAME                            (0x10000000UL)
#define OSAPI_LOG_DETAIL_FORMAT                                 (0x08000000UL)
#define OSAPI_LOG_DETAIL_DATA_ONLY                              (0x04000000UL)

#define OSAPI_LOG_DETAIL_ALL \
        (OSAPI_LOG_DETAIL_MODULENAME | \
         OSAPI_LOG_DETAIL_SOURCEFILE | \
         OSAPI_LOG_DETAIL_LINENUMBER | \
         OSAPI_LOG_DETAIL_FUNCTIONAME | \
         OSAPI_LOG_DETAIL_FORMAT | \
         OSAPI_LOG_DETAIL_DATA_ONLY)

#define OSAPI_LOG_DETAIL_NO_DATA \
        (OSAPI_LOG_DETAIL_MODULENAME | \
         OSAPI_LOG_DETAIL_SOURCEFILE | \
         OSAPI_LOG_DETAIL_LINENUMBER | \
         OSAPI_LOG_DETAIL_FUNCTIONAME )

#if OSAPI_ENABLE_PRECONDITION
#define OSAPI_LOG_BUFFER_SIZE (16384)
#else
#define OSAPI_LOG_BUFFER_SIZE (128)
#endif

#define OSAPI_LogProperty_INIITALIZER \
{\
    OSAPI_LOG_BUFFER_SIZE,\
    OSAPI_LOG_DETAIL_ALL,\
    NULL\
}

#if OSAPI_ENABLE_TRACE
typedef void
(*OSAPI_TraceHandler_T)(OEI_UINT32 trace_mask,
                        void *param,
                        OEI_INT32 context,
                        const char *const module,
                        const char *const file,
                        const char *const function,
                        OEI_INT32 line_no,
                        OSAPI_TraceType_T type,
                        const void *title,
                        OEI_INT32 int_value,
                        const void *ptr_value,
                        const char *str_value,
                        OEI_BOOL is_final);

OSAPIDllVariable extern OSAPI_TraceHandler_T OSAPI_gv_TraceFunction;
OSAPIDllVariable extern void* OSAPI_gv_TraceFunctionParam;
OSAPIDllVariable extern OEI_UINT32 OSAPI_gv_TraceMask;
#endif

/*ce 
 * \ingroup OSAPILogClass
 * \brief Optional user-defined function for processing new log messages 
 *  
 * \details Definition of a function that can be installed with the logger and 
 * that will be called for each new log event. 
 *  
 * The handler is set by OSAPI_Log_set_log_handler. 
 *  
 * When called, provides parameters containing the raw log entry and additional 
 * optional information. 
 *  
 *  
 * \param[in] param User-defined payload
 * \param[in] msg   Log entry
 * \param[in] kind  Kind of log message
 * \param[in] ec    Unique error code of log message
 * \param[in] module Module of log message
 * \param[in] file  Name of source file. Optional.
 * \param[in] func  Name of function. Optional.
 * \param[in] line  Line number. Optional.
 * \param[in] argc  Variable length argument count
 * \param[in] ap    Variable length argument list
 */
typedef void
(*OSAPI_LogHandler_T)(void *param,OSAPI_LogEntry_T *entry);

typedef void
(*OSAPI_LogDisplay_T)(void *param,OSAPI_LogEntry_T *msg);

OSAPIDllVariable extern OSAPI_LogHandler_T OSAPI_gv_LogFunction;
OSAPIDllVariable extern void* OSAPI_gv_LogFunctionParam;

OSAPIDllVariable extern OSAPI_LogDisplay_T OSAPI_gv_LogDisplayFunction;
OSAPIDllVariable extern void* OSAPI_gv_LogDisplayFunctionParam;

/*ce
 * \ingroup OSAPILogClass
 * \brief Install a log handler
 *
 * \details
 * The log functionality allows the user to specify a log handler. The log
 * handler is a function which is called for every logged event. It is up
 * to the user to decide what to do with the log message. The handler is
 * a global function pointer.
 *
 * \param [in] handler Pointer to log handler function
 * \param [in] param   Parameter passed to the log handler function. This
 *                     parameter is transparent to the log functionality.
 *
 * \return OEI_TRUE on success, OEI_FALSE on failure
 *
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Log_set_log_handler(OSAPI_LogHandler_T handler,void *param);

/*ce 
 * \ingroup OSAPILogClass
 * \brief Return the current log handler
 *
 * \details
 * Return the current log handler.
 *
 * \param [in] handler Pointer to store log handler function
 * \param [in] param   Pointer to store the current log handler parameter.
 *
 * \return OEI_TRUE on success, OEI_FALSE on failure
 *
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Log_get_log_handler(OSAPI_LogHandler_T *handler,void **param);

#if OSAPI_ENABLE_TRACE
/*ce 
 * \ingroup OSAPILogClass
 * \brief Install a trace handler
 *
 * \details
 * Install a custom trace handler. Traces are not stored in the log-buffer
 * and is generally used to analyze behavior interactively. the default
 * trace handler outputs the trace data to a console.
 *
 * \param [in] handler Pointer to trace handler function
 * \param [in] param   Parameter passed to the trace handler function. This
 *                     parameter is transparent to the trace functionality.
 *
 * \return OEI_TRUE on success, OEI_FALSE on failure
 *
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Log_set_trace_handler(OSAPI_TraceHandler_T handler,void *param);

/*ce
 * \brief Return the trace handler
 * \ingroup OSAPILogClass
 *
 * \details
 * Return the current trace handler and trace parameter. This information
 * can be used to daisy-chain calls to multiple trace-handlers.
 *
 * \param [in] handler Pointer to store trace handler function
 * \param [in] param   Pointer to store the trace handler parameter.
 *
 * \return OEI_TRUE on success, OEI_FALSE on failure
 *
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Log_get_trace_handler(OSAPI_TraceHandler_T *handler,void **param);
#endif

/*ce
 * \ingroup OSAPILogClass
 * \brief Install a display handler
 *
 * \details
 * The display handler is responsible for outputting log messages to a console.
 *
 * \param [in] handler Pointer to display function
 * \param [in] param   Parameter passed to the display handler function. This
 *                     parameter is transparent to the log functionality.
 *
 * \return OEI_TRUE on success, OEI_FALSE on failure
 *
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Log_set_display_handler(OSAPI_LogDisplay_T handler,void *param);

/*ce
 * \brief Return the current display function
 * \ingroup OSAPILogClass
 *
 * \details
 * Return the current log handler.
 *
 * \param [in] handler Pointer to store display handler function
 * \param [in] param   Pointer to store the current display handler parameters.
 *
 * \return OEI_TRUE on success, OEI_FALSE on failure
 *
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Log_get_display_handler(OSAPI_LogDisplay_T *handler,void **param);

/*ce
 * \brief Initialize the log functionality
 * \ingroup OSAPILogClass
 *
 * \details
 * Dynamically allocates bytes for the log ring buffer. Also prints out endianness.
 * If store_debug_logs is false, debug-level logs are printed to the console.
 * 0Otherwise, the logs are stored in the log buffer.
 * The log functionality must be initialized before any log messages can be
 * stored. It should only be called once. Since debug logs can easily exhaust
 * the log buffer, it can optionally be enabled. However, even if debug
 * logging is disabled, the log handler function still has the option
 * to store it.
 *
 * \return OEI_TRUE on success, OEI_FALSE on failure
 */
MUST_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Log_initialize(void);

/*ce
 * \ingroup OSAPILogClass
 * \brief Finalize the log buffer
 *
 * \details
 * This function release all memory allocated to the log buffer and release
 * all resources associated with it.
 *
 * \return OEI_TRUE on success, OEI_FALSE on failure
 *
 * \sa \ref OSAPI_Log_initialize
 */
SHOULD_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Log_finalize(void);

/*ce
 * \ingroup OSAPILogClass
 * \brief Set the log verbosity
 *
 * \details
 * Change the log verbosity. The new setting takes immediate effect.
 *
 * \param [in] verbosity New log verbosity
 *
 */
OSAPIDllExport void
OSAPI_Log_set_verbosity(OSAPI_LogVerbosity_T verbosity);

#if OSAPI_ENABLE_TRACE
/*ce
 * \ingroup OSAPILogClass
 * \brief Set the trace mask
 *
 * \param [in] mask New trace mask
 */
OSAPIDllExport void
OSAPI_Trace_set_trace_mask(OEI_UINT32 mask);
#endif

/*ce
 * \ingroup OSAPILogClass
 * \brief Clear the log buffer
 *
 * \details
 * Clear the log buffer, all the current entries are lost
 *
 * \return OEI_TRUE on success, OEI_FALSE on failure
 */
SHOULD_CHECK_RETURN OSAPIDllExport OEI_BOOL
OSAPI_Log_clear(void);

/*ce
 * \brief Returns the error code for a function that failed
 * \ingroup OSAPILogClass
 *
 * \details
 * Many functions returns OEI_FALSE or NULL on failure. In order to provide
 * additional information about reason for the failure fucntions may set
 * an additional error code. This function returns the last error-code
 * recorded for the calling thread.
 *
 * \return Last error-code recorded for this thread
 *
 */
OSAPIDllExport OEI_INT32
OSAPI_Log_get_last_error_code(void);

/*ci
 * \brief Get the current log properties
 * \ingroup OSAPILogClass
 *
 * \details
 * Return the current log properties
 *
 * \param[out]  property  - Current log properties
 *
 * \sa OSAPI_Log_set_property
 */
OSAPIDllExport void
OSAPI_Log_get_property(struct OSAPI_LogProperty *property);

/*ci
 * \brief Set the log properties
 * \ingroup OSAPILogClass
 *
 * \details
 * Set the current log properties. It is not possible to set new
 * properties after OSAPI_Log_initialize() has been called/
 *
 * \param[in]  property New log properties
 *
 * \return OEI_TRUE if new properties can be set, OEI_FALSE otherwise
 * \sa OSAPI_Log_get_property
 */
OSAPIDllExport OEI_BOOL
OSAPI_Log_set_property(struct OSAPI_LogProperty *property);

/*ci
 * \brief Get the current log verbosity
 * \ingroup OSAPILogClass
 *
 * \return Current verbosity
 */
OSAPIDllExport OSAPI_LogVerbosity_T
OSAPI_Log_get_verbosity(void);

/*ci
 * \brief Create a new log-entry
 *
 * \ingroup OSAPILogClass
 *
 * \param[in] kind       The type of log entry
 * \param[in] error_code The error-code
 * \param[in] module     The name of the module logging the error
 * \param[in] file       The file logging the error
 * \param[in] line       The line number in file the error is logged
 * \param[in] is_final   If OEI_TRUE more data follows, if OEI_FALSE then
 *                       the log meesage is considered complete.
 */
OSAPIDllExport void
OSAPI_Log_entry_create(OSAPI_LogKind_T kind, OEI_INT32 error_code,
                       const char *const module, const char *const file,
                       const char *const func, OEI_INT32 line,OEI_BOOL is_final);

/*ci
 * \brief Add an integer to a log-entry
 *
 * \ingroup OSAPILogClass
 *
 * \param[in] name     The name of the integer being logged
 * \param[in] value    The value of the integer being logged
 * \param[in] is_final OEI_TRUE if this is the last value added to the log entry
 *                     OEI_FALSE if more values are being added to the log entry
 */
OSAPIDllExport void
OSAPI_Log_entry_add_int(const char *name,OEI_INT32 value,OEI_BOOL is_final);

/*ci
 * \brief Add a string to a log-entry
 *
 * \ingroup OSAPILogClass
 *
 * \param[in] name     The name of the string being logged
 * \param[in] value    The value of the string being logged
 * \param[in] is_final OEI_TRUE if this is the last value added to the log entry
 *                     OEI_FALSE if more values are being added to the log entry
 */
OSAPIDllExport void
OSAPI_Log_entry_add_string(const char *name,const char *value,OEI_BOOL is_final);


/*ci
 * \brief Add a pointer to a log-entry
 *
 * \ingroup OSAPILogClass
 *
 * \param[in] name     The name of the pointer being logged
 * \param[in] value    The value of the pointer being logged
 * \param[in] is_final OEI_TRUE if this is the last value added to the log entry
 *                     OEI_FALSE if more values are being added to the log entry
 */
OSAPIDllExport void
OSAPI_Log_entry_add_pointer(const char *name,const void *value,OEI_BOOL is_final);

OSAPIDllExport OEI_BOOL
OSAPI_Log_entry_get_data(OSAPI_LogEntry_T *log_entry,char **data_ptr,
                         OSAPI_LogType_T *type,const char **name,
                         const void **value,OEI_BOOL *is_final);

/*ci
 * \brief Create a new log-entry for an error-code with no additional data
 *
 * \ingroup OSAPILogClass
 *
 * \param[in] kind       The type of log entry
 * \param[in] error_code The error-code
 * \param[in] module     The name of the module logging the error
 * \param[in] file       The file logging the error
 * \param[in] line       The line number in file the error is logged
 *
 * \sa OSAPI_Log_entry_create
 */
OSAPIDllExport void
OSAPI_Log_entry_add(OSAPI_LogKind_T kind, OEI_INT32 error_code,
                       const char *const module, const char *const file,
                       const char *const func, OEI_INT32 line);

/*ci
 * \brief Create a new log-entry with a single integer
 *
 * \ingroup OSAPILogClass
 *
 * \param[in] kind       The type of log entry
 * \param[in] error_code The error-code
 * \param[in] module     The name of the module logging the error
 * \param[in] file       The file logging the error
 * \param[in] line       The line number in file the error is logged
 * \param[in] name       The name of the integer being logged
 * \param[in] value      The value of the integer being logged
 *
 */
OSAPIDllExport void
OSAPI_Log_entry_add_1int(OSAPI_LogKind_T kind, OEI_INT32 error_code,
                        const char *const module, const char *const file,
                        const char *const func, OEI_INT32 line,const char *name,
                        OEI_INT32 value);


/*ci
 * \brief Create a new log-entry with a 2 integers
 *
 * \ingroup OSAPILogClass
 *
 * \param[in] kind       The type of log entry
 * \param[in] error_code The error-code
 * \param[in] module     The name of the module logging the error
 * \param[in] file       The file logging the error
 * \param[in] line       The line number in file the error is logged
 * \param[in] name1      The name of the 1st integer being logged
 * \param[in] value1     The value of the 1st integer being logged
 * \param[in] name2      The name of the 2nd integer being logged
 * \param[in] value2     The value of the 2nd integer being logged
 *
 */
OSAPIDllExport void
OSAPI_Log_entry_add_2int(OSAPI_LogKind_T kind, OEI_INT32 error_code,
                        const char *const module, const char *const file,
                        const char *const func, OEI_INT32 line,
                        const char *name1,OEI_INT32 value1,
                        const char *name2,OEI_INT32 value2);

/*ci
 * \brief Create a new log-entry with a 3 integers
 *
 * \ingroup OSAPILogClass
 *
 * \param[in] kind       The type of log entry
 * \param[in] error_code The error-code
 * \param[in] module     The name of the module logging the error
 * \param[in] file       The file logging the error
 * \param[in] line       The line number in file the error is logged
 * \param[in] name1      The name of the 1st integer being logged
 * \param[in] value1     The value of the 1st integer being logged
 * \param[in] name2      The name of the 2nd integer being logged
 * \param[in] value2     The value of the 2nd integer being logged
 * \param[in] name3      The name of the 3rd integer being logged
 * \param[in] value3     The value of the 3rd integer being logged
 *
 */
OSAPIDllExport void
OSAPI_Log_entry_add_3int(OSAPI_LogKind_T kind, OEI_INT32 error_code,
                        const char *const module, const char *const file,
                        const char *const func, OEI_INT32 line,
                        const char *name1,OEI_INT32 value1,
                        const char *name2,OEI_INT32 value2,
                        const char *name3,OEI_INT32 value3);

/*ci
 * \brief Create a new log-entry with a single string
 *
 * \ingroup OSAPILogClass
 *
 * \param[in] kind       The type of log entry
 * \param[in] error_code The error-code
 * \param[in] module     The name of the module logging the error
 * \param[in] file       The file logging the error
 * \param[in] line       The line number in file the error is logged
 * \param[in] name       The name of the string being logged
 * \param[in] value      The value of the string being logged
 *
 */
OSAPIDllExport void
OSAPI_Log_entry_add_1string(OSAPI_LogKind_T kind, OEI_INT32 error_code,
                            const char *const module, const char *const file,
                            const char *const func, OEI_INT32 line,
                            const char *name,const char* value);

/*ci
 * \brief Create a new log-entry with a 2 strings
 *
 * \ingroup OSAPILogClass
 *
 * \param[in] kind       The type of log entry
 * \param[in] error_code The error-code
 * \param[in] module     The name of the module logging the error
 * \param[in] file       The file logging the error
 * \param[in] line       The line number in file the error is logged
 * \param[in] name1       The name of the 1st string being logged
 * \param[in] value1      The value of the 1st string being logged
 * \param[in] name2       The name of the 2nd string being logged
 * \param[in] value2      The value of the 2nd string being logged
 *
 */
OSAPIDllExport void
OSAPI_Log_entry_add_2string(OSAPI_LogKind_T kind, OEI_INT32 error_code,
                        const char *const module, const char *const file,
                        const char *const func, OEI_INT32 line,
                        const char *name1,const char* value1,
                        const char *name2,const char* value2);

/*ci
 * \brief Create a new log-entry with a single pointer
 *
 * \ingroup OSAPILogClass
 *
 * \param[in] kind       The type of log entry
 * \param[in] error_code The error-code
 * \param[in] module     The name of the module logging the error
 * \param[in] file       The file logging the error
 * \param[in] line       The line number in file the error is logged
 * \param[in] name       The name of the pointer being logged
 * \param[in] value      The value of the pointer being logged
 *
 */
OSAPIDllExport void
OSAPI_Log_entry_add_1pointer(OSAPI_LogKind_T kind, OEI_INT32 error_code,
                            const char *const module, const char *const file,
                            const char *const func, OEI_INT32 line,
                            const char *name, const void* value);

/*ci
 * \brief Create a new log-entry with a single string and a integer
 *
 * \ingroup OSAPILogClass
 *
 * \param[in] kind       The type of log entry
 * \param[in] error_code The error-code
 * \param[in] module     The name of the module logging the error
 * \param[in] file       The file logging the error
 * \param[in] line       The line number in file the error is logged
 * \param[in] s_name     The name of the string being logged
 * \param[in] s_value    The value of the string being logged
 * \param[in] i_name     The name of the integer being logged
 * \param[in] i_value    The value of the string being logged
 */
OSAPIDllExport void
OSAPI_Log_entry_add_1string_1int(OSAPI_LogKind_T kind, OEI_INT32 error_code,
                            const char *const module, const char *const file,
                            const char *const func, OEI_INT32 line,
                            const char *s_name,const char* s_value,
                            const char *i_name,OEI_INT32 i_value);
#endif /* OSAPI_ENABLE_LOG */

/*ci
 * \brief Convert an integer to a string in decimal format
 * *
 * \param[inout] buffer      Buffer to store result in
 * \param[in]    max_length  Maximum length of the buffer
 * \param[in]    d           The digit to convert
 *
 * \return The number of characters placed in the buffer excluding the
 *         NULL termination. If there is insufficient space max_length
 *         is returned.
 */
OSAPIDllExport OEI_INT32
OSAPI_Log_itoa(char *buffer,OEI_INT32 max_length,OEI_INT32 d);

#ifdef __cplusplus
}                               /* extern "C" */
#endif

#include "osapi/osapi_log_impl.h"

#endif /* osapi_log_h */
