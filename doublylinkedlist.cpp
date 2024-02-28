#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node * head=NULL;
void insert(int e)
{
	struct node *t;
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof (struct node));
		head->data=e;
		head->next=NULL;
		head->prev=NULL;
		
	}
	else
	{
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(struct node*)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->next=NULL;
		t->next->prev=t;
	}
}
	
	void disp()
	{
		struct node * t;
		t=head;
		if(head==NULL)
		{
			printf("DOUBLY LINKED LIST IS EMPTY");
		}
		else
		{
			while(t!=NULL)
			{
				printf("%d\n",t->data);
				t=t->next;
			}
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
	

