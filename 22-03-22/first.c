#include <stdio.h>
#include<string.h>
struct student
{
    /* data */
    int rool;
    char name[40], gender;
    float height;
}first;



int main()
{
    struct student second;
    struct student third = {103, "Om Patel", 'm', 5.7};

    printf("\n roll no\tName\t\t\t\t\tGender\tHeight\n");
    strcpy(first.name,"Dhruv");
    first.gender='f';
    first.height = 3.3;
    printf("%3d\t\t%-40s%c\t%1.2f\n",first.rool,first.name,first.gender,first.height);
    printf("%3d\t\t%-40s%c\t%1.2f\n",third.rool,third.name,third.gender,third.height);
    return 0;
}