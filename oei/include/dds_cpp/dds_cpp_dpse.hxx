#ifndef dds_cpp_dpse_hxx
#define dds_cpp_dpse_hxx

#ifndef dds_cpp_dll_hxx
#include "dds_cpp/dds_cpp_dll.hxx"
#endif
#ifndef dds_cpp_infrastructure_hxx
#include "dds_cpp/dds_cpp_infrastructure.hxx"
#endif
#ifndef dds_cpp_domain_hxx
#include "dds_cpp/dds_cpp_domain.hxx"
#endif
#ifndef dds_cpp_subscription_hxx
#include "dds_cpp/dds_cpp_subscription.hxx"
#endif
#ifndef rt_rt_h
#include "rt/rt_rt.h"
#endif
#ifndef disc_dpse_dpsediscovery_h
#include "disc_dpse/disc_dpse_dpsediscovery.h"
#endif

class DDSCPPDllExport DPSEDiscoveryFactory {
public:
    static struct RT_ComponentFactoryI* get_interface();
};

class DDSCPPDllExport DPSEDiscoveryPlugin
{
public:
    static DDS_ReturnCode_t
    RemoteParticipant_assert(DDSDomainParticipant *const participant,
                                           const char *rem_participant_name);

    static DDS_ReturnCode_t
    RemotePublication_assert(DDSDomainParticipant * const participant,
                      const char *const rem_participant_name,
                      const struct DDS_PublicationBuiltinTopicData *const data,
                      NDDS_TypePluginKeyKind key_kind);

    static DDS_ReturnCode_t
    RemoteSubscription_assert(DDSDomainParticipant * const participant,
                   const char *const rem_participant_name,
                   const struct DDS_SubscriptionBuiltinTopicData *const data,
                   NDDS_TypePluginKeyKind key_kind);
};

#endif /* dds_cpp_dpse_hxx */
