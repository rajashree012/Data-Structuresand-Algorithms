/*write a c program to randomely generate n numbers and sort these numbers using radix sort.Make several runs for sorting the generated random numbers.Print the run time for sorting these set of numbers into a file.Also calculate mean and standard deviation for these run times.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void bucketsort(int a[],int i,int n);
void radixsort(int a[],int n,int i);
main()
{
	int i,n,x,j,z=0,r;
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
			a[i]=rand();
			//printf("%d ",a[i]);
		}
		for(i=0;i<n;i++)
		{
			while(a[i]/(int)pow(10,z)!=0)
			{
				z++;
			}
		}
		//printf("%d",z);
		e1=clock();
		for(i=0;i<z;i++)
		{		
			radixsort(a,i,n);
		}
		/*printf("\n****************************\n");
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
void radixsort(int a[],int i,int n)
{
	bucketsort(a,i+1,n);
	return;
}
void bucketsort(int a[],int i,int n)
{	
	struct linked_list
	{
		int number;
		struct linked_list*next;
	};
	typedef struct linked_list node;	
	int m=9,j,k,l;
	int count[10];
	node *pointer[10];
	node *pointer1[10];
	for(j=0;j<=9;j++)
	{
		pointer[j]=(node *)malloc(sizeof(node));
		pointer1[j]=pointer[j];
	}
	for(j=0;j<=9;j++)
	{
		count[j]=0;
	}
	for(j=0;j<n;j++)
	{	
		k=(a[j]%(int)pow(10,i))/pow(10,i-1);		
		count[k]++;
		pointer[k]->number=a[j];
		pointer[k]->next=(node *)malloc(sizeof(node));
		pointer[k]=pointer[k]->next;
	}
	k=0;	
	for(j=0;j<=m;j++)
	{
		for(;count[j]>0;count[j]--)
		{
			a[k++]=pointer1[j]->number;
			pointer1[j]=pointer1[j]->next;
		}
	}	
	return;
}	
		
