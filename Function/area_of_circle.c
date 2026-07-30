#include <stdio.h>
int calculatearea(int r);
int calculatecircum(int r);
int main()
{
    int radius,circumference,area;
    printf("enter the radius:");
    scanf("%d",&radius);
    area=calculatearea(radius);
    circumference=calculatecircum(radius);
    printf("The area of circle is %d",area);
    printf("the circ of a circle %d",circumference);
    return 0;
}
int calculatearea(int r)
{
    return(3.14159*r*r);
}
int calculatecircum(int r)
{
    return(2*3.14159*r);
}