#include <stdio.h>
int fact(int n);
int main()
{
	int num;
	printf("enter the number");
	scanf("%d",&num);
	if(num<0){
        printf("enter the postitve number");
	int result = fact(num);
	printf("The factorial of %d is %d",num,result);
	return 0;
	}
}

int fact(int n)
{
  if(n==1 || n==0)
	  return 1;
  else
  {
	  return n*fact(n-1);
  };
}
