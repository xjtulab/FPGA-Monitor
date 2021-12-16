#ifndef __UTILS_H
#define __UTILS_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define PROCESS_PREFIX "/home/fpg/school/fpga_monitor/subproc/"
#define DEFAULT_BUCKET_SIZE 16
#define MAX_METHOD_SIZE 16
#define MAX_PROCS 8
#define MAX_BUFFER_LENGTH 256


typedef uint32_t (*HashFunc)(uintptr_t key);
typedef bool (*EqualFunc)(const void *p1, const void *p2);

extern int nprocs;
extern const char *proc_names[];

#endif