#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>


int main(){
    struct stat st;
    int fd;
    stat("lseek.c",&st);
       
    
}