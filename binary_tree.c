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
void create(node *head,char x[],char a[][100],int j);
void insert(node *head,char n[]);
int height(node *head);
void print(node *head);
int n;
main()
{
	int i;
	node *head;
	printf("enter the number of strings");
        scanf("%d",&n);
	char a[n][100];
        FILE *f1;
        f1=fopen("DsaNames.txt","r");	
        for(i=0;i<n;i++)
        fgets(a[i],50,f1);
        fclose(f1);	
	head=(node *)malloc(sizeof(node));
	char x[100];
	int b[n];
	int j,k=0;
	for(i=0;i<n;i++)
	{
		b[i]=0;
	}
	int g=0,l=0;
	read:
	for(i=0;i<n;i++)
	{
		j=rand()%100;
		b[j]++;
		if(b[j]==1)
		{
			g++;	
			strcpy(x,a[j]);
			strcpy(head->n,x);
			head->left=NULL;
			head->right=NULL;
			create(head,x,a,j);
			printf("%d is height of tree with root as %s %d\n",height(head),a[j],g);
			//print(head);
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		if(b[i]==0)
		{
			k++;			
		}
	}
	if(k>5)
	goto read;
	for(i=0;i<n;i++)
	{
		if(b[i]==0)
		{
			g++;	
			strcpy(x,a[i]);
			strcpy(head->n,x);
			head->left=NULL;
			head->right=NULL;
			create(head,x,a,i);
			printf("%d is height of tree with root as %s %d\n",height(head),a[i],g);
			//print(head);
		}
	}
}
void create(node *head,char x[],char a[][100],int z)
{
	int i,j,k;
	int b[n];	
	for(i=0;i<n;i++)
	{
		b[i]=0;
	}
	b[z]=1;
	int g=0,l=0;
	read:
	for(i=0;i<n;i++)
	{
		j=rand()%100;
		b[j]++;
		if(b[j]==1)
		{
			insert(head,a[j]);
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		if(b[i]==0)
		{
			k++;			
		}
	}
	if(k>5)
	goto read;
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
