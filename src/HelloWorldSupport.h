/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorld.idl using "oeiddsgen".
The oeiddsgen tool is part of the OEI Data Distribution Service distribution.
For more information, type 'oeiddsgen -help' at a command shell
or consult the OEI Data Distribution Service manual.
*/

#ifndef HelloWorldSupport_1436885487_h
#define HelloWorldSupport_1436885487_h

#include <stdlib.h>

/* Uses */
#include "HelloWorld.h"
/* Requires */
#include "HelloWorldPlugin.h"

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

/* ========================================================================== */
/**
Uses:     T
Defines:  TTypeSupport, TDataWriter, TDataReader*/

NDDSUSERDllExport extern DDS_ReturnCode_t
HelloWorldTypeSupport_register_type(
    DDS_DomainParticipant* participant,
    const char* type_name);

NDDSUSERDllExport extern DDS_ReturnCode_t
HelloWorldTypeSupport_unregister_type(
    DDS_DomainParticipant* participant,
    const char* type_name);

DDS_DATAWRITER_C(HelloWorldDataWriter, HelloWorld);

DDS_DATAREADER_C(HelloWorldDataReader, HelloWorldSeq, HelloWorld);

#ifdef NDDS_USER_DLL_EXPORT
#if (defined(OEI_WIN32) || defined(OEI_WINCE))
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
#endif

#endif  /* HelloWorldSupport_1436885487_h */

