#include <stdio.h>
#include<string.h>

void myprint(char *msg){
    if(msg!=NULL)
        printf("Msg: %s\n",msg);
}
int main()
{
    char buf[] = "OmPatel";
    myprint(buf);
    return 0;
}