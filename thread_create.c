#include <stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* myturn(void* arg)
{
    // int *iptr = (int *)arg;
    int *iptr = (int *)malloc(sizeof(int));
    *iptr = 5;
    for(int i = 0;i<8;i++)
    {
        sleep(1);
        printf("My turn %d %d\n",i,*iptr);
        (*iptr)++;
    }
    return iptr;
}

void yourturn()
{
    for(int i=0;i<3;i++)
    {
        sleep(1);
        printf("Your turn %d\n",i);
    }
}



int main()
{
    pthread_t newthread;

    int *result;
    // int v = 5;
    //pthread_create(&newthread, NULL, myturn, &v);
    pthread_create(&newthread, NULL, myturn, NULL);

    yourturn();
    pthread_join(newthread, (void*)&result);
    printf("Final result  = %d\n",*result);
}