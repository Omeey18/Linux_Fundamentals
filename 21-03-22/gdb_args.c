#include <stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{   
    int i;
    printf("\n File name is: %s\n",argv[0]);
    printf("\n Total Number of Arguments: %d",argc);
    printf("\n Arguments passed : ");
    for(int i=0;i<argc;i++){
        printf("%s ",argv[i]);
    }
    printf("\n");
    return 0;
}