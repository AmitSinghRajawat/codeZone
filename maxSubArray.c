#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int T,N,max[100][100],a[100][100],val[100],i,j,l,k,b;
    scanf("%d",&T);
    while(T--)
        {
        scanf("%d",&N);
        k=0;
        b=0;
        while(k<N)
            {
            scanf("%d",&val[k++]);
            }
        
        
            
        
            for(i=0;i<N;i++)
	          { max[i][i]=val[i];
               a[i][i]=val[i];
              }
	        for(l=0;l<N;l++)
	           {
		          for(i=0;i<N-l-1;i++)
		              {
		                j=i+l+1;
		                a[i][j]=a[i][j-1]+val[j];
		                  if(a[i][j]>max[i][j-1])
		                      max[i][j]=a[i][j];
		
		                  else
		                      max[i][j]=max[i][j-1];
		              }
	              }
	           printf("%d ",max[0][N-1]);
        
        for(i=0;i<N;i++)
            {
            if(val[i]>0)
                b+=val[i];
        }
        printf("%d",b);
	       
            
            
        }
    
    return 0;
}
