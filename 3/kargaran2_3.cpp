#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


int main (){

int v1,v2;
char prefix[256],file_address [256];
scanf("%s %s %d  %d",prefix , file_address , &v1 , &v2);

for(int i=v1 ; i<=v2 ; i++){

char S[32];
char C[32];
sprintf(S,"useradd  %s-%d",prefix,i);
system(S);

sprintf(C,"cp %s /home/%s-%d",file_address,prefix,i);
system(C);

//system("ls");

}
return(0);
}

