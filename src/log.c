#include "log.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/* Some macros for print colorful messages to terminal. */
#define NONE                 "\e[0m"
#define RED                  "\e[0;31m"
#define GREEN                "\e[0;32m"
#define L_BLUE               "\e[1;34m"

void Log(LOG_LEVEL level, const char *fmt, ...){
    va_list args;
    time_t t;
    struct tm *timeinfo;

    /* Get current system time. */
    time(&t);
    timeinfo = localtime(&t);

    /* Print log prefix: notice or error. */
    if(level == NOTICE){
        printf("%s[NOTICE]%s: ", GREEN, NONE);
    }else{
        printf("%s[ERROR]%s: ", RED, NONE);
    }

    /* Show current time, such as [2012/12/12 16:58:30] */
    printf("%s[%d/%d/%02d %02d:%02d:%02d]%s: ", L_BLUE, 1900 +timeinfo->tm_year,
        1 + timeinfo->tm_mon, timeinfo->tm_mday, timeinfo->tm_hour,
        timeinfo->tm_min, timeinfo->tm_sec, NONE);

    /* Print user messages. */
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);

    printf("\n");

    /* Error will exit program abnormally. */
    if(level == ERROR)
        exit(-1);
}

/* Do not show time version. */
#if 0
void Log(LOG_LEVEL level, const char *fmt, ...){
    va_list args;


    if(level == NOTICE){
        printf("%s[NOTICE]%s: ", GREEN, NONE);
    }else{
        printf("%s[ERROR]%s: ", RED, NONE);
    }
    
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);

    printf("\n");
}
#endif