//write a program child executed (exec()) a new program while parent waits child task to complete.
//Author Om Patel

#include<stdio.h>
#include<unistd.h>


int main(){
    int pid;
    pid=fork();
    if(pid==0){
        int ret = execl("/home/ompatel/linux_Fundamentals/10-03-22/Asignment/5","./5",NULL);
        //5 file will execute
    }
    else{
        wait(0);
        printf("Parent running");
    }
}