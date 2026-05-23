#include <stdio.h>
#include <string.h>
int main()
{
	char s[15];
	printf("enter a string:");
	scanf("%s",s);
	strupr(s);
	printf("%s",s);
	return 0;
}
