#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int fd1, fd2, fd3;
    fd1=open("linux.txt",O_WRONLY|O_CREAT|O_TRUNC,777);
    fd2=open("linux1.txt",O_WRONLY|O_CREAT|O_TRUNC,777);
    printf("Fd1=%d\n",fd1);
    printf("Fd2=%d\n",fd2);

    fd3 = fcntl(fd1,F_DUPFD,10);
    //fd3 = dup2(fd1,4);
    //fd3 = dup(fd1);
    printf("Fd3=%d\n",fd3);
    close(fd1);
    close(fd2);
    close(fd3);
}