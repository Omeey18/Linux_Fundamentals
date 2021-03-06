#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd1;

    mkfifo("newfifo", 0666);

    char str1[100], str2[100];
    while (1)
    {
        /* first open in read only and read */
        fd1 = open("newfifo", O_RDONLY);
        read(fd1, str1, 100);

        // print the read string and close
        printf("user1 : %s\n", str1);
        close(fd1);

        // now open in writing mode and write
        // string take from user
        fd1 = open("newfifo", O_WRONLY);
        fgets(str2, 100, stdin);
        write(fd1, str2, strlen(str2) + 1);
        close(fd1);
    }
}