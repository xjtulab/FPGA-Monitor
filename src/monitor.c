#include "monitor.h"
#include "dpde_agent.h"
#include "log.h"
#include "interp.h"

void StartMonitor(const char *agent_ip, const char *status_ip, int status_port,
                   int domain_id, const char* pub_topic_name, const char *sub_topic_name){

    //Init the dds agent
    char *udp_intf = "lo";
    DDS_Long sleep_time = 100000;
    DDS_Long count = 0;
    char send_msg[64];

    InitAgent(pub_topic_name, sub_topic_name, domain_id, udp_intf, agent_ip, sleep_time, 0);

    Log(NOTICE, "Start FPGA Monitor:");
    for(;;){
        char  *recv_msg = subscribe_msg();
        Log(NOTICE, "Get command: %s", recv_msg);

        int ret = Interpreter(recv_msg, send_msg);
        if (ret == 0)
            break;

        publish_msg(send_msg);
    }
}
