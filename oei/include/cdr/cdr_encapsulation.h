/*
 * FILE: cdr_log.h CDR Log definitions
 * 
 */

 /*ci
 * \file 
 * \defgroup CDREncapsulationClass CDR Data Encapsulation 
 * \ingroup CDRModule 
 * \brief CDR Data Encapsulation 
 *  
 * \details 
 * Data encapsulation headers defined by and for RTPS data payloads.
 *  
 */

/*ci \addtogroup CDREncapsulationClass
 *   @{
 */
#ifndef cdr_encapsulation_h
#define cdr_encapsulation_h

#ifndef osapi_types_h
#include "osapi/osapi_types.h"
#endif

#ifndef cdr_serialize_h
#include "cdr/cdr_serialize.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*ci \brief OMG CDR Big Endian encapsulation ID */
#define OEI_CDR_ENCAPSULATION_ID_CDR_BE     ((OEI_UINT16)0x0000)

/*ci \brief OMG CDR Little Endian encapsulation ID */
#define OEI_CDR_ENCAPSULATION_ID_CDR_LE     ((OEI_UINT16)0x0001)

/*ci \brief Parameter List OMG CDR Big Endian encapsulation ID */
#define OEI_CDR_ENCAPSULATION_ID_PL_CDR_BE  ((OEI_UINT16)0x0002)

/*ci \brief Parameter List OMG CDR Little Endian encapsulation ID */
#define OEI_CDR_ENCAPSULATION_ID_PL_CDR_LE  ((OEI_UINT16)0x0003)

/*ci \brief Empty encapsulation options */
#define OEI_CDR_ENCAPSULATION_OPTIONS_NONE  ((OEI_UINT16)0x0000)

/*ci \brief Encapsulation header size */
#define OEI_CDR_ENCAPSULATION_HEADER_SIZE   4

/*ci \brief Encapsulation ID */
typedef OEI_UINT16 NDDSCDREncapsulationId;

/*ci \brief Encapsulation options */
typedef OEI_UINT16 NDDSCDREncapsulationOptions;

/*ci \brief CDR Encapsulation */
typedef struct NDDSCDREncapsulation
{
    /*ci \brief Encapsulation ID */
    NDDSCDREncapsulationId identifier;

    /*ci \brief Encapsulation options */
    NDDSCDREncapsulationOptions options;
} NDDSCDREncapsulation;

/*ci 
 * \brief 
 * Deserialize a CDR data encapsulation header from a stream 
 *  
 * \param[inout] stream Deserialization stream 
 *  
 * \return OEI_TRUE on success with stream set according to deserialized 
 * data encapsulation header. OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_header(struct CDR_Stream_t *stream);

/*ci 
 * \brief 
 * Serialize a CDR data encapsulation header into a stream 
 *  
 * \param[inout] stream Serialization stream 
 * \param[in] is_guid Flag whether to use parameter/GUID data encapsulation   
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_header(struct CDR_Stream_t * stream,OEI_BOOL is_guid);

#ifdef __cplusplus
}                               /* extern "C" */
#endif


#endif /* cdr_encapsulation_h */

/*ci @} */
