#include <stdio.h>
int main  ()
{
	int side_1,side_2,side_3;
	printf("Enter the  first side");
	scanf("%d",&side_1);
	printf("Enter the second side");
	scanf("%d",&side_2);
	printf("Enter the third side");
	scanf("%d",&side_3);
    if(side_1 + side_2 > side_3 &&
        side_1 + side_3 > side_2 &&
        side_2 + side_3 > side_1)
        {
        printf("The triangle exist");	
		}
        
    else
 {
 	printf("The triangle doesnt exist");
 }
	return 0;
}
