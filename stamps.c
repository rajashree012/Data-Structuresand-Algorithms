#include<stdio.h>
void stamp(int x,int a[],int y);
main()
{
	int x,y,i;
	printf("enter the number of denominations");
	scanf("%d",&y);
	int a[y];
	printf("enter the values of the denominations in increasing order");
	for(i=0;i<y;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the value");
	scanf("%d",&x);
	stamp(x,a,y);
}
void stamp(int x,int a[],int y)
{	
	int b[x+1];
	int c[x+1];
	int k=0,n=x;
	b[0]=0;
	int i,j,min=0;
	for(j=1;j<=x;j++)
	{
		k=0;		
		for(i=0;i<y;i++)
		{
			if(j-a[i]<0)
			continue;
			else
			goto read;
		}
		b[j]=999;
		continue;
		read:
		{
			min=b[j-a[0]];
			for(i=0;i<y;i++)
			{
				if(j-a[i]>=0)
				{
					if(min>b[j-a[i]]&&b[j-a[i]]!=999)
					{
						min=b[j-a[i]];
						k=i;
					}				
				}
			}
			c[j]=k;
			//printf("%%%d %d%%",k,j);
			if(min==999)
			b[j]=999;
			else
			b[j]=1+min;
		}
	}
	//printf("%d",b[x]);
	if(b[x]!=999)
	{	
		printf("%d",b[x]);
		while(n>=2)
		{
			printf("\n %d ",a[c[n]]);			
			n=n-a[c[n]];
			//printf("\n %d ",a[c[n]]);	
		}
	}
}
	
