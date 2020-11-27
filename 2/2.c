#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int count, char ** args)
{
 int i = 0;
 int j = 0;
 int arg_1 = 0;
 int arg_2 = 0;
 char Buffer[256];

 for (i = 0; i < 256; i++)
 {
  Buffer[i] = '\0';
 };

 if (!strcmp(args[1], "-make"))
 {
  arg_1 = atoi(args[5]);
  arg_2 = atoi(args[6]);
  for( j = arg_1; j <= arg_2; j++)
  {
   sprintf(Buffer,"%s/%s_%d.%s", args[2], args[3], j, args[4]);
   open(Buffer, O_CREAT, 00777);
  };
 };

return 0;
}
