// wap to swap variables in c using pointer
#include <stdio.h>
int swap(int *a,int*b);
int main()
{
    int x,y;
    printf("enter the numbers\n");
    scanf("%d%d",&x,&y);
    printf("The number before swap is %d and %d\n",x,y);
    swap(&x,&y);
    int result = swap(&x,&y);
    printf("after swap x is %d and y is %d \n",x,y);
    return 0;
}

int swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    printf("during swap x is %d and y is %d\n",*a,*b);
   return 0;
}