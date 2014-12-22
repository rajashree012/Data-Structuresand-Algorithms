#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NULL 0
struct linkedlist
{
	char n[100];
	struct linkedlist *left;
	struct linkedlist *right;
}; 
typedef struct linkedlist node;
void create(node *head,char x[]);
void insert(node *head,char n[]);
int height(node *head);
void print(node *head);
main()
{
	node *head;
	head=(node *)malloc(sizeof(node));
	char x[100];
	printf("enter the element");
	gets(x);
	strcpy(head->n,x);
	head->left=NULL;
	head->right=NULL;
	create(head,x);
	printf("%d is height of tree",height(head));
	print(head);
}
void create(node *head,char x[])
{
	char m[100];
	printf("enter the element and press -999 at the end");
	gets(m);
	if(strcmp(m,"-999")!=0)
	{		
		insert(head,m);	
		create(head,x);
	}
	else
	return;
}	
void insert(node *head,char m[])
{
	if(strcmp(m,head->n)<0&&head->left==NULL)
	{
		head->left=(node *)malloc(sizeof(node));
		strcpy(head->left->n,m);
		head->left->left=NULL;
		head->left->right=NULL;
		return;
	}
	if(strcmp(m,head->n)>0&&head->right==NULL)
	{
		head->right=(node *)malloc(sizeof(node));
		strcpy(head->right->n,m);
		head->right->left=NULL;
		head->right->right=NULL;
		return;	
	}
	if(strcmp(m,head->n)<0)
	{
		insert(head->left,m);
	}
	else
	{
		insert(head->right,m);
	}
	return;
}
int height(node *head)
{
	int heightsright=-1,heightsleft=-1;
	if(head->left==NULL&&head->right==NULL)
	return(0);
	if(head->left!=NULL)	
	heightsleft=height(head->left);
	if(head->right!=NULL)
	heightsright=height(head->right);	
	if(heightsleft>heightsright)
	return(1+heightsleft);
	else
	return(1+heightsright);
}
void print(node *head)
{
	if(head==NULL)
	{
		return;
	}
	print(head->left);
	printf("%s ",head->n);
	print(head->right);
	return;
}
