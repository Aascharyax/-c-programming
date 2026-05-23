#include <stdio.h>
int main()
{
	int age[50],i,count=0;
	printf("enter age for 50 students:\n");
	for (i=1;i<5;i++)
	{
		printf("enter age of student  %d",i+1);
		scanf("%d",&age[i]);
	}
	for (i=1;i<5;i++)
	{
		if (age[i]>=15 && age[i] <= 20)
		{
			count ++;
		}
	}
	printf("the no of student between age 15 and 20 is %d",count);
	return 0;
}
