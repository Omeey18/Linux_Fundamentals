#include <stdio.h>
#include<pthread.h>

void *method(void *num){
    pthread_t id;
    id = pthread_self();
    printf("Thread ID: %u\n",id);
    printf("Process ID: %u\n",getpid());
    printf("Parent Process ID: %u\n",getppid());
    return NULL;
}
int main()
{
    pthread_t thread;
    printf("Thread 1 is created..!\n");
    pthread_create(&thread,NULL,method,NULL);
    pthread_exit(thread);
    return 0;
}