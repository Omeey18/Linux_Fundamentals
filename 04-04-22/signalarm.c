#include <stdio.h>
#include<signal.h>

void sighand(int signum){
    printf("\nI have recevied CTRL+C signal\n");
}

int main()
{
    signal(SIGINT,sighand);
    // alarm(2);
    sleep(4);
    // while (1)
    // {
    //     /* code */
    // }
    
    return 0;
}