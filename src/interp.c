#include "interp.h"
#include "hash.h"
#include "log.h"

#include <stdio.h>

typedef struct MethodEntry{
    const char *name;
    Method method;
}MethodEntry;

/* Internal variables */
HashTable *methodTable;


/* Methods in the table */
static void test(Param *args, Result *result);
static void add(Param *args, Result *result);

static MethodEntry methods[] = {
    {"test", test},
    {"add", add},
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



void Interpreter(const char *command, char *result){
       
}


void Call(const char *name, Param *args, Result *result){
    Method f;
    Entry *entry = Find(methodTable, (uintptr_t)name);
    if(entry == NULL)
        Log(ERROR, "There is no such method name \"%s\".", name);
    printf("found function %s", name);
    f = (Method)entry->value;

    f(args, result);

}


static void test(Param *args, Result *result){
    printf("This is test method.\n");
}

static void add(Param *args, Result *result){
    result->ires = args->a + args->b;
}