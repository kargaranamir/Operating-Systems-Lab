#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include <unistd.h>
#include<semaphore.h>
#define THREADS 5

int lock = 0;
int inc = 1;
void * routine(void * id)
{

	int id2 = (int) id;
	
	while ( 1==1 ) { 
	
	while(lock != id2);
	printf("thread_id = %d\n",id2);

	if(id2 == THREADS-1)
	{	
		inc = -1;
	}else if(id2 == 0)
	{
		inc = 1;
	}
	sleep(1);
	lock += inc; }
	
	pthread_exit((void *) id2);
	
}

int main(int argc , char ** argv)
{
	pthread_t threads[THREADS];
	int i;
	for(i=0;i<THREADS;i++)
	{
		pthread_create(&threads[i],NULL,routine,(void *) i);
	}
	for(i=0;i<THREADS;i++)
	{
		pthread_join(threads[i],NULL);
	}
	return 0;
}
