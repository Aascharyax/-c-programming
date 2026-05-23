// To determine the biggest number among three numbers
#include <stdio.h>
int main()
{
	int a,b,c;
	printf("Enter the first number\n");
	scanf("%d",&a);
	printf("enter the second number\n");
	scanf("%d",&b);
	printf("Enter the third number\n");
	scanf("%d",&c);
	if (a>b && a>c)
	{
		printf("%d is the greatest number",a);
	}
	else if( b>a && b>c)
	{
		printf("%d is the greatest number",b);
		
	}
	else
	{
		printf("%d is the greatest number",c);
	}
	
	
	
	
}
