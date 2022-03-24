#include <stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock =PTHREAD_MUTEX_INITIALIZER;

int done = 1;

void *foo (void *arg){
    char *str = (char*)arg;
    printf("thread task called by = %s\n",str);

    pthread_mutex_lock(&lock);
    if(done == 1){
        //let's wait on condition variable cond1
        //done =2
        printf("Waiting on condition variable cond1\n");
        pthread_cond_wait(&cond1,&lock);
    }
    else{
        //let's signal condition variable cond1
        printf("signalling condition varibale cond1\n");
        pthread_cond_signal(&cond1);
    }
    //release lock 
    pthread_mutex_unlock(&lock);
    printf("Returning thread\n");
    return NULL;
}
int main()
{
    pthread_t tid1, tid2;
    //create thread 1
    pthread_create(&tid1,NULL,foo,"THDone");
    //sleep for 1 sec so that thread 1 
    //would get a chance to run first
    sleep(1);
    //let's wait condition variable  cond1
    done = 2;

    pthread_create(&tid2,NULL,foo,"THDtwo");
    pthread_join(tid2,NULL);
    return 0;
}