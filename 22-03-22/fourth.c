#include <stdio.h>
#include<string.h>
struct A
{
    /* data */
    //int rool;
    char name[40], gender;
    //char b;
    //float height;
}first;



int main()
{
   
    struct A first;
    printf("\n size of struct A: %3d\n",sizeof(first));
    return 0;
}