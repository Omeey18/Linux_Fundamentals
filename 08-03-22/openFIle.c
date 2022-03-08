#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main(){
    int fd1, fd2, fd3;
    fd1 = creat("linux100.txt",777);

    fd2 = creat("linux200.txt",777);
    fd3 = creat("linux300.txt",777);
    printf("Fd for linux100= %d\n",fd1);
    printf("Fd for linux200= %d\n",fd2);
    printf("Fd for linux300= %d\n",fd3);

    open("linux100.txt",O_RDWR | O_CREAT, 777);
    open("linux200.txt",O_RDWR | O_CREAT, 777);
    open("linux300.txt",O_RDWR | O_CREAT, 777);

    close(fd1);
    close(fd2);
    close(fd3);
}