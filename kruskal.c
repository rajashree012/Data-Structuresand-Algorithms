#include<stdio.h>
#define MAX 50
#define INFINITY 4000
void inputgraph(int);
void makeset(int);
void findmin(int);
int findset(int);
void unionset(int,int);
int wt[MAX][MAX];
int edge[MAX][MAX];
int edge1,edge2;
int c = INFINITY;
int mstree[ 2*MAX];
int n;
int set[MAX];
int flag;
int tedge = 0;
main()
{
	int i,j;
	int k=0;
	FILE *f;
	f=fopen("kruskals.txt", "r");
	fscanf(f,"%d",&n);
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			fscanf(f, "%d", &wt[i][j]);
			if(wt[i][j] == 0)
			{
				edge[i][j] = 0;
				edge[j][i] = 0;
			}
			if(wt[i][j] != 0)
			{
				edge[i][j] = 1;
				edge[j][i] = 1;
				tedge = tedge + 2;
			}
		}		
	}
	fclose(f);
	makeset(n);
	for(i = 1;i<=tedge/4;i++)
	{
		findmin(n);
		//printf(" ^^%d %d**",edge1,edge2);
		if(findset(edge1) != findset(edge2))
		{
			mstree[k++] = edge1;
			mstree[k++] = edge2;
			edge[edge1][edge2] = 0;
			unionset(edge1,edge2);
		}
	}
	k=0;
	flag = 1;
	for(i = 0;i<n;i++)
	{
		printf("Edge no. %d of minimum spanning tree hv vertices %d and %d \n",flag,mstree[k]+1,mstree[k+1]+1);
		flag++;
		k = k+2;
	}
}
void makeset(int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		set[i] = i+1;
	}
}
void findmin(int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(edge[i][j] == 1)
			{
				if(wt[i][j] <= c)
				{
					c = wt[i][j];
					edge1 = i;
					edge2 = j;
				}
			}
		}
	}
	edge[edge1][edge2]= 0;
	c = INFINITY;
}
int findset( int a)
{
	return set[a];
}
void unionset(int a,int b)
{
	int z,i;
	int temp;
	temp = set[b];
	set[b] = set[a];
	for(z = 0;z<n;z++)
	{
		if(set[z] == temp)
		{
		set[z] = set[a];
		}	
	}
	//for(i=0;i<n;i++)
	//printf(" %d ",set[i]);
	//printf("\n");
}

