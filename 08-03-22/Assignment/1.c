#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

//author Om Patel

int main(){
    int in_fd,out_fd;//crateing file descriptors  
    char buf[300];//creating buffer to read and write data on file
     
    in_fd = open("readfile.txt",O_RDWR, 777);//open readfile to read content
    out_fd = open("writefile.txt",O_CREAT| O_RDWR, 777);//open or create writefile to write content
    read(in_fd, buf, 300);//reading data from readfile
    write(out_fd,buf,300);//writing data on write file
    close(out_fd);//closing file descriptor 1
    close(in_fd);//closing file descriptor 2
    return 0;
}