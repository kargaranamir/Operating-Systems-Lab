
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <wait.h>

#define maxchild 3	//Note: if you increase the number of children,
			//	you should increase the time to sleep too(lines: 61,66).

char namedPipe[50];
int childID=-1;
int pipeDescriptor;

void handler(int signo){
	char buffer[256];
	int id,pid=0;
	switch(signo){
		case SIGUSR1:
			sprintf(buffer, "%d %d\n",childID,getpid());
			pipeDescriptor=open(namedPipe,O_RDWR,0777);
			write(pipeDescriptor,buffer,strlen(buffer));
			childID=-2;	//by this line the child will terminate after returning to while(childID>=0).
			kill(getppid(),SIGUSR2);
			break;
		case SIGUSR2:
			pipeDescriptor=open(namedPipe,O_RDWR,0777);
			read(pipeDescriptor,buffer,255);
			sscanf(buffer,"%d %d\n",&id,&pid);
			printf("child[%d] = %d \n",id,pid);
			break;
	}
	return;
}



int main(){
	sprintf(namedPipe,"%s","signalPipe");
	mkfifo(namedPipe,0777);		//this function just make the pipe and
					//we need to open it separately in child and parent(See Signal Handler).
	struct sigaction userSigAction;
	userSigAction.sa_flags=0;
	sigemptyset(&userSigAction.sa_mask);
	userSigAction.sa_handler=handler;
	sigaction(SIGUSR1,&userSigAction,NULL);
	sigaction(SIGUSR2,&userSigAction,NULL);
	pid_t childPIDs[maxchild];
	for(int i=0;i<maxchild;i++){
		childPIDs[i]=fork();	//remember: the return value of fork() for parent is child's PID.
		if(childPIDs[i]==0){
			childID=i;
			break;
		}
	}
	while(childID>=0);		//the childID just for parent is -1

	sleep(1);		//please Note this sleep is necessary,
				//because we should sure all childs have taken their ID.
	if(childID==-1){
		for(int i=0;i<maxchild;i++){
			kill(childPIDs[i],SIGUSR1);
			sleep(1);	//this sleep is necessary too,
					//we should avoid receiving two SIGUSR2 simultaneously.
					//otherwise we can expect Undefined Behavior(such as 'core dump' or 'terminating' or 'waiting for ever')
		}
		for(int i=0;i<maxchild;i++)
			waitpid(childPIDs[i],NULL,0);
	}
	return 0;
}

//All my friends, I hope the comments be clear, but anyway, feel free to ask your questions:   milad_golgolnia@yahoo.com
