#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("Hello world FPGA1!\n");
    for(;;){
        sleep(2);
    }
    return 0;
}
