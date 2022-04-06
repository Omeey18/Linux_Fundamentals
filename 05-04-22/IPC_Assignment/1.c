#include <stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>


int main()
{
    void *p;
    int id;

    //creating shared memory region
    id = shmget(48,250,IPC_CREAT|0644);   
    //print id of shared memory region
    printf("id= %d\n",id);

    //getting address of shared memory region
    p = shmat(id,0,0);
    //print address of shared memory region 
    printf("Address: %p\n",p);

    return 0;
}