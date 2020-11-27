#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#define MAX_CHILD 5
#define MAXIMUM 100
#define t 1
int main(){
	int total = 0;
	int fd[MAX_CHILD][2];
	int j = 0;
	for ( int i = 0; i < MAX_CHILD; i++)
	{
		pipe(fd[i]);
		pid_t pid;
		pid = fork();
		if (pid==0)  //in child 
		{

			while(1)
			{
				srand(time(NULL)+getpid());
				int num = rand() % 10 + 1;
				char input[256];
				sprintf(input,"%d", num);
				write(fd[i][1], input, 255);
			  sleep(t);
			}
		}
	}

//	if (pid!=0) // in parent 
	while(1)
	{
		char buffer[256];
		read(fd[j][0], buffer, 255);
		int a;
		sscanf(buffer, "%d", &a);
	    total += a;
		printf("In this check total is %d\n", total);
		if ( total > MAXIMUM)
			{	
				kill(0,SIGKILL);
				exit(0);
				break;
			}
		j++;
		if(j == MAX_CHILD)
			j = 0;
	}
	return 0;
}
