#include <stdio.h>
#include <malloc.h>

int main()
{
    char *str;
    char *leftstr,*rightstr;
    int N,i=0,l1,l2,r1,r2;
    str = (char*)malloc(sizeof(char));
    
    scanf("%s",str);
    scanf("%d",&N);
    
    while(i++<N){
    scanf("%d %d",&l1,&l2);
	scanf("%d %d",&r1,&r2);
	if((l2-l1)!=(r2-r1)){
	printf("No");
	break;	
	}
	
	int j=0;
	leftstr = (char*)malloc(sizeof(char));
    rightstr = (char*)malloc(sizeof(char));
	while(j<(l2-l1+1)){
		*(leftstr+j)=*(str+l1+j-1);
		*(rightstr+j)=*(str+r1+j-1);
	//	printf("%d",j);
		j++;
	}
	*(leftstr+j)='\0';
	*(rightstr+j)='\0';
//	printf("%s\n%s\t%s",leftstr,rightstr,str);
	for(j=0;j<(l2-l1+1);j++){
		if(*(leftstr+j)==*(rightstr+j)){
		//	printf("%d",j);
		continue;	
		}
		else
		break;
	}
	
	if(j!=(l2-l1+1))
	printf("No");
	else
	printf("Yes");	
    }
  //  printf("%s",str);
    return 0;
}
