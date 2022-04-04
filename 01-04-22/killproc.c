#include <stdio.h>
#include<signal.h>
#include<stdio.h>

int main()
{
    pid_t pid;
    int sig_no;
    printf("Enter the pid of process for which the signal need to be sent: ");
    scanf("%d",&pid);
    printf("Enter the signal that need to be sent: ");
    // sig_no = getpid();
   scanf("%d",&sig_no);

    kill(pid,sig_no);
    perror("sig_res:");    
    return 0;
}