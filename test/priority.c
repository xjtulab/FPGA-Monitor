#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static pid_t getPidByName(const char *name);
int main(int argc, char const *argv[])
{
    /* code */
    pid_t pid = getPidByName("fpga1");
    if(pid < 0){
        printf("There is no such process.\n");
        return 1;
    }

    int prio = getpriority(PRIO_PROCESS, pid);
    printf("The priority of fpga1 is %d\n", prio);

    setpriority(PRIO_PROCESS, pid, prio +1);
    printf("Now incre the priority\n");

    prio = getpriority(PRIO_PROCESS, pid);
    printf("The new priority of fpga1 is %d\n", prio);



    return 0;
}


static pid_t getPidByName(const char *name){
    FILE *fp;
    char buf[64];
    char cmd[128];
    pid_t pid = -1;

    // The shell command is 'pidof of name'
    snprintf(cmd, sizeof(cmd), "pidof %s", name);

    // User popen to interactive with shell
    if ((fp = popen(cmd, "r")) != NULL){
        if (fgets(buf, 128, fp) != NULL)
            pid = atoi(buf);
    }

    pclose(fp);
    return pid;
}
