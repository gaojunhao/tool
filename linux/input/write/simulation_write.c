#include<linux/input.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int keyboard(char* argv)
{
    int fd_kb;
    fd_kb = open(argv,O_RDWR ,__O_DIRECT);
    if(fd_kb <= 0)
    {
        printf("open %s device error!\n",argv);
        return -1;
    }

    struct input_event event;
    printf( "write keyboard once\n");

    event.code = MSC_SCAN;
    event.type = EV_MSC;
    event.value = 0x90001;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = 0x0010;
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
    event.value = 0x90001;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = 0x0010;
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
int mouse(char* argv)
{
    int fd_kb;
    fd_kb = open(argv,O_RDWR ,__O_DIRECT);
    if(fd_kb <= 0)
    {
        printf("open %s device error!\n",argv);
        return -1;
    }

    struct input_event event;
    printf( "write mouse once\n");

    event.code = MSC_SCAN;
    event.type = EV_MSC;
    event.value = 0x90001;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = 0x0110;
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
    event.value = 0x90001;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = 0x0110;
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
int touch(char* argv)
{
    int fd_kb;
    fd_kb = open(argv,O_RDWR);
    if(fd_kb <= 0)
    {
        printf("open %s device error!\n", argv);
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

    event.code = 0x014a;
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

    event.code = 0x014a;
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

int main(int argc, char* argv[])
{
    if(!strcmp(argv[1], "keyboard"))
	keyboard(argv[2]);
    else if(!strcmp(argv[1], "mouse"))
	mouse(argv[2]);
    else if(!strcmp(argv[1], "touch"))
	touch(argv[2]);
    else
	printf("please input correctly\n");
}

