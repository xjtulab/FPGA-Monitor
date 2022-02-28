#ifndef dds_cpp_rt_hxx
#define dds_cpp_rt_hxx

#ifndef dds_cpp_dll_hxx
#include "dds_cpp/dds_cpp_dll.hxx"
#endif
#ifndef dds_cpp_infrastructure_hxx
#include "dds_cpp/dds_cpp_infrastructure.hxx"
#endif

#ifndef rt_rt_h
#include "rt/rt_rt.h"
#endif

class DDSDomainParticipantFactory_impl;

class DDSCPPDllExport RTRegistry
{
    friend class DDSDomainParticipantFactory_impl;

public:
    bool register_component(const char *name,
                        RT_ComponentFactoryI *intf,
                        RT_ComponentFactoryProperty *property,
                        RT_ComponentFactoryListener *listener);

    bool unregister(const char *name,
                        RT_ComponentFactoryProperty **property,
                        RT_ComponentFactoryListener **listener);
protected:
    RTRegistry();
    ~RTRegistry();

    static RTRegistry* get_instance();
    static RTRegistry *registry;
    RT_Registry_T *c_registry;
};

#endif /* dds_cpp_rt_hxx */
