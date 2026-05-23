#include <string.h>
#include <stdio.h>
int main()
{
	char s[15];
	printf("enter a string:");
	scanf("%s",s);
	strlwr(s);
	printf("%s",s);
	return 0;
}
