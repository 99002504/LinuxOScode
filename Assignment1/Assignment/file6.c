#include<stdio.h>
#include <pthread.h> 
#define MAX 1000 
#define THREADMAX 10 

int arr[MAX];


int sum[10] = { 0 }; 
int part = 0; 
  
void* arraysum(void* arg) 
{  
	int threadpart = part++; 
      for(int i = threadpart * (MAX / 10); i < (threadpart + 1) * (MAX / 10); i++)
	{
		arr[i]=1;
	}
    // Each thread computes sum of 1/10th of array 
   
  
    for (int i = threadpart * (MAX / 10); i < (threadpart + 1) * (MAX / 10); i++) 
        sum[threadpart] += arr[i]; 
        	

} 
  
// Code for Driver
int main() 
{ 

  
    pthread_t threads[THREADMAX]; 
  
    // Creating  threads 
    for (int i = 0; i < THREADMAX; i++) 
        pthread_create(&threads[i], NULL, arraysum, (void*)NULL); 
  
    // joining  threads i.e. waiting for all  threads to complete 
    for (int i = 0; i < THREADMAX; i++) 
        pthread_join(threads[i], NULL); 
  
    // adding sum of all parts 
    int total= 0; 
    for (int i = 0; i < THREADMAX; i++) 
        total += sum[i]; 
  
   printf("total:%d\n",total);
  
    return 0; 
} 