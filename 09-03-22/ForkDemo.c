#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int pid_1;
    printf("Current procces id : %d\n",getpid());
    pid_1 = fork();

    if(pid_1==0){
        //sleep(3);
        printf("new child Process pid :%d\n",getpid());
        printf("new child parent Process pid :%d\n",getppid());
    }
    else if(pid_1>0){
            wait(0);
            printf("parent Process pid :%d\n",getpid());
            printf("parents parent Process pid :%d\n",getppid());
    }

    
    while(1);
}
