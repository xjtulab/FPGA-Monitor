#include "interp.h"
#include "hash.h"
#include "stat.h"
#include "log.h"

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>

typedef struct MethodEntry{
    const char *name;
    Method method;
}MethodEntry;

/* Internal variables */
HashTable *methodTable;
int active_procs_count;
pid_t active_procs[MAX_PROCS];

static pthread_t stat_tid;

/* Methods in the table */
static void test(Param *args, Result *result);
static void add(Param *args, Result *result);
static void start(Param *args, Result *result);
static void stop(Param *args, Result *result);
static void stat(Param *args, Result *result);
static void incre_priority(Param *args, Result *result);
static void decre_priority(Param *args, Result *result);

/* Internal methods */
static Param *parse(const char *command);
static pid_t getPidByName(const char *name);
static void addProc(pid_t pid);
static void removeProc(pid_t pid);
static void shutdown();

static MethodEntry methods[] = {
    {"test", test},
    {"add", add},
    {"start process", start},
    {"stop process", stop},
    {"stat", stat},
    {"incre priority", incre_priority},
    {"decre priority", decre_priority},
};


/* Internal methods */
//static void parse();


void InitMethodTable(){
    int i;
    int n = sizeof(methods) / sizeof(MethodEntry); 
    methodTable = CreateHashTable("method table", string_hash, string_equal);

    for(i = 0; i < n;i++){
        Insert(methodTable, (uintptr_t)methods[i].name, 
            (uintptr_t)methods[i].method);
    }

}

void InitAll(){
    InitMethodTable();
    active_procs_count = 0;
    stat_tid = 0;
    memset(active_procs, -1, sizeof(active_procs));
}



int Interpreter(const char *command, char *result_msg){
    Param *param = parse(command);
    
    switch (param->tag)
    {
    case PARAM_STAT:
        Call("stat", param, NULL);
        strcpy(result_msg, 
            param->status?"Start stat process":"Stop stat process");
        break;
    
    case PARAM_START:
        Log(NOTICE, "Prepare to start process '%s'", param->pname);
        Call("start process", param, NULL);
        sprintf(result_msg, "Start process '%s' ", param->pname);
        break;

    case PARAM_STOP:
        Log(NOTICE, "Prepare to stop process '%s'", param->pname);
        Call("stop process", param, NULL);
        sprintf(result_msg, "Stop process '%s' ", param->pname);
        break;

    case PARAM_SHUTDOWN:
        Log(NOTICE, "Prepare to shutdown this monitor");
        shutdown();
        sprintf(result_msg, "Now monitor is closed. '%s' ", param->pname);
        return 0;
        break;
    
    default:
        strcpy(result_msg, "Unknown command.");
        break;
    }

    free(param);

    return 1;
}


void Call(const char *name, Param *args, Result *result){
    Method f;
    Entry *entry = Find(methodTable, (uintptr_t)name);
    if (entry == NULL)
        Log(ERROR, "There is no such method name \"%s\".", name);
    f = (Method)entry->value;

    f(args, result);

}

/*
 * Commands:
 * start process [process_name]  => start a process
 * stop process  [process_name] => stop a process
 * stat stat => start stat process
 * stop stat => stop stat process 
 */ 
static Param *parse(const char *command){

    //remember to free param after interpreter this command
    Param *param = (Param *) malloc(sizeof(Param));
    //memset(param, 0 ,sizeof(Param));

    if (strncmp(command, "stat start", 10) == 0){
        param->tag = PARAM_STAT;
        param->status = 1;
    }else if (strncmp(command, "stat stop", 9) == 0){
        param->tag = PARAM_STAT;
        param->status = 0;
    }else if(strncmp(command, "start process", 13) == 0){
        param->tag = PARAM_START;

        //skip prefix and additional space 
        param->pname = command +13;
        while(!isalpha(*param->pname) && *param->pname != '\0')
            param->pname++;
    }else if(strncmp(command, "stop process", 12) == 0){
        param->tag = PARAM_STOP;

        //skip prefix and additional space
        param->pname = command + 12; // skip 'stop process' prefix
        while(!isalpha(*param->pname) && *param->pname != '\0')
            param->pname++;
    }else if(strncmp(command, "q", 1) == 0){
        param->tag = PARAM_SHUTDOWN;
    }else
        Log(NOTICE, "unknown command:%s", command);
    return param;
}


