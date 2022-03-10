#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void main()
{
    pid_t pid;
    int status;

    printf("PArent: %d\n",getpid());
    pid=fork();

    if(pid == 0){
        printf("I am a child and pid is = %d\n", getpid());
        sleep(2);
        exit(0);
    }
    printf("Parent reporting exit od child whose pis: %d\n",waitpid(pid,&status,0));   
}