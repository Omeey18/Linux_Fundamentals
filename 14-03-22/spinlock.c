#include<unistd.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


static pthread_spinlock_t spinlock;
volatile int slock;

void *spinlock_thread(void *i)
{
    int rc;
    int  count=0;
    printf("Enter thread %d, getting spin lock\n",(int*)i);
    rc = pthread_spin_lock(&slock);
    printf("%d thread unlock the spin lock\n",(int *)i);
    return NULL;
}


void main()
{
    int rc=0;
    
    pthread_t t1, t2;
    if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0){
        perror("init");
    }
    printf("Main, get spin lock\n");
    rc = pthread_spin_lock(&slock);
    printf("Main created spin lock thread\n");
    rc =pthread_create(&t1,NULL,spinlock_thread,(int*)1);

    printf("Main will wait bit holding the spin lock\n");
    sleep(5);

    printf("Main now unlock spin lock\n");
    rc = pthread_spin_unlock(&slock);

    if(rc==0){
        printf("\n main thread succesfully unlocked\n");
    }else{
        printf("\n main thread unsuccesfully unlocked\n");
    }

    printf("Main wait for the thread\n");
    rc = pthread_join(t1,NULL);
    printf("Main completed\n");
    return 0;
}