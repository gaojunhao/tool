#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>

//#define DEV_PATH "/dev/input/event4" 

int main(int argc, char* argv[])
{
    int keys_fd; 
    char ret[2];
    struct input_event t;  
    
    keys_fd = open(argv[1], O_RDONLY);  
    if(keys_fd <= 0)
    {
        printf("open %s device error!\n",argv[1]);
        return -1;
    }
    while(1)
    {
        if(read(keys_fd, &t, sizeof(t)) == sizeof(t))  
        {
            if(t.type == EV_KEY)
            {
                if(t.value==0 || t.value==1)
                {
		    if(t.code == 0x0010)
                        printf("keyboard event success\n");
		    else if(t.code == 0x0110)
			printf("mouse event success\n");
		    else if(t.code == 0x014A)
			printf("touch event success\n");
		    else
			printf("error\n");
//		    printf("key %d %s\n", t.code, (t.value) ? "Pressed" : "Released");
                }
            }
        }
    }
    close(keys_fd);
    return 0;
}
