#include<stdio.h>
int area(int,int);
int main()
{
    int l,b,a;
    printf("enter l and b");
    scanf("%d%d",&l,&b);
    a=area(l,b); // function call 
    printf("The area of recatangle is %d unit square",a);
    return 0;
}
int area(int l, int b)
{
    int area;
    area = l*b;
    return area;
}