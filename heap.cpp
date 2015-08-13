#include <iostream.h>
long int *arr = new long int[1000000];

void swap(long int *x,long int *y)
{
long int temp;
temp=*x;
*x = *y;
*y = temp;
}

void heapsort(long int a[],long int n)
{
long int i,s,f;
for(i=1;i< n;++i)
{
s=i;
f=(s-1)/2;
while( arr[f]< arr[s])
{
swap(&arr[f],&arr[s]);
s=f;
if(s==0)
break;
f=(s-1)/2;
}
}
for(i=n-1;i>=1;--i)
{
swap(&arr[0],&arr[i]);
f=0;
s=1;
if(i==1)
break;
if(i>2)if(arr[2]>arr[1])s=2;
while( arr[f]< arr[s] )
{ 
swap(&arr[f],&arr[s]);
f=s;
s=2*f+1;
if(i>s+1 )if(arr[s+1]>arr[s])s=s+1;
if (s>=i)
break;
}
}
}

int main()
{
    long int i,k,o=0;
    float t[100];
    time_t s,f;
    for(i=10000;i<100000;i+=10000)
    {
         for(k=0;k<i;k++)
         arr[k]=rand();
         s=clock();
         heapsort(arr,i);
         f=clock();
         t[o++]=((double)(f-s))/CLOCKS_PER_SEC;
    }
    cout<<"x=[\t";
    for(i=10000;i<300000;i+=10000)
    cout<<i<<"\t";
    
    cout<<"];\ny=[\t";
    for(i=0;i<29;i++)
        cout<<t[i]<<"\t";
    cout<<"];\nplot(x,y)";
    
    delete[] arr;
    getchar();
}
