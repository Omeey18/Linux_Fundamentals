#include <stdio.h>
#include<unistd.h>
#include<errno.h>

int main()
{
    int ret, cnt=0;
    errno = 0;
    ret = nice(1);
    if(ret == -1 && errno !=0 )
        perror("nice");
    else
        printf("nice value is now %d\n",ret);

    while (1)
    {
        /* code */
        printf("Process with nice number: %d count = %d \n",ret,cnt);
        for(int i=0;i<00000000;i++){
            cnt++;
        }
    }
        
    return 0;
}