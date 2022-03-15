
//4. A program that replaces old program, with vim editor program and open new text file.
//author Om Patel


#include <stdio.h>


int main(int argc,char *argv[])
{
    execlp("vim","vim",argv[1], NULL);
    return 0;
}
