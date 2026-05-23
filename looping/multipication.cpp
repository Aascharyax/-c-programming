#include <stdio.h>
int main()
{
	int i,num;
	printf ("Enter a positive number");
	scanf("%d",&num);
	if (num>0)
	{
		for (i=1;i<=10;i++)
		{
	printf("%d x %d = %d\n", num, i, num * i);
		}
	}
	else
	{
		printf("inavlid number");
	}
	return 0;
}
