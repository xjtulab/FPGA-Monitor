#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


typedef struct ProcStatus{
    char state;
    unsigned long utime; //用户代码花费的cpu时间  
    unsigned long stime; //内核代码花费的cpu时间
    long vss;
    long rss;
}ProcStatus;

static pid_t getPidByName(const char *name);
static void getProcStatus(const char *name, ProcStatus *proc);

int main(int argc, char const *argv[])
{
    /* code */
    if (argc != 2){
        exit(1);
    }

    pid_t pid = getPidByName(argv[1]);

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

    ProcStatus pstate;
    memset(&pstate, 0 , sizeof(pstate));

    sscanf(stat + 1, " %c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d"
        "%lu %lu %*d %*d %*d %*d %*d %*d %*d %lu %ld",
        &pstate.state, &pstate.utime, &pstate.stime, &pstate.vss, 
        &pstate.rss);



    printf("utime: %lu, stime: %lu, vss: %ld, rss: %ld\n",
        pstate.utime, pstate.stime, pstate.vss, pstate.rss);
    


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
        "%lu %lu %*d %*d %*d %*d %*d %*d %*d %lu %ld",
        proc->state, &proc->utime, &proc->stime, proc->vss, 
        proc->rss);


    printf("utime: %lu, stime: %lu, vss: %ld, rss: %ld\n",
        proc->utime, proc->stime, proc->vss, proc->rss);
}