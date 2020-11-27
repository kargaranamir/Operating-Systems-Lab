#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>

void handler(){
    
    printf("\nCTRL + C");
    exit(0);
}

void main(){

    signal(SIGINT , handler);
    pid_t pid;

    while(1){
        
        pid = fork();
        if(pid == 0){
         
            printf("child pid : %d\n" , getpid());
            exit(0);
        }
        
        sleep(2);
    }
    return;
}
