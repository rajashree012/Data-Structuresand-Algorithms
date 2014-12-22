/*selection sort*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
main()
{
	int i,n,x,j,k,r;
	float m;
	float mean=0;
	float sd=0;
	clock_t e1,e2;
	FILE *f1;
	f1=fopen("abc.txt","a");
	printf("enter number of elements to be sorted and number of runs");
	scanf("%d %d",&n,&x);
	int a[n];
	for(j=0;j<x;j++)
	{
		for(i=0;i<n;i++)
		{
			a[i]=rand();
		}
		e1=clock();
		for(i=0;i<n;i++)
		{
			for(k=i+1;k<n;k++)
			{
				if(a[i]>a[k])
				{
					r=a[i];
					a[i]=a[k];
					a[k]=r;
				}
			}
			//printf("%d ",a[i]);
		}
		e2=clock();
		fprintf(f1,"%f%c",((float)(e2-e1))/CLOCKS_PER_SEC,' ');
		printf("\nrun %d: %f",j+1,((float)(e2-e1))/CLOCKS_PER_SEC);
	}

	fclose(f1);
	f1=fopen("abc.txt","r");
	for(i=0;i<x;i++)
	{
		fscanf(f1,"%f ",&m);
		mean=mean+m;
	}
	mean=mean/x;
	fclose(f1);
	f1=fopen("abc.txt","r");
	for(i=0;i<x;i++)
	{
		fscanf(f1,"%f ",&m);
		sd=sd+pow(mean-m,2);
	}
	sd=sqrt(sd/x);
	fclose(f1);
	f1=fopen("abc.txt","a");
	fprintf(f1,"%f%c%f",mean,' ',sd);
	fclose(f1);
} 

