/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorld.idl using "oeiddsgen".
The oeiddsgen tool is part of the OEI Data Distribution Service distribution.
For more information, type 'oeiddsgen -help' at a command shell
or consult the OEI Data Distribution Service manual.
*/

#ifndef HelloWorldPlugin_1436885487_h
#define HelloWorldPlugin_1436885487_h

#include "HelloWorld.h"

#ifdef NDDS_USER_DLL_EXPORT
#if (defined(OEI_WIN32) || defined(OEI_WINCE))
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif
#else
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

NDDSUSERDllExport extern struct NDDS_Type_Plugin*
HelloWorldTypePlugin_get(void);
NDDSUSERDllExport extern const char*
HelloWorldTypePlugin_get_default_type_name(void);
NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
HelloWorld_get_key_kind(
    struct NDDS_Type_Plugin *plugin,
    void *param);
/* --------------------------------------------------------------------------
Untyped interfaces to the typed sample management functions
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern OEI_BOOL
HelloWorldPlugin_create_sample(
    struct NDDS_Type_Plugin *plugin, void **sample,void *param);

NDDSUSERDllExport extern OEI_BOOL 
HelloWorldPlugin_delete_sample(
    struct NDDS_Type_Plugin *plugin, void *sample,void *param);

NDDSUSERDllExport extern OEI_BOOL 
HelloWorldPlugin_copy_sample(
    struct NDDS_Type_Plugin *plugin, void *dst, const void *src, void *param);

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern OEI_BOOL 
HelloWorld_cdr_serialize(
    struct CDR_Stream_t *stream, const void *void_sample, void *param);

NDDSUSERDllExport extern OEI_BOOL 
HelloWorld_cdr_deserialize(
    struct CDR_Stream_t *stream, void *void_sample, void *param);

NDDSUSERDllExport extern OEI_UINT32
HelloWorld_get_serialized_sample_max_size(
    struct NDDS_Type_Plugin *plugin,
    OEI_UINT32 current_alignment,
    void *param);
/* Unkeyed type key serialization equivalent to sample serialization */
#define HelloWorld_cdr_serialize_key HelloWorld_cdr_serialize
#define HelloWorld_cdr_deserialize_key HelloWorld_cdr_deserialize
#define HelloWorld_get_serialized_key_max_size HelloWorld_get_serialized_sample_max_size

#ifdef NDDS_USER_DLL_EXPORT
#if (defined(OEI_WIN32) || defined(OEI_WINCE))
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
#endif

#endif /* HelloWorldPlugin_1436885487_h */

