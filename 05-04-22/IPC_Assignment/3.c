// 3.Write a program parent process writing to pipe and child reading toggled data from pipe,
// and also analyse the data flow order from write end to read end.


#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>


int fd[2];

void child(){
    char data[100];
    int len;
    len = read(fd[0],data,100);

    printf("\nData read by child: ");
    for(int i=0;i<len;i++){
        //changing uppercase char to lower
        if(data[i]<97)
            printf("%c",data[i]+32);
        //changing lower char to uper
        else
            printf("%c",data[i]-32);
    }
    printf("\nEnd of child\n");

}

void parent(){
    char data[100];
    scanf("%s",data);
    int len  =strlen(data);
    write(fd[1],data,len);
    printf("End of Parent\n");
    sleep(1);
}

int main()  
{

    pid_t pid;
    int res = pipe(fd);
    if(res == -1){
        perror("PIPE");
        exit(1);
    }   

    pid = fork();
    if(pid==0){
        //child execute
        child();
    }
    else{
        //Parent Execute
        parent();
    }

    return 0;
}