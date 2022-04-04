#include <stdio.h>
#include<signal.h>
void sighand(int signum){
    printf("interrupt signal rec'd...but ");
}
int main()
{
    signal(SIGSTOP,sighand);
    //signal(SIGSTOP,SIG_DFL);
    for(int i=0;;i++){
        printf("%d\n",i);
        sleep(1);
    }
    return 0;
}