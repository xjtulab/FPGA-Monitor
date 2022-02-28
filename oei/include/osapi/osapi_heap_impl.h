/*
 * FILE: osapi_heap_impl.h - Implementation of HEAP API
 *
 */
/*ce \file 
 *   \brief Macro implementing heap interface
 */
#ifndef osapi_heap_impl_h
#define osapi_heap_impl_h

#ifndef osapi_dll_h
#include "osapi/osapi_dll.h"
#endif

#include "osapi/osapi_config.h"

#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif

/*--------------------------------------------------------------------------*/
/* This needs to stay a MACRO; not for performance reasons but because
   it is the only way to pass a "type" into the "function"
 */
#define OSAPI_Heap_allocate_struct(dest_, type_) \
    *(dest_) = (type_ *)OSAPI_Heap_allocate(1, sizeof(type_))
/*--------------------------------------------------------------------------*/
#ifndef OEI_CERT
#define OSAPI_Heap_free_struct(dest_) \
    if ((dest_) != NULL) OSAPI_Heap_free(dest_)
#else
#define OSAPI_Heap_free_struct(dest_) 
#endif 
/*--------------------------------------------------------------------------*/
/* This needs to stay a MACRO; not for performance reasons but because
   it is the only way to pass a "type" into the "function"
 */
#define OSAPI_Heap_allocate_array(dest_, count_, type_)    \
    *(dest_) = (type_ *)OSAPI_Heap_allocate(count_,sizeof(type_))
/*--------------------------------------------------------------------------*/
#ifndef OEI_CERT
#define OSAPI_Heap_free_array(dest_) \
    if ((dest_) != NULL) OSAPI_Heap_free(dest_)
#else
#define OSAPI_Heap_free_array(dest_) 
#endif
/*--------------------------------------------------------------------------*/
#define OSAPI_Heap_allocate_string(string_, size_) \
    *(string_) = (char *)OSAPI_Heap_allocate((size_)+1, 1)
/*--------------------------------------------------------------------------*/
#ifndef OEI_CERT
#define OSAPI_Heap_free_string(string_) \
    if ((string_) != NULL) OSAPI_Heap_free(string_)
#else
#define OSAPI_Heap_free_string(string_) 
#endif
/*--------------------------------------------------------------------------*/

#endif /* osapi_heap_impl_h */
