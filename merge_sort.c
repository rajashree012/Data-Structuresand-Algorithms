/*write a c program to randomely generate n numbers and sort these numbers using merge sort.Make several runs for sorting the generated random numbers.Print the run time for sorting these set of numbers into a file.Also calculate mean and standard deviation for these run times.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void mergesort(int a[],int n);
void merge(int left[],int n,int m);
main()
{
	int i,n,x,j,k,r;
	float m;	
	double mean=0;
	double sd=0;
	clock_t e1,e2;
	FILE *f1;
	f1=fopen("abcd.txt","a");	
	printf("enter the number of elements to be sorted and number of runs");
	scanf("%d %d",&n,&x);
	int a[n];
	for(j=0;j<x;j++)
	{
		for(i=0;i<n;i++)
		{
			a[i]=rand()%100;
			//printf("%d ",a[i]);
		}
		e1=clock();
		mergesort(a,n);
		/*printf("\n");
		for(i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}*/
		e2=clock();
		fprintf(f1,"%f%c",((float)(e2-e1))/CLOCKS_PER_SEC,' ');
		printf("\nrun %d : %f",j+1,((float)(e2-e1))/CLOCKS_PER_SEC);
	}
	fclose(f1);
	f1=fopen("abcd.txt","r");
	for(i=0;i<x;i++)
	{
		fscanf(f1,"%f ",&m);
		mean=mean+m;
	}
	mean=mean/x;
	 
	fclose(f1);
	f1=fopen("abcd.txt","r");
	for(i=0;i<x;i++)
	{
		fscanf(f1,"%f ",&m);
		sd=sd+pow(mean-m,2);
	}
	sd=sqrt(sd/x);
	fclose(f1);
	f1=fopen("abcd.txt","a");
	fprintf(f1,"%f%c%f",mean,' ',sd);
	fclose(f1);
} 
void mergesort(int a[],int n)
{
	if(n==1)
	return;
	mergesort(a,(int)floor(n/2));
	mergesort(a+(int)floor(n/2),n-(int)floor(n/2));
	merge(a,(int)floor(n/2),n-(int)floor(n/2));
	return;
}
void merge(int a[],int n,int m)
{
	int i,j=0,k=0;
	int output[n+m];
	for(i=0;i<n+m;i++)
	{
		output[i]=a[i];
	}
	i=0;
	while(i<n&&k<m)
	{
		if(output[i]<=output[n+k])
		{
			a[j]=output[i];
			j++;
			i++;
		}
		if(output[i]>output[n+k])
		{
			a[j]=output[n+k];
			j++;
			k++;
		}
	}
	while(j<n+m)
	{
		if(i<n)
		{
			a[j]=output[i];
			j++;
			i++;
		}
		else
		{
			a[j]=output[n+k];
			j++;
			k++;
		}
	}	
	return;
}
			
