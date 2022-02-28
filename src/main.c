#include <stdio.h>
#include <assert.h>

#include "log.h"
#include "server.h"
#include "hash.h"
#include "interp.h"
#include "monitor.h"
#include "stat.h"

static void looper();

int main(int argc, char const *argv[])
{

    printf("Read config from ini:\n");
    int status_port;
    int domain_id;
    char agent_ip[32];
    char status_ip[32];
    char pub_topic_name[16];
    char sub_topic_name[16];
    char buf[64];

    FILE *fp = fopen("config/ini", "r");

    fgets(agent_ip, 32, fp);
    //remote last '\n'
    agent_ip[strlen(agent_ip)-1] = '\0';

    fgets(status_ip, 32, fp);
    //remote last '\n'
    status_ip[strlen(status_ip)-1] = '\0';

    fgets(buf, 64, fp);
    buf[strlen(buf)-1] = '\0';
    status_port = atoi(buf);

    fgets(buf, 64, fp);
    buf[strlen(buf)-1] = '\0';
    domain_id = atoi(buf);

    fgets(pub_topic_name, 16, fp);
    //remote last '\n'
    pub_topic_name[strlen(pub_topic_name)-1] = '\0';

    fgets(sub_topic_name, 16, fp);
    //remote last '\n'
    sub_topic_name[strlen(sub_topic_name)-1] = '\0';

    printf("Agent ip: %s]\n", agent_ip);
    printf("Status ip: %s]\n", status_ip);
    printf("Status port: %d]\n", status_port);
    printf("Domain id: %d]\n", domain_id);
    printf("Publish topic name: %s]\n", pub_topic_name);
    printf("Subscribe topic name: %s]\n", sub_topic_name);




    InitAll();

    StartMonitor(agent_ip, status_ip, status_port, domain_id, pub_topic_name,
                    sub_topic_name);


    //StartServer();
    //looper();
    return 0;
}


static void looper(){
    char line[128];

    while (fgets(line, sizeof(line), stdin) != NULL){
        printf("%s",line);

        Interpreter(line, NULL);
    }
}