#include <stdio.h>
int calculate_greatest(a,b,c);
int main()
{
    int num1,num2,num3;
    printf("enter the number");
    scanf("%d%d%d",&num1,&num2,&num3);
    int greatest = calculate_greatest(num1,num2,num3);
    return 0;
}
int calculate_greatest(a,b,c){
    if(a>b && a>c)
    {
        return a;
    }
    if(b>a && b>c)
    {
        return b;
    }
    if(c>a&& c>b)
    {
        return c;
    }
}