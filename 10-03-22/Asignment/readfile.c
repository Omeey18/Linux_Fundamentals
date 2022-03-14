
//author OM PATEL.
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
     int ret = execl("/home/ompatel/Linux_Internals/10-03-22/Asignment/1","",0);
    if(ret == -1){
        printf("execl returned error %d\n", ret);
    }
}