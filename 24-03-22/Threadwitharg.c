#include <stdio.h>
#include<pthread.h>

void *method(void *arg){
    int i = (int *)arg;
    printf("Threead is created %d...!\n",i);
}

int main()
{
    pthread_t t;
    pthread_create(&t,NULL,method,(void*)1);
    pthread_exit(NULL);
    return 0;
}