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
	int n,m;
	void create(node *p);
	int count(node *p);
	void print(node *p,int m);
	head=(node *)malloc(sizeof(node));
	create(head);
	n=count(head);
	printf("enter the position from where you want the reverse order and the position should be less than %d",n);
	scanf("%d",&m);
	print(head,m);
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
void print(node *list,int m)
{
	static int x=1;
	if(x==m)
	{
		printf("%d ",list->number);
		return;
	}
	else
	{
		x++;
		print(list->next,m);
	}
	printf("%d ",list->number);
	return;
}
	
