// 1.Write a pthread application where main task terminated but pending pthreads task still
// execute.

#include <stdio.h>
#include<pthread.h>


void *t_method(void *n){
    int t_num = (int *) n;
    printf("--------Thread %d is running---------\n",t_num);
}
int main()
{
    printf("Main fun Started...!\n");
    pthread_t t[5];

    for(int i=1;i<=5;i++){
        pthread_create(&t[i],NULL,(void *)t_method,i);
    }

    printf("Main fun Completed...!\n");
    pthread_exit(NULL);
    return 0;
}