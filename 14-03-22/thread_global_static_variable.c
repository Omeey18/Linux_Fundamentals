#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include<semaphore.h>

int sharedVar = 5; // shared variable(critical section)
sem_t my_sem;


void *thread_inc(void *arg)
{
    sem_wait(&my_sem);//lock
    sharedVar++;
    sem_post(&my_sem);//unlock

    printf("After inc = %d\n", sharedVar);
}

void *thread_dec(void *arg)
{
    sem_wait(&my_sem);
    sharedVar--;
    sem_post(&my_sem);

    printf("After dec = %d\n", sharedVar);
}

void main()
{
    pthread_t t1, t2;

    sem_init(&my_sem,0,1);//initlize
    pthread_create(&t1, NULL, thread_inc, NULL);
    pthread_create(&t2, NULL, thread_dec, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("shared var = %d\n", sharedVar);
}