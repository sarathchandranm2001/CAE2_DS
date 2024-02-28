//linkedlist
#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL;

void insert(int e)
{
	struct node *t;
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=e;
		head->next=NULL;
	}
	else
	{
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(struct node *)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->next=NULL;
	}
	
}

void disp()
{
	struct node *t;
	if(head==NULL)
	{
		printf("LinkedList is EMpty");
	}
	else
	{ 
		t=head;
		while(t!=NULL)
		{
		 	printf("%d\n",t->data);
		 	t=t->next;
		}
	}
}

void delt(int e)
{
	struct node*t;
	if(head==NULL)
	{
		printf("Linked List Is EMpty");
	}

	else if(head->data==e)
	{
		head=head->next;
	}
	else
	{
		t=head;
		while(t->next!=NULL&&t->next->data!=e)
		{
			t=t->next;
		}
		if(t->next==NULL)
		{
			printf("NOt found");
		}
		else
		{
			t->next=t->next->next;
		}
	}
}

int main()
{
	insert(10);
	insert(15);
	insert(30); 
	insert(45);
	disp();
	delt(30);
	disp();
	return 0;
}

