#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>


#define COMMAND cat /proc/cpuinfo | grep flags | grep ' lm ' | wc -l

typedef struct CPUInfo{
    unsigned long utime, ntime, stime, itime;
    unsigned long iowtime, irqtime, sirqtime;
}CPUInfo;
typedef struct ProcStatus{
    char state;
    unsigned long utime; //用户代码花费的cpu时间  
    unsigned long stime; //内核代码花费的cpu时间
    long vss;
    long rss;
}ProcStatus;


unsigned long old_total_time, new_total_time;
unsigned long old_proc_time, new_proc_time;

//static unsigned long getProcTime(const char *name);
static void getProcStatus(const char *name, ProcStatus *proc);
static pid_t getPidByName(const char *name);
static void show_cpu_percent();
static unsigned long getCPUTime(){
    char buf[128];
    CPUInfo *cpu = malloc(sizeof(CPUInfo));
    FILE *file = fopen("/proc/stat","r");
    if(!file){
        printf("Could not open /proc/stat.\n");
        exit(1);
    }

    int num_cpu = 1;

    memset(cpu, 0, sizeof(CPUInfo));
    CPUInfo tmp;
    
    for(int i = 0; i < num_cpu; i ++){
        fgets(buf, 128, file);
        sscanf(buf, "cpu  %lu %lu %lu %lu %lu %lu %lu", &tmp.utime, &tmp.ntime,
        &tmp.stime, &tmp.itime, &tmp.iowtime, &tmp.irqtime, &tmp.sirqtime);

        cpu->utime += tmp.utime;
        cpu->ntime += tmp.ntime;
        cpu->stime += tmp.stime;
        cpu->itime += tmp.itime;
        cpu->iowtime += tmp.iowtime;
        cpu->irqtime += tmp.irqtime;
        cpu->sirqtime += tmp.sirqtime;
    
    }

    return (cpu->utime +cpu->ntime + cpu->stime + cpu->itime +
            cpu->iowtime + cpu->irqtime + cpu->sirqtime);

}


int main(int argc, char const *argv[])
{
    /* code */
    if (argc != 2){
        exit(1);
    }

    ProcStatus pstate;



    getProcStatus(argv[1], &pstate);
    old_proc_time = pstate.stime + pstate.utime;
    old_total_time   =  getCPUTime();

    show_cpu_percent(argv[1]);

    return 0;
}

static void show_cpu_percent(const char *name){

    ProcStatus pstate;

    struct sysinfo s_info;
    sysinfo(&s_info);
    
    unsigned long total_mem = s_info.totalram;
    for(;;){

        sleep(1);

        getProcStatus(name, &pstate);
        new_proc_time = pstate.stime + pstate.utime;
        new_total_time =  getCPUTime();

        unsigned long delte_time = new_proc_time - old_proc_time;
        unsigned long total_delta_time = new_total_time - old_total_time;

        double percentage = 100 * (delte_time / total_delta_time);

        unsigned long used_mem = pstate.rss * getpagesize();




        double mem_percentage = 100 *( (double)(used_mem) / total_mem); 

        //printf("used_mem: %luKB total_mem: %luKB\n", used_mem/1024, total_mem/1024);
        printf("%%CPU: %.2lf %%MEM: %.2lf used memory: %luKB\n", percentage, mem_percentage, used_mem / 1024);

        printf("vss(virtual memory): %luKB\n", pstate.vss / 1024);

        old_total_time = new_total_time;
        old_proc_time = new_proc_time;


    }
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

static void getProcStatus(const char *name, ProcStatus *proc){
    pid_t pid = getPidByName(name);

    char filename[32];
    char buf[128];
    sprintf(filename, "/proc/%d/stat", pid);

    FILE *file = fopen(filename, "r");
    if (!file){
        printf("Cannot read file %s!\n", filename);
        exit(1);
    }

    fgets(buf, 128, file);
    char *stat = strchr(buf, ')');

    memset(proc, 0 , sizeof(ProcStatus));

    sscanf(stat + 1, " %c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d"
        "%lu %lu %*d %*d %*d %*d %*d %*d %*d %ld %ld",
        &proc->state, &proc->utime, &proc->stime, &proc->vss, 
        &proc->rss);
}