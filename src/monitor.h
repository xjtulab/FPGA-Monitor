#ifndef __MONITOR__H__
#define __MONITOR__H__

void StartMonitor(const char *agent_ip, const char *status_ip, int status_port,
                   int domain_id, const char* pub_topic_name, const char *sub_topic_name);


#endif