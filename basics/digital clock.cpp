#include <stdio.h>
int main()
{
	int h=0,m=0,s=0,i;
	clrscr()
	printf("Please enter the time formate in HH:MM:SS\n");
	scanf("%d%d%d",&h,&m,&s);
	for (h;h<24;h++)
	{
		for (m;m<60;m++)
		{
			for ( s;s<60;s++)
			printf("%d:%d:%d",h,m,s);
			if (h<12)
			printf("AM")
			else
			printf("PM")
		}
	}
}
