#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>// insmod: error inserting './scull.ko': -1 Invalid module format
#define device "/dev/scull0"
int main(void){   
     int fd; 
       char buf[] = "Late Lee"; 
       char buf2[30]={0};  
      int len;        fd = open(device, O_RDWR);
        if (fd < 0)      
  {       
         perror("Open device faile!"); 
               return -1;     
   }    
    len = write(fd, buf, sizeof(buf)); 
       printf("buf: %s %d\n", buf, len); 
    sleep(2);    
   len = read(fd, buf2, 25); // 由此指定读取数据，可大可小，但是驱动只读取这个指定的(大者读实际值)，并返回       
 printf("buf2: %s %d\n", buf2, len);
        close(fd);  
      return 0;
}
//here has a stay problem is that it cannot write and read but can wirte end and
//read in another process but i donnot know why
