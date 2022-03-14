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