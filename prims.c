#include<stdio.h>
int n; 
int weight[100][100]; 
char inTree[100];
int d[100];
int whoTo[100];
void updateDistances(int target)
{
	int i;
	for (i = 0; i < n; ++i)
	{ 		
		if ((weight[target][i] != 0) && (d[i] > weight[target][i])) 
		{
			d[i] = weight[target][i];
			whoTo[i] = target;
		}
	}
}
main() 
{
	FILE *f = fopen("dist.txt", "r");
	int i,j,total,treeSize;
	fscanf(f, "%d", &n);
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			fscanf(f, "%d", &weight[i][j]);
		}
	}
	fclose(f);
	for (i = 0; i < n; ++i)
		d[i] = 100000;
	for (i = 0; i < n; ++i)
		inTree[i] = 0;
	//printf("Adding node %c\n", 0 + 'A');
	inTree[0] = 1;
	updateDistances(0);
	total = 0;
	for (treeSize = 1; treeSize < n; ++treeSize) 
	{
		int min = -1;
		for (i = 0; i < n; ++i) 			
                {
			if (!inTree[i]) 				
			{
				if ((min == -1) || (d[min] > d[i]))
				min = i;
			}
		}
		printf("Adding edge %c-%c\n", whoTo[min] + 'A', min + 'A');
		inTree[min] = 1;
		total += d[min];
		updateDistances(min);
	}
	printf("Total distance: %d\n", total);
	return 0;
}

