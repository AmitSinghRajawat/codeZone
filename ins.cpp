#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int main(){

  int i,j,s=0,temp,a[100000],N=1000,n,y[100000],k=0;
  int x[100000];
  clock_t start,end;
    n=N;
    while(N)
    {
     fflush(stdin);
  s=s+10;
  
  for(i=0;i<s;i++)
     a[i]=rand();

 start=clock();
  for(i=1;i<s;i++){
      temp=a[i];
      j=i-1;
      while((temp<a[j])&&(j>=0)){
      a[j+1]=a[j];
          j=j-1;
      }
      a[j+1]=temp;
  }
     end=clock();
  
   		y[k]=s;

   		x[k]=end-start;
     	k++;

	  N--;	
    }
     printf("y=[");
	 for(i=0;i<n;i++)
 	printf("%d\t",y[i]);

      printf("];\nx=[");
      for(i=0;i<n;i++)
	  printf("%d\t",x[i]);
	  printf("];\nplot(y,x);");
 

  return 0;
}