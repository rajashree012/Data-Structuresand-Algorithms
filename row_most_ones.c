/*suppose that each row of an n by n array A consists of 1's and 0's such that in any row of A,all the ones come before zeroes in that row.Assuming A is already in memory,describe an algorithm in O(n) time for finding the row of A that contains the most ones.*/
#include<stdio.h>
main()
{
	int n,i,j,k,l;
	printf("enter the dimension of array");
	scanf("%d",&n);
	int A[n][n];
	printf("enter the elements sticking to the conditions");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	j=0;
	k=0;
	l=0;
	for(i=0;i<n;i++)
	{
		k=l;
		while(A[i][j]==1&&j<n)
		{
			j++;
		}
		if(k<j)
		{		
			l=j;
		}	
	}
	printf("\n%d   ",l);
	for(i=0;i<n;i++)
	{
		if(A[i][l-1]==1)
		printf("%d has maximum number of ones which is equal to %d",i+1,l);
	}
}
 
	
