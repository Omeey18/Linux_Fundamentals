#include <stdio.h>
#include<signal.h>

void check_blocked_sigs(){
    int i, res;
    sigset_t s;
    sigprocmask(SIG_BLOCK,NULL,&s);
    for(i=1;i<5;i++){
        res = sigismember(&s,i);
        if(res)
            printf("signal %d is blocked \n",i);
        else    
            printf("Signal %d is not blocked \n",i);
    }
}
int main()
{
    sigset_t s_Set;
    sigemptyset(&s_Set);
    sigaddset(&s_Set,2);
    sigaddset(&s_Set,4);
    sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_Set,NULL);
    check_blocked_sigs();
    sigprocmask(SIG_UNBLOCK,&s_Set,NULL);
    check_blocked_sigs();  
    return 0;
}