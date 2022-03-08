#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int  main(){
    int fd;
    char buf[300];
    int res; 
    fd = open("writeFC.c",O_CREAT| O_RDWR, 777);
    read(fd, buf, 300);
    printf("Data is \n%s",buf);
    close(fd);
    return 0;
}