#include <linux/input.h>
#include<stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc, char* argv[])
{
    int fd_kb;
    fd_kb = open(argv[1],O_RDWR);
    if(fd_kb <= 0)
    {
        printf("open /dev/input/event4 device error!\n");
        return -1;
    }

    struct input_event event;
    printf( "write once\n");

//    event.code = LED_NUML;
//    event.type = EV_LED;
//    event.value = 0;
//    gettimeofday (&event.time, 0);
//    write(fd_kb, &event, sizeof (event));

    event.code = MSC_SCAN;
    event.type = EV_MSC;
    event.value = 0x70014;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = KEY_Q;
    event.type = EV_KEY;
    event.value = 1;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.type = EV_SYN;
    event.code = SYN_REPORT;
    event.value = 0;
    write(fd_kb, &event, sizeof(event));

    event.code = MSC_SCAN;
    event.type = EV_MSC;
    event.value = 0x70014;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = KEY_Q;
    event.type = EV_KEY;
    event.value = 0;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.type = EV_SYN;
    event.code = SYN_REPORT;
    event.value = 0;
    write(fd_kb, &event, sizeof(event));
    fsync(fd_kb);
    close(fd_kb);
}

