/*
 * FILE: dds_c_tstatus_gen.h - DDS topic module
 *
 */

#ifndef dds_c_tstatus_gen_h
#define dds_c_tstatus_gen_h

#ifndef dds_c_common_impl_h
#include "dds_c/dds_c_common_impl.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef concatenate
#define concatenate(A, B)   A ## B
#endif

#ifndef T_initialize
#define _initialize(T) concatenate(T,_initialize)
#define T_initialize _initialize(T)

#ifndef T_INITIALIZER
#define _INITIALIZER(T) concatenate(T,_INITIALIZER)
#define T_INITIALIZER _INITIALIZER(T)
#endif

DDS_ReturnCode_t
T_initialize(struct T *self)
{
    struct T def_val = T_INITIALIZER;
    if (self == NULL)
    {
        return DDS_RETCODE_BAD_PARAMETER;
    }
    *self = def_val;
    return DDS_RETCODE_OK;
}
#undef T_INITIALIZER
#undef T_initialize
#undef _initialize
#undef _INITIALIZER
#endif /* T_initialize */

#undef concatenate

#ifdef __cplusplus
} /* extern "C" */
#endif

#undef dds_c_tstatus_gen_h

#endif /* dds_c_tstatus_gen_h */
