/*
 * FILE: rtps_log.h - RTPS Log definitions
 *
 */

/*ce
 * \file 
 * \brief RTPS module log codes 
 *  
 * \details 
 * Log codes of the RTPS module 
 */
#ifndef rtps_log_h
#define rtps_log_h


#ifndef osapi_log_h
#include "osapi/osapi_log.h"
#endif

/*ce
 * \defgroup RTPSLogCodesClass RTPS 
 * \brief Real-Time Publish-Subscribe. ModuleID = 6 
 * \ingroup LoggingModule
 */

/*ce
 * \brief Failed to initialize an RTPS interface
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_INITIALIZE_INTERFACE_EC                     (RTPS_LOG_BASE + 1)
#define RTPS_LOG_INITIALIZE_INTERFACE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_INITIALIZE_INTERFACE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to allocate heap memory for internal resources
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_ALLOCATE_EC                                 (RTPS_LOG_BASE + 2)
#define RTPS_LOG_ALLOCATE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_ALLOCATE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to create a database table for storing RTPS route info
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_CREATE_ROUTE_TABLE_EC                       (RTPS_LOG_BASE + 3)
#define RTPS_LOG_CREATE_ROUTE_TABLE(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_CREATE_ROUTE_TABLE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to create database index for route-peer info
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_CREATE_ROUTE_PEER_INDEX_EC               (RTPS_LOG_BASE + 4)
#define RTPS_LOG_DB_CREATE_ROUTE_PEER_INDEX(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_CREATE_ROUTE_PEER_INDEX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to create database index for route-transport info
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_CREATE_ROUTE_XPORT_INDEX_EC              (RTPS_LOG_BASE + 5)
#define RTPS_LOG_DB_CREATE_ROUTE_XPORT_INDEX(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DB_CREATE_ROUTE_XPORT_INDEX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to create database index for bind-peer info
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_CREATE_BIND_PEER_INDEX_EC                (RTPS_LOG_BASE + 6)
#define RTPS_LOG_DB_CREATE_BIND_PEER_INDEX(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DB_CREATE_BIND_PEER_INDEX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to add an entry to a database index
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_INDEX_ADD_ENTRY_EC                          (RTPS_LOG_BASE + 8)
#define RTPS_LOG_INDEX_ADD_ENTRY(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_INDEX_ADD_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to select all entries of a database table 
* \details Failure reason given by database return code (dbrc)
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_SELECT_ALL_EC                            (RTPS_LOG_BASE + 9)
#define RTPS_LOG_DB_SELECT_ALL(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_SELECT_ALL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Matching entry not found in a database table. 
 * \details Failure reason given by database return code (dbrc)
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_SELECT_MATCH_EC                         (RTPS_LOG_BASE + 10)
#define RTPS_LOG_DB_SELECT_MATCH(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_SELECT_MATCH_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief No matching entries found in a database table.
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_SELECT_RANGE_EC                         (RTPS_LOG_BASE + 11)
#define RTPS_LOG_DB_SELECT_RANGE(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_SELECT_RANGE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to create database entry for route. 
 *  
 * \details May have exceeded 
 *        DomainParticipantQos.resource_limits.matching_writer_reader_pair_allocation, 
 *        DataWriterQos.writer_resource_limits.max_remote_readers, or
 *        DataReaderQos.reader_resource_limits.max_remote_writers
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_CREATE_ROUTE_ENTRY_EC                   (RTPS_LOG_BASE + 12)
#define RTPS_LOG_DB_CREATE_ROUTE_ENTRY(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_CREATE_ROUTE_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to insert entry into route table 
 * \details Failure reason given by database return code (dbrc)
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_INSERT_ROUTE_ENTRY_EC                   (RTPS_LOG_BASE + 13)
#define RTPS_LOG_DB_INSERT_ROUTE_ENTRY(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_INSERT_ROUTE_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to remove entry from route table
 * \details Failure reason given by database return code (dbrc)
 */
