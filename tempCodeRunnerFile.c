#include<stdio.h>
int find_greatest(int a ,int b, int c); // function declare
int main()
{
   int num1,num2,num3;
   printf("enter three number");
   scanf("%d%d%d",&num1,&num2,&num3);
   int greatest= int find_greatest(num 1, num2, num3);
   printf("The greatest number is %d",greatest)
}
int find_greatest(int a ,int b ,int c)
{
    if (a>b && a>c){
        return a;
    }

    if (b>a && b>c){
        return b;
    }
    if (c>b && c>a){
        return c;
    }
}