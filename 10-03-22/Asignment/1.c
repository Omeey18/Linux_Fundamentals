/*
test whether the process (exec() system call) that replaces old program data, will inherit the fd's or not.
*/
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int fd;
    fd=open("/home/ompatel/Linux_Internals/10-03-22/Asignment/readfile",O_RDONLY,0777);
    printf("Inherit File Descriptor: %d\n",fd);   
}
