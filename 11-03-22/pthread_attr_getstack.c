#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>

void *Proc(void *param)
{
    sleep(2);
    return 0;
}

int main()
{
    pthread_attr_t Attr; // 1
    pthread_t Id;
    void *stk;
    size_t siz; // size_t int
    int *sch;
    struct sched_param pro;
    int err;        

    size_t my_stksize = 0X30000000;
    void *my_stack;

    pthread_attr_getstacksize(&Attr, &siz);
    pthread_attr_getstackaddr(&Attr, &stk);
    pthread_attr_getschedpolicy(&Attr, &sch);
    pthread_attr_getschedparam(&Attr,&pro);
    printf("Default: Addr=%08x default size=%ld   Scheduling = %ld  priority = %ld\n", stk, siz, sch,pro.sched_priority);

    my_stack = (void *)malloc(my_stksize);
    sch =2;
    pro.sched_priority = 20;
    printf("MALLOC checking : add=%08x and size=%ld\n",my_stack,my_stksize);
    pthread_attr_setstack(&Attr, my_stack, my_stksize);
    pthread_attr_setschedpolicy(&Attr,sch);
    pthread_attr_setschedparam(&Attr,&pro);
    pthread_create(&Id, &Attr, Proc, NULL);

    pthread_attr_getstack(&Attr, &stk, &siz);
    pthread_attr_getschedpolicy(&Attr, &sch);
    pthread_attr_getschedparam(&Attr,&pro);
    printf("newly defined stack: Addr= %08x and Size=%ld   Scheduling = %ld   priority = %ld\n", stk, siz, sch,pro.sched_priority);

    sleep(3);
}