/*implement stack using two queues.(Here is stack is of size N-1 and queue is of size N)*/
#include<stdio.h>
int size(int a[]);
void top(int a[]);
int isEmpty(int a[]);
void push(int a[],int i);
int pop(int a[],int b[]);
int rear=0;
int front=0;
int N;
main()
{
	int i,j,l,k,h;
	printf("enter the number of elements of array to store stack");
	scanf("%d",&N);
	int queue1[N];
	int queue2[N];
	printf("number of times you want to perform the operaton");
	scanf("%d",&l);
	for(k=0;k<l;k++)
	{
		printf("\nenter the operation you want to perform\n");
		printf("1.size of stack \n2.returning the top element of the stack \n3.checking wether stack is empty or not \n4.adding element to stack \n5.removing element from stack");
		scanf("%d",&i);
		switch(i)
		{
			case 1:printf("size of stack is %d",size(queue1));
			       break;
			case 2:top(queue1);
			       break;
			case 3:if(isEmpty(queue1)==0)
			       printf("stack is empty");
			       else
			       printf("stack is not empty");
			       break;	
			case 4:if(size(queue1)==N-1)
			       printf("stack is full");
			       else
			       {
				       printf("enter the element into the stack");
				       scanf("%d",&j);
				       push(queue1,j);
			       }
			       break;
			case 5:if(isEmpty(queue1)==0)
			       printf("stack is empty");
			       else
			       {
			       	    printf("element is %d",pop(queue1,queue2));
			       	    for(h=0;h<N;h++)
				    queue1[h]=queue2[h];
			       }		
			       break;
			default:printf("invalid operation");
		}
	}
}
int size(int a[])
{	
	if(front<=rear)
	return(rear-front);
	else
	return(N-front +rear);
}
void top(int a[])
{
	if(!isEmpty(a))
	printf("there are no elements in the stack");
	else
	printf("%d is the top element of the stack",a[rear-1]);
	return;
}
int isEmpty(int a[])
{
	if(size(a)==0)
	return(0);
	else
	return(1);
}
void push(int a[],int i)
{
	a[rear]=i;	
	if(rear==N-1)
	rear=0;
	else
	rear++;
	return;
}
int pop(int a[],int b[])
{
	int j,i;
	i=front;
	for(j=1;j<size(a);j++)
	{
		b[i]=a[i];
		if(i==N-1)
		i=0;
		else
		i++;
	}
	if(rear==0)
	rear=N-1;
	else
	rear--;
	return(a[i]);
}
