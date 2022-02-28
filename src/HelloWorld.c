/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorld.idl using "oeiddsgen".
The oeiddsgen tool is part of the OEI Data Distribution Service distribution.
For more information, type 'oeiddsgen -help' at a command shell
or consult the OEI Data Distribution Service manual.
*/

#include "HelloWorld.h"

#define UNUSED_ARG(x) (void)(x)

/*** SOURCE_BEGIN ***/

/* ========================================================================= */

const char *HelloWorldTYPENAME = "HelloWorld";

OEI_BOOL
HelloWorld_initialize(HelloWorld* sample)
{
    if (sample == NULL)
    {
        return OEI_FALSE;
    }

    if (!CDR_String_initialize(&sample->msg, (128)))
    {
        return OEI_FALSE;
    }
    return OEI_TRUE;
}

OEI_BOOL
HelloWorld_finalize(HelloWorld* sample)
{
    if (sample == NULL)
    {
        return OEI_FALSE;
    }

    CDR_String_finalize(&sample->msg);
    return OEI_TRUE;
}

HelloWorld *
HelloWorld_create(void)
{
    HelloWorld* sample;
    OSAPI_Heap_allocate_struct(&sample, HelloWorld);
    if (sample != NULL) {
        if (!HelloWorld_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}

void
HelloWorld_delete(HelloWorld*sample)
{
    if (sample != NULL) {
        /* HelloWorld_finalize() always 
        returns OEI_TRUE when called with sample != NULL */
        HelloWorld_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}

OEI_BOOL
HelloWorld_copy(HelloWorld* dst,const HelloWorld* src)
{        
    if ((dst == NULL) || (src == NULL))
    {
        return OEI_FALSE;
    }
    if (!CDR_String_copy(&dst->msg, &src->msg, (128)))
    {
        return OEI_FALSE;
    }
    return OEI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'HelloWorld' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T HelloWorld
#define TSeq HelloWorldSeq
#define T_initialize HelloWorld_initialize
#define T_finalize   HelloWorld_finalize
#define T_copy       HelloWorld_copy
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

