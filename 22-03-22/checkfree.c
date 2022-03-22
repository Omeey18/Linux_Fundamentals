#include <stdio.h>
#include<stdlib.h>

    // extern int EF_PROTECT_BELOW;

void buggy(){
    int *intptr;
    int i;
    intptr = (int *)malloc(sizeof(int)); //giving 20 bytes to intptr
    printf("Value of ptr intptr =%d\n",(*intptr));
    free(intptr);
    *intptr = 99;
}

int main()
{
    buggy();
    return 0;
}