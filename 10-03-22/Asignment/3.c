//A process using execl system call should replace a new command line program


#include<stdio.h>
#include<unistd.h>

int main(){
     execlp("pstree","pstree",NULL);
}