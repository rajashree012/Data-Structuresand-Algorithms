/*Write a program to print the elements in reverse order of single linked list from a specific location.*/
#include<stdio.h>
#include<stdlib.h>
#define NULL 0
struct linked_list
{
	int number;
	struct linked_list*next;
};
typedef struct linked_list node;
main()
{
	node *head;
	node *result;
	int n;
	void create(node *p);
	int count(node *p);
	node *reverse (node *p,int n);
	void print(node *p);
	head=(node *)malloc(sizeof(node));
	create(head);
	n=count(head);
	result=reverse(head,n);
	print(result);
}
void create(node *list)
{
	printf("input nubers and press -999 at the end");
	scanf("%d",&list->number);
	if(list->number==-999)
	{
		list->next=NULL;
	}
	else
	{
		list->next=(node *)malloc(sizeof(node));
		create(list->next);
	}
	return;
}
int count(node *list)
{
	if(list->next==NULL)
	return(0);
	else
	return(1+count(list->next));
}
node *reverse(node *base,int n)
{
	int x,i;
	node *y=base;
	node *next;
	node *current;
	current=base;
	node *result;
	printf("enter the location from where you want the reverse order");
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		y=y->next;
	}
	result=y;
	while(current!=y)
	{
		next=current->next;
		current->next=result;
		result=current;
		current=next;
	}
	return(result);
}
void print(node *list)
{
	if(list->next!=NULL)
	{
		printf("%d ",list->number);
		print(list->next);
	}
	return;
}
