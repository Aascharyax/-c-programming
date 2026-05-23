include <stdio.h>
int main()
{
	int age [5],i,count=0;
	printf("enter the age for 5 students:\n");
	for (i-0;i<5;i++)
	{
		printf("enter the age for student %d:",i+1);
		scanf("%d",&age [i]);
		
	}
	
	for (i=0;i<5;i++)
	{
		if (age [i]>=15&&age[i]<=20)
		{
			count ++;
		}
		printf("\nthe number of student between age 15 to 20 is %d",count);
	}
	return 0;
