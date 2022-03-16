#include <stdio.h>
#include<unistd.h>

int main()
{
    size_t i;
    const int allocc_size = 1 * 1024;
    char* memory = malloc(allocc_size);
    mlock(memory,allocc_size);

    for(i=0;i<allocc_size;i++)
        memory[i] = '#';
        printf("allocted memory initilized with: %s\n",memory);
        munlock(memory,allocc_size);    
    return 0;
}