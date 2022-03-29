// 2.Write a program where a structure of information passed to pthread task function, and
// display structure of information.

#include <stdio.h>
#include <pthread.h>
#include<string.h>

struct trainee
{
    int id;
    char name[20];
};

void *dis(void *arg)
{
    struct trainee *t = (struct trainee *)arg;
    printf("ID := %d\t Trainee name := %s \n", t->id,t->name);
    return NULL;
}

void main()
{
    int id,n;
    printf("Enter number trainee: ");
    scanf("%d",&n);
    pthread_t tid[n];
    char name[20];
    struct trainee T[n];

    for(int i=0;i<n;i++){
        printf("Enter Trainee ID: ");
        scanf("%d",&id);
        T[i].id = id;

        printf("Enter Trainee Name: ");
        scanf("%s",name);
        strcpy(T[i].name,name);
    }
    printf("\n\n");
    for(int i=0;i<n;i++)
        pthread_create(&tid[i], NULL,(void *)dis, &T[i]);
    pthread_exit(NULL);
}