#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_t tid;

void* thread1(void *threadid){
    //printf("newly created thread 1 is executing \n");
    printf("\nHello\n");
    while(1);
}

int main(void){
    
    int rc, t=0;
    
    rc = pthread_create(&tid, NULL, thread1, NULL);
    printf("\n thread ID: %u",tid);
    sleep(6);
    t=pthread_cancel(tid);
    if(t==0)
        printf("\n Cancelled thread\n");
    else    
        printf("Thread1 is created\n");
    printf("\n thread ID: %u",tid);
    return 0;
}