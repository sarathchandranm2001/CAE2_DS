//linked queue
#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node queue;
queue *f=NULL;
queue*r=NULL;
void enqueue(int e)
{
	queue *t=(queue*)malloc(sizeof(queue));//allocating memory to new node
	t->data=e;//allocating data to new node
	t->next=NULL;//next of new node is null
	if(f==NULL)
	{
		f=t;
		r=t;
	}
	else
	{
		r->next=t;
		r=t;
	}
	
}

void dequeue()
{
	if(f==NULL)
	{
		printf("Queue Is Empty");
	}
	else
	{
		printf("%d",f->data);
		f=f->next;
		if(f==NULL)
		{
			r=NULL;
		}
	}
}

int main()
{
	enqueue(10);
	enqueue(10);
	enqueue(10);
	enqueue(10);
	enqueue(20);
	dequeue();
	dequeue();
	
}
