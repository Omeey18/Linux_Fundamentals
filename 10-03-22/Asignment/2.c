#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    pid_t q,q_child;
    q = fork();
    if(q==0){
        //wait(NULL);
        printf("I am child Process and id: %d\n",getpid());
        printf("    My parent process id is: %d\n",getppid());
        execlp("vim", "vim", NULL);
            
        q_child=fork();
        if(q_child==0){
            printf("I am grand child process and id: %d\n",getpid());
            execlp("ls","-a","-s",NULL);        
        }
    }
    else{
        //wait(NULL);
        printf("I am parent Process and id: %d\n",getpid());
        printf("    My child process id: %d\n",q);
    }      

    return 0;
}