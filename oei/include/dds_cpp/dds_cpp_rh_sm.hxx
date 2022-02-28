#ifndef dds_cpp_rh_sm_hx
#define dds_cpp_rh_sm_hx

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
#ifndef rh_sm_history_h
#include "rh_sm/rh_sm_history.h"
#endif

class DDSCPPDllExport RHSMHistoryFactory {
public:
    static struct RT_ComponentFactoryI* get_interface();
};


#endif /* dds_cpp_rh_sm_hx */
