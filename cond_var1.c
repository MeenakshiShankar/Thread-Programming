#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mFuel;

int Fuel_Ltr = 0;

void * FuelFilling(void* arg)
{
    for(int i=0;i<5;i++)
    {   
        pthread_mutex_lock(&mFuel);
        fuel += 15;
        printf("Fuel Dispensed from tank: %d\n",fuel);
        pthread_mutex_unlock(&mFuel);
        sleep(1);

    }
}

void * vehicle(void* arg)
{
        pthread_mutex_lock(&mFuel);
        fuel -= 40;
        printf("Fuel Fed to Vehicle: %d\n",fuel);
        pthread_mutex_unlock(&mFuel);
        sleep(1);
}

int main()
{
    pthread_t thr[2];
    pthread_mutex_init(&mFuel,NULL);
    for(int i = 0;i<2;i++)
    {
        if(i == 1)
        {
            pthread_create(thr+i, NULL, &FuelFilling, NULL);
        }
        else
        {
            pthread_create(thr+i, NULL, &vehicle, NULL);
        }
    }

    for(int i=0;i<2;i++)
    {
        pthread_join(thr[i], NULL);
    }

    pthread_mutex_destroy(&mFuel);

    return 0;
}