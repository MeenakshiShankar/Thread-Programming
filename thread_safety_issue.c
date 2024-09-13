#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

#define BIG 1000000000UL
uint32_t counter = 0;


void* count_to_big()
{
    for(uint32_t i=0;i<BIG;i++)
    {
        counter++;
    }
}

int main()
{
    pthread_t t;
    pthread_create(&t, NULL, count_to_big,NULL);

    count_to_big(NULL);
    pthread_join(t,NULL);
    printf("Counter Value = %u\n",counter);
}

//why this code can create problem??
// because operation such as i++ need not be atomic
// hence when both threads overlap a race condition may occur
//where both are trying to prove dominance of their operation
//and is not working on a mutaully respected value to a resrc
//leads to wrong output