#include <stdio.h>
#include<stdlib.h>

    // extern int EF_PROTECT_BELOW;

void buggy(int *p){
    *p=20;
    free(p);
}

int main()
{
    int *ptr;
    ptr = (int*)malloc(4);
    buggy(ptr);
    free(ptr);
    return 0;
}