static void test(Param *args, Result *result){
    printf("This is test method.\n");
}

static void add(Param *args, Result *result){
    result->ires = args->a + args->b;
}

/* Start a process */
static void start(Param *args, Result *result){
    char cmd[128];
    pid_t pid;

    // We use '&' to make it start at background
    snprintf(cmd, sizeof(cmd), "%s%s &", PROCESS_PREFIX, args->pname);
    system(cmd);
    pid = getPidByName(args->pname);

    if (pid >= 0)
        addProc(pid);

    Log(NOTICE, "Start a process: %s pid: %d", args->pname, pid);
}

/* Stop a process */
static void stop(Param *args, Result *result){
    pid_t pid = getPidByName(args->pname);

    if (pid < 0){
        Log(WARNING, "There is no such process named '%s'\n");
        return;
    }
    
    // User kill method 
    kill(pid, SIGKILL);

    removeProc(pid);
    Log(NOTICE, "Stop a process: %s pid: %d", args->pname, pid);
}

//Show resource usage periodic
static void stat(Param *args, Result *result){
    int whether_start = args->status;

    #if 0
    pid_t pid;

    // Start a child process or stop a status process which already exists 
    if (whether_start == 1){
        // Start a new process
        Log(NOTICE, "Start process status");
        pid = fork();
        if (pid == 0){
            // child process
            Log(NOTICE, "This is child process for status infos.");
            ShowProcStatus();
        }else
            stat_pid = pid;
    }else{
        // Stop the stat child process if it exists
        if (stat_pid < 0)
            Log(NOTICE, "Thre is no stat process.");
        else{
            Log(NOTICE, "Stop status child process %d", stat_pid);
            kill(stat_pid, SIGKILL);
            stat_pid = -1;
        }
    }
    #endif
    if (whether_start == 1){
        // Start a new thread
        Log(NOTICE, "Start stat thread");
        pthread_create(&stat_tid, NULL, ShowProcStatus, NULL);    
    }else{
        if (stat_tid == 0)
            Log(NOTICE, "Thre is no stat thread.");
        else{
            Log(NOTICE, "Stop status thread %d");
            pthread_cancel(stat_tid);
            stat_tid = 0;
        }
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

static void addProc(pid_t pid){
    for(int i = 0; i < MAX_PROCS; i++){
        if (active_procs[i] < 0){
            active_procs[i] = pid;
            Log(NOTICE, "Add process %d to active array.", pid);
            break;
        }
    }
    active_procs_count++;
}
static void removeProc(pid_t pid){
    for(int i = 0; i < MAX_PROCS; i++){
        if (active_procs[i] == pid){
            active_procs[i] = -1;
            Log(NOTICE, "Remove process %d from active array.", pid);
            break;
        }
    }
    active_procs_count--;
}

static void shutdown(){
    for(int i = 0; i < MAX_PROCS; i++){
        if (active_procs[i] > 0){
            kill(active_procs[i], SIGKILL);
            Log(NOTICE, "Stop process: %d", active_procs[i]);
            active_procs[i] = -1;
        }
    }

    if (stat_tid > 0){
        pthread_cancel(stat_tid);
        Log(NOTICE, "Shutdown stat thread");
    }
}

static void incre_priority(Param *args, Result *result){
    pid_t pid = getPidByName(args->pname);
    int priority_value;

    if (pid < 0){
        Log(WARNING, "There is no process named '%s'", args->pname);
        return;
    }

    priority_value = getpriority(PRIO_PROCESS, pid);
    setpriority(PRIO_PROCESS, pid, priority_value +1);

    Log(NOTICE, "Now the priority value is %d", priority_value + 1);
    
}
static void decre_priority(Param *args, Result *result){
    pid_t pid = getPidByName(args->pname);
    int priority_value;

    if (pid < 0){
        Log(WARNING, "There is no process named '%s'", args->pname);
        return;
    }

    priority_value = getpriority(PRIO_PROCESS, pid);
    setpriority(PRIO_PROCESS, pid, priority_value -1);

    Log(NOTICE, "Now the priority value is %d", priority_value - 1);
}
