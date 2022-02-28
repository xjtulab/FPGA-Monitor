/*
 * FILE: cdr_serialize.h - CDR serialize API
 *
 */

/*ci
 * \file 
 * \defgroup CDRSerializeClass CDR Serialize 
 * \ingroup CDRModule 
 * \brief Serialization to and deserialization from CDR streams 
 *  
 * \details 
 * Operations to serialize types, and sequences and arrays of types, 
 * into CDR streams. 
 * Operations to deserialize types, and sequences and arrays of types, 
 * from CDR streams. 
 * Operations to get sizes of serialized types in CDR streams. 
 */

/*ci \addtogroup CDRSerializeClass
 *   @{
 */
#ifndef cdr_serialize_h
#define cdr_serialize_h

#ifndef reda_sequence_h
#include "reda/reda_sequence.h"
#endif
#ifndef reda_sequenceNumber_h
#include "reda/reda_sequenceNumber.h"
#endif
#ifndef cdr_dll_h
#include "cdr/cdr_dll.h"
#endif
#ifndef cdr_cdr_type_h
#include "cdr/cdr_cdr_type.h"
#endif
#ifndef cdr_stream_h
#include "cdr/cdr_stream.h"
#endif
#ifndef cdr_serialize_impl_h
#include "cdr/cdr_serialize_impl.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*ci \brief Standard CDR serialized parameter alignment */
#define CDR_DEFAULT_PARAMETER_ALIGNMENT (4)

/*ci \brief Get max serialized size of octet */
#define CDR_get_max_size_serialized_octet       CDR_get_1_byte_max_size_serialized

/*ci \brief Get max serialized size of char */
#define CDR_get_max_size_serialized_char        CDR_get_1_byte_max_size_serialized

/*ci \brief Get max serialized size of boolean */
#define CDR_get_max_size_serialized_boolean     CDR_get_1_byte_max_size_serialized

/*ci \brief Get max serialized size of short */
#define CDR_get_max_size_serialized_short       CDR_get_2_byte_max_size_serialized

/*ci \brief Get max serialized size of unsigned short */
#define CDR_get_max_size_serialized_unsigned_short \
                                                CDR_get_2_byte_max_size_serialized

/*ci \brief Get max serialized size of long */
#define CDR_get_max_size_serialized_long        CDR_get_4_byte_max_size_serialized

/*ci \brief Get max serialized size of unsigned long */
#define CDR_get_max_size_serialized_unsigned_long \
                                                CDR_get_4_byte_max_size_serialized

/*ci \brief Get max serialized size of wchar */
#define CDR_get_max_size_serialized_wchar       CDR_get_4_byte_max_size_serialized

/*ci \brief Get max serialized size of enum */
#define CDR_get_max_size_serialized_enum        CDR_get_4_byte_max_size_serialized

/*ci \brief Get max serialized size of float */
#define CDR_get_max_size_serialized_float       CDR_get_4_byte_max_size_serialized

/*ci \brief Get max serialized size of long long */
#define CDR_get_max_size_serialized_long_long   CDR_get_8_byte_max_size_serialized

/*ci \brief Get max serialized size of unsigned long long */
#define CDR_get_max_size_serialized_unsigned_long_long \
                                                CDR_get_8_byte_max_size_serialized

/*ci \brief Get max serialized size of double */
#define CDR_get_max_size_serialized_double      CDR_get_8_byte_max_size_serialized

/*ci \brief Get max serialized size of long double */
#define CDR_get_max_size_serialized_long_double CDR_get_16_byte_max_size_serialized

/*******************************************************************************
 * Declare serialization / deserialization for base primative types:
 * UnsignedShort (2 bytes), UnsignedLong (4 bytes), UnsignedLongLong (8 bytes),
 * LongDouble (16 bytes)
 ******************************************************************************/

/*ci 
 * \brief 
 * Serialize an unsigned short 
 *  
 * \param[in] dest_buffer Serialization buffer
 * \param[in] instance Value to serialize 
 * \param[in] byte_swap Flag whether to byte swap when serializing
 *   
 */
CDRDllExport void
CDR_serialize_unsigned_short(char **dest_buffer, const OEI_UINT16 * instance,
                           OEI_BOOL byte_swap);

