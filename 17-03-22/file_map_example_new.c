#include <stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>

int main()
{
    char *c;
    int fd;
    struct stat file_info;
    fd = open("kernel.txt",O_CREAT|O_RDWR);
    write(fd,"Linux Internals",25);
    fstat(fd,&file_info);
    printf("File size of :%d\n",file_info.st_size);
    c= mmap(0, file_info.st_size, PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
    perror("mmap");
    //strcpy(c,"linuxkernel");
    printf("%s\n",c);

    munmap(c, file_info.st_size);
    close(fd);    
    return 0;
}