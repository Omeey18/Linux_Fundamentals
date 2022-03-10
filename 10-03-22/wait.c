#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void main()
{
    pid_t pid;
    pid=fork();

    if(pid == 0){
        sleep(5);
        printf("I am a child wiht 5 delay and pid is = %d\n", getpid());
    }
    else{
        int pid2;
        printf("I am parent and pid is = %d\n",getpid());
        pid2 = wait(0);
        printf("parent saying .. child %d exited/ terminated normally\n",pid2);
        printf("I am parent and id is = %d\n",getpid());
    }
    
}