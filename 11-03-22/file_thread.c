#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<fcntl.h>
int fd;


void* thread1(void *p){
    char * str, buff[100];
    int n,pid;
    str = (char *)p;

    //printf("newly created thread 1 is executing \n");
    pid = getpid();//process id
    printf("%s: \tStarted Now: \t for process %d \n\n",str,pid);
    do{
        n=read(fd,buff,100);
        printf("%s: \tRead: \t %d \n\n",str,pid);
        printf("\n-------------------\n");
        write(1,buff,100);

        printf("\n------------------\n");
        sleep(3);
    }while(1);
    printf("%s: \t Finished: \t for process %d\n\n",str,pid);
    return NULL;
}

int main(void){

    pthread_t t1, t2;
    fd = open("/etc/passwd",O_RDONLY);
     printf("File Opend with fd: %d \n",fd);//FD=3 return kernel os
     pthread_create(&t1,NULL,thread1,"Thread One"); 
     pthread_create(&t2,NULL,thread1,"Thread Two");
     pthread_join(t1,NULL);
     pthread_join(t2,NULL);    
    

    return 0;
}