/*ci 
 * \brief 
 * Deserialize an unsigned short 
 *  
 * \param[in] src_buffer Deserialization buffer
 * \param[out] instance Deserialized instance 
 * \param[in] byte_swap Flag whether to byte swap when deserializing
 *   
 */
CDRDllExport void
CDR_deserialize_unsigned_short(char **src_buffer, OEI_UINT16 * instance,
                             OEI_BOOL byte_swap);

/*ci 
 * \brief 
 * Serialize an unsigned long 
 *  
 * \param[in] dest_buffer Serialization buffer
 * \param[in] instance Value to serialize 
 * \param[in] byte_swap Flag whether to byte swap when serializing
 *   
 */
CDRDllExport void
CDR_serialize_unsigned_long(char **dest_buffer, const OEI_UINT32 * instance,
                          OEI_BOOL byte_swap);

/*ci 
 * \brief 
 * Deserialize an unsigned long 
 *  
 * \param[in] src_buffer Deserialization buffer
 * \param[out] instance Deserialized instance 
 * \param[in] byte_swap Flag whether to byte swap when deserializing
 *   
 */
CDRDllExport void
CDR_deserialize_unsigned_long(char **src_buffer, OEI_UINT32 * instance,
                            OEI_BOOL byte_swap);

/*ci 
 * \brief 
 * Serialize an unsigned long to big endian byte order
 *  
 * \param[in] dest_buffer Serialization buffer
 * \param[in] instance Value to serialize 
 *   
 */
CDRDllExport void
CDR_serialize_unsigned_long_to_big_endian(char **dest_buffer,
							const OEI_UINT32 * instance);

/*ci 
 * \brief 
 * Deserialize an unsigned long from big endian byte order 
 *  
 * \param[in] src_buffer Deserialization buffer
 * \param[out] instance Deserialized instance 
 *   
 */
CDRDllExport void
CDR_deserialize_unsigned_long_from_big_endian(char **src_buffer,
							OEI_UINT32 * instance);

/*ci 
 * \brief 
 * Serialize an unsigned long long 
 *  
 * \param[in] dest_buffer Serialization buffer
 * \param[in] instance Value to serialize 
 * \param[in] byte_swap Flag whether to byte swap when serializing
 *   
 */
CDRDllExport void
CDR_serialize_unsigned_long_long(char **dest_buffer, const OEI_UINT64 * instance,
                              OEI_BOOL byte_swap);

/*ci 
 * \brief 
 * Deserialize an unsigned long long 
 *  
 * \param[in] src_buffer Deserialization buffer
 * \param[out] instance Deserialized instance 
 * \param[in] byte_swap Flag whether to byte swap when deserializing
 *   
 */
CDRDllExport void
CDR_deserialize_unsigned_long_long(char **src_buffer, OEI_UINT64 * instance,
                                OEI_BOOL byte_swap);

/*ci 
 * \brief 
 * Serialize a long double 
 *  
 * \param[in] dest_buffer Serialization buffer
 * \param[in] instance Value to serialize 
 * \param[in] byte_swap Flag whether to byte swap when serializing
 *   
 */
CDRDllExport void
CDR_serialize_long_double(char **dest_buffer, const OEI_DOUBLE128 * instance,
                        OEI_BOOL byte_swap);

/*ci 
 * \brief 
 * Deserialize a long double 
 *  
 * \param[in] src_buffer Deserialization buffer
 * \param[out] instance Deserialized instance 
 * \param[in] byte_swap Flag whether to byte swap when deserializing
 *   
 */
CDRDllExport void
CDR_deserialize_long_double(char **src_buffer, OEI_DOUBLE128 * instance,
                          OEI_BOOL byte_swap);

/******************************************************************************
 * Define serialization / deserialization macros for primative types that are
 * implemented by equivalent sized base primative types
 ******************************************************************************/

/*ci \brief Deserialize Long */
#define CDR_deserialize_long(__buf,__inst,_b) \
    CDR_deserialize_unsigned_long(__buf,((OEI_UINT32*)__inst),_b)

/*******************************************************************************
 * Declare stream serialization / deserialization for base primative types:
 * Char (1 byte), UnsignedShort (2 bytes), UnsignedLong (4 bytes),
 * UnsignedLongLong (8 bytes), LongDouble (16 bytes)
 ******************************************************************************/

