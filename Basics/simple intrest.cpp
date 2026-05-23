#include <stdio.h>
int main ()
{
	int p,r,t,si;
	printf("Enter the principal time and rate\n");
	scanf("%d%d%d",&p,&r,&t);
	si = (p*t*r)/100;
	printf("the simple intrest is %d",si);
	return 0;
}
