#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
int main()
{
	struct timeval start_n, end_n;
	gettimeofday(&start_n, NULL);
	sleep(5);
	gettimeofday(&end_n, NULL);
	long seconds = (end_n.tv_sec - start_n.tv_sec);
	long micros = ((seconds*1000000)+end_n.tv_usec) - (start_n.tv_usec);
	printf("Elapsed time is %ld seconds and %ld micros\n", seconds, micros);
	return 0;
}