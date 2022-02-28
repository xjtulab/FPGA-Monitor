/*
 * FILE: rh_sm_history.h - Reader History API
 *
 */
/*ce
 * \file
 * \brief Reader History API
 */
/*ci \addtogroup RHSMModule
 * @{
 */
#ifndef rh_sm_history_h
#define rh_sm_history_h

#ifndef rh_sm_dll_h
#include "rh_sm/rh_sm_dll.h"
#endif
#ifndef osapi_heap_h
#include "osapi/osapi_heap.h"
#endif
#ifndef osapi_mutex_h
#include "osapi/osapi_mutex.h"
#endif
#ifndef osapi_time_h
#include "osapi/osapi_time.h"
#endif
#ifndef osapi_system_h
#include "osapi/osapi_system.h"
#endif
#ifndef reda_buffer_h
#include "reda/reda_buffer.h"
#endif
#ifndef dds_c_discovery_plugin_h
#include "dds_c/dds_c_discovery_plugin.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

struct RHSM_History;

/*ci
 * \brief RHSM History properties
 */
struct RHSM_HistoryProperty
{
    /*ci
     * \brief Inherited properties from the base-class
     */
    struct DDSHST_ReaderProperty _parent;
};

/*ci
 * \def DDSHST_ReaderProperty_INITIALIZER
 * \brief Constant to initialize \ref RHSM_HistoryProperty
 */
#define RHSM_HistoryProperty_INITIALIZER {\
    DDSHST_ReaderProperty_INITIALIZER \
}

/*ci
 * \def RHSM_HISTORY_INTERFACE_ID
 * \brief The RHSM interface id
 */
#define RHSM_HISTORY_INTERFACE_ID \
                            RT_MKINTERFACEID(RT_COMPONENT_CLASS_RHISTORY,\
                            RT_COMPONENT_INSTANCE_RHISTORY_SM)

/*e \dref_RHSM_ComponentFactory_get_instance
 */
MUST_CHECK_RETURN RHSMDllExport struct RT_ComponentFactoryI*
RHSM_HistoryFactory_get_interface(void);

#ifdef __cplusplus
}                               /* extern "C" */
#endif


#endif

/*ci @} */

