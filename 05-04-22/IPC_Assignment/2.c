#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/msg.h>

struct msgbuf
{
    long mtype;
    char data[100];
}v;


int main(){

    int id ,nMsgs;
    char msg[100];
    id = msgget(55, IPC_CREAT | 0644);
    struct msqid_ds buf;

    printf("Enter number of mags you want to senD: ");
    scanf("%d",&nMsgs);
    for(int i=1;i<=nMsgs;i++){
        printf("Data: ");
        scanf("%s",msg);
        strcpy(v.data,msg);
        v.mtype = i;
        printf("Return value of msgsnd of As = %d\n",msgsnd(id, &v, sizeof(v), 0));

    }
   

   //will print statactics of msg queue
    msgctl(id,IPC_STAT,&buf);
    printf("Num of msgs: %d\n",buf.msg_qnum);
    printf("Max of bytes: %hi\n",buf.msg_qbytes);
    printf("No of bytes in msq: %hi\n",buf.__msg_cbytes);

    //will delete msg queue
    msgctl(id,IPC_RMID,&buf);
    return 0;
}