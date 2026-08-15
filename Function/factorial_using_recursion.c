#include <stdio.h>
int factorial(int n);
int main()

{
  int num;
  printf("enter the number");
  scanf("%d",&num);
  if (num < 0)
  {
    printf("invalid number");
  }
  else
  {
    int result= factorial(num);
    printf("The factorial of %d is %d",num,result);
  }
  return 0;

}
int factorial(int n){

    if (n==0 || n==1)
    return n;

    else{
        return n*factorial(n-1);
    }
}