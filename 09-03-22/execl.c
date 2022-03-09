#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    
    // printf("I am going  to excute an 'ls' progrma\n");
    // execl("/bin/vfork","./vfork",0);

    // printf("I executed LS program\n");
    // printf("I executed LS program\n");
    // printf("I executed LS program\n");

    int ret;
    ret = execl("/usr/bin/vim","vim","info1.txt",0);
    if(ret == -1)
        printf("excel return error: %d\n",ret);

}