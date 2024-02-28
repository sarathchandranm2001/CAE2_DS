#include<stdio.h>
int top=-1;
int stack[20];

void push(int a)
{
	if(top+1==20)
	{
		printf("Stack Overflow");
	}
	else
	{
		stack[++top]=a;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("stack is Empty");
	}
	else
	{
		printf("Popped Elemnt is %d\n",stack[top]);
		top--;
	}
	
}
int main()
{
	push(10);
	push(20);
	push(30);
	pop();
	pop();
	return 0;
}

