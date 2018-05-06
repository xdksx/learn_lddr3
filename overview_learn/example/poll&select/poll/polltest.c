#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <fcntl.h>  
#include <unistd.h>  
#include <linux/poll.h>  
#include <sys/time.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
  
int main(int argc, char *argv[])  
{  
    int fd0, fd1, fd2, fd3;  
    struct pollfd poll_fd[4];  
    char buf[100];  
    int retval;  
  
    if(argc != 2 || ((strcmp(argv[1], "read") != 0) && (strcmp(argv[1], "write") != 0)))  
    {  
        printf("usage: ./poll_test read|write\n");  
        return -1;  
    }  
  
    fd0 = open("/dev/pipee0", O_RDWR);  
    if ( fd0 < 0)  
    {  
        printf("open pipee0 error\n");  
        return -1;  
    }  
      
    fd1 = open("/dev/pipee1", O_RDWR);  
    if ( fd1 < 0)  
    {  
        printf("open pipee1 error\n");  
        return -1;  
    }  
      
    fd2 = open("/dev/pipee2", O_RDWR);  
    if ( fd2 < 0)  
    {  
        printf("open pipee2 error\n");  
        return -1;  
    }  
      
    fd3 = open("/dev/pipee3", O_RDWR);  
    if ( fd3 < 0)  
    {  
        printf("open pipee3 error\n");  
        return -1;  
    }  
  
    if(strcmp(argv[1], "read") == 0)  
    {  
        poll_fd[0].fd = fd0;  
        poll_fd[1].fd = fd1;  
        poll_fd[2].fd = fd2;  
        poll_fd[3].fd = fd3;  
  
        poll_fd[0].events = POLLIN | POLLRDNORM;  
        poll_fd[1].events = POLLIN | POLLRDNORM;  
        poll_fd[2].events = POLLIN | POLLRDNORM;  
        poll_fd[3].events = POLLIN | POLLRDNORM;  
  
        retval = poll(poll_fd, 4, 10000);  
    }  
    else  
    {  
        poll_fd[0].fd = fd0;  
        poll_fd[1].fd = fd1;  
        poll_fd[2].fd = fd2;  
        poll_fd[3].fd = fd3;  
  
        poll_fd[0].events = POLLOUT | POLLWRNORM;  
        poll_fd[1].events = POLLOUT | POLLWRNORM;  
        poll_fd[2].events = POLLOUT | POLLWRNORM;  
        poll_fd[3].events = POLLOUT | POLLWRNORM;  
          
        retval = poll(poll_fd, 4, 10000);  
    }  
  
    if (retval == -1)  
    {  
        printf("poll error!\n");  
        return -1;  
    }  
    else if (retval)  
    {  
        if(strcmp(argv[1], "read") == 0)  
        {  
            if(poll_fd[0].revents & (POLLIN | POLLRDNORM))  
            {  
                printf("/dev/pipee0 is readable!\n");  
                memset(buf, 0, 100);  
                read(fd0, buf, 100);  
                printf("%s\n", buf);  
            }  
  
            if(poll_fd[1].revents & (POLLIN | POLLRDNORM))  
            {  
                printf("/dev/pipee1 is readable!\n");  
                memset(buf, 0, 100);  
                read(fd1, buf, 100);  
                printf("%s\n", buf);  
            }  
  
            if(poll_fd[2].revents & (POLLIN | POLLRDNORM))  
            {  
                printf("/dev/pipee2 is readable!\n");  
                memset(buf, 0, 100);  
                read(fd2, buf, 100);  
                printf("%s\n", buf);  
            }  
  
            if(poll_fd[3].revents & (POLLIN | POLLRDNORM))  
            {  
                printf("/dev/pipee3 is readable!\n");  
                memset(buf, 0, 100);  
                read(fd3, buf, 100);  
                printf("%s\n", buf);  
            }  
        }  
        else  
        {  
            if(poll_fd[0].revents & (POLLOUT | POLLWRNORM))  
            {  
                printf("/dev/pipee0 is writable!\n");  
            }  
  
            if(poll_fd[1].revents & (POLLOUT | POLLWRNORM))  
            {  
                printf("/dev/pipee1 is writable!\n");  
            }  
  
            if(poll_fd[2].revents & (POLLOUT | POLLWRNORM))  
            {  
                printf("/dev/pipee2 is writable!\n");  
            }  
  
            if(poll_fd[3].revents & (POLLOUT | POLLWRNORM))  
            {  
                printf("/dev/pipee3 is writable!\n");  
            }  
        }  
    }  
    else  
    {  
        if(strcmp(argv[1], "read") == 0)  
        {  
            printf("No data within ten seconds.\n");  
        }  
        else  
        {  
            printf("Can not write within ten seconds.\n");  
        }  
    }  
  
    return 0;  
}  