/*ci 
 * \brief 
 * Serialize a char with a stream
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] instance Value to serialize 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_char(struct CDR_Stream_t *cdrs, const OEI_INT8 * instance);

/*ci 
 * \brief 
 * Deserialize a char with a stream 
 *  
 * \param[in] cdrs Deserialization buffer 
 * \param[out] instance Deserialized instance 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_char(struct CDR_Stream_t *cdrs, OEI_INT8 * instance);

/*ci 
 * \brief 
 * Serialize an unsigned short with a CDR stream
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] instance Value to serialize 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure    
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_unsigned_short(struct CDR_Stream_t *cdrs,
                                   const OEI_UINT16 * instance);

/*ci 
 * \brief 
 * Deserialize an unsigned short with a stream 
 *  
 * \param[in] cdrs Deserialization buffer 
 * \param[out] instance Deserialized instance 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_unsigned_short(struct CDR_Stream_t *cdrs,
                                     OEI_UINT16 * instance);

/*ci 
 * \brief 
 * Serialize an unsigned short to big endian byte order with a CDR stream
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] instance Value to serialize 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure    
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_unsigned_short_to_big_endian(struct CDR_Stream_t *cdrs,
                                              const OEI_UINT16 * instance);

/*ci 
 * \brief 
 * Deserialize an unsigned short of big endian byte order with a stream 
 *  
 * \param[in] cdrs Deserialization buffer 
 * \param[out] instance Deserialized instance 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_unsigned_short_from_big_endian(struct CDR_Stream_t *cdrs,
                                                  OEI_UINT16* instance);

/*ci 
 * \brief 
 * Serialize an unsigned long with a CDR stream
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] instance Value to serialize 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure    
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_unsigned_long(struct CDR_Stream_t *cdrs,
                                  const OEI_UINT32 * instance);

/*ci 
 * \brief 
 * Deserialize an unsigned long with a stream 
 *  
 * \param[in] cdrs Deserialization buffer 
 * \param[out] instance Deserialized instance 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_unsigned_long(struct CDR_Stream_t *cdrs,
                                    OEI_UINT32 * instance);

/*ci 
 * \brief 
 * Serialize an unsigned long to big endian byte order with a CDR stream
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] instance Value to serialize 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure    
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_unsigned_long_to_big_endian(struct CDR_Stream_t *cdrs,
                                             const OEI_UINT32 * instance);

/*ci 
 * \brief 
 * Deserialize an unsigned long with big endian byte order from a stream 
 *  
 * \param[in] cdrs Deserialization buffer 
 * \param[out] instance Deserialized instance 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_unsigned_long_from_big_endian(struct CDR_Stream_t *cdrs,
                                                 OEI_UINT32 * instance);

/*ci 
 * \brief 
 * Serialize an unsigned long long with a CDR stream
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] instance Value to serialize 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure    
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_unsigned_long_long(struct CDR_Stream_t *cdrs,
                                      const OEI_UINT64 * instance);

/*ci 
 * \brief 
 * Deserialize an unsigned long long from a stream 
 *  
 * \param[in] cdrs Deserialization buffer 
 * \param[out] instance Deserialized instance 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_unsigned_long_long(struct CDR_Stream_t *cdrs,
                                        OEI_UINT64 * instance);

/*ci 
 * \brief 
 * Serialize a long double with a CDR stream
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] in Value to serialize 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure    
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_long_double(struct CDR_Stream_t *cdrs,
                                const OEI_DOUBLE128 * in);

/*ci 
 * \brief 
 * Deserialize a long double from a stream 
 *  
 * \param[in] cdrs Deserialization buffer 
 * \param[out] out Deserialized instance 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_long_double(struct CDR_Stream_t *cdrs,
                                  OEI_DOUBLE128 * out);

/*ci 
 * \brief 
 * Serialize a string with a CDR stream
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] in Pointer to string 
 * \param[in] max_length Maximum length of string
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure    
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_string(struct CDR_Stream_t *cdrs,
                            const char *in, OEI_UINT32 max_length);

/*ci 
 * \brief 
 * Deserialize a string from a stream 
 *  
 * \param[in] cdrs Deserialization buffer 
 * \param[out] out Deserialized instance 
 * \param[in] max_length Maximum length of string
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_string(struct CDR_Stream_t *cdrs,
                              char *out, OEI_UINT32 max_length);

/*ci 
 * \brief 
 * Serialize a wstring with a CDR stream
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] in Pointer to wstring 
 * \param[in] max_length Maximum length of wstring
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure    
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_wstring(struct CDR_Stream_t *cdrs,
                           const OEI_UINT32 *in, OEI_UINT32 max_length);

/*ci 
 * \brief 
 * Deserialize a wstring from a stream 
 *  
 * \param[in] cdrs Deserialization buffer 
 * \param[inout] out Deserialized wstring 
 * \param[in] max_length Maximum wstring length
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_wstring(struct CDR_Stream_t *cdrs,
                             OEI_UINT32 *out, OEI_UINT32 max_length);

/*ci 
 * \brief 
 * Serialize unsigned short to big endian byte order with stream 
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] in Value to serialize 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_2_octets_big_endian(struct CDR_Stream_t *cdrs,
                                    const OEI_UINT16 * in);

/*ci 
 * \brief 
 * Deserialize an unsigned short with big endian byte order from a stream 
 *  
 * \param[in] cdrs Deserialization buffer 
 * \param[out] out Deserialized instance 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_2_octets_big_endian(struct CDR_Stream_t *cdrs,
                                      OEI_UINT16 * out);

/******************************************************************************
 * Define serialization / deserialization stream macros for primative types that
 * are implemented by equaivalent sized base primative types
 ******************************************************************************/

