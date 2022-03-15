#include <stdio.h>
#include <pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;//declaring variable

void *myinit(){//init pointer function
    printf("I am a init func\n");
}

void *mythread(void *i){
    printf("I am a my thread: %d \n",(int *)i);
    pthread_once(&once,(void *)myinit);//calling thread once func 
                                        //but it will call only once time
    printf("Exit from my thread: %d\n",(int *)i);
}

int main()
{
    pthread_t thread,thread1, thread2;
    pthread_create(&thread,NULL,mythread,(void*)1);
    pthread_create(&thread1,NULL,mythread,(void*)2);
    pthread_create(&thread2,NULL,mythread,(void*)3);
    sleep(1);
    printf("Exit from main func\n");
    pthread_exit(NULL);
    return 0;
}