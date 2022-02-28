#ifndef dds_cpp_osapi_hxx
#define dds_cpp_osapi_hxx

#ifndef dds_cpp_dll_hxx
#include "dds_cpp/dds_cpp_dll.hxx"
#endif
#ifndef dds_cpp_infrastructure_hxx
#include "dds_cpp/dds_cpp_infrastructure.hxx"
#endif
#ifndef osapi_log_h
#include "osapi/osapi_log.h"
#endif

#if OSAPI_ENABLE_LOG

class DDSCPPDllExport OSAPILog {
public:
    static bool initialize();
#ifndef OEI_CERT
    static bool finalize();
#endif /* OEI_CERT */
    static bool clear();
    static bool set_log_handler(OSAPI_LogHandler_T handler,void *param);
    static bool get_log_handler(OSAPI_LogHandler_T *handler,void **param);
#if OSAPI_ENABLE_TRACE
    static bool set_trace_handler(OSAPI_TraceHandler_T handler,void *param);
    static bool get_trace_handler(OSAPI_TraceHandler_T *handler,void **param);
#endif /* OSAPI_ENABLE_TRACE */
    static bool set_display_handler(OSAPI_LogDisplay_T handler,void *param);
    static bool get_display_handler(OSAPI_LogDisplay_T *handler,void **param);

};

#if OSAPI_ENABLE_TRACE
class DDSCPPDllExport OSAPITrace {
public:
    static void set_trace_mask(OEI_UINT32 mask);
};
#endif /* OSAPI_ENABLE_TRACE */

#endif /* OSAPI_ENABLE_LOG */

#endif /* dds_cpp_osapi_hxx */
