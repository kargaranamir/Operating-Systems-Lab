#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char ** b){

	int openfile;
	int i;
	char c[50];

	int v1 = atoi(b[5]);
	int v2 = atoi(b[6]);
	if(!strcmp(b[1], "-make")){
		for(i = v1; i<=v2; i++){

			sprintf(c,"%s/%s_%d.%s",b[2],b[3],i,b[4]);
			openfile = open (c, O_CREAT, 00777);
		}
	}
	
	close (openfile);
return 0;
}

