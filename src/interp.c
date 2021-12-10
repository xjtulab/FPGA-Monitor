#include "interp.h"
#include "hash.h"
#include "stat.h"
#include "log.h"

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

typedef struct MethodEntry{
    const char *name;
    Method method;
}MethodEntry;

/* Internal variables */
HashTable *methodTable;


/* Methods in the table */
static void test(Param *args, Result *result);
static void add(Param *args, Result *result);
static void start(Param *args, Result *result);
static void stop(Param *args, Result *result);
static void stat(Param *args, Result *result);

/* Internal methods */
static Param *parse(const char *command);
static pid_t getPidByName(const char *name);

static MethodEntry methods[] = {
    {"test", test},
    {"add", add},
    {"start", start},
    {"stop", stop},
    {"stat", stat}
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



void Interpreter(const char *command, char *result_msg){
    Param *param = parse(command);
    
    switch (param->tag)
    {
    case PARAM_STAT:
        Call("stat", param, NULL);
        strcpy(result_msg, 
            param->status?"Start stat process":"Stop stat process");
        break;
    
    default:
        strcpy(result_msg, "Unknown command.");
        break;
    }

    free(param);

}


void Call(const char *name, Param *args, Result *result){
    Method f;
    Entry *entry = Find(methodTable, (uintptr_t)name);
    if (entry == NULL)
        Log(ERROR, "There is no such method name \"%s\".", name);
    f = (Method)entry->value;

    f(args, result);

}


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

    Log(NOTICE, "Start a process: %s pid: %d", args->pname, pid);
}

/* Stop a process */
static void stop(Param *args, Result *result){
    pid_t pid = getPidByName(args->pname);

    if (pid < 0)
        Log(ERROR, "There is no such process named '%s'\n");
    
    // User kill method 
    kill(pid, SIGKILL);
    Log(NOTICE, "Stop a process: %s pid: %d", args->pname, pid);
}

//Show resource usage periodic
static void stat(Param *args, Result *result){
    int whether_start = args->status;
    pid_t pid;

    static pid_t stat_pid = -1;

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