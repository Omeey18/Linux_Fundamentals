#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* thread1(void *arg){
    //printf("newly created thread 1 is executing \n");
    char *s = (char *) arg;
    printf("%s\n",s);
    sleep(5);
    return (void*)strlen(s);
    //return NULL;
}

int main(int argc, char *argv[]){
    
    pthread_t tid;
    void *res;
    int s;

    int ret = pthread_create(&tid, NULL, thread1, "Hello world");
    
    if(ret)
        printf("Thread1 is not created\n");
    else    
        printf("Thread1 is created\n");
    
    printf("Message from main()\n");

    sleep(3);
    pthread_join(tid,&res);
    printf("Thread return %ld\n",(long)res);
    exit(0);
    // pthread_join(tid, NULL);
    // pthread_join(tid2, NULL);
    return 0;
}