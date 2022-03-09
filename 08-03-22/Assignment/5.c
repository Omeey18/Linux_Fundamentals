#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int fd;
    char write_buf[4000]=" ";
    fd = open("4k.txt", O_CREAT | O_RDWR, 777);
    write(fd,write_buf,4000);
    close(fd);
    return 0;
}