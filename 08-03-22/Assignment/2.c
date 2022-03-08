#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int fd, len;
    char write_buf[11]="Hello om..!";
    char read_buf[50];

    fd = open("linux_kernel.txt", O_CREAT | O_RDWR, 777);
    len = write(fd,write_buf,50);
    //printf("Return value from write buffer is %d \n", len);
    printf("Seek set at start position of file\n");
    lseek(fd,0,SEEK_SET);
    read(fd,read_buf,len);
    printf("Data in file is:\n%s",read_buf);
    printf("\nSeek set at end position of file\n");
    lseek(fd,-50,SEEK_END);
    read(fd,read_buf,len);
    printf("Data in file is:\n%s",read_buf);
    printf("\nSeek set at current position of file\n");
    lseek(fd,-45,SEEK_CUR);
    read(fd,read_buf,len);
    printf("Data in file is:\n%s",read_buf);
    close(fd);
    return 0;
}