/*ci \brief Serialize boolean in stream */
#define CDR_Stream_serialize_boolean(__s,__i) \
    CDR_Stream_serialize_char(__s,((OEI_INT8*)__i))

/*ci \brief Deserialize boolean from stream */
#define CDR_Stream_deserialize_boolean(__s,__i) \
    CDR_Stream_deserialize_char(__s,((OEI_INT8*)__i))

/*ci \brief Serialize octet into stream */
#define CDR_Stream_serialize_octet(__s,__i) \
    CDR_Stream_serialize_char(__s,((OEI_INT8*)__i))

/*ci \brief Deserialize octet from stream */
#define CDR_Stream_deserialize_octet(__s,__i) \
    CDR_Stream_deserialize_char(__s,((OEI_INT8*)__i))

/*ci \brief Serialize short into stream */
#define CDR_Stream_serialize_short(__s,__i) \
    CDR_Stream_serialize_unsigned_short(__s,((OEI_UINT16*)__i))

/*ci \brief Deserialize short from stream */
#define CDR_Stream_deserialize_short(__s,__i) \
    CDR_Stream_deserialize_unsigned_short(__s,((OEI_UINT16*)__i))

/*ci \brief Serialize wchar into stream */
#define CDR_Stream_serialize_wchar(__s,__i) \
    CDR_Stream_serialize_unsigned_long(__s,(OEI_UINT32*)__i)

/*ci \brief Deserialize wchar from stream */
#define CDR_Stream_deserialize_wchar(__s,__i) \
    CDR_Stream_deserialize_unsigned_long(__s,(OEI_UINT32*)__i)

/*ci \brief Serialize enum into stream */
#define CDR_Stream_serialize_enum(__s,__i) \
    CDR_Stream_serialize_unsigned_long(__s,(OEI_UINT32*)__i)

/*ci \brief Deserialize enum from stream */
#define CDR_Stream_deserialize_enum(__s,__i) \
    CDR_Stream_deserialize_unsigned_long(__s,(OEI_UINT32*)__i)

/*ci \brief Serialize long into stream */
#define CDR_Stream_serialize_long(__s,__i) \
    CDR_Stream_serialize_unsigned_long(__s,((OEI_UINT32*)__i))

/*ci \brief Deserialize long from stream */
#define CDR_Stream_deserialize_long(__s,__i) \
    CDR_Stream_deserialize_unsigned_long(__s,((OEI_UINT32*)__i))

/*ci \brief Serialize float into stream */
#define CDR_Stream_serialize_float(__s,__i) \
    CDR_Stream_serialize_unsigned_long(__s,((OEI_UINT32*)__i))

