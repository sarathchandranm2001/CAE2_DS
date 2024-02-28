//circular queue
#include<stdio.h>
int cq[5];
int f=-1;
int r=-1;

void enqueue(int a)
{
	if((r+1)%5==f)
	{
		printf("QUEUE IS FULL");
	}
	else
	{
		if(f==-1)
		{
			f=0;
		}
		cq[++r]=a;
		r=(r+1)%5;
		printf("Enqueued item :%d\n\n",a);
		
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
		if(f==r)
		{
			f=r=-1;
		}
		printf("dequeued elemnet is %d \n \n",cq[f]);
		f=(f+1)%5;
	}
}

int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(30);
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	
	
	
	
	return 0;
}
