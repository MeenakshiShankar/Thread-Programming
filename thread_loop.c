#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

#define BIG 1000000000UL
uint32_t mails = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void* routine()
{
    for(uint32_t  i=0;i < BIG;i++)
    {
        pthread_mutex_lock(&lock);
        mails++;
        pthread_mutex_unlock(&lock);
    }
}

int main()
{
    pthread_t thr[4];
    int i;
    for(i=0;i<4;i++)
    {
        pthread_create(thr + i, NULL, &routine, NULL);
        printf("Thread %d has started. \n",i);
    }
    for(i=0;i<4;i++)
    {
        pthread_join(thr[i],NULL);
        printf("Thread %d has finished executing.\n",i);
    }

    printf("Number of mails:%d\n",mails);
    return 0;
}