#include<unistd.h>
#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if( argc != 2 ) { printf("argument Faild\n");
    exit(EXIT_FAILURE);
    }
    printf("i'm going to sleep %s sec\n", argv[1]);
    sleep( atoi(argv[1]) );
return 0;
}
