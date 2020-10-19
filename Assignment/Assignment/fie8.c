#define THREAD_COUNT 4
#define ARRAY_SIZE 400
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
int arr[ARRAY_SIZE];
void fillArray(void);

struct ThreadParameters
{
    int* array;
    int start;
    int end;

    // output
    int smallest;
    int largest;
};
void* find_min_max(void* args)
{
    struct ThreadParameters* params = (struct ThreadParameters*)args;
    int *array = params->array;
    int start = params->start;
    int end = params->end;
    int smallest = array[start];
    int largest = array[start];


    for (int j = start; j < end; j++)
    {
        if (array[j] < smallest)
        {
            smallest = array[j];
        }

        if (array[j] > largest)
        {
            largest = array[j];
        }
    }


    params->smallest = smallest;
    params->largest = largest;

    return 0;
}
void fillArray()
{
    for (int j = 0; j < ARRAY_SIZE; j++)
    {
        arr[j] = rand() % 1000 + 1;
    }
}

int main()
{
    int smallest;
    int largest;

    
    pthread_t threads[THREAD_COUNT] = {0};
    struct ThreadParameters thread_parameters[THREAD_COUNT]  = {0};

      
    fillArray();

    
    smallest = arr[0];
    largest = arr[0];

    
    for (int k = 0; k < THREAD_COUNT; k++)
    {
        thread_parameters[k].array = arr;
        thread_parameters[k].start = k * (ARRAY_SIZE / THREAD_COUNT);
        thread_parameters[k].end = (k+1) * (ARRAY_SIZE / THREAD_COUNT);
        thread_parameters[k].largest = 0;
        pthread_create(&threads[k], 0, find_min_max, &thread_parameters[k]);
    }

    
    for (int j = 0; j < THREAD_COUNT; j++)
    {
        pthread_join(threads[j], 0);
    }

    
    for (int j = 0; j < THREAD_COUNT; j++)
    {
        if (thread_parameters[j].smallest < smallest)
        {
            smallest = thread_parameters[j].smallest;
        }

        if (thread_parameters[j].largest > largest)
        {
            largest = thread_parameters[j].largest;
        }
    }

    printf("Minimum element = %d\n", smallest);
    printf("Maximum element = %d\n", largest);

}