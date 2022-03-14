//write a program child executed (exec()) a new program while parent waits child task to complete.
//Author Om Patel

#include<stdio.h>
#include<unistd.h>


int main(){
    int pid;
    pid=fork();
    if(pid==0){
        //child process
        printf("Child process is running \n");
        int ret = execl("/home/ompatel/Linux_Internals/10-03-22/Asignment/6","",NULL);
        //5 file will execute
    
    }
    else{
        wait(0);//parent will wait till child execute
        //sleep(5);
        printf("Parent running\n");
        printf("Parent Process Stopped...!\n");
    }
}