//Write a program, where functions of the program are called in the reverse order of
//their function calls from main().
//author Om Patel

#include <stdio.h>
#include<stdlib.h>

void display1(){
    printf("Display 1\n");
}
void display2(){
    printf("Display 2\n");
}
void display3(){
    printf("Display 3\n");
}
void display4(){
    printf("Display 4\n");
}
int main()
{
    atexit(display1);
    atexit(display2);
    atexit(display3);
    atexit(display4);
    return 0;
}