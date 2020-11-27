#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_CHILD 5

int main()
{
    int pipe, inChild = 0;
    int id = -1;
	char namedPipe[50];
	
	sprintf(namedPipe,"%s","signalPipe");
	mkfifo(namedPipe,0777);		//this function just make the pipe and
    char buffer[256];
    pid_t pid[MAX_CHILD];

    for (int i = 0; i < MAX_CHILD && inChild == 0; i++)
    {
        pid[i] = fork();
        if (pid[i] == 0)
        {
            id = i;
            inChild = 1;
        }
    }

    if (inChild == 0)
    {
        pipe = open(namedPipe, O_WRONLY);
        sprintf(buffer, "%d", MAX_CHILD);
		bzero(buffer, 256);
        write(pipe, buffer, 256);
        close(pipe);
    }

    while (inChild == 1)
    {
        sleep(2);
        bzero(buffer, 256);
        pipe = open(namedPipe, O_RDWR);
        read(pipe, buffer, 255);
        if (atoi(buffer) == 0)  //zero in pip line 
           exit(0);
		   break;
        if (atoi(buffer) == id)
        {	
            bzero(buffer, 256);
            sprintf(buffer, "%d", id - 1);
            printf("%d", id - 1);
        }
        write(pipe, buffer,256);
        close(pipe);
    }
    return 0;
}