#include <stdio.h>
int main()
{
	int num, reversed =0,remainder;
	printf("Enter a number:");
	scanf("%d",&num);
	while (num != 0)
	{
		remainder = num%10; // get the last digit of a number
		reversed = reversed * 10 + remainder ;
		num = num/10; // to remove the last digit
	}
	printf("Reversed number: %d\n", reversed);
	return 0;
}
