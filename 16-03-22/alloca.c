#include <stdio.h>
#include<stdlib.h>

int main()
{
    char *str1= "Linuxkernel";
    char *str2 ="OmPatel";
    char *name = (char *)alloca(strlen(str1)+strlen(str2)+1);
    strcpy(strcpy(name,str1),str2);
    printf("the COPIED string data: %s\n",name);    
    return 0;
}