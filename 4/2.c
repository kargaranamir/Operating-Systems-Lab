#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>


#define MAXCHILED 5

void handler(){
    
    printf("\nCTRL + C");
    exit(0);
}

void main(){

    srand(time(NULL));
    signal(SIGINT , handler);
    
    pid_t childs[MAXCHILED];
    int i , inChild = 0 , alive , status = 0;
    pid_t pid;
    
    for(i = 0 ; i < MAXCHILED ; i++){
        
        childs[i] = fork();
        
        if(childs[i] == 0){
         
            inChild = 1;
            int random1 = (rand() % 5) + 1;
            sleep(random1);
            printf("message from child %d , waited for %d\n" , getpid() , random1);
            exit(0);
        }
    }

    while(inChild == 0){
        
        for(i = 0 ; i < MAXCHILED ; i++){
         
            alive = waitpid(childs[i] , &status , 0);
            if(alive != 0){
             
                childs[i] = fork();
                if(childs[i] == 0){
         
                    inChild = 1;
                    int random2 = (rand() % 5) + 1;
                    sleep(random2);
                    printf("message from child %d , waited for %d\n" , getpid() , random2);
                    exit(0);
                }
            }
        }
        sleep(5);
    }
    return;
}
