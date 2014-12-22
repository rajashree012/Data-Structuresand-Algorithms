/*Suppose that each row of an n by n array A consists of ones and zeroes, such that in any row i of A ones come before zeroes in that row.Suppose further that number of ones in row i is atleast the number in row i+1.Assuming that A is already in memory,describe a method running in O(n) time to count total number of ones in this array*/
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
	i=0;j=0;k=0;l=0;
	for(i=0;i<n;i++)
	{
		while(A[i][j]==1)
		{
			j++;
		}
		l=l+j;
	}
	printf("number of ones=%d",l);
}
