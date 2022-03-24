#include <stdio.h>
#include<pthread.h>


pthread_mutex_t lock;
int i=1;

void *inc(void *num){
    
    long th_id;
    th_id = (long)num;
    printf("thread:%ld  |  ",th_id);
    pthread_mutex_lock(&lock);
    i++;
    sleep(1);
    pthread_mutex_unlock(&lock);
    printf("i: %d\n",i);
    return NULL;
}

void *dec(void *num){
    
    long th_id;
    th_id = (long)num;
    printf("thread:%ld  |  ",th_id);
    pthread_mutex_lock(&lock);
    i--;
    sleep(1);
    pthread_mutex_unlock(&lock);
    printf("i: %d\n",i);
    return NULL;
}
int main()
{
    pthread_t thread[10];
    pthread_mutex_init(&lock,NULL);
    for(int i=1;i<=10;i++){
        if(i%2==0){
            sleep(1);
            pthread_create(&thread[i],NULL,inc,(void *)i);
        }
        else{
            sleep(1);  
            pthread_create(&thread[i],NULL,dec,(void *)i);
        }
    }
    pthread_exit(NULL);
    return 0;
}