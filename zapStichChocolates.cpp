#include<stdio.h>
int main(){
	int i,n,a[100],b[100],max=0,big=0,ind;
	scanf("%d",&n);
	i=0;
	while(i<n){
		scanf("%d",&a[i]);
		b[i]=a[i]+n-i;
	if(b[i]>=max){
		max=b[i];
		ind = i;
	}	
		i++;
	}
	
	for(i=0;i<n;i++){
	if(a[i]>a[ind]){
		big +=1; 	
		}
	}
	i=n-ind-1-big;
	printf("%d",i);
return 0;	
}
