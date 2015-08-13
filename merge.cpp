#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);

int main()
	{
   
    int merge[100000],i,n=100,N=1000,nc,x[100000],y[100000],k1=0;
    clock_t start,end;
    nc=N;
while(N)
{
    n=n+10;
    for(i=0;i<n;i++)

        merge[i]=rand();

start=clock();
    partition(merge,0,n-1);
	

end=clock();
fflush(stdin);
y[k1]=n;
   		
   		x[k1]=end;
     	k1++;
         N--;
    
}

 printf("y=[");
	 for(i=0;i<nc;i++)
 	printf("%d\t",y[i]);

      printf("];\nx=[");
      for(i=0;i<nc;i++)
	  printf("%d\t",x[i]);
	  printf("];\nplot(y,x);");
 

   return 0;
}

void partition(int arr[],int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l,temp[100000];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}
