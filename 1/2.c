#include <stdio.h>

int main ()
{
int inp1, inp2;
char prefix[80];
char location[80];
char temp[80];
	
scanf("%d", &inp1);
scanf("%d", &inp2);
scanf("%s", prefix);
scanf("%s", location);
int i;
for  ( i = inp1; i <= inp2; i++)
{
sprintf(temp, "sudo useradd -m %s%d" , prefix  , i )
system(temp);
sprintf(temp, "sudo cp %s /home/%s%d", loc, prefix, i );
system(temp);
	}
return 0;
}; 
