/*
this program initializes a signal action
assigns a handler to this action and waits for SIGINT (ctrl+c) to be handled
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#define MAX_TRY 4
// "handler1" is handler function for action1, returns void
int num = 0 ; 
void handler1(int signo)
{
 switch(signo)
 {
 case SIGINT:
 num++;
 printf("Number : %d \n",num);
 break;
 }

}
int main()
{
 //initializing sigaction structure
 struct sigaction action1;
 action1.sa_handler = handler1;
 sigemptyset(&action1.sa_mask);  //action1.sa_mask = 0;
 action1.sa_flags = 0;

 sigaction(SIGINT, &action1,NULL);

 //runnign forever, while process is sensitive to SIGINT
 while(1){
	 
	 if (num==MAX_TRY)
		 return 0;
		 
 }

 return 0;
}