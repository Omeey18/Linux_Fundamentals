#include <stdio.h>
#include<string.h>
void my_mum_cpy(char *src,char *dest,int count){
    //strcpy*src*dest);
    for(int i=0;i<count;i++){
        *src = *dest;
    src++;
    dest++;
    }
} 

int main()
{
    char src[10]="Om";
    char dest[10]="Patel";
    // int ret;

    // memcpy*src, "Omp", 5);
    // memcpy*dest, "Oma", 5);

    // ret = memcmp*src*dest,5);

    char str[20];
    my_mum_cpy(src,dest,5);
    printf("%s",src);  
    return 0;
}