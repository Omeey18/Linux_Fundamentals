#include <stdio.h>
#include<string.h>
int main()
{
    char dest[]="oldstring";
    const char src[] = "newstring";

    printf("before move dest: %s and src: %s\n",dest,src);
    memmove(dest,src,2);
    printf("after move dest: %s and src: %s\n",dest,src);

    return 0;
}