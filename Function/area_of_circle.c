#include<stdio.h>
int calcarea(int r);
int calccirc(int r);
int main()
{
    int radius,area,circumference;
    printf("enter the radius");
    scanf("%d",&radius);
    area = intcalcarea(radius);
    circumference= intcalcirc(radius);
    return 0;
    
}
int calcarea(int r){
    return(3.14*r*r);
}
int calcirc(int r)
{ 
    return(2*3.14*r);
}