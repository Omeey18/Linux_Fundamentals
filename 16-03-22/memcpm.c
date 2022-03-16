#include <stdio.h>
#include<string.h>

int main()
{
    char buf[10];
    char buf1[10];
    int ret;

    memcpy(buf, "Omp", 5);
    memcpy(buf1, "Oma", 5);

    ret = memcmp(buf,buf1,5);

    if(ret > 0){
        printf("buf is greter then buf1\n");
    }
    else if (ret< 0){
        printf("Buf1 is greater than buf\n");
    }
    else{
        printf("both are equal\n");
    }
    
    return 0;
}