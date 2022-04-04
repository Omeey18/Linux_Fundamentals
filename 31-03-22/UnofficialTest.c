#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int p[n];
    printf("Parent id: %d\n", getpid());
for(int i=0;i<n;i++){
    p[i] = fork();
    sleep(1);
    if(p[i]==0){
        printf("Child %d's Parent id = %d\n",i,getppid());
        return 0;
    }
}
    return 0;
}