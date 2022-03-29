// 3.Write a pthread program that implements simple initialization code.

#include <stdio.h>
#include <pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *init(){
    printf("I am a init func\n");
}

void *method(void *i){
    printf("--------Thread: %d ---------\n",(int *)i);
    pthread_once(&once,(void *)init);
}

int main()
{
    pthread_t t[5];
    printf("Main fun Started...!\n");
    for(int i=1;i<=5;i++){
        pthread_create(&t[i],NULL,(void *)method,i);
    }
    sleep(2);
    printf("Main fun Completed...!\n");
    pthread_exit(NULL);
    return 0;
}
