#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>

int main (int argc ,char** argv)
{
  char  f[255] ; 
  int i,j;
  char c;

 if (strcmp(argv[1], "-matrix") ==0)
{
  FILE *file=fopen(argv[4] ,"w+");

for (i=0 ; i<atoi(argv[2]) ; i++)
{
   for (j=0 ; j<atoi(argv[3]) ;j++){
  
  scanf ("%s",f);
  fprintf (file , "%s ",f);}
  fprintf(file, "\n");	
 
}
}

 else if (strcmp(argv[1], "-vector") ==0)
{
  FILE *file=fopen(argv[3] ,"w+");

for (i=0 ; i<atoi(argv[2]) ; i++)
{
  scanf ("%s",f);
  fprintf (file , "%s ",f);
 
}
}


else if ((strcmp(argv[1], "-readMat") ==0) && argc==5)
{
  FILE *file=fopen(argv[4] ,"r");
 for (i=0 ; i<atoi(argv[2])-1 ; i++);
  fgets (f , 255, file);
   for (j=0 ; j<atoi(argv[3]) ;j++)
   fscanf(file , "%s ",f);
   printf ("%s\n" , f);
}



else if ((strcmp(argv[1], "-readMat") ==0) && argc==3)

{
  FILE *file=fopen(argv[2] ,"r"); 
while ((c=fgetc (file ))!=-1)
{
 printf ("%c" , c);
}
}

else if ((strcmp(argv[1], "-readVec") ==0) && argc==4)
{
  FILE *file=fopen(argv[3] ,"r");

   for (j=0 ; j<atoi(argv[2]) ;j++)
   fscanf(file , "%s ",f);
   printf ("%s\n" , f);
}

else if ((strcmp(argv[1], "-readVec") ==0) && argc==3)
{
  FILE *file=fopen(argv[2] ,"r"); 
while ((c=fgetc (file))!=-1)
{
 printf ("%c" , c);
}
}


return(1);
}
