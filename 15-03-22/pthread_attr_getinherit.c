#include <stdio.h>
#include <pthread.h>


void *mythread(void *i){
    // printf("I am a my thread: %d \n",(int *)i);
    // pthread_once(&once,(void *)myinit);//calling thread once func 
    //                                     //but it will call only once time
    // printf("Exit from my thread: %d\n",(int *)i);
    sleep(3);
}

int main()
{
    pthread_attr_t attr;
    pthread_t thread;
    int err, info;
    
    pthread_attr_init(&attr);
    pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);//changing attributes 
    pthread_attr_getinheritsched(&attr,&info);//getting attributes 
    switch (info)
    {
    case PTHREAD_INHERIT_SCHED:
        printf("\nSCHED\n");
        break;
    
    case PTHREAD_EXPLICIT_SCHED:
        printf("\nEXPLICIT\n");
        break;

    default:
        printf("Default\n");
        break;
    }
    pthread_create(&thread,&attr,mythread,(void*)1);
    
    sleep(1);
    printf("Exit from main func\n");
    pthread_exit(NULL);
    return 0;
}