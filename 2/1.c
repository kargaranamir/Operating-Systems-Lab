#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int ac, char ** args)
{
int i = 0;
int openc = 0;
int openv = 0;
int openr = 0;
char Buffer[300];

for (i = 0; i < 299; i++)
{
 Buffer[i] = '\0';
};

if (!strcmp(args[1], "-c")){
 openc = open(args[2], O_CREAT, strtol(args[3], NULL , 8));
}

else if (!strcmp(args[1], "-w")){
  scanf("%s", Buffer);
  openv = open(args[2], O_CREAT|O_RDWR, 00755);
  write(openv, Buffer, strlen(Buffer));
  close(openv);
}

else if (!strcmp(args[1], "-r")){
 openr = open(args[2], O_RDONLY);
 read(openr, Buffer, 300);
 printf("%s /n", Buffer);
}

return 0;
}


