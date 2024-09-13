#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>


int primes[10] = {2,3,5,7,11,13,17,19,23,29};


void* routine(void *arg)
{
    int index = *(int *)arg; 
    int sum = 0;
    for(int j=0;j<5;j++)
    {
        sum+= primes[index+j];
    }
    printf("Local Sum = %d\n",sum);
    *(int *)arg = sum;
    return arg;
}



int main()
{
    pthread_t thr[2];

    int i;

    for(int i=0;i<2;i++)
    {
        int* a = (int *)malloc(sizeof(int));
        *a = i*5;
        pthread_create(thr+i,NULL,&routine,a);
    }
    int globalSum = 0;
    int *r;
    for(int i=0;i<2;i++)
    {
        pthread_join(thr[i],(void *)&r);
        globalSum +=*r;
        free(r);
    }

    printf("Global Sum =  %d\n", globalSum);
    return 0;
}