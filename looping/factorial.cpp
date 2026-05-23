#include <stdio.h>
int main()
{
	int i,num,fact=1;
	printf("enter a positive number:");
	scanf("%d",&num);
	if (num <0)
	{
		printf("The factorial of negative number doesnt exist");
		
		
	}
	
	else if (num==0 || num==1)
	{
		printf("The factorial of %d is 1",num);
	}
	else
	{
		for (i=1;i<=num;i++)
		{
			fact=fact*i;
		}
		printf("The factorial of %d is %d",num,fact);
	}
	return 0;
}
