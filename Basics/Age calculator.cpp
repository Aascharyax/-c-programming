#include <stdio.h>
int main()
{
	int birth_year,current_year,Age;
	printf("Enter your Birth year");
	scanf ("%d",&birth_year);
	printf("Enter the current year");
	scanf("%d",&current_year);
	Age = current_year - birth_year;
	if (Age < 0)
	printf("Invalid input! Birth year cannot be greater than current year");
	else
	printf("Your Age is %d",Age);
	return 0;

}
