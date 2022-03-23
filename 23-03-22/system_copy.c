#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char buff_comm[5];
    strcpy(buff_comm,"ls -l");
    printf("System() library function uses fork() to create a chils process\n");
    printf("child process executes excel() which loads ans runs new program provided by system() arguments:\n");
    
    printf("%d",system(buff_comm));
    return 0;
}