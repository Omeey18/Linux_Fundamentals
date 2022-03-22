#include <stdio.h>
#include<stdlib.h>

    extern int EF_PROTECT_BELOW;

void buggy(){
    int *intptr;
    int i;
    intptr = (int *)malloc(sizeof(int)*5); //giving 20 bytes to intptr
    printf("Malloc checking %08x and size=%d\n",intptr,sizeof(int)*5);
    for(int i=0;i<5;i++){
        *intptr=100;
        printf("value of ptr int= %d\n",(*intptr));
        intptr--;
    }
}

int main()
{
    buggy();
    return 0;
}