/*ci \brief Deserialize float from stream */
#define CDR_Stream_deserialize_float(__s,__i) \
    CDR_Stream_deserialize_unsigned_long(__s,((OEI_UINT32*)__i))

/*ci \brief Serialize long long into stream */
#define CDR_Stream_serialize_long_long(__s,__i) \
    CDR_Stream_serialize_unsigned_long_long(__s,((OEI_UINT64*)__i))

/*ci \brief Deserialize long long from stream */
#define CDR_Stream_deserialize_long_long(__s,__i) \
    CDR_Stream_deserialize_unsigned_long_long(__s,((OEI_UINT64*)__i))

/*ci \brief Serialize double into stream */
#define CDR_Stream_serialize_double(__s,__i) \
    CDR_Stream_serialize_unsigned_long_long(__s,((OEI_UINT64*)__i))

/*ci \brief Deserialize double from stream */
#define CDR_Stream_deserialize_double(__s,__i) \
    CDR_Stream_deserialize_unsigned_long_long(__s,((OEI_UINT64*)__i))

/*ci \brief Serialization function for an arbitrary type 
 *
 * \param[inout] stream Serialization stream
 * \param[in] sample Pointer to type to serialize
 * \param[in] param Serialization function parameter
 * 
 * \return OEI_TRUE on success, OEI_FALSE on failure
 */
typedef OEI_BOOL
(*CDR_Stream_SerializeFunction) (struct CDR_Stream_t * stream,
                                 const void *sample,
                                 void *param);
   
/*ci \brief Deserialization function for an arbitrary type 
 *
 * \param[in] stream Deserialization stream
 * \param[inout] sample Deserialized type from stream 
 * \param[in] param Deserialization function parameter
 * 
 * \return OEI_TRUE on success, OEI_FALSE on failure
 */                                                   
typedef OEI_BOOL
(*CDR_Stream_DeserializeFunction) (struct CDR_Stream_t * stream,
                                   void *sample,
                                   void *param);

struct NDDS_Type_Plugin;            /* forward declaration */

/*ci \brief Get serialized size of stream buffer with a sample of a custom type 
 *   with a type-plugin 
 *  
 * \param[in] plugin Custom type's type-plugin 
 * \param[in] current_alignment Stream buffer's current alignment 
 * \param[in] param Optional function parameter
 *  
 * \return Number of bytes to serialize one sample of plugin's type 
 */
typedef OEI_UINT32
(*CDR_Stream_GetSerializedSizeFunction)(struct NDDS_Type_Plugin *plugin,
                                        OEI_UINT32 current_alignment,
                                        void *param);

/******************************************************************************/
/*ci 
 * \brief 
 * Serialize array of bytes with stream 
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] in_array Array containing elements to serialize
 * \param[in] length Length of array 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_byte_array(struct CDR_Stream_t *cdrs,
                             const unsigned char *in_array,
                             OEI_UINT32 length);

/*ci 
 * \brief 
 * Deserialize an array of bytes from a stream 
 *  
 * \param[in] cdrs Deserialization stream 
 * \param[out] out Array of deserialized elements 
 * \param[in] length Length of array 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_byte_array(struct CDR_Stream_t *cdrs,
                               unsigned char *out,
                               OEI_UINT32 length);

/*ci \brief Get serialized size of byte array */
#define CDR_get_max_size_serialized_byte_array(current_alignment, length, type) \
  (length)

