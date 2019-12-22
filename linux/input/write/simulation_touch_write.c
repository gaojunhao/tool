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

    event.code = 0x0039;
    event.type = EV_ABS;
    event.value = 0x0000001b;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = 0x0035;
    event.type = EV_ABS;
    event.value = 0x00004db0;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = 0x0036;
    event.type = EV_ABS;
    event.value = 0x00001ee0;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = BTN_TOUCH;
    event.type = EV_KEY;
    event.value = 0x00000001;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = ABS_X;
    event.type = EV_ABS;
    event.value = 0x00004db0;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = ABS_Y;
    event.type = EV_ABS;
    event.value = 0x00001ee0;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.type = EV_SYN;
    event.code = SYN_REPORT;
    event.value = 0;
    write(fd_kb, &event, sizeof(event));

    event.code = 0x0035;
    event.type = EV_ABS;
    event.value = 0x00004d50;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = 0x0036;
    event.type = EV_ABS;
    event.value = 0x00001f20;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = ABS_X;
    event.type = EV_ABS;
    event.value = 0x00004d50;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = ABS_Y;
    event.type = EV_ABS;
    event.value = 0x00001f20;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.type = EV_SYN;
    event.code = SYN_REPORT;
    event.value = 0;
    write(fd_kb, &event, sizeof(event));

    event.code = 0x0039;
    event.type = EV_ABS;
    event.value = 0xffffffff;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = BTN_TOUCH;
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

