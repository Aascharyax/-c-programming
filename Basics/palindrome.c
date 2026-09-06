#include <stdio.h>
int main()
{
    int n,s=0,r,x;
    printf("enter the number");
    scanf("%d",&n);
     x=n;
    while(n!=0){
        
        r=n%10;
        n=n/10;
        s=s*10+r;
    }
    
    if (x==s)
    {
        printf("true");
    }
    else{
        printf("false");
    }
return 0;    
}