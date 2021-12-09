#include <stdio.h>
#include <sys/sysinfo.h>

int main(int argc, char const *argv[])
{
    /* code */
    struct sysinfo s_info;
    sysinfo(&s_info);

    printf("total physical memory: %ldKB \n", s_info.totalram/1024);
    printf("Number of current processes: %d\n", s_info.procs);
    return 0;
}
