#ifndef dds_cpp_netio_hxx
#define dds_cpp_netio_hxx

#ifndef dds_cpp_dll_hxx
#include "dds_cpp/dds_cpp_dll.hxx"
#endif
#ifndef dds_cpp_infrastructure_hxx
#include "dds_cpp/dds_cpp_infrastructure.hxx"
#endif
#ifndef netio_interface_h
#include "netio/netio_interface.h"
#endif
#ifndef netio_udp_h
#include "netio/netio_udp.h"
#endif

class DDSCPPDllExport UDPInterfaceFactory {
public:
    static struct RT_ComponentFactoryI* get_interface();
};

class DDSCPPDllExport UDPInterfaceTable {
public:
    static bool add_entry(struct UDP_InterfaceTableEntrySeq *seq,
                             OEI_UINT32 address,
                             OEI_UINT32 netmask,
                             const char *ifname,
                             OEI_UINT32 flags);
};

#endif /* dds_cpp_netio_hxx */
