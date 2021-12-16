#ifndef __INTERP_H
#define __INTERP_H

#include "utils.h"

enum PARAM_TAG{
    PARAM_ARITH,
    PARAM_STAT,
    PARAM_START,
    PARAM_STOP,

    PARAM_SHUTDOWN,
};

typedef struct Param{

    int tag;
    union
    {
        /* Arith Parameters like '+', '-' */
        struct
        {
            int a;
            int b;
        };

        // Process Parameters: name
        const char *pname;

        //Record the status of program parameter
        int status;
    };

}Param;

typedef struct Result{
    int tag;
    /* Arith Result like '+', '-' */
    union 
    {
        int ires;
    };
    
}Result;

extern int active_procs_count;
extern pid_t active_procs[MAX_PROCS];

typedef void (*Method)(Param *args, Result *result);

void Call(const char *name, Param *args, Result *result);
void InitMethodTable();
void InitAll();
int Interpreter(const char *command, char *result_msg);
#endif