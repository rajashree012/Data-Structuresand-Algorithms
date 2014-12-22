#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NULL 0
struct linkedlist
{
	char n[100];
	char *color;
	struct linkedlist *parent;
	struct linkedlist *left;
	struct linkedlist *right;
}; 
typedef struct linkedlist node;
node *raj;
void create(node *head,char x[],char a[][100],int g);
node* insert(node *head,char m[]);
int height(node *head);
void print(node *head);
node *grandparent(node *n);
node *uncle(node *n);
void insert_case1(node *n);
void insert_case2(node *n);
void insert_case3(node *n);
void insert_case4(node *n);
void insert_case5(node *n);
void rotate_left(node *n);
void rotate_right(node *n);
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
	//head=(node *)malloc(sizeof(node));
	char x[100];
	int b[n];
	int j,k=0;
	for(i=0;i<n;i++)
	{
		b[i]=0;
	}
	int g=0,l=0;
	read:
	k++;
	//raj=head;
	for(i=0;i<n;i++)
	{
		j=rand()%100;
		b[j]++;
		if(b[j]==1)
		{
			head=(node *)malloc(sizeof(node));
			raj=head;
			g++;	
			strcpy(x,a[j]);
			strcpy(head->n,x);
			head->color="BLACK";
			head->parent=NULL;
			head->left=(node *)malloc(sizeof(node));
			head->right=(node *)malloc(sizeof(node));
			head->left->parent=head;
			head->right->parent=head;
			strcpy(head->left->n,"NULL");
			strcpy(head->right->n,"NULL");
			head->left->right=NULL;
			head->left->left=NULL;
			head->right->left=NULL;
			head->right->right=NULL;
			head->left->color="BLACK";
			head->right->color="BLACK";
			create(head,x,a,j);
			printf("%d is height of tree with root as %s %d\n",height(raj),a[j],g);
			//print(head);
		}
	}
	if(k<50)
	goto read;
	for(i=0;i<n;i++)
	{
		if(b[i]==0)
		{
			g++;
			head=(node *)malloc(sizeof(node));
			raj=head;	
			strcpy(x,a[i]);
			strcpy(head->n,x);
			head->color="BLACK";
			head->parent=NULL;
			head->left=(node *)malloc(sizeof(node));
			head->right=(node *)malloc(sizeof(node));
			head->left->parent=head;
			head->right->parent=head;
			strcpy(head->left->n,"NULL");
			strcpy(head->right->n,"NULL");
			head->left->right=NULL;
			head->left->left=NULL;
			head->right->left=NULL;
			head->right->right=NULL;
			head->left->color="BLACK";
			head->right->color="BLACK";
			create(head,x,a,i);
			printf("%d is height of tree with root as %s %d\n",height(raj),a[i],g);
			//print(head);
		}
	}
}
void create(node *head,char x[],char a[][100],int z)
{
	int i,j,k=0;
	node *temp;
	int b[n];	
	for(i=0;i<n;i++)
	{
		b[i]=0;
	}
	b[z]=1;
	int g=0,l=0;
	read:
	k++;
	for(i=0;i<n;i++)
	{
		j=rand()%100;
		b[j]++;
		if(b[j]==1)
		{
			temp=insert(raj,a[j]);
			temp->color="RED";
			temp->left=(node *)malloc(sizeof(node));
			temp->right=(node *)malloc(sizeof(node));
			temp->left->parent=temp;
			temp->right->parent=temp;
			strcpy(temp->left->n,"NULL");
			strcpy(temp->right->n,"NULL");
			temp->left->right=NULL;
			temp->left->left=NULL;
			temp->right->left=NULL;
			temp->right->right=NULL;
			temp->left->color="BLACK";
			temp->right->color="BLACK";
			insert_case1(temp);
		}
	}
	if(k<50)
	goto read;
	for(i=0;i<100;i++)
	{
		if(b[i]==0)
		{
			temp=insert(raj,a[j]);
			temp->color="RED";
			temp->left=(node *)malloc(sizeof(node));
			temp->right=(node *)malloc(sizeof(node));
			temp->left->parent=temp;
			temp->right->parent=temp;
			strcpy(temp->left->n,"NULL");
			strcpy(temp->right->n,"NULL");
			temp->left->right=NULL;
			temp->left->left=NULL;
			temp->right->left=NULL;
			temp->right->right=NULL;
			temp->left->color="BLACK";
			temp->right->color="BLACK";
			insert_case1(temp);
		}
	}	
	return;
}	
node *insert(node *head,char m[])
{
	if(strcmp(m,head->n)<0&&strcmp(head->left->n,"NULL")==0)
	{
		strcpy(head->left->n,m);
		return(head->left);
	}
	if(strcmp(m,head->n)>0&&strcmp(head->right->n,"NULL")==0)
	{
		strcpy(head->right->n,m);
		return(head->right);	
	}
	if(strcmp(m,head->n)<0)
	{
		return(insert(head->left,m));
	}
	else
	{
		return(insert(head->right,m));
	}
}
int height(node *head)
{
	int heightsright=-1,heightsleft=-1;
	if(strcmp(head->left->n,"NULL")==0&&strcmp(head->right->n,"NULL")==0)
	return(0);
	if(strcmp(head->left->n,"NULL")!=0)	
	heightsleft=height(head->left);
	if(strcmp(head->right->n,"NULL")!=0)
	heightsright=height(head->right);	
	if(heightsleft>heightsright)
	return(1+heightsleft);
	else
	return(1+heightsright);
}
void print(node *head)
{
	if(strcmp(head->n,"NULL")==0)
	{
		return;
	}
	print(head->left);
	printf("%s ",head->n);
	print(head->right);
	return;
}
node *grandparent(node *n)
{
        if ((n != NULL) && (n->parent != NULL))
        return (n->parent->parent);
        else
        return NULL;
}
node *uncle(node *n)
{
        node *g = grandparent(n);
        if (g == NULL)
        return NULL; 
	if (n->parent == g->left)
        return (g->right);
        else
        return (g->left);
}
void insert_case1(node *n)
{
        if (n->parent == NULL)
        n->color = "BLACK";
        else
        insert_case2(n);
	return;
}
void insert_case2(node *n)
{
        if (n->parent->color == "BLACK")
        return;
        else
        insert_case3(n);
	return;
}
void insert_case3(node *n)
{
        node *u = uncle(n), *g;
 	if ((u != NULL) && (u->color == "RED")) 
	{
        	n->parent->color = "BLACK";
                u->color = "BLACK";
                g = grandparent(n);
                g->color = "RED";
                insert_case1(g);
        }
	else 
	{	 
               insert_case4(n);
		//printf("######");
        }
	return;
}
void insert_case4(node *n)
{
        node *g = grandparent(n);
 	if ((n == n->parent->right) && (n->parent == g->left)) 
	{
                rotate_left(n->parent);
                n = n->left;
        } 
	else if ((n == n->parent->left) && (n->parent == g->right)) 
	{
                rotate_right(n->parent);
                n = n->right;
        }
	insert_case5(n);
	return;
}
void insert_case5(node *n)
{
        node *g = grandparent(n);
 	n->parent->color = "BLACK";
        g->color = "RED";
        if ((n == n->parent->left) && (n->parent == g->left)) 
	{
                rotate_right(g);
        }
	if ((n == n->parent->right) && (n->parent == g->right)) 
	{             
		rotate_left(g);
		//printf("^^%d^^%d^^%d^^",n->parent->n,n->n,n->parent->left->n);
        }
	return;
}
void rotate_right(node *n)
{
	node *temp;
	temp=n->left->right;
	n->left->parent=n->parent;
	n->left->right=n;
	if(n->parent==NULL)
	raj=n->left;
	if(n->parent!=NULL)
	{ 
		if(n->parent->right==n)
		n->parent->right=n->left;
		else
		n->parent->left=n->left;
	}
	temp->parent=n;
	n->parent=n->left;
	n->left=temp;
	return;
}	
void rotate_left(node *n)
{
	node *temp;
	temp=n->right->left;
	n->right->parent=n->parent;
	n->right->left=n;
	if(n->parent==NULL)
	raj=n->right;
	if(n->parent!=NULL)
	{ 
		if(n->parent->left==n)
		n->parent->left=n->right;
		else
		n->parent->right=n->right;
	}
	temp->parent=n;
	n->parent=n->right;
	n->right=temp;
	return;
}
