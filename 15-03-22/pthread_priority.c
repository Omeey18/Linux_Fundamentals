#include <stdio.h>
#include <pthread.h>


// void *mythread(void *i){
//     printf("Exit from my thread: %d\n",(int *)i);
//     //sleep(3);
// }

int main()
{
    struct sched_param param;
    //pthread_attr_t attr;
   // pthread_t thread;
    int priority,policy,ret;
    
    ret = pthread_getschedparam(pthread_self(),&policy,&param);
    //it will policy and priority of thread
    if(ret!=0){
        perror("GetSchedulaerparam\n");
    }
    printf("\n------------main thread -------------\n policy: %d \t Priority: %d\n",policy,param.sched_priority);
    policy = SCHED_FIFO;
    param.sched_priority=3;
    ret= pthread_setschedparam(pthread_self(),policy,&param);
    if(ret!=0){
        perror("GetSchedulaerparam\n");
    }
    ret = pthread_getschedparam(pthread_self(),&policy,&param);
    if(ret!=0){
        perror("GetSchedulaerparam\n");
    }

    printf("\n------------main thread -------------\n policy: %d \t Priority: %d\n",policy,param.sched_priority);
    printf("Exit from main func\n");
    pthread_exit(NULL);
    return 0;
}