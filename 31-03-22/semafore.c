#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int get_semaphore(void);

int release_semaphore(void);

int sem_id;
unton semun{

};

int struct semid_ds *buf;

unsigned short

    (Linux specific) *
    /

    struct sembuf sem_op; // refer man page

union semun sem_union; // refer man page

val;

/* Value for SETVAL */

/* Buffer for IPC_STAT, IPC_SET*/

/*array; / Array for GETALL, SETALL */
struct seminfo *_buf; // Buffer for IPC INFO

int main()

    int i,
    j;

sem_id = senget((key_t)1234, 1, 0666 | IPC_CREAT);

for (i = 0; i < 10; i++)

{

    get_semaphore();

    printf("\nSEM2: %d: got the semaphore\n", getpid());
    for (j = 0; j <= 3; j++)
    {
        sleep(1);
        printf("\a");
    }

    printf("\nSEM2:%d: released the semapore\n", getpid());
    release_semaphore();

    sleep(2);
}
if (semctl(sem_id, 0, IPC_RMID, sem_union) < 0)
    printf("Unable delete semaphore\n");

else

    printf("Semaphore deleted\n");
}

int get_semaphore(void)
{

    sem_op.sem_num = 0;

    // gets the nth no of semaphore specified in sem_num, here its zero,

    sem_op.sem_op = -1;

    sem_op.sem_flg = SEM_UNDO;

    // this flag is optional but its wise to set this flag //it tells the kernel to automatically release the semaphore //if this process terminates without releasing the semaphore... //it can also have the flag IPC_NOWAIT(refer man) if(semop(sem_id, &sem_op, 1) <6)

    printf("Failed to get the sempahore\n");
    return -1;

    /* param 1:Semaphore_id retured by senget systemcall param 2:pointer to sem_buf structure(refer man)

    param 3:no of semphore operations stuctures since we are using only on
    */
    return 0;
}
int release_semaphore(void)
{

    sem_op.sem_num = 0;
    sem_op.sem_op = 1; // same as above but here instead of incrementing we are de
    sem_op.sem_flg = SEM_UNDO;