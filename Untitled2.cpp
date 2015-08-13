#include<stdio.h>
int main()
{
 int i,j;
while(1)
{
printf("\nenter number:");
scanf("%d",i);
j=2;
j=i&j;
printf("\nvalue\t%d",j);
/*printf("\nnumber is multiple of 2");
else
printf("\nnumber is not a multiple of 2 %d",~i);  */
printf("\n");	
}

return 0;
}