#ifndef __LOG_H
#define __LOG_H

#include <stdarg.h>

typedef enum LOG_LEVEL{
    NOTICE,
    WARNING,
    ERROR
}LOG_LEVEL;

void Log(LOG_LEVEL level, const char *fmt, ...);

#endif