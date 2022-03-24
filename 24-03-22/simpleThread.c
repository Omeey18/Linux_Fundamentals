#include <stdio.h>
#include<pthread.h>

void method(){
    printf("Threead is created...!\n");
}

int main()
{
    pthread_t t;
    pthread_create(&t,NULL,method,NULL);
    pthread_exit(NULL);
    return 0;
}