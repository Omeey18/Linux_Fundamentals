// 4.write a program, which get and set pthread scheduling policy and priority.


#include <pthread.h>
#include <stdio.h>

void* method(void* arg){
    sleep(3);
    return 0;
}

int main(){
    pthread_attr_t Attr;
    pthread_t id;
    struct sched_param p;
    int *sc;

    pthread_attr_init(&Attr);
    pthread_attr_getschedpolicy(&Attr,&sc);
    pthread_attr_getschedparam(&Attr,&p);
    printf("Default Scheduler behavior= %d\tPriority = %d\n",sc,p.sched_priority);
    sc=2;
    p.sched_priority=20;


    pthread_attr_setschedpolicy(&Attr,sc);
    pthread_attr_setschedparam(&Attr,&p);
    
    pthread_create(&id,&Attr,method,NULL);

    pthread_attr_getschedparam(&Attr,&p);
    pthread_attr_getschedpolicy(&Attr,&sc);
    printf("New Scheduler behavior = %ld\tPriority = %ld\n",sc,p.sched_priority);
}
