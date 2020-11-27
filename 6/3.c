#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_CHILD 5

int pipe_fd[2];

void handler(int signo)
{
	if(signo == SIGUSR1)
	{
	pid_t my_pid = getpid();
	char pid_str[50]="";
	sprintf(pid_str, "%d", my_pid);
	write(pipe_fd[1], pid_str, 49);
	kill(getppid(), SIGUSR2);
	printf("Signal to parent \n");
	exit(0);
	}
	if(signo == SIGUSR2)
	{
	int pid;
	static int id=0;
	char read_str[50]="";
	read(pipe_fd[0], read_str, 49);
	pid = atoi(read_str);
	printf("Child [%d] = %d\n", id, pid);
	id++;
	}
}


int main()
{
		int result = pipe(pipe_fd);
	int id;
	pid_t child[MAX_CHILD];
	struct sigaction action;
	action.sa_handler = handler;
	action.sa_flags = SA_NODEFER;
	sigaction(SIGUSR2, (struct sigaction *) &action, NULL);
	sigaction(SIGUSR1, (struct sigaction *) &action, NULL);

	for(id = 0; id < MAX_CHILD; id++)
	{
	child[id] = fork();
	int is_child = (child[id] == 0) ? 1:0;
	if(is_child)while(1);
	kill(child[id], SIGUSR1);
	sleep(1);

	}

	return 0;

}
