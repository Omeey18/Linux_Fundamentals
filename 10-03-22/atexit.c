#include <stdio.h>

void callback1(void)
{
    printf("Callback 1 func called\n");
}

void callback2(void)
{
    printf("Callback 2 func called\n");
}

void callback3(void)
{
    printf("Callback 3 func called\n");
}

void main()
{
    printf("Registring callback1\n");
    atexit(callback1);

    printf("Registring callback2\n");
    atexit(callback2);

    printf("Registring callback3\n");
    atexit(callback3);

    printf("Main().. exiting now\n");
    exit(0);
}   