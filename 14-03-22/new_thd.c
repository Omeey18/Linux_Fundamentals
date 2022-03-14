#include <pthread.h>
#include <stdio.h>

void function(void *arg)
{
    pthread_detach(pthread_self());
    printf("Sleeping 2 secs\n");
    sleep(2);
    printf("slept 2 sec\n");
}

void main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, function, NULL);

    printf("Ths is main code\n");

    pthread_exit(NULL); // OR We can write pthread_join(&thread, NULL);
    // pthread_exit terminates the main process, but it allows pending tasks to finish, Its not terminating task
}