#define RTPS_LOG_DB_REMOVE_ROUTE_ENTRY_EC                   (RTPS_LOG_BASE + 14)
#define RTPS_LOG_DB_REMOVE_ROUTE_ENTRY(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_REMOVE_ROUTE_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to delete entry from route table 
 * \details Failure reason given by database return code (dbrc)
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_DELETE_ROUTE_ENTRY_EC                   (RTPS_LOG_BASE + 15)
#define RTPS_LOG_DB_DELETE_ROUTE_ENTRY(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_DELETE_ROUTE_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to create database entry for bind. 
 *  
 * \details If DomainParticipant, may have exceeded 
 *        DomainParticipantQos.resource_limits.matching_reader_writer_pair_allocation.
 *        Failure reason given by database return code (dbrc).
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_CREATE_BIND_ENTRY_EC                    (RTPS_LOG_BASE + 16)
#define RTPS_LOG_DB_CREATE_BIND_ENTRY(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_CREATE_BIND_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to insert an entry into the bind table. 
 * \details Failure reason given by database return code (dbrc)
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_INSERT_BIND_ENTRY_EC                    (RTPS_LOG_BASE + 17)
#define RTPS_LOG_DB_INSERT_BIND_ENTRY(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_INSERT_BIND_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to remove an entry from the bind table. 
 * \details Failure reason given by database return code (dbrc)
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_REMOVE_BIND_ENTRY_EC                    (RTPS_LOG_BASE + 18)
#define RTPS_LOG_DB_REMOVE_BIND_ENTRY(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_REMOVE_BIND_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to remove an entry from the external bind table. 
 * \details Failure reason given by database return code (dbrc)
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_REMOVE_EXTERNAL_BIND_ENTRY_EC           (RTPS_LOG_BASE + 19)
#define RTPS_LOG_DB_REMOVE_EXTERNAL_BIND_ENTRY(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_REMOVE_EXTERNAL_BIND_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to delete entry from external bind table 
 * \details Failure reason given by database return code (dbrc)
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_DELETE_EXTERNAL_BIND_ENTRY_EC           (RTPS_LOG_BASE + 20)
#define RTPS_LOG_DB_DELETE_EXTERNAL_BIND_ENTRY(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_DELETE_EXTERNAL_BIND_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to send a packet due to a lower module failing to send the 
 * packet. 
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_SEND_EC                                    (RTPS_LOG_BASE + 21)
#define RTPS_LOG_SEND(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_SEND_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to receive a packet due to a higher module failing to receive 
 * the packet. 
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_RECEIVE_EC                                 (RTPS_LOG_BASE + 22)
#define RTPS_LOG_RECEIVE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_RECEIVE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to send a packet, when routing to a lower module or peer
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_ROUTE_PACKET_EC                            (RTPS_LOG_BASE + 23)
#define RTPS_LOG_ROUTE_PACKET(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_ROUTE_PACKET_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to receive a packet, when forwarding to a higher upstream module 
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_FORWARD_UPSTREAM_EC                        (RTPS_LOG_BASE + 24)
#define RTPS_LOG_FORWARD_UPSTREAM(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_FORWARD_UPSTREAM_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Bad parameter to an RTPS interface function 
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_BAD_PARAMETER_EC                           (RTPS_LOG_BASE + 25)
#define RTPS_LOG_BAD_PARAMETER(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_BAD_PARAMETER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed because interface is not enabled
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_NOT_ENABLED_EC                             (RTPS_LOG_BASE + 26)
#define RTPS_LOG_NOT_ENABLED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_NOT_ENABLED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief RTPS reader does not support send
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_READER_UNSUPPORTED_EC                      (RTPS_LOG_BASE + 27)
#define RTPS_LOG_READER_UNSUPPORTED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_READER_UNSUPPORTED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Upstream interface does not match source or destination of packet 
 * being sent or received 
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_INTERFACE_MISMATCH_EC                      (RTPS_LOG_BASE + 28)
#define RTPS_LOG_INTERFACE_MISMATCH(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_INTERFACE_MISMATCH_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to send due to reaching maximum send window size
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_FULL_SEND_WINDOW_EC                        (RTPS_LOG_BASE + 29)
#define RTPS_LOG_FULL_SEND_WINDOW(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_FULL_SEND_WINDOW_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to set tail of packet to send
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_NETIO_PACKET_SET_TAIL_EC                   (RTPS_LOG_BASE + 31)
#define RTPS_LOG_NETIO_PACKET_SET_TAIL(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_NETIO_PACKET_SET_TAIL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief RTPS interface does not support this function
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_FUNC_UNSUPPORTED_EC                        (RTPS_LOG_BASE + 32)
#define RTPS_LOG_FUNC_UNSUPPORTED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_FUNC_UNSUPPORTED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Out of transport entries. 
 * \details Exceeded either 
 *        DataWriterQos.writer_resource_limits.max_remote_readers or
 *        DataReaderQos.reader_resource_limits.max_remote_writers
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_EXCEEDED_LIMIT_TRANSPORTS_EC               (RTPS_LOG_BASE + 33)
#define RTPS_LOG_EXCEEDED_LIMIT_TRANSPORTS(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_EXCEEDED_LIMIT_TRANSPORTS_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Out of peer entries. 
 *  
 * \details Exceeded either 
 *        DataWriterQos.writer_resource_limits.max_remote_readers or
 *        DataReaderQos.reader_resource_limits.max_remote_writers
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_EXCEEDED_LIMIT_PEERS_EC                    (RTPS_LOG_BASE + 34)
#define RTPS_LOG_EXCEEDED_LIMIT_PEERS(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_EXCEEDED_LIMIT_PEERS_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to assert a remote writer or reader
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_ASSERT_PEER_EC                             (RTPS_LOG_BASE + 35)
#define RTPS_LOG_ASSERT_PEER(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_ASSERT_PEER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to assert a downstream transport
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_ASSERT_TRANSPORT_EC                        (RTPS_LOG_BASE + 36)
#define RTPS_LOG_ASSERT_TRANSPORT(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_ASSERT_TRANSPORT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to lookup an external interface
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_FIND_EXTERNAL_INTERFACE_EC                 (RTPS_LOG_BASE + 37)
#define RTPS_LOG_FIND_EXTERNAL_INTERFACE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_FIND_EXTERNAL_INTERFACE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to delete a nonexistent route
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_NONEXISTENT_ROUTE_EC                       (RTPS_LOG_BASE + 38)
#define RTPS_LOG_NONEXISTENT_ROUTE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_NONEXISTENT_ROUTE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to remove a nonexistent bind entry
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_NONEXISTENT_BIND_EC                        (RTPS_LOG_BASE + 39)
#define RTPS_LOG_NONEXISTENT_BIND(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_NONEXISTENT_BIND_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to remove a nonexistent external bind entry
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_NONEXISTENT_EXTERNAL_BIND_EC               (RTPS_LOG_BASE + 40)
#define RTPS_LOG_NONEXISTENT_EXTERNAL_BIND(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_NONEXISTENT_EXTERNAL_BIND_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Dropped an ACKNACK submessage with an old epoch
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_STALE_ACK_EPOCH__EC                        (RTPS_LOG_BASE + 41)
#define RTPS_LOG_STALE_ACK_EPOCH(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_STALE_ACK_EPOCH__EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Dropped a HEARTBEAT submessage with an old epoch
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_STALE_HB_EPOCH_EC                          (RTPS_LOG_BASE + 42)
#define RTPS_LOG_STALE_HB_EPOCH(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_STALE_HB_EPOCH_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed an acknack() upstream
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_ACK_EC                                     (RTPS_LOG_BASE + 43)
#define RTPS_LOG_ACK(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_ACK_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed a request() upstream
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_REQUEST_EC                                 (RTPS_LOG_BASE + 45)
#define RTPS_LOG_REQUEST(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_REQUEST_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed a return_loan() upstream
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_RETURN_LOAN_EC                             (RTPS_LOG_BASE + 46)
#define RTPS_LOG_RETURN_LOAN(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_RETURN_LOAN_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to set the head of a packet
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_NETIO_PACKET_SET_HEAD_EC                   (RTPS_LOG_BASE + 47)
#define RTPS_LOG_NETIO_PACKET_SET_HEAD(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_NETIO_PACKET_SET_HEAD_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to send a HEARTBEAT submessage
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_SEND_HEARTBEAT_EC                          (RTPS_LOG_BASE + 48)
#define RTPS_LOG_SEND_HEARTBEAT(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_SEND_HEARTBEAT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to shift a bitmap
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_SHIFT_BITMAP_EC                            (RTPS_LOG_BASE + 49)
#define RTPS_LOG_SHIFT_BITMAP(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_SHIFT_BITMAP_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief A Reader is fully acknowledged and does not need to respond to a 
 * final HEARTBEAT 
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_FULLY_ACKED_READER_EC                      (RTPS_LOG_BASE + 50)
#define RTPS_LOG_FULLY_ACKED_READER(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_FULLY_ACKED_READER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Dropping a DATA submessage whose sequence number is outside of 
 * a Reader's receive window 
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DATA_OUT_OF_RANGE_EC                       (RTPS_LOG_BASE + 51)
#define RTPS_LOG_DATA_OUT_OF_RANGE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DATA_OUT_OF_RANGE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Dropping a DATA submessage whose sequence number was previously 
 * received 
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DATA_ALREADY_RECEIVED_EC                   (RTPS_LOG_BASE + 52)
#define RTPS_LOG_DATA_ALREADY_RECEIVED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DATA_ALREADY_RECEIVED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to receive a message because interface is not enabled
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_INTERFACE_NOT_ENABLED_EC                   (RTPS_LOG_BASE + 53)
#define RTPS_LOG_INTERFACE_NOT_ENABLED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_INTERFACE_NOT_ENABLED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Dropped a message with an invalid packet header
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_INVALID_PACKET_EC                          (RTPS_LOG_BASE + 54)
#define RTPS_LOG_INVALID_PACKET(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_INVALID_PACKET_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Received a message on an unsupported interface
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_UNSUPPORTED_INTERFACE_EC                   (RTPS_LOG_BASE + 55)
#define RTPS_LOG_UNSUPPORTED_INTERFACE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_UNSUPPORTED_INTERFACE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Received a submessage with an unknown ID
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_UNKNOWN_SUBMESSAGE_EC                      (RTPS_LOG_BASE + 56)
#define RTPS_LOG_UNKNOWN_SUBMESSAGE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_UNKNOWN_SUBMESSAGE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to process received ACKNACK submessage
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_PROCESS_ACKNACK_EC                         (RTPS_LOG_BASE + 57)
#define RTPS_LOG_PROCESS_ACKNACK(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_PROCESS_ACKNACK_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to process received DATA submessage
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_PROCESS_DATA_EC                            (RTPS_LOG_BASE + 58)
#define RTPS_LOG_PROCESS_DATA(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_PROCESS_DATA_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to process received GAP submessage
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_PROCESS_GAP_EC                             (RTPS_LOG_BASE + 59)
#define RTPS_LOG_PROCESS_GAP(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_PROCESS_GAP_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to process received HEARTBEAT submessage
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_PROCESS_HEARTBEAT_EC                       (RTPS_LOG_BASE + 60)
#define RTPS_LOG_PROCESS_HEARTBEAT(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_PROCESS_HEARTBEAT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to create periodic HEARTBEAT event
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_CREATE_HB_EVENT_EC                         (RTPS_LOG_BASE + 61)
#define RTPS_LOG_CREATE_HB_EVENT(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_CREATE_HB_EVENT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to create periodic HEARTBEAT event timer
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_CREATE_EVENT_TIMER_EC                      (RTPS_LOG_BASE + 62)
#define RTPS_LOG_CREATE_EVENT_TIMER(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_CREATE_EVENT_TIMER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to set bitmap bit due to out-of-range sequence number
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_SEQ_NUM_OUT_OF_RANGE_EC                    (RTPS_LOG_BASE + 63)
#define RTPS_LOG_SEQ_NUM_OUT_OF_RANGE(level_,dist_,bc_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),RTPS_LOG_SEQ_NUM_OUT_OF_RANGE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "distance",(dist_),"bitcount",(bc_))

