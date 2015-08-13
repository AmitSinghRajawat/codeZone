#include<stdio.h>
void kcall(int *);
int main()
{
	int A[]={
		4,0
	};
	kcall(A);
	printf("\t%d\t%d",A[0],A[1]);
	return 0;
}

void kcall(int *A)
{
A[1]=A[0];	
A[0]=10;

//printf("aaa\byr");
return;
}