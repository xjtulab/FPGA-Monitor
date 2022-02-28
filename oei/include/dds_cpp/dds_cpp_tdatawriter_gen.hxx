#ifndef dds_cpp_tdatawriter_gen_hxx
#define dds_cpp_tdatawriter_gen_hxx

#ifndef dds_cpp_publication_hxx
#include "dds_cpp/dds_cpp_publication.hxx"
#endif
#ifndef dds_c_common_h
#include "dds_c/dds_c_common.h"
#endif
#ifndef dds_c_infrastructure_h
#include "dds_c/dds_c_infrastructure.h"
#endif
#ifndef dds_c_publication_h
#include "dds_c/dds_c_publication.h"
#endif


/* ================================================================== */
/*i
   <<INTERFACE>>

   Defines:   TDataWriter, TData

   Organized using the well-documented "Generics Pattern" for
   implementing generics in C and C++.
*/

/* ================================================================== */
/*i
   <<IMPLEMENTATION>>

   Defines:   TDataWriter TData
*/
#if defined(TDataWriter) && defined(TData)


/*
 * Two step procedure needed for stringize the value of a macro
 */
#define _QUOTE(x) # x
#define QUOTE(x) _QUOTE(x)

// ---------------------------------------------------------------------
// Public Methods
// ---------------------------------------------------------------------


// ---------------------------------------------------------------------

TDataWriter*
TDataWriter::narrow(DDSDataWriter *writer)
{
    TDataWriter *typedWriter = static_cast<TDataWriter*>(writer);
    return typedWriter;
}


DDS_ReturnCode_t
TDataWriter::write(const TData& instance_data,
                                    const DDS_InstanceHandle_t& handle) 
{
    return this->write_untyped((void*) &instance_data, handle);
}

DDSDataWriter*
TDataWriter::as_datawriter()
{
    return this;
}

DDS_InstanceHandle_t
TDataWriter::register_instance(const TData& instance_data)
{
    return this->register_instance_untyped((void*) &instance_data);
}

DDS_InstanceHandle_t
TDataWriter::register_instance_w_timestamp(
            const TData& instance_data,
            const DDS_Time_t& source_timestamp)
{
    return this->register_instance_w_timestamp_untyped((void*) &instance_data,
                source_timestamp);
}

DDS_ReturnCode_t
TDataWriter::unregister_instance(
            const TData& instance_data,
            const DDS_InstanceHandle_t& handle)
{
    return this->unregister_instance_untyped((void*)&instance_data, handle);
}

DDS_ReturnCode_t
TDataWriter::unregister_instance_w_timestamp(
            const TData& instance_data,
            const DDS_InstanceHandle_t& handle,
            const DDS_Time_t& source_timestamp)
{
    return this->unregister_instance_w_timestamp_untyped(
                (void*)&instance_data, handle, source_timestamp);
}

DDS_ReturnCode_t
TDataWriter::dispose(
            const TData& instance_data,
            const DDS_InstanceHandle_t& handle)
{
    return this->dispose_untyped((void*)&instance_data, handle);
}

DDS_ReturnCode_t
TDataWriter::dispose_w_timestamp(
            const TData& instance_data,
            const DDS_InstanceHandle_t& handle,
            const DDS_Time_t& source_timestamp)
{
    return this->dispose_w_timestamp_untyped(
                    (void*)&instance_data, handle, source_timestamp);
}

DDS_ReturnCode_t
TDataWriter::write_w_timestamp(
            const TData& instance_data,
            const DDS_InstanceHandle_t& handle,
            const DDS_Time_t& source_timestamp)
{
    return this->write_w_timestamp_untyped(
                    (void*)&instance_data, handle, source_timestamp);
}

// ---------------------------------------------------------------------
// Protected Methods
// ---------------------------------------------------------------------

// --- Constructors & destructors: -------------------------------------

TDataWriter::~TDataWriter()
{
}


TDataWriter::TDataWriter(DDS_DataWriter* cDataWriter)
    : DDSDataWriter_impl(cDataWriter)
{
    // empty
}


// ---------------------------------------------------------------------
// Private Methods
// ---------------------------------------------------------------------

#else
#error "Incorrect use of dds_cpp_tdatawriter_gen.hxx: TDataWriter, and TData must be defined"
#endif /* defined(TDataWriter) && defined(TData) */

#undef dds_cpp_tdatawriter_gen_hxx
#endif /* dds_cpp_tdatawriter_gen_hxx */