/*ce
 * \brief Invalid range of sequence numbers to fill in bitmap
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_FIRST_SN_GREATER_LAST_SN_EC                (RTPS_LOG_BASE + 65)
#define RTPS_LOG_FIRST_SN_GREATER_THAN_LAST_SN(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_FIRST_SN_GREATER_LAST_SN_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Deserialized an invalid out-of-bounds bitcount for a bitmap
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_BITCOUNT_OUT_OF_BOUNDS_EC                  (RTPS_LOG_BASE + 66)
#define RTPS_LOG_BITCOUNT_OUT_OF_BOUNDS(level_,bc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_SEQ_NUM_OUT_OF_RANGE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"bitcount",(bc_))

/*ce
 * \brief Failed to shift bitmap due to invalid starting sequence number
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_SHIFT_SN_OUT_OF_RANGE_EC                   (RTPS_LOG_BASE + 67)
#define RTPS_LOG_SHIFT_SEQ_NUM_OUT_OF_RANGE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_SHIFT_SN_OUT_OF_RANGE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to serialize host ID of GUID
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_SERIALIZE_HOST_ID_EC                       (RTPS_LOG_BASE + 68)
#define RTPS_LOG_SERIALIZE_HOST_ID(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_SERIALIZE_HOST_ID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to serialize app ID of GUID
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_SERIALIZE_APP_ID_EC                        (RTPS_LOG_BASE + 69)
#define RTPS_LOG_SERIALIZE_APP_ID(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_SERIALIZE_APP_ID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to serialized instance ID of GUID
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_SERIALIZE_INSTANCE_ID_EC                   (RTPS_LOG_BASE + 70)
#define RTPS_LOG_SERIALIZE_INSTANCE_ID(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_SERIALIZE_INSTANCE_ID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to serialize object ID of GUID
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_SERIALIZE_OBJECT_ID_EC                     (RTPS_LOG_BASE + 71)
#define RTPS_LOG_SERIALIZE_OBJECT_ID(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_SERIALIZE_OBJECT_ID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to deserialize host ID of GUID
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DESERIALIZE_HOST_ID_EC                     (RTPS_LOG_BASE + 72)
#define RTPS_LOG_DESERIALIZE_HOST_ID(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DESERIALIZE_HOST_ID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Faild to deserialize app ID of GUID
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DESERIALIZE_APP_ID_EC                      (RTPS_LOG_BASE + 73)
#define RTPS_LOG_DESERIALIZE_APP_ID(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DESERIALIZE_APP_ID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to deserialize instance ID of GUID
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DESERIALIZE_INSTANCE_ID_EC                 (RTPS_LOG_BASE + 74)
#define RTPS_LOG_DESERIALIZE_INSTANCE_ID(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DESERIALIZE_INSTANCE_ID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to deserialize object ID of GUID
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DESERIALIZE_OBJECT_ID_EC                   (RTPS_LOG_BASE + 75)
#define RTPS_LOG_DESERIALIZE_OBJECT_ID(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DESERIALIZE_OBJECT_ID_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to create database entry for external bind table. 
 *  
 * \details If DomainParticipant, may have exceeded 
 *        DomainParticipantQos.resource_limits.matching_reader_writer_pair_allocation.
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_CREATE_EXT_BIND_ENTRY_EC                (RTPS_LOG_BASE + 76)
#define RTPS_LOG_DB_CREATE_EXT_BIND_ENTRY(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DB_CREATE_EXT_BIND_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to set bit in bitmap 
 *  
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_BITMAP_SET_BIT_EC                          (RTPS_LOG_BASE + 77)
#define RTPS_LOG_BITMAP_SET_BIT(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_BITMAP_SET_BIT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Received and dropped currently unsupported INFO_REPLY submessage
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_UNSUPPORTED_INFO_REPLY_EC                  (RTPS_LOG_BASE + 78)
#define RTPS_LOG_UNSUPPORTED_INFO_REPLY(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_UNSUPPORTED_INFO_REPLY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Received and dropped currently unsupported INFO_REPLY_IP4 submessage
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_UNSUPPORTED_INFO_REPLY_IP4_EC              (RTPS_LOG_BASE + 79)
#define RTPS_LOG_UNSUPPORTED_INFO_REPLY_IP4(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_UNSUPPORTED_INFO_REPLY_IP4_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Received and dropped currently unsupported INFO_SRC submessage
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_UNSUPPORTED_INFO_SRC_EC                    (RTPS_LOG_BASE + 80)
#define RTPS_LOG_UNSUPPORTED_INFO_SRC(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_UNSUPPORTED_INFO_SRC_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to delete index of a database table
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DELETE_INDEX_EC                            (RTPS_LOG_BASE + 81)
#define RTPS_LOG_DELETE_INDEX(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DELETE_INDEX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to delete a database table
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DELETE_TABLE_EC                            (RTPS_LOG_BASE + 82)
#define RTPS_LOG_DELETE_TABLE(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DELETE_TABLE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to take database lock
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_LOCK_EC                                 (RTPS_LOG_BASE + 83)
#define RTPS_LOG_DB_LOCK(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DB_LOCK_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to give database lock
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_UNLOCK_EC                               (RTPS_LOG_BASE + 84)
#define RTPS_LOG_DB_UNLOCK(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DB_UNLOCK_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to create a database table for storing RTPS bind info
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_CREATE_BIND_TABLE_EC                       (RTPS_LOG_BASE + 85)
#define RTPS_LOG_CREATE_BIND_TABLE(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_CREATE_BIND_TABLE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to update status for reliable reader activity changed.
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_STATUS_CHANGE_EC                           (RTPS_LOG_BASE + 86)
#define RTPS_LOG_STATUS_CHANGE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_STATUS_CHANGE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM )

/*ce
 * \brief Failed to update status for reliable reader activity changed.
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_SET_GAP_EC                                 (RTPS_LOG_BASE + 87)
#define RTPS_LOG_SET_GAP(level_,start_,end_,sffx_) \
OSAPI_LOG_ENTRY_CREATE((level_),RTPS_LOG_SET_GAP_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("start",(start_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("end",(end_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("suffix",(sffx_),OEI_TRUE)

/*ce
 * \brief Out of memory to allocate send window pool
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_WINDOW_POOL_ALLOC_EC                       (RTPS_LOG_BASE + 88)
#define RTPS_LOG_WINDOW_POOL_ALLOC(level_,size_,count_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),RTPS_LOG_WINDOW_POOL_ALLOC_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "size",(size_),"count",(count_))

/*ce
 * \brief Failed to get buffer from send window pool
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_GET_WINDOW_BUFFER_EC                       (RTPS_LOG_BASE + 89)
#define RTPS_LOG_GET_WINDOW_BUFFER(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_GET_WINDOW_BUFFER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)
        
/*ce
 * \brief Cannot insert sample into full window
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_INSERT_WINDOW_FULL_EC                      (RTPS_LOG_BASE + 90)
#define RTPS_LOG_INSERT_WINDOW_FULL(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_INSERT_WINDOW_FULL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to insert sample into send window
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_WINDOW_INSERT_EC                           (RTPS_LOG_BASE + 91)
#define RTPS_LOG_WINDOW_INSERT(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_WINDOW_INSERT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to delete a timeout event
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_TIMER_DELETE_TIMEOUT_EC                    (RTPS_LOG_BASE + 92)
#define RTPS_LOG_TIMER_DELETE_TIMEOUT(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_TIMER_DELETE_TIMEOUT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to delete a buffer pool
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_BUFFERPOOL_DELETE_EC                       (RTPS_LOG_BASE + 93)
#define RTPS_LOG_BUFFERPOOL_DELETE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_BUFFERPOOL_DELETE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to send a message to a specific peer 
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DIRECT_SEND_EC                             (RTPS_LOG_BASE + 94)
#define RTPS_LOG_DIRECT_SEND(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DIRECT_SEND_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)
        
/*ce
 * \brief RTPS writer failed to initialize a packet
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_PACKET_INITIALIZE_EC                       (RTPS_LOG_BASE + 95)
#define RTPS_LOG_PACKET_INITIALIZE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_PACKET_INITIALIZE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief RTPS reliable writer failed to request and resend history
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_WRITER_REQUEST_SENT_HISTORY_EC             (RTPS_LOG_BASE + 96)
#define RTPS_LOG_WRITER_REQUEST_SEND_HISTORY(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_WRITER_REQUEST_SENT_HISTORY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to shift bitmap to new lead sequence number
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_BITMAP_SHIFT_EC                            (RTPS_LOG_BASE + 97)
#define RTPS_LOG_BITMAP_SHIFT(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_BITMAP_SHIFT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)
  
/*ce
 * \brief Send window of a remote reader failed to advance 
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_WINDOW_ADVANCE_EC                          (RTPS_LOG_BASE + 98)
#define RTPS_LOG_WINDOW_ADVANCE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_WINDOW_ADVANCE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed when advancing window ahead of unacknowledged sequence number 
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_WINDOW_ADVANCE_UNACKED_EC                  (RTPS_LOG_BASE + 99)
#define RTPS_LOG_WINDOW_ADVANCE_UNACKED(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_WINDOW_ADVANCE_UNACKED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to find peer that should exist 
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_LOOKUP_PEER_EC                            (RTPS_LOG_BASE + 100)
#define RTPS_LOG_LOOKUP_PEER(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_LOOKUP_PEER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief RTPS reader failed to send an ACKNACK message
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_READER_SEND_ACKNACK_EC                    (RTPS_LOG_BASE + 101)
#define RTPS_LOG_READER_SEND_ACKNACK(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_READER_SEND_ACKNACK_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)
        
/*ce
 * \brief Failed to finalize an RTPS interface
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_FINALIZE_INTERFACE_EC                     (RTPS_LOG_BASE + 102)
#define RTPS_LOG_FINALIZE_INTERFACE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_FINALIZE_INTERFACE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to remove index entry for external interface upon deleting 
 *        RTPS interface
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_INDEXER_REMOVE_ENTRY_EC                   (RTPS_LOG_BASE + 103)
#define RTPS_LOG_INDEXER_REMOVE_ENTRY(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_INDEXER_REMOVE_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed when looking up external bind entry from database 
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_LOOKUP_EXT_BIND_ENTRY_EC                  (RTPS_LOG_BASE + 104)
#define RTPS_LOG_LOOKUP_EXT_BIND_ENTRY(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_LOOKUP_EXT_BIND_ENTRY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

/*ce
 * \brief Failed to initialize a local sequence
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_SEQ_INIT_EC                               (RTPS_LOG_BASE + 105)
#define RTPS_LOG_SEQ_INIT(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_SEQ_INIT_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to set maximum of a local sequence
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_SEQ_MAX_EC                                (RTPS_LOG_BASE + 106)
#define RTPS_LOG_SEQ_MAX(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_SEQ_MAX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to set length of a local sequence
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_SEQ_LEN_EC                                (RTPS_LOG_BASE + 107)
#define RTPS_LOG_SEQ_LEN(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_SEQ_LEN_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Initializing an RTPS interface with undefined mode
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_INTF_MODE_UNDEF_EC                        (RTPS_LOG_BASE + 108)
#define RTPS_LOG_INTF_MODE_UNDEF(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_INTF_MODE_UNDEF_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to delete buffer pool 
 * \details May still have buffers in use, thus cannot delete pool.
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DELETE_BUFFER_POOL_EC                     (RTPS_LOG_BASE + 109)
#define RTPS_LOG_DELETE_BUFFER_POOL(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DELETE_BUFFER_POOL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)
        
/*ce
 * \brief Failed to create buffer pool 
 * \details May have insufficient memory to allocate pool.
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_CREATE_BUFFER_POOL_EC                     (RTPS_LOG_BASE + 110)
#define RTPS_LOG_CREATE_BUFFER_POOL(level_,size_,count_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),RTPS_LOG_CREATE_BUFFER_POOL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "size",(size_),"count",(count_))

/*ce
 * \brief Failed to create index of peers 
 * \details System may have insufficient memory to allocate new index.
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_CREATE_PEERS_INDEX_EC                     (RTPS_LOG_BASE + 111)
#define RTPS_LOG_CREATE_PEERS_INDEX(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_CREATE_PEERS_INDEX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)


/*ce
 * \brief Failed to delete indexer
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DELETE_INDEXER_EC                         (RTPS_LOG_BASE + 112)
#define RTPS_LOG_DELETE_INDEXER(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_DELETE_INDEXER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief Failed to get buffer from peer buffer pool
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_GET_PEER_BUFFER_EC                        (RTPS_LOG_BASE + 113)
#define RTPS_LOG_GET_PEER_BUFFER(level_) \
OSAPI_LOG_ENTRY_ADD((level_),RTPS_LOG_GET_PEER_BUFFER_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)
        

/*ce
 * \brief Failed to create database index for direct sends
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_CREATE_DIRECT_INDEX_EC                 (RTPS_LOG_BASE + 114)
#define RTPS_LOG_DB_CREATE_DIRECT_INDEX(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_CREATE_DIRECT_INDEX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))


/*ce
 * \brief Failed to create database index for group sends
 * \ingroup RTPSLogCodesClass
 */
#define RTPS_LOG_DB_CREATE_GROUP_INDEX_EC                  (RTPS_LOG_BASE + 115)
#define RTPS_LOG_DB_CREATE_GROUP_INDEX(level_,dbrc_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),RTPS_LOG_DB_CREATE_GROUP_INDEX_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"dbrc",(dbrc_))

#endif /* rtps_log_h */
