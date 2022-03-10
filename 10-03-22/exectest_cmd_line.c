// #include<stdio.h>

// int main(int argc, char *argv[]){
//     int i;
//     printf("\n file name is: %s\n",argv[0]);
//     printf("\n Total numbers of args %d:\n",argv);
//     pritnf("\n Arguments Passed :");
//     for(i=1;i<argc;i++){
//         printf("%s ",argv[i]);
//     }
// }


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void main()
{
    printf("Can you see me [one]\n");
    execl("/home/ompatel/linux_Fundamentals/10-03-22/hello", "./hello", "hello", "om", "patel", NULL);
}
