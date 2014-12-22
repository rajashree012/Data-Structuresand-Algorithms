/*write a c program to randomely generate n numbers and sort these numbers using quick sort.Make several runs for sorting the generated random numbers.Print the run time for sorting these set of numbers into a file.Also calculate mean and standard deviation for these run times.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void quicksort(int a[],int n,int m);
int partition(int a[],int n,int m);
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
		quicksort(a,0,n-1);
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
void quicksort(int a[],int low,int high)
{	
	int pivot;
	if(high<=low)
	return;
	pivot=partition(a,low,high);
	quicksort(a,low,pivot-1);
	quicksort(a,pivot+1,high);
	return;
}
int partition(int a[],int low,int high)
{
	int temp,b=low,i;	
	while(low<high)
	{
		while(a[high]>a[b])
		{
			high--;
		}
		while(a[low+1]<=a[b])
		{
			low++;
		}
		if(low<high)
		{		
			temp=a[low+1];
			a[low+1]=a[high];
			a[high]=temp;
		}		
	}
	temp=a[b];
	a[b]=a[low];
	a[low]=temp;
	return(low);
}
