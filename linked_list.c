//program template for linked list implementation......just copy and paste it....and produce the rest
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node* NODE;

NODE getnode()
{
  struct node *temp;
  temp=(NODE)malloc(sizeof(struct node));
  if(temp==NULL)
  	printf("\nMemory not available");
  
  else
  
  return temp;
}


int main()
{
struct node *head,*start;
int key;
start=getnode();
head=getnode();
start->next=head;


printf("\nEnter the element");
scanf("%d",&key);
head->data=key;
printf("Value%d",head->data);
head->next=getnode();
head=head->next;
printf("\nEnter the element2");
scanf("%d",&key);
head->data=key;
head->next=NULL;
head=start->next;
while(head!=NULL)
{
printf("\nValues are %d",head->data);
head=head->next;	
}
 
 
return 0;

}