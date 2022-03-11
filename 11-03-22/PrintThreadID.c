#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_t tid;

void* thread1(void *arg){
    //printf("newly created thread 1 is executing \n");
    pid_t pid;//process id
    pthread_t tid;// thrd id
    pid = getpid();
    tid = pthread_self();
    printf("PID %u tid %u \n",(unsigned int)pid,(unsigned int)tid);
    return NULL;
}

int main(void){
    
    int err;
    void *res;
    int s;

    err = pthread_create(&tid, NULL, thread1, NULL);
    
    if(err!=0)
        printf("Thread1 is not created\n");
    else    
        printf("Thread1 is created\n");

    while (1);    
    sleep(3);
    // pthread_join(tid, NULL);
    // pthread_join(tid2, NULL);
    return 0;
}