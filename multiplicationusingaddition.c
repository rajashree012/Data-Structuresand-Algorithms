/*Give a recursive algorithm to compute product of two positive integers m & n using only addition*/
#include<stdio.h>
int mul(int ,int );
main()
{
	int a,b;	
	printf("enter the two numbers to be multiplied");
	scanf("%d %d",&a,&b);
	printf("product=%d",mul(a,b));
}
int mul(int a,int b)
{
	int product;	
	if(b==1)
	return(a);
	else
	product=a+mul(a,b-1);
	return(product);
}
