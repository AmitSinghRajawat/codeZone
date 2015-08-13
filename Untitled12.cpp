#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int caltemp(int a[],int n){
    int temp=a[0];
    for(int i=0;i<n;i++){
        if(a[i] > temp)
            temp = a[i] + 1;
    }
    
    return(temp);
}
    void countsort(int a[],int n,int temp,int c[]){
    for(int i=0;i<temp;i++)
        c[i] = 0;
    
    for(int i=0;i<n;i++)
        c[a[i]] = c[a[i]] + 1; 
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,m,i,tempa;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    int b[m];
    for(i=0;i<m;i++)
        scanf("%d",&b[i]);
    
    tempa = caltemp(a,n);
    int ca[tempa];
    countsort(a,n,tempa,ca);
    
    int cb[tempa];
    countsort(b,m,tempa,cb);
    
   
    int ans[tempa];
    for(i=0;i<tempa;i++)
        ans[i] = 0;
    
    if(m != n){
           for(i=0;i<m;i++){
               if(ca[b[i]] != cb[b[i]])
                   ans[b[i]] = b[i];
                   ca[b[i]] = 0;
                   cb[b[i]] = 0;
           }
        
        for(i=0;i<tempa;i++){
            if(ans[i] != 0)
                printf("%d ",ans[i]);
        }
   }
     
    return 0;
}
