#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

void quicksort(int [100000],int,int);

int main(){
	int i,j,s=0,temp,a[100000],N=50,n,y[100000],k=0;
  int x[100000];
  clock_t start,end;
    n=N;
  
 while(N)
 {
 s=s+2000;

  for(i=0;i<s;i++)
    a[i]=rand()%10000;
start=clock();
  quicksort(a,0,s-1);
  end=clock();
  x[k]=end-start;
  y[k]=s;
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

void quicksort(int a[100000],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(a[i]<=a[pivot]&&i<last)
                 i++;
             while(a[j]>a[pivot])
                 j--;
             if(i<j){
                 temp=a[i];
                  a[i]=a[j];
                  a[j]=temp;
             }
         }

         temp=a[pivot];
         a[pivot]=a[j];
         a[j]=temp;
         quicksort(a,first,j-1);
         quicksort(a,j+1,last);

    }
}