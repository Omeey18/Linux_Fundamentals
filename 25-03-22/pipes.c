#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int fds[2];

void parent_code(){
    char *buf1="aaaaaaaccccccccc";
    char *buf="bbbbbbbbb";
    int len = strlen(buf1);
    int len1 = strlen(buf);
    close(fds[0]);
    write(fds[1],buf1,len);
    write(fds[1],buf,len1);
    printf("end of parent\n");
}

void child_code(){
    char buff2[100];
    int n, i;
    close(fds[1]);
    n = read(fds[0],buff2,100);
    printf("no of chars read = %d\n",n);
    for(i=0;i<n;i++){
        printf("%c",buff2[i]);
    }
    printf("\nEnd of child\n");
}
int main()
{
    int res;
    pid_t p;
    
    //printf("%d",len);

    res = pipe(fds);
    if(res == -1){
        perror("pipe");
        exit(1);
    }
    p = fork();
    if(p==0)
        child_code();
    else
        parent_code();

    // read(fds[0],buff2,len+len1);
    // for(i=0;i<len+len1;i++)
    //     printf("%c",buff2[i]);
    // printf("\n");
    return 0;
}