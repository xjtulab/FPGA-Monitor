#include <stdio.h>
#include <assert.h>

#include "log.h"
#include "server.h"
#include "hash.h"
#include "interp.h"
#include "stat.h"

static void test_hash();
static void test_fp();
static void test_stat();
static void looper();

int main(int argc, char const *argv[])
{
    printf("Hello world\n");
    InitMethodTable();

    //test_hash();
    //test_stat();

    //StartServer();
    looper();
    return 0;
}

static void test_hash(){
    HashTable *htab = CreateHashTable("tbl1", string_hash, NULL);
    Entry *entry = NULL;
    const char *str1 = "hello";
    int value = 0;
    bool success;

    entry = Find(htab, (uintptr_t)str1);
    assert(entry == NULL);

    success = Insert(htab, (uintptr_t)str1,  1);
    printf("success = %s\n", success?"true":"false");

    const char *str2 = "hello2";
    value = 2;
    success = Insert(htab, (uintptr_t)str2,  2);
    printf("success = %s\n", success?"true":"false");

    entry = Find(htab, (uintptr_t)str1);
    printf("str1 value is %d\n", (int)entry->value);
    entry = Find(htab, (uintptr_t)str2);
    printf("str2 value is %d\n", (int)entry->value);

}

static void test_fp(){
    InitMethodTable();

    Call("test", NULL, NULL);

    Param param;
    param.a = 1;
    param.b = 2;

    Result result;

    Call("add", &param, &result);
    printf("Call add(%d, %d) = %d\n",param.a, param.b, result.ires);

    param.pname = "fpga1";
    Call("start", &param, &result);

    Call("stop", &param, &result);

}

static void test_stat(){

    // create a new process 
    ShowProcStatus();   
}

static void looper(){
    char line[128];

    while (fgets(line, sizeof(line), stdin) != NULL){
        printf("%s",line);

        Interpreter(line, NULL);
    }
}