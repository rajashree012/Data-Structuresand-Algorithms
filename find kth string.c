#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void check(char a[][100],int n);
char *selects(char a[][100],int i,int n);
main()
{
    int n,k,i,m;
    long h;
    printf("enter the number of strings");
    scanf("%d",&n);
    m=n+5;
    char a[m][100];
    FILE *f1;
    f1=fopen("dsa12.txt","r");	
    for(i=0;i<n;i++)
    fgets(a[i],50,f1);
    fclose(f1);
    printf("enter the value of k");
    scanf("%d",&k);
    printf("%dth largest string is %s",k,selects(a,k,n));
}
void check(char a[][100],int n)
{
	int i;	
	//printf("%d enter %d zeroes",n,5-n%5);
	//scanf("\n");	
	/*for(i=0;i<5-n%5;i++)
        {
	     gets(a[n+i]);
	}*/
	for(i=0;i<5-n%5;i++)
        {
		strcpy(a[n+i],"0");
	}
	return;
}
char *selects(char a[][100],int k,int n)
{
    int i,j,h,l;
    char temp[100];
    char temp1[100];
    char temp2[100];
    char xgreater[100][100];
    char xlesser[100][100];
    if(n<=5)
    {
        for(i=0;i<n-1;i++)
            {
                for(j=0;j<n-1;j++)
                {
                    if(strcmp(a[j],a[j+1])<0)
                    {
                        strcpy(temp,a[j]);
                        strcpy(a[j],a[j+1]);
                        strcpy(a[j+1],temp);
                    }
                }
            }
        return(a[k-1]);
    }
    if(n%5!=0)
    {
	check(a,n);
    }
    if(n%5!=0)
    n=(n/5+1)*5;
    if(n>5)
    {
        h=n/5;
        char m[h][100];
        for(l=0;l<n/5;l++)
        {
            for(i=0;i<4;i++)
            {
                for(j=5*l;j<5*l+4;j++)
                {
                    if(strcmp(a[j],a[j+1])<0)
                    {
                        strcpy(temp,a[j]);
                        strcpy(a[j],a[j+1]);
                        strcpy(a[j+1],temp);
                    }
                }
            }
            strcpy(m[l],a[5*l+2]);
	printf("%s*****",m[l]);
        }
	if(n%2!=0)
	strcpy(temp1,selects(m,h/2+1,h));
	else
	strcpy(temp1,selects(m,h/2,h));
	printf("@@%s&&",temp1);
        j=0;l=0;
        for(i=0;i<n;i++)
        {
             if(strcmp(temp1,a[i])<0)
             {
                strcpy(xgreater[j],a[i]);
		printf("\n%s",xgreater[j]);
                j++;
             }
             if(strcmp(temp1,a[i])>0)
             {
                strcpy(xlesser[l],a[i]);
                l++;
             }
        }
   printf("@@@%d@@",j);
        if(j==k-1)
        return(temp1);
        if(j>=k)
        strcpy(temp2,selects(xgreater,k,j));
        else
        strcpy(temp2,selects(xlesser,k-j-1,l));
        return(temp2);
    }
    
}
