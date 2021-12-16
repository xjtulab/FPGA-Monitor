#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("This is fpga1!\n");
    for(;;){
        usleep(800000);
    }
    return 0;
}
