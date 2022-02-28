/*
 * FILE: rtps_rtps_impl.h 
 *
 */

/*e \file
 * \brief Implementation of RTPS interface functions and types 
 *  
 * \details 
 * RTPS protocol defined types, implemented in C. 
 *  
 *  
 */

#ifndef rtps_rtps_impl_h
#define rtps_rtps_impl_h


#ifndef reda_sequenceNumber_h
#include "reda/reda_sequenceNumber.h"
#endif

/* -------------------------------------------------------------------------- */
/*ci \brief Get major field of vendor ID */
#define RTPS_VendorId_get_major(vendor)         (DDS_Octet)(*(vendor) >> 8)

/*ci \brief Get minor field of vendor ID */
#define RTPS_VendorId_get_minor(vendor)         (DDS_Octet)(*(vendor) & 0x00ff)

/* -------------------------------------------------------------------------- */
/*ci \brief Deserialize epoch of HEARTBEAT or ACKNACK from stream buffer */
#define RTPS_Epoch_deserialize(me_, stream_, swap_) \
    CDR_deserialize_long((stream_), (me_), (swap_))

/*ci \brief Serialized size of 2 octets */
#define RTPS_get_2_octets_max_size_serialized(size_) (2)

#endif /* rtps_rtps_impl_h */
