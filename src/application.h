#ifndef __APPLICATION__H
#define __APPLICATION_H

#include "oei_c.h"

typedef struct Application{
    DDS_DomainParticipant *participant;
    char pub_topic_name[255];
    char sub_topic_name[255];
    char type_name[255];
    DDS_Long sleep_time;
    DDS_Long count;
    DDS_Topic *pub_topic;
    DDS_Topic *sub_topic;
}Application;

extern void 
Application_help(char *appname);

extern Application *Application_create(const char *pub_topic_name,
                  const char *sub_topic_name,
                  DDS_Long domain_id,  char *peer, char *udp_intf, 
                  DDS_Long sleep_time, DDS_Long count);

extern DDS_ReturnCode_t
Application_enable(struct Application *application);

extern void
Application_delete(struct Application *application);


#endif