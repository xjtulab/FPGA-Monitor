#ifndef __INTERP_H
#define __INTERP_H

typedef union Param{

    /* Arith Parameters like '+', '-' */
    struct
    {
        int a;
        int b;
    };
}Param;

typedef union Result{

    /* Arith Result like '+', '-' */
    int ires;
}Result;

typedef void (*Method)(Param *args, Result *result);

void Call(const char *name, Param *args, Result *result);
void InitMethodTable();
#endif