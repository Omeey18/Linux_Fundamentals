#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    printf("Server - lintening ");
    int code = mkfifo("cli_Ser_fifo",0764);
    if(code == -1){
        perror("mkfifo returned an error -file any already their");
    }   
    int fd = open("cli_ser_fifo",O_RDONLY);

    if(fd == -1){
        perror("Cannot open FIFO for read");
        return 0;
    }
    printf("FIFO OPEN");

    char serverrcv[100];
    memset(serverrcv,0,100);

    int res;
    char Len;
    while (1)
    {
        /* code */
        res  = read(fd,&Len,1);
        if(res ==0)
            break;
        read(fd,serverrcv,Len);
        printf("\n-------server print: %s---------\n",serverrcv);
    }
    printf("EOF Reached");
    close(fd);
    printf("FIFO Closed");
    return 0;
}