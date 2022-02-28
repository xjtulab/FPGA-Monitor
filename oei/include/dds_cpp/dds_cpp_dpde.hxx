#ifndef dds_cpp_dpde_hxx
#define dds_cpp_dpde_hxx

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
#ifndef disc_dpde_discovery_plugin_h
#include "disc_dpde/disc_dpde_discovery_plugin.h"
#endif

class DDSCPPDllExport DPDEDiscoveryFactory {
public:
    static struct RT_ComponentFactoryI* get_interface();
};

#endif /* dds_cpp_dpde_hxx */
