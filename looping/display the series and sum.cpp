// c program to display the series 1,2......100 using for loop and their sum//
#include <stdio.h>
int main()
{
	int i,sum=0;
	printf("The required series from 1 to 100 is :");
	for (i=1;i<=100;i++)
	{
		printf("%d\t",i);
		sum = sum+i;
	}
	printf("\nthe sum of the series is %d",sum);
	return 0;
}
