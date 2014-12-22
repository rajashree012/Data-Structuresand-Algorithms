// Construction of Binary Search tree where the nodes data types is integers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NULL 0
struct linkedlist
{
	int n;
	struct linkedlist *left;
	struct linkedlist *right;
}; 
typedef struct linkedlist node;
void create(node *head,int x);
void insert(node *head,int n);
int height(node *head);
void print(node *head);
main()
{
	node *head;
	head=(node *)malloc(sizeof(node));
	int x;
	printf("enter the element");
	scanf("%d",&x);
	head->n=x;
	head->left=NULL;
	head->right=NULL;
	create(head,x);
	printf("%d is height of tree",height(head));
	print(head);
}

// create function creates a tree with a root node(head)
void create(node *head,int x)
{
	int m;
	printf("enter the element and press -999 at the end");
	scanf("%d",&m);
	if(m!=-999)
	{		
		insert(head,m);	
		create(head,x);
	}
	else
	return;
}

// insert function inserts a node in already formed binary search tree	
void insert(node *head,int m)
{
	if(m<head->n&&head->left==NULL)
	{
		head->left=(node *)malloc(sizeof(node));
		head->left->n=m;
		head->left->left=NULL;
		head->left->right=NULL;
		return;
	}
	if(m>head->n&&head->right==NULL)
	{
		head->right=(node *)malloc(sizeof(node));
		head->right->n=m;
		head->right->left=NULL;
		head->right->right=NULL;
		return;	
	}
	if(m<head->n)
	{
		insert(head->left,m);
	}
	else
	{
		insert(head->right,m);
	}
	return;
}

// calculates height of tree
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

// prints the node of the tree in inorder traversal
void print(node *head)
{
	if(head==NULL)
	{
		return;
	}
	print(head->left);
	printf("%d ",head->n);
	print(head->right);
	return;
}

	
