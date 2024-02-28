#include<stdio.h>
int queue[5];
int f=-1,r=-1;
void enqueue(int a)
{
	if(r+1==5)
	{
		printf("Queue is full\n");
	}
	else
	{
		if(f==-1)
		{
			f=0;
		
		}
		queue[++r]=a;
		printf("Enqueued item : %d\n \n",a);
	}
}
void dequeue()
{
	if(f==-1)
	{
		printf("Queue is empty\n \n");
	}
	else
	{
		printf("Dequed Item is : %d \n \n",queue[f]);
		f++;
		if(f==r)
		{
			f=r=-1;
		}
	}
}
int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	enqueue(20);
	dequeue();
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
}
