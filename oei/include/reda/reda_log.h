/*
 * FILE: reda_log.h - Log codes
 *
 */
/*ce 
 * \file 
 * \brief REDA module log codes
 */
#ifndef reda_log_h
#define reda_log_h

#ifndef osapi_log_h
#include "osapi/osapi_log.h"
#endif

/*ce
 * \defgroup REDALogCodesClass REDA
 * \brief Real-time Efficient Data Structures and Algorithms. ModuleID = 1
 * \ingroup LoggingModule
 */

/*ce
 * \brief Not sufficient memory to allocate buffer-pool
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_BUFFERPOOL_OUT_OF_RESOURCES_EC              (REDA_LOG_BASE + 1)
#define REDA_LOG_BUFFERPOOL_OUT_OF_RESOURCES(level_) \
OSAPI_LOG_ENTRY_ADD((level_),REDA_LOG_BUFFERPOOL_OUT_OF_RESOURCES_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief The buffer initialization method failed
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_BUFFERPOOL_BUFFER_INITIALIZATION_FAILED_EC  (REDA_LOG_BASE + 2)
#define REDA_LOG_BUFFERPOOL_BUFFER_INITIALIZATION_FAILED(level_,if_,ip_) \
OSAPI_LOG_ENTRY_CREATE((level_),REDA_LOG_BUFFERPOOL_BUFFER_INITIALIZATION_FAILED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("if",(if_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("ip",(ip_),OEI_TRUE)

/*ce
 * \brief Cannot delete buffer-pool due to buffer(s) not returned to pool
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_BUFFERPOOL_NOT_EMPTY_EC                     (REDA_LOG_BASE + 3)
#define REDA_LOG_BUFFERPOOL_NOT_EMPTY(level_,count_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),REDA_LOG_BUFFERPOOL_NOT_EMPTY_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"count",(count_))

/*ce
 * \brief A buffer was freed more than once
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_BUFFERPOOL_DOUBLE_FREE_EC                   (REDA_LOG_BASE + 4)
#define REDA_LOG_BUFFERPOOL_DOUBLE_FREE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),REDA_LOG_BUFFERPOOL_DOUBLE_FREE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)


/*ce
 * \brief An error occurred while copying a sequence
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_SEQUENCE_COPY_FAILED_EC                   (REDA_LOG_BASE + 100)
#define REDA_LOG_SEQUENCE_COPY_FAILED(level_,dstbuf_,srcbuf_,len_,esize_) \
OSAPI_LOG_ENTRY_CREATE((level_),REDA_LOG_SEQUENCE_COPY_FAILED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("dstbuf",(if_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("srcbuf",(ip_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("len",(len_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("esize",(esize_),OEI_TRUE)

/*ce
 * \brief An error occured while allocating space for a sequence
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_SEQUENCE_ALLOC_FAILED_EC                  (REDA_LOG_BASE + 101)
#define REDA_LOG_SEQUENCE_ALLOC_FAILED(level_,size_,align_) \
OSAPI_LOG_ENTRY_ADD_2INT((level_),REDA_LOG_SEQUENCE_ALLOC_FAILED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,\
        "size",(size_),"align",(align_))

/*ce
 * \brief An error occured while setting the maximum sequence size
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_SEQUENCE_SET_MAX_FAILED_EC                (REDA_LOG_BASE + 102)
#define REDA_LOG_SEQUENCE_SET_MAX_FAILED(level_,self_,max_) \
OSAPI_LOG_ENTRY_CREATE((level_),REDA_LOG_SEQUENCE_SET_MAX_FAILED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_POINTER("self",(self_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("max",(max_),OEI_TRUE)

/*ce
 * \brief An attempt was made to resize an already allocated sequence
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_SEQUENCE_REALLOCATION_EC                  (REDA_LOG_BASE + 103)
#define REDA_LOG_SEQUENCE_REALLOCATION(level_) \
OSAPI_LOG_ENTRY_ADD((level_),REDA_LOG_SEQUENCE_REALLOCATION_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM )

/*ce
 * \brief An error occured while operating on two sequences (copy/compare)
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_SEQUENCE_INVALID_OPERATION_EC             (REDA_LOG_BASE + 104)
#define REDA_LOG_SEQUENCE_INVALID_OPERATION(level_,llen_,rlen_,lesz_,resz_) \
OSAPI_LOG_ENTRY_CREATE((level_),REDA_LOG_SEQUENCE_INVALID_OPERATION_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM,OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("llen",(llen_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("rlen",(rlen_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("lesz",(lesz_),OEI_FALSE)\
        OSAPI_LOG_ENTRY_ADD_INT("resz",(resz_),OEI_TRUE)

/*ce
 * \brief An attempt was made to set an illegal length (length < 0
 *        or length > max_length)
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_SEQUENCE_INVALID_LENGTH_EC                (REDA_LOG_BASE + 105)
#define REDA_LOG_SEQUENCE_INVALID_LENGTH(level_) \
OSAPI_LOG_ENTRY_ADD((level_),REDA_LOG_SEQUENCE_INVALID_LENGTH_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief An illegal sequence index was specified (index < 0 or index > length)
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_SEQUENCE_INDEX_OUT_OF_BOUNDS_EC           (REDA_LOG_BASE + 106)
#define REDA_LOG_SEQUENCE_INDEX_OUT_OF_BOUNDS(level_) \
OSAPI_LOG_ENTRY_ADD((level_),REDA_LOG_SEQUENCE_INDEX_OUT_OF_BOUNDS_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief An error occured while allocating memory for a string
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_STRING_ALLOC_FAILED_EC                    (REDA_LOG_BASE + 200)
#define REDA_LOG_STRING_ALLOC_FAILED(level_,size_) \
OSAPI_LOG_ENTRY_ADD_1INT((level_),REDA_LOG_STRING_ALLOC_FAILED_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM ,"size",(size_))

/*ce
 * \brief An attempt was made to add an element to a full index
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_INDEX_FULL_EC                             (REDA_LOG_BASE + 300)
#define REDA_LOG_INDEX_FULL(level_) \
OSAPI_LOG_ENTRY_ADD((level_),REDA_LOG_INDEX_FULL_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

/*ce
 * \brief An attempt was made to add an existing element to an index
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_INDEX_ENTRY_EXISTS_EC                     (REDA_LOG_BASE + 301)
#define REDA_LOG_INDEX_ENTRY_EXISTS(level_) \
OSAPI_LOG_ENTRY_ADD((level_),REDA_LOG_INDEX_ENTRY_EXISTS_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)


/*ce
 * \brief An attempt was made to add an existing element to an index
 * \ingroup REDALogCodesClass
 */
#define REDA_LOG_INVALID_LIST_NODE_EC                      (REDA_LOG_BASE + 302)
#define REDA_LOG_INVALID_LIST_NODE(level_) \
OSAPI_LOG_ENTRY_ADD((level_),REDA_LOG_INVALID_LIST_NODE_EC,\
        OSAPI_LOG_MSG_PN_X2_STD_PARAM)

#endif
