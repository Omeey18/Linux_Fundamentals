/*msgrcv*/

#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>

struct msg
{
    long mtype;
    char data[100];
} m1;

int main()
{
    int qid, i;

    qid = msgget(32, IPC_CREAT | 0644);

    msgrcv(qid, &m1, sizeof(m1), 10, 0);
    for (i = 0; i < 100; i++)
    {
        printf("%c", m1.data[i]);
    }
    printf("\n");
    

    return 0;
}