#ifndef __DPDE_AGENT__
#define __DPDE_AGENT__

#include "oei_c.h"
#include "application.h"


extern void InitAgent(const char *pub_topic_name, const char *sub_topic_name, DDS_Long domain_id, 
                        char *udp_intf, char *peer, DDS_Long sleep_time, DDS_Long count); 

extern void publish_msg(char *msg);
extern char *subscribe_msg();



#endif