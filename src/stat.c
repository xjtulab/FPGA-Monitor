#include "stat.h"
#include "utils.h"
#include "log.h"
#include "interp.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

typedef struct CPUInfo{
    unsigned long utime, ntime, stime, itime;
    unsigned long iowtime, irqtime, sirqtime;
}CPUInfo;

typedef struct ProcStatus{
    char state;
    bool exist;
    unsigned long utime; //用户代码花费的cpu时间  
    unsigned long stime; //内核代码花费的cpu时间
    long vss; //virtual memory
    long rss; //physical memory
}ProcStatus;


static void getProcStatus(pid_t pid, ProcStatus *proc);
static pid_t getPidByName(const char *name);
static unsigned long getCPUTime();


//show every program status
void *ShowProcStatus(void *arg){
    char buf[MAX_BUFFER_LENGTH];
    char parent_msg[16];
    ProcStatus pstate;
    unsigned long process_delta_time, total_delta_time;
    unsigned long used_mem;
    unsigned long old_proc_time[MAX_PROCS], new_proc_time[MAX_PROCS];
    unsigned long old_cpu_time, new_cpu_time;
    int sockfd;
    struct sockaddr_in serv_addr;
    socklen_t addr_len;
    

    struct sysinfo s_info;
    sysinfo(&s_info);
    
    unsigned long total_mem = s_info.totalram;

    // Initialize send socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(9999);
    addr_len = sizeof(serv_addr);

    memset(old_proc_time, 0 ,sizeof(old_proc_time));
    memset(new_proc_time, 0 ,sizeof(new_proc_time));

    //First Initialize cpu time and each process's time
    old_cpu_time = getCPUTime();
    for(int i = 0; i < MAX_PROCS; i++){
        if (active_procs[i] > 0){
            pid_t pid = active_procs[i];
            //Initialize process time point
            getProcStatus(pid, &pstate);

            if (pstate.exist)
                old_proc_time[i] = pstate.stime + pstate.utime;

        }
    }


    // Begin status infinite loop
    for(;;){
        sleep(1); // update every second

        memset(buf, 0, sizeof(buf));
        memset(parent_msg, 0 ,sizeof(parent_msg));

        // Fetch cpu time 
        new_cpu_time =  getCPUTime();
        total_delta_time = new_cpu_time - old_cpu_time;

        for(int i = 0; i < MAX_PROCS; i++){
            pid_t pid = active_procs[i];
            char tmp[64];
            double cpu_percent, mem_percent;

            if (pid < 0)
                continue;

            memset(tmp, 0, sizeof(tmp));
            
            //Get the status of target process
            getProcStatus(pid, &pstate);

            // This process is no longer exist, just skip report it.
            if (pstate.exist == false)
                continue;

            // The time point of this process is kernal time(stime) + user time(utime)
            new_proc_time[i] = pstate.stime + pstate.utime;

            // Calculate delta time and the percent of cpu
            process_delta_time = new_proc_time[i] - old_proc_time[i];
            cpu_percent = 100 * ((double)process_delta_time / total_delta_time);

            // Fix first appear bug of each new process
            if (cpu_percent > 100 || cpu_percent < 0)
                cpu_percent = 0.0;

            // Calculate physical memory usage
            used_mem = pstate.rss * getpagesize();
            mem_percent = 199 * ((double)used_mem / total_mem);

            //printf("used time: %lu total time: %lu\n", process_delta_time, total_delta_time);
            
            // Status format:
            //pid name %cpu %mem used_mem
            sprintf(tmp, "%d %s %.2lf %.2lf %lu\n", pid, proc_names[i], 
                cpu_percent, mem_percent, used_mem);
            
            strcat(buf, tmp);    
        }

        //update time point of each process and cpu
        old_cpu_time = new_cpu_time;
        memcpy(old_proc_time, new_proc_time, sizeof(old_proc_time));

        //send all status message to status server
        sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&serv_addr, addr_len);
        //printf("%s\n", buf);
    }

    return NULL;
    
    
}

//get the pid number by process's name
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

// get the proc status of target process, including cpu time and memory
static void getProcStatus(pid_t pid, ProcStatus *proc){
    
    char filename[32];
    char buf[128];

    //filename must contain pid, such as '/proc/111/stat'
    sprintf(filename, "/proc/%d/stat", pid);

    FILE *file = fopen(filename, "r");

    if (!file){
        Log(NOTICE, "The process %d is not exist.", pid);
        proc->exist = false;
        return;
    }

    fgets(buf, 128, file);
    char *stat = strchr(buf, ')');

    memset(proc, 0 , sizeof(ProcStatus));
    proc->exist = true;


    sscanf(stat + 1, " %c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d"
        "%lu %lu %*d %*d %*d %*d %*d %*d %*d %ld %ld",
        &proc->state, &proc->utime, &proc->stime, &proc->vss, 
        &proc->rss);
}

//get current cpu time point
static unsigned long getCPUTime(){
    char buf[128];
    CPUInfo *cpu = malloc(sizeof(CPUInfo));

    // Open file of "/proc/stat"
    FILE *file = fopen("/proc/stat","r");
    if(!file){
        printf("Could not open /proc/stat.\n");
        exit(1);
    }

    //Now we only take care one cpu
    int num_cpu = 1;

    memset(cpu, 0, sizeof(CPUInfo));
    CPUInfo tmp;
    
    for(int i = 0; i < num_cpu; i ++){
        fgets(buf, 128, file);
        sscanf(buf, "cpu  %lu %lu %lu %lu %lu %lu %lu", &tmp.utime, &tmp.ntime,
        &tmp.stime, &tmp.itime, &tmp.iowtime, &tmp.irqtime, &tmp.sirqtime);

        cpu->utime  += tmp.utime;
        cpu->ntime  += tmp.ntime;
        cpu->stime  += tmp.stime;
        cpu->itime  += tmp.itime;
        cpu->iowtime += tmp.iowtime;
        cpu->irqtime += tmp.irqtime;
        cpu->sirqtime += tmp.sirqtime;
    }

    //return total cpu time
    return (cpu->utime +cpu->ntime + cpu->stime + cpu->itime +
            cpu->iowtime + cpu->irqtime + cpu->sirqtime);
}