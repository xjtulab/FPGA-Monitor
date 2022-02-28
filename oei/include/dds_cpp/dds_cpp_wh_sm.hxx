#ifndef dds_cpp_wh_sm_hxx
#define dds_cpp_wh_sm_hxx

#ifndef dds_cpp_dll_hxx
#include "dds_cpp/dds_cpp_dll.hxx"
#endif
#ifndef dds_cpp_infrastructure_hxx
#include "dds_cpp/dds_cpp_infrastructure.hxx"
#endif
#ifndef dds_cpp_subscription_hxx
#include "dds_cpp/dds_cpp_subscription.hxx"
#endif
#ifndef rt_rt_h
#include "rt/rt_rt.h"
#endif
#ifndef wh_sm_history_h
#include "wh_sm/wh_sm_history.h"
#endif

class DDSCPPDllExport WHSMHistoryFactory {
public:
    static struct RT_ComponentFactoryI* get_interface();
};


#endif /* dds_cpp_wh_sm_hxx */
