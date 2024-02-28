#include<stdio.h>
#include<malloc.h>
struct node 
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head=NULL;

void insert(int e)
{
	struct node*t;
	
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=e;
		head->next=head;
		head->prev=head;
	}
	else
	{
		t=head;
		while(t->next!=head)
		{
			t=t->next;
		}
		t->next=(struct node*)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->next=head;
		t->next->prev=t;
	}
	
}

void disp()
{
	struct node *t;
	if(head==NULL)
	{
		printf("Circular doubly Linked List is empty");
	}
	else
	{
		t=head;
		while(t->next!=head)
		{
			printf("%d\n\n",t->data);
			t=t->next;
		}
		printf("%d",t->data);
	}
}

void delt(int e)
{
	if(head==NULL)
	{
		printf("Ciruclar Doubly Linked List is Empty");
	}
	else if(head->data==e&&head->next==head)
	{
		head=NULL;
	}
}

int main()
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	disp();
}
