/*
 * FILE: wh_sm_history.h - Writer History API
 *
 */
/*ce
 * \file
 * \brief Writer History API
 */
/*ci \addtogroup WHSMModule
 * @{
 */
#ifndef wh_sm_history_h
#define wh_sm_history_h

#ifndef wh_sm_dll_h
#include "wh_sm/wh_sm_dll.h"
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
#ifndef dds_c_discovery_h
#include "dds_c/dds_c_discovery.h"
#endif
#ifndef dds_c_type_h
#include "dds_c/dds_c_type.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

struct WHSM_History;

/*ci
 * \brief WHSM History properties
 */
struct WHSM_HistoryProperty
{
    /*ci
     * \brief Inherited properties from the base-class
     */
    struct DDSHST_WriterProperty _parent;
};

/*ci
 * \def WHSM_HistoryProperty_INITIALIZER
 * \brief Constant to initialize \ref WHSM_HistoryProperty
 */
#define WHSM_HistoryProperty_INITIALIZER {\
    DDSHST_WriterProperty_INITIALIZER\
}

/*ci
 * \def WHSM_HISTORY_INTERFACE_ID
 * \brief The WHSM interface id
 */
#define WHSM_HISTORY_INTERFACE_ID RT_MKINTERFACEID(\
            RT_COMPONENT_CLASS_WHISTORY,RT_COMPONENT_INSTANCE_WHISTORY_SM)

/*e \dref_WHSM_ComponentFactory_get_instance
 */
MUST_CHECK_RETURN WHSMDllExport struct RT_ComponentFactoryI*
WHSM_HistoryFactory_get_interface(void);

#ifdef __cplusplus
}                               /* extern "C" */
#endif

#endif

/*ci @} */

