#include <linux/input.h>
#include<stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
void keyboard(char* argv)
{
    int fd_kb;
    fd_kb = open(argv,O_RDWR ,__O_DIRECT);
    if(fd_kb <= 0)
    {
        printf("open %s device error!\n",argv);
        return -1;
    }

    struct input_event event;
    printf( "write once\n");

    event.code = MSC_SCAN;
    event.type = EV_MSC;
    event.value = 0x90001;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = BTN_LEFT;
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

    event.code = BTN_LEFT;
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
void mouse(char* argv)
{
    int fd_kb;
    fd_kb = open(argv,O_RDWR ,__O_DIRECT);
    if(fd_kb <= 0)
    {
        printf("open %s device error!\n",argv);
        return -1;
    }

    struct input_event event;
    printf( "write once\n");

    event.code = MSC_SCAN;
    event.type = EV_MSC;
    event.value = 0x90001;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = BTN_LEFT;
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

    event.code = BTN_LEFT;
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
void touch(char* argv)
{
    int fd_kb;
    fd_kb = open(argv,O_RDWR ,__O_DIRECT);
    if(fd_kb <= 0)
    {
        printf("open %s device error!\n",argv);
        return -1;
    }

    struct input_event event;
    printf( "write once\n");

    event.code = MSC_SCAN;
    event.type = EV_MSC;
    event.value = 0x90001;
    gettimeofday (&event.time, 0);
    write(fd_kb, &event, sizeof (event));

    event.code = BTN_LEFT;
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

    event.code = BTN_LEFT;
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
    if(argv[1] == "keyboard")
	keyboard(argv[2]);
    else if(argv[1] == "mouse")
	mouse(argv[2]);
    else if(argv[1] == "touch")
	touch(argv[2]);
    else
	printf("please input correctly\n");
}

