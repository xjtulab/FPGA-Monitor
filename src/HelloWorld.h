/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorld.idl using "oeiddsgen".
The oeiddsgen tool is part of the OEI Data Distribution Service distribution.
For more information, type 'oeiddsgen -help' at a command shell
or consult the OEI Data Distribution Service manual.
*/

#ifndef HelloWorld_1436885487_h
#define HelloWorld_1436885487_h

#ifndef oei_c_h
#include "oei_c.h"
#endif

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

typedef struct HelloWorld

{

    CDR_String msg;

} HelloWorld ;

extern const char *HelloWorldTYPENAME;

#define REDA_SEQUENCE_USER_API
#define T HelloWorld
#define TSeq HelloWorldSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#include <reda/reda_sequence_decl.h>

#define REDA_SEQUENCE_USER_API
#define T HelloWorld
#define TSeq HelloWorldSeq
#define REDA_SEQUENCE_EXCLUDE_STRUCT
#include <reda/reda_sequence_decl.h>

NDDSUSERDllExport extern OEI_BOOL
HelloWorld_initialize(HelloWorld* sample);

NDDSUSERDllExport extern OEI_BOOL
HelloWorld_finalize(HelloWorld* sample);

NDDSUSERDllExport extern HelloWorld*
HelloWorld_create();

NDDSUSERDllExport extern void
HelloWorld_delete(HelloWorld* sample);

NDDSUSERDllExport extern OEI_BOOL
HelloWorld_copy(HelloWorld* dst, const HelloWorld* src);

#ifdef NDDS_USER_DLL_EXPORT
#if (defined(OEI_WIN32) || defined(OEI_WINCE))
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
#endif

#endif /* HelloWorld */

