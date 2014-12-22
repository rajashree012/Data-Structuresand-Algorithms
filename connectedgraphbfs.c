#include<stdio.h>
main()
{	
	int i,j,x;	
	int wt[9][9];
	FILE *fp;
	fp=fopen("raj.txt","r");
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			fscanf(fp,"%d",&wt[i][j]);
		}
	}
	int a[9];
	for(i=0;i<9;i++)
	{
		a[i]=0;
	}
	printf("enter the node from which the connected has to be seen");
	scanf("%d",&x);
	a[x-1]=1;
	for(i=x-1;i<9;i++)
	{	
		for(j=0;j<9;j++)
		{
			if(wt[i][j]!=0&&a[i]!=1)
			a[j]=1;
		}
	}
	for(i=x-2;i>=0;i--)
	{	
		for(j=0;j<9;j++)
		{
			if(wt[i][j]!=0&&a[i]!=1)
			a[j]=1;
		}
	}
	printf("the vertices which are not connected to the are:");
	for(i=0;i<9;i++)
	{
		if(a[i]==0)		
		printf(" %d ",a[i]);
	}
}
