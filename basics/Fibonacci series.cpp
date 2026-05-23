#include <stdio.h>
int main()
{
	int a=0,b=1,c,i,num;
	printf("enter no of required series");
	scanf("%d",&num);
	if (num < 0)
	{
		printf("invalid");
	}
	else {
		for (i=0;i<num;i++)
		{
			printf("%d",a);
			c=a+b;
			a=b;
			b=c;
		}
		printf("/nthe required no of series is %d",c);
	}
	return 0;
}
