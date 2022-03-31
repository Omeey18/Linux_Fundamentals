#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>

int main()
{
    int qid;
    struct msqid_ds buf;
    qid = msgget(55,IPC_CREAT|0644);
    printf("Qid = %d\n",qid);
    msgctl(qid,IPC_STAT,&buf);
    printf("Here are the details of the queue\n");
    printf("no of msg's in q %hi\n",buf.msg_qnum);
    printf("MAx of bytes in q % hi\n",buf.msg_qbytes);
     msgctl(qid,IPC_RMID,&buf);
    return 0;
}