/*ci 
 * \brief 
 * Serialize array of strings with stream 
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] in Array containing elements to serialize 
 * \param[in] length Length of array 
 * \param[in] max_string_length Maximum length of string
 * \param[in] type Type of string, char or wide char 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_string_array(struct CDR_Stream_t *cdrs,
                               const void* in, 
                               OEI_UINT32 length,
                               OEI_UINT32 max_string_length,
                               CdrPrimitiveType type);

/*ci 
 * \brief 
 * Deserialize an array of strings from a stream 
 *  
 * \param[in] cdrs Deserialization stream 
 * \param[out] out Array of deserialized strings 
 * \param[in] length Length of array 
 * \param[in] max_string_length Maximum length of string
 * \param[in] type Type of string, char or wide char 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_string_array(struct CDR_Stream_t *cdrs,
                                 void *out,
                                 OEI_UINT32 length,
                                 OEI_UINT32 max_string_length,
                                 CdrPrimitiveType type);

/*ci 
 * \brief 
 * Return length in bytes of serialized string array 
 *  
 * \param[in] current_alignment Alignment of serialization buffer pointer
 * \param[in] length Length of array 
 * \param[in] max_string_length Maximum length of string
 * \param[in] type Type of string, char or wide char 
 *  
 * \return Number of bytes of serialized string array
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32
CDR_get_max_size_serialized_string_array(OEI_UINT32 current_alignment,
                                    OEI_UINT32 length,
                                    OEI_UINT32 max_string_length,
                                    CdrPrimitiveType type);

/*ci 
 * \brief 
 * Serialize array of primitive type elements with stream 
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] in Array pointer 
 * \param[in] length Length of array 
 * \param[in] type Type of array element 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_primitive_array(struct CDR_Stream_t *cdrs,
                                  const void* in,
                                  OEI_UINT32 length,
                                  CdrPrimitiveType type);

/*ci 
 * \brief 
 * Deserialize an array of primitive type elements from a stream 
 *  
 * \param[in] cdrs Deserialization stream 
 * \param[out] out Array of deserialized elements 
 * \param[in] length Length of array 
 * \param[in] type Type of array element 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_primitive_array(struct CDR_Stream_t *cdrs,
                                    void* out,
                                    OEI_UINT32 length,
                                    CdrPrimitiveType type);

/*ci \brief Get serialized size of primitive array 
 *
 * \param[in] alignment Current alignment
 * \param[in] length Array length
 * \param[in] type Array element type
 * 
 * \return Serialized size of primitive array, in bytes.
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32
CDR_get_max_size_serialized_primitive_array(OEI_UINT32 alignment,
                                            OEI_UINT32 length, 
                                            CdrPrimitiveType type);

/*ci 
 * \brief 
 * Serialize array of non-primitive type elements with stream 
 *  
 * \param[in] stream Serialization stream 
 * \param[in] in Array pointer 
 * \param[in] length Length of array 
 * \param[in] element_size Size in bytes of an array element
 * \param[in] serialize_function Serialization function per array element
 * \param[in] param Parameter for element serialization function
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_non_primitive_array(struct CDR_Stream_t *stream,
                                       const void* in,
                                       OEI_UINT32 length,
                                       OEI_UINT32 element_size,
                                       CDR_Stream_SerializeFunction
                                         serialize_function,
                                       void * param);

/*ci 
 * \brief 
 * Deserialize an array of non-primitive type elements from a stream 
 *  
 * \param[in] stream Deserialization stream 
 * \param[out] out Array of deserialized elements 
 * \param[in] length Length of array 
 * \param[in] element_size Size in bytes of an array element
 * \param[in] deserialize_function Deserialization function per array element
 * \param[in] param Parameter for element deserialization function
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_non_primitive_array(struct CDR_Stream_t *stream,
                                         void* out,
                                         OEI_UINT32 length,
                                         OEI_UINT32 element_size,
                                         CDR_Stream_DeserializeFunction
                                           deserialize_function,
                                         void * param);

/*ci 
 * \brief 
 * Return length in bytes of serialized non-primitive array 
 *  
 * \param[in] current_alignment Alignment of serialization buffer pointer
 * \param[in] length Length of array 
 * \param[in] get_serialized_size_func Function returning serialized size of one
 * element 
 * \param[in] param Parameter for element serialized size function 
 *  
 * \return Number of bytes to serialize array of non-primitive elements 
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32
CDR_get_max_size_serialized_non_primitive_array(OEI_UINT32 current_alignment,
                                            OEI_UINT32 length,
                                            CDR_Stream_GetSerializedSizeFunction
                                              get_serialized_size_func,
                                            void * param);

/*ci 
 * \brief 
 * Serialize a sequence of char or wide char strings with a stream 
 *  
 * \param[in] cdrs Serialization stream 
 * \param[in] in Sequence of strings 
 * \param[in] max_string_length Maximum length of a string
 * \param[in] type Type of string, either char or wide char 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_string_sequence(struct CDR_Stream_t *cdrs,
                                    const struct REDA_Sequence* in,
                                    OEI_UINT32 max_string_length,
                                    CdrPrimitiveType type);

/*ci 
 * \brief 
 * Deserialize a sequence of char or wide char strings from a stream 
 *  
 * \param[in] cdrs Deserialization stream 
 * \param[out] out Sequence of deserialized strings 
 * \param[in] max_string_length Maximum length of a string
 * \param[in] type Type of string, either char or wide char 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_string_sequence(struct CDR_Stream_t *cdrs,
                                      struct REDA_Sequence* out,
                                      OEI_UINT32 max_string_length,
                                      CdrPrimitiveType type);

/*ci 
 * \brief 
 * Return length in bytes of serialized string sequence  
 *  
 * \param[in] current_alignment Alignment of serialization buffer pointer
 * \param[in] length Length of array 
 * \param[in] max_string_length Maximum length of a string
 * \param[in] Type of string, either char or wide char 
 *  
 * \return Number of bytes to serialize sequence of strings
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32
CDR_get_max_size_serialized_string_sequence(OEI_UINT32 current_alignment,
                                         OEI_UINT32 length,
                                         OEI_UINT32 max_string_length,
                                         CdrPrimitiveType type);

/*ci 
 * \brief 
 * Serialize a sequence of primitive type elements with a stream 
 *  
 * \param[in] stream Serialization stream 
 * \param[in] in Sequence of primitive elements 
 * \param[in] type Type of sequence element  
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_primitive_sequence(struct CDR_Stream_t *stream,
                                       const struct REDA_Sequence* in,
                                       CdrPrimitiveType type);

/*ci 
 * \brief 
 * Deserialize a sequence of primitive type elements with a stream 
 *  
 * \param[in] stream Deserialization stream 
 * \param[out] out Sequence of primitive elements 
 * \param[in] type Type of sequence element  
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_primitive_sequence(struct CDR_Stream_t *stream,
                                         struct REDA_Sequence* out,
                                         CdrPrimitiveType type);

/*ci 
 * \brief 
 * Return length in bytes of serialized primitive sequence  
 *  
 * \param[in] current_alignment Alignment of serialization buffer pointer
 * \param[in] length Length of sequence 
 * \param[in] type Type of sequenece element 
 *  
 * \return Number of bytes to serialize sequence of primitives
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32
CDR_get_max_size_serialized_primitive_sequence(OEI_UINT32 current_alignment,
                                               OEI_UINT32 length,
                                               CdrPrimitiveType type);

/*ci 
 * \brief 
 * Serialize a sequence of non-primitive type elements with a stream 
 *  
 * \param[in] stream Serialization stream 
 * \param[in] in Sequence of non-primitive elements 
 * \param[in] serialize_function Serialization function of the non-primitive type
 * \param[in] param Parameter for serialize function of non-primitive type 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_non_primitive_sequence(struct CDR_Stream_t *stream,
                                          const struct REDA_Sequence* in,
                                          CDR_Stream_SerializeFunction
                                            serialize_function,
                                          void * param);

/*ci 
 * \brief 
 * Deserialize a sequence of non-primitive type elements with a stream 
 *  
 * \param[in] stream Deserialization stream 
 * \param[out] out Sequence of non-primitive elements 
 * \param[in] deserialize_function Deserialization function of a non-primitive
 * type  
 * \param[in] param Parameter for deserialize function of non-primitive type 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_deserialize_non_primitive_sequence(struct CDR_Stream_t *stream,
                                            struct REDA_Sequence* out,
                                            CDR_Stream_DeserializeFunction
                                              deserialize_function,
                                            void * param);

/*ci 
 * \brief 
 * Return the length in bytes to serialize a sequence of non-primitive type 
 * elements 
 *  
 * \param[in] current_alignment Alignment of serialization buffer
 * \param[in] length Length of sequence
 * \param[in] get_serialized_size_func Function returning the length in bytes of
 * one serialized sequence element 
 * type  
 * \param[in] param Parameter for serialized size function of non-primitive type 
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32
CDR_get_max_size_serialized_non_primitive_sequence(OEI_UINT32 current_alignment,
                                               OEI_UINT32 length,
                                               CDR_Stream_GetSerializedSizeFunction
                                                 get_serialized_size_func,
                                               void * param);

/*ci 
 * \brief 
 * Serialize a sequence of properties with a stream 
 *  
 * \param[inout] stream Serialization stream 
 * \param[in] data Sequence of properties to serialize
 * \param[in] param Parameter for property serialization function
 *  
 * \return OEI_TRUE on success, OEI_FALSE on failure 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL
CDR_Stream_serialize_property_sequence(struct CDR_Stream_t *stream,
                                       const void *data,
                                       void *param);

/*ci 
 * \brief 
 * Return the size of additional padding in bytes to a buffer to get desired 
 * alignment 
 *  
 * \param[in] current_size Current position of buffer
 * \param[in] align Desired alignment
 *  
 * \return Number of bytes to add to current buffer to be at desired alignment
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32
CDR_get_pad_size(OEI_UINT32 current_size, OEI_UINT8 align);


/*ci \brief Align current location to specified alignment 
 * \param[in] location Current position 
 * \param[in] alignment Desired alignment 
 *  
 * \return New position, at or greater than input location, at the desired 
 *         alignment 
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32 
CDR_align_upwards(OEI_UINT32 location, 
                  OEI_UINT8 alignment);

/*ci \brief Serialize a byte into a stream
 * \param[inout] me Serialization stream 
 * \param[in] in Byte to serialize 
 *  
 */
