//A program that replaces old program with new program data and is expected to display
//the currently running processes in a hierarchical tree format.

#include<stdio.h>
#include<unistd.h>

int main(){
     execlp("pstree","pstree",NULL);
}