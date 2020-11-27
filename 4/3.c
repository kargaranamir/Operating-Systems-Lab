#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>

int main (int argc, char *argv[])
{
	char buf[1000];
	FILE *  fd = fopen("log.txt", "w" );
	fprintf(fd , "Date \t\t Time  Execution Time(ms) \t\t path \n");
	fclose(fd);
	while (1)
	{	
		int arg_num;
		char command[1000];
		printf("Enter your program's path:");
		scanf("%s", command);
		printf("Enter number of arguments");
		scanf("%d", &arg_num);
		char **args = malloc (sizeof(char *) * (arg_num+1));
		for ( int i = 0; i < arg_num; i++)
		{
			args[i] = malloc(sizeof(char) * 1000);
			printf("Please %d th argument ", i);
				scanf("%s", args[i]);
		}
		args[arg_num] = NULL;
		pid_t pid = fork();
		
		if (pid==0)
		{
			execv(command , args ); //24 ms
			//system("/bin/ls .");  //36 ms
			
			/* system will call the shell (sh) to execute the command sent as an argument. The problem with system because 
			the shell behavior depends on the user who run the command. but 
			execv does not call a shell. It executes the program that passed to it as first argument.*/
			
			exit (0);
			
		}
		
		else
		{
			struct timeval start , end ;
			struct tm tminfo;
			time_t seconds;
			seconds=time(NULL);
			tminfo = * localtime(&seconds);
			gettimeofday(&start, NULL);
			wait(NULL);
			gettimeofday(&end , NULL);
			
			long sec=end.tv_sec-start.tv_sec;
			float m1=start.tv_usec;
			float m2=end.tv_usec;
			long elapsed = sec*1000+(m2-m1)/1000; 
			
			FILE *  fd = fopen("log.txt", "a" );
			fprintf(fd , "%04d-%02d-%02d \t\t %ld (ms) \t\t %s \n", (tminfo.tm_year)+1900 , (tminfo.tm_mon)+1 , tminfo.tm_mday , elapsed ,command);

			fflush(fd);
			
			
			
		}
	fclose(fd);
	}
}
			
		
