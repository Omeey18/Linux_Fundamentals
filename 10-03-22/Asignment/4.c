
//3. A program that replaces old progra, with vim editor program and open new text file.
//author Om Patel


#include<stdio.h>
#include<unistd.h>

int main(){
    printf("This will open om.txt file\n");
    int ret = execlp("vim","vim","om.txt",NULL);
    if(ret == -1){
        printf("error\n");
    }
    return 0;
}