#ifndef __INTERP_H
#define __INTERP_H

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

typedef void (*Method)(Param *args, Result *result);

void Call(const char *name, Param *args, Result *result);
void InitMethodTable();
#endif