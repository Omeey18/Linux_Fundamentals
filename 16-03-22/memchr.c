#include <stdio.h>
#include <string.h>

int main()
{
    const char str[] = "Linux#kernel-om-patel";
    const char ch ='#';
    char *ret;
    printf("String before set is %s\n",str);
    ret = memchr(str,ch,strlen(str));

    printf("String after **%c** set is :**%s**\n",ch,ret+1);    
    return 0;
}