#include<stdio.h>
#define cube(x) (x*x*x)
int main()
{
	int a,b=3;
	a=cube(b++);
	printf("\n%d\t%d",a,b);
	return 0;
}