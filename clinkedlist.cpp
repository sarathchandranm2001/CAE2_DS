#include<stdio.h>
#include<malloc.h>
//circularlinkedlist
struct node
{
	int data;
	struct node *next;
};

struct node*head=NULL;
void insert(int e)
{
	struct node *t;
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->data=e;
		head->next=head;
	}
	else
	{
		t=head;
		while(t->next!=head)
		{
			t=t->next;
		}
		t->next=(struct node * )malloc(sizeof(struct node));
		t->next->data=e;
		t->next->next=head;
	}
}
void disp()
{
	struct node *t;
	if(head==NULL)
	{
		printf("Linked list is empty");
	}
	else
	{
		t=head;
		while(t->next!=head)
		{
			printf("%d \n",t->data);
			t=t->next;
		}
		printf("%d\n",t->data);
		
	}
	
}
int main()
{
	insert(10);
	insert(11);
	insert(15);
	insert(40);
	insert(66);
	disp();
	return 0;
}
