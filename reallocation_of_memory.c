/*Implement an extendible table using arrays that can increase in size as elements are added.Perform an experimental analysis of each of the running time for performing a sequence of n add methods, assuming the array is increased from N to the following possible values 2N,N+sqrtN,N+logN,n+100.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
main()
{
	int N=10;
	int n,i;
	clock_t e1,e2;
	int *a,*b,*c,*d;
	printf("enter the size");
	scanf("%d",&n);
	a=(int *)malloc(N*sizeof(int));
	if(a==NULL)
	{
		printf("no space is available");
		exit(1);
	}
	e1=clock();
	for(i=0;i<n;i++)	
	{
		if(i==N)
		{				
			a=(int *)realloc(a,2*N*sizeof(int));
			if(a==NULL)
			{
				printf("no space is available");
				exit(1);
			}
			N=2*N;
		}
		*(a+i)=rand();
	}	
	e2=clock();
	printf("time taken for 2*N extension is %f ",((float)(e2-e1)/CLOCKS_PER_SEC));
	free(a);
	N=10;	
	b=(int *)malloc(N*sizeof(int));
	if(b==NULL)
	{
		printf("no space is available");
		exit(1);
	}	
	e1=clock();
	for(i=0;i<n;i++)	
	{
		if(i==N)
		{					
			b=(int *)realloc(b,(N+(int)floor(sqrt(N)))*sizeof(int));
			if(b==NULL)
			{
				printf("no space is available");
				exit(1);
			}
			N=N+sqrt(N);
		}
		*(b+i)=rand();
	}	
	e2=clock();
	printf("time taken for N+sqrt(N) extension is %f ",((float)(e2-e1)/CLOCKS_PER_SEC));
	free(b);
	N=10;
	c=(int *)malloc(N*sizeof(int));
	if(c==NULL)
	{
		printf("no space is available");
		exit(1);
	}	
	e1=clock();
	for(i=0;i<n;i++)	
	{
		if(i==N)
		{			
			c=(int *)realloc(c,(N+(int)floor(log(N)))*sizeof(int));
			if(c==NULL)
			{
				printf("no space is available");
				exit(1);
			}
			N=N+log(N);
		}
		*(c+i)=rand();
	}	
	e2=clock();
	printf("time taken for N+logN extension is %f ",((float)(e2-e1)/CLOCKS_PER_SEC));
	free(c);
	N=10;
	d=(int *)malloc(N*sizeof(int));
	if(d==NULL)
	{
		printf("no space is available");
		exit(1);
	}	
	e1=clock();
	for(i=0;i<n;i++)	
	{
		if(i==N)
		{					
			d=(int *)realloc(d,(N+100)*sizeof(int));
			if(d==NULL)
			{
				printf("no space is available");
				exit(1);
			}
			N=N+100;
		}
		*(d+i)=rand();
	}	
	e2=clock();
	printf("time taken for N+100 extension is %f ",((float)(e2-e1)/CLOCKS_PER_SEC));
	free(d);
}

	
