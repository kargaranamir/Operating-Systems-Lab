#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
int stride=0;

int a[SIZE]= { 5, 9, 23, 32, 1};


void * min_routine(void* id){
	
	int idx = (int) id;
	
	if(idx+stride<SIZE){
		if(a[stride+idx]<a[idx])
			a[idx]=a[stride+idx];
	}
	else
		if(a[stride+idx-1]<a[idx])
			a[idx]=a[stride+idx-1];
	pthread_exit(NULL);
}


int main(){
	if(SIZE%2==0)
		stride=SIZE/2; //even
	else stride=SIZE/2+1; //odd
	pthread_t threads[stride];
	
	while(stride){
		for(int i=0;i<stride;i++)
			pthread_create(&threads[i],NULL,min_routine,(void*)i);
		for(int i=0;i<stride;i++)
			pthread_join(threads[i],NULL);

		if (stride=1)
			stride=0;
		if else (stride%2)
			stride=stride/2+1;
		else stride/=2;
		//sleep(1);
	}
	printf("%d\n",a[0]);
	return 0;
}
