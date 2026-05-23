// write a c program to display the given pattern
*
**
***
****
*****
//
#include <stdio.h>
int main()
{
	for (i=1;i<=5;i++)
	{
		for (j=1;j<=1;j++)
		{
			printf("*\t",j++);
		}
		printf("\n";)
	}
	return 0;
}
