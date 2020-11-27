/*
this program initializes 2 signal actions, assigns same handler to both actions.
while action1 is handled, SIGUSR2 will be blocked on delivery.
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#define MAXCHILD 1
#define MAXIMUM 5

int total=0 ;
// "handler1" is handler function for action1 and action2, returns void
void handler1(int signo)
{
 switch(signo)
 {
 /* handling SIGUSR1 takes one second
 during this time if SIGUSR2 will be blocked on delivery. */
 case SIGUSR1:
 total++ ; 
 printf("Total : %d \n",total);
 break;
 }

}
int main()
{
 
 struct sigaction action1;
 action1.sa_handler = handler1;
 sigemptyset(&action1.sa_mask);  //action1.sa_mask = 0;
 action1.sa_flags = 0;
 
 //initializng parent process before fork()
 sigaction(SIGUSR1, &action1,NULL);
 
int inchild=0;

 pid_t parent=getpid();
 pid_t pid[MAXCHILD]; 
  for ( int i=0;i<MAXCHILD;i++)
 {
 pid[i]=fork();
 if( pid[i]==0)
 {
 inchild=1;
 break;
 }
 }

 while(inchild==0){
	 if (total> MAXIMUM ){
		 kill(0,SIGKILL);
		 return 0 ; 
	 }
 };

 while(inchild==1)
 {
 //child sends SIGUSR1 and immediately SIGUSR2 to parent every one second
 kill(parent,SIGUSR1);
 sleep(1);
 }
 return 0;
}