CDRDllExport void 
CDR_Stream_serialize_1_byte(struct CDR_Stream_t *me, 
                            const OEI_INT8 *in);     

/*ci \brief Deserialize a byte from a stream
 * \param[in] me Deserialization stream 
 * \param[inout] out Deserialized byte 
 *  
 */
CDRDllExport void 
CDR_Stream_deserialize_1_byte(struct CDR_Stream_t *me, 
                              OEI_INT8 *out);  


/*ci \brief Get size of serialized and aligned short 
 * \param[in] current_size Current position 
 *  
 * \return Size of serialized and aligned short 
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32 
CDR_get_2_byte_max_size_serialized(OEI_UINT32 current_size);

/*ci \brief Get size of serialized and aligned long 
 * \param[in] current_size Current position 
 *  
 * \return Size of serialized and aligned long 
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32 
CDR_get_4_byte_max_size_serialized(OEI_UINT32 current_size);

/*ci \brief Get size of serialized and aligned long long 
 * \param[in] current_size Current position 
 *  
 * \return Size of serialized and aligned long long 
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32 
CDR_get_8_byte_max_size_serialized(OEI_UINT32 current_size); 

/*ci \brief Get size of serialized and aligned long double 
 * \param[in] current_size Current position 
 *  
 * \return Size of serialized and aligned long double 
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32 
CDR_get_16_byte_max_size_serialized(OEI_UINT32 current_size);

/*ci \brief Get size of serialized and aligned string 
 * \param[in] current_size Current position 
 * \param[in] length String length  
 *  
 * \return Size of serialized and aligned string 
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32 
CDR_get_max_size_serialized_string(OEI_UINT32 current_size, 
                                   OEI_UINT32 length);

/*ci \brief Get size of serialized and aligned wstring 
 * \param[in] current_size Current position 
 * \param[in] length Wstring length, in Wchars  
 *  
 * \return Size of serialized and aligned wstring 
 */
MUST_CHECK_RETURN CDRDllExport OEI_UINT32 
CDR_get_max_size_serialized_wstring(OEI_UINT32 current_size, 
                                    OEI_UINT32 length);


/*ci 
 * \brief 
 * Whether the stream has enough space for additional bytes
 *  
 * \param[in] cdrs Stream 
 * \param[in] needed_space Additional bytes needed 
 *  
 * \return OEI_TRUE if stream has enough free space to serialize or deserialize 
 * needed_space more bytes, otherwise OEI_FALSE 
 */
MUST_CHECK_RETURN CDRDllExport OEI_BOOL 
CDR_Stream_has_remaining_space(struct CDR_Stream_t *cdrs,
                          OEI_UINT32 needed_space);

#ifdef __cplusplus
}                               /* extern "C" */
#endif


#endif /* cdr_serialize_h */

/*ci @} */
