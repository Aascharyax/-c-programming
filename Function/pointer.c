#include <stdio.h>
int swap(int *a,int *b);
int main()
{
    int x ,y;
    printf("enter two number");
    scanf("%d%d",&x,&y);
    printf("before function call x = %d and y=%d\n",x,y);
    swap(&x,&y);
    printf("after function call x is %d and y is %d\n",x,y);
    return 0;

}

int swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b= temp;

    printf("During swap x is %d and y is %d\n",*a,*b);
}

