#include<stdio.h>
main()
{	
	int i,j,x,k=0,l=0;	
	int wt[9][9];
	FILE *fp;
	fp=fopen("raj.txt","r");
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			fscanf(fp,"%d",&wt[i][j]);
			//printf(" %d ",wt[i][j]);
		}
	}
	int a[9];
	int b[9];
	int c[9];
	for(i=0;i<9;i++)
	{
		a[i]=0;
	}
	printf("enter the node from which the connected has to be seen");
	scanf("%d",&x);
	a[x-1]=1;
	b[0]=x-1;
	k++;
	for(j=0;j<9;j++)
	{	
		l=0;		
		while(k>0)
		{
			for(i=0;i<9;i++)
			{
				if(wt[b[k-1]][i]!=0&&a[i]==0)
				{
					a[i]=1;
					//printf(" %d ",i);
					c[l]=i;
					l++;
				}
			}
			k--;
		}
		k=l;
		l=0;
		for(i=0;i<9;i++,l++)
		b[i]=c[l];
	}
	printf("the vertices which are not connected to the are:");
	for(i=0;i<9;i++)
	{
		if(a[i]==0)		
		printf(" %d ",i+1);
	}
}
