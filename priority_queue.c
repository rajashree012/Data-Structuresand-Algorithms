/*implement priority queue using linked lists*/
#include<stdio.h>
#include<stdlib.h>
# define NULL 0
struct linked_list
{
	int info;
	int priority;
	struct linked_list *next;
}*front=NULL;
void insert();
void delete();
void print();
int size();
typedef struct linked_list node;
main()
{
	int i,j,k;
	printf("enter the number of times you want to do operations");
	scanf("%d",&j);
	for(k=0;k<j;k++)
	{
		printf("\n enter your option \n1.inserting into priority queue\n2.removing an element from priority queue\n3.printing the elements\n4.size of queue");
	scanf("%d",&i);		
		switch(i)
		{
			case 1:insert();
			       break;
			case 2:delete();
			       break;
			case 3:print();
			       break;
			case 4:printf("%d is size",size());
			       break;
			default:printf("invalid option");
		}
	}
}
void insert()
{
	int number,priority_num;
	node *temp,*temp1;
	node *temp2=(node *)malloc(sizeof(node));
	printf("enter the number and its priority");
	scanf("%d %d",&number,&priority_num);
	if(front==NULL||priority_num<front->priority)
	{
		temp2->info=number;
		temp2->priority=priority_num;
		temp2->next=front;
		front=temp2;
	}
	else
	{
		temp=front;		
		while(temp!=NULL)
		{
			if(temp->priority>=priority_num)
			break;
			temp1=temp;
			temp=temp->next;
		}
		temp1->next=temp2;
		temp2->info=number;
		temp2->priority=priority_num;
		temp2->next=temp;
	}
	return;
}
void delete()
{
	if(front==NULL)
	{
		printf("queue is empty");
		return;
	}	
	else
	{
	   printf("%d is the element",front->info);
	   front=front->next;
    }
	return;
}
void print()
{
	node *temp=front;	
	if(front==NULL)
	{
		printf("queue is empty");
		return;
	}
	else
	{
		printf("priority queue is:\n");
		while(temp!=NULL)
		{		
			printf("number=%d,priority=%d\n",temp->info,temp->priority);			
			temp=temp->next;
		}
	}
	return;
}	
int size()
{
	int count=0;
	node *temp=front;	
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return(count);
}			

