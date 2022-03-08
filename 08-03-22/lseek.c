#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int fd, len;
    char write_buf[50]="Hello om..!";
    char read_buf[50];

    fd = open("linux_kernel.txt", O_CREAT | O_RDWR, 777);
    len = write(fd,write_buf,50);
    printf("Return value from write buffer is %d \n", len);
    lseek(fd,0,SEEK_SET);
    read(fd,read_buf,len);
    printf("Data in file is:\n%s",read_buf);
    close(fd);
    return 0;
}