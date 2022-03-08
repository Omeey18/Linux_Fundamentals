#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int fd;
    int x;
    char write_buf[40]="Linux Kernel Om Patel";
    fd = open("linuxabc.txt",O_CREAT | O_RDWR, 777);
    write(fd,write_buf,60);
    close(fd);
    return 0;
}