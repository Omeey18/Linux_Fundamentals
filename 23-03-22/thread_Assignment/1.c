#include <stdio.h>
#include<pthread.h>
int i=1;
void *inc(void *num){
    
    long th_id;
    th_id = (long)num;
    printf("thread:%ld  |  ",th_id);
    i++;
    printf("i: %d\n",i);
    sleep(1);
    return NULL;
}

void *dec(void *num){
    
    long th_id;
    th_id = (long)num;
    printf("thread:%ld  |  ",th_id);
    i--;
    printf("i: %d\n",i);
    sleep(1);
    return NULL;
}
int main()
{
    pthread_t thread[3];
    for(int i=1;i<=3;i++){
        //sleep(1);
        //printf("Thread %d is created..!\n",i);  
        if(i%2==0)
            pthread_create(&thread[i],NULL,inc,(void *)i);
        else    
            pthread_create(&thread[i],NULL,dec,(void *)i);
    }
    pthread_exit(NULL);
    return 0;
}