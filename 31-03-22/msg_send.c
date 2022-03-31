#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>


struct  msg
{
    long mtype;
    char data[100];
}m1;

int main()
{
    int qid, i;
    // msg m1, m2;

    qid = msgget(32, IPC_CREAT | 0644);

    m1.mtype = 10;
    char d[50];
    gets(d);
    for (i = 0; i < strlen(d); i++)
    {    
        m1.data[i] = d[i];
    }
    
    i = msgsnd(qid, &m1, sizeof(m1), 0);
    return 0;
}