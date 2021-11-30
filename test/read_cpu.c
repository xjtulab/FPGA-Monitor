#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

static unsigned long getProcTime(const char *name);
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
    char buf[128];
    if (argc != 2){
        exit(1);
    }



    old_proc_time  = getProcTime(argv[1]);
    old_total_time   =  getCPUTime();

    show_cpu_percent(argv[1]);

    return 0;
}

static unsigned long  getProcTime(const char *name){
    ProcStatus *proc = malloc(sizeof(ProcStatus));
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
        "%lu %lu %*d %*d %*d %*d %*d %*d %*d %lu %ld",
        &proc->state, &proc->utime, &proc->stime, &proc->vss, 
        &proc->rss);

    return proc->utime + proc->stime;
}

static void show_cpu_percent(const char *name){

    for(;;){

        sleep(1);
        new_proc_time = getProcTime(name);
        new_total_time =  getCPUTime();


        printf("new time: %lu, old time: %lu\n", new_total_time, old_total_time);

        

        unsigned long delte_time = new_proc_time - old_proc_time;
        unsigned long total_delta_time = new_total_time - old_total_time;

        printf("total time = %lu, delta time = %lu\n", total_delta_time, delte_time);
        double percentage = 100 * (delte_time / total_delta_time);


        printf("cpu percentage is %.2lf%%\n", percentage);

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