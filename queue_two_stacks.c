/*Implement queue using two stacks.(Here size of stack is N-1 and size of queue is N)*/
#include<stdio.h>
int size(int a[]);
int isEmpty(int a[]);
void enqueue(int a[],int i);
int dequeue(int a[],int b[]);
int top1=-1;
int top2=-1;
int N;
main()
{
	int i,j,l,k;
	printf("enter the number of elements of array to store queue");
	scanf("%d",&N);
	int stack1[N-1];
	int stack2[N-1];
	printf("number of times you want to perform the operaton");
	scanf("%d",&l);
	for(k=0;k<l;k++)
	{
		printf("\nenter the operation you want to perform\n");
		printf("1.size of queue \n2.checking wether queue is empty or not \n3.adding element to queue \n4.removing element from queue");
		scanf("%d",&i);
		switch(i)
		{
			case 1:printf("size of queue is %d",size(stack1));
			       break;
			case 2:if(isEmpty(stack1)==0)
			       printf("queue is empty");
			       else
			       printf("queue is not empty");
			       break;	
			case 3:if(size(stack1)==N-1)
			       {
				       printf("queue is full");
			       }
			       else
			       {
				       printf("enter the element into the queue");
				       scanf("%d",&j);
				       enqueue(stack1,j);
			       }
			       break;
			case 4:printf("%d********%d$$$$$",size(stack1),top1);
			       if(size(stack1)==0)
			       printf("queue is empty");
			       else
			       printf("element is %d",dequeue(stack1,stack2));
			       break;
			default:("invalid operation");
		}
	}
}
int size(int a[])
{
	return(top1+1);
}
int isEmpty(int a[])
{
	if(top1==-1)
	return(0);
	else return(1);
}
void enqueue(int a[],int i)
{
	top1++;
	a[top1]=i;
	return;
}
int dequeue(int a[],int b[])
{
	int i,c;
	top2=-1;	
	{
		for(i=0;i<size(a);i++)
		{
			top2++;
			b[top2]=a[top1];
			top1--;
		}
		c=top2;
		for(i=0;i<top2;i++)
		{
			top1++;
			a[top1]=b[top2-1];
			top2--;
		}
	}
	return(b[c]);
}
