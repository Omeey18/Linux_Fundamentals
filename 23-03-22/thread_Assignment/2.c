#include <stdio.h>
#include<pthread.h>

void *method(void *num){
    //sleep(3);
    pthread_t id;
    id = pthread_self();
    int th_id;
    th_id = (int)num;
    printf("Hello thread:%ld\n",th_id);
    printf("Thread ID: %u\n",id);
    printf("Thread cancel itself...\n");
    int a = pthread_cancel(id);
    if(a)
        printf("thread is not cancelled\n");
    else if(a==0)
        printf("Thread is cancelled\n");
    
    //pthread_exit(NULL);
    return NULL;
}
int main()
{
    pthread_t thread;
        printf("Thread 1 is created..!\n");
        pthread_create(&thread,NULL,method,(void *)1);

   pthread_exit(thread);
        printf("hjxgfdhsbckhsbxklmjabxhksnxsjkn");
    return 0;
}