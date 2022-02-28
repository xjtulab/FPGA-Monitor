/*
 * FILE: cdr_log.h CDR Log definitions
 *
 */
/*ce
 * \file
 * \brief CDR Log
 */
#ifndef cdr_log_h
#define cdr_log_h

#ifndef osapi_log_h
#include "osapi/osapi_log.h"
#endif

/*ce
 * \brief Failed to allocate stream or stream buffer
 * \ingroup CDRLogCodesClass
 */
#define CDR_LOG_STREAM_ALLOC_EC                               (CDR_LOG_BASE + 1)
#define CDR_LOG_STREAM_ALLOC(level_,size_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),CDR_LOG_STREAM_ALLOC_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"size",(size_))

/*ce
 * \brief Failed to set stream's current offset
 * \ingroup CDRLogCodesClass
 */
#define CDR_LOG_SET_OFFSET_EC                                 (CDR_LOG_BASE + 2)
#define CDR_LOG_SET_OFFSET(level_,offset_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),CDR_LOG_SET_OFFSET_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"offset",(offset_))


/*ce
 * \brief Failed to increament stream's current offset
 * \ingroup CDRLogCodesClass
 */
#define CDR_LOG_INCR_OFFSET_EC                                (CDR_LOG_BASE + 3)
#define CDR_LOG_INCR_OFFSET(level_,offset_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),CDR_LOG_INCR_OFFSET_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"offset",(offset_))


#endif /* cdr_log_h */
