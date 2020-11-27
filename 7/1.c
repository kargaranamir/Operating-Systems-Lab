#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>

#define THREADS 2
#define SIZE 5
int a[SIZE] ={3,0,3,7,5};

int b[SIZE] = {1,2,2,2,2};

sem_t sem1;
int product =0 ;
void * routine(void * id)
{	
	int id2 = (int) id;
	int temp=0 ;
	int j ;
	for (j = id2 ; j < SIZE ; j+=THREADS) {
		temp += a[j] * b[j];
	}
	sem_wait(&sem1);
	product += temp;
	sem_post(&sem1);
	pthread_exit((void *) id2);
	
}

int main(int argc , char ** argv)
{
	sem_init(&sem1,0,1);
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
	printf("product is %d\n",product);
	return 0;
}
