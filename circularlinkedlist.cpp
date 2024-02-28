//circular LInked LIst
#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;//data part
	struct node * next;//self refernce part of the linked list
};

struct node*head=NULL;
void insert(int e)
{
	struct node *t;
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=e;
		head->next=head;
	}
	else
	{
		t=head;
		while(t->next!=head)//traverse upto the last node
		{
			t=t->next;
		}
		t->next=(struct node *)malloc(sizeof(struct node));//allocating new memory to next of lastnode                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
		t->next->data=e;//copy data to newly allocated node;
		t->next->next=head;//make the next of newly allocated node as head;
	}
}

void disp()
{
	struct node *t;
	if(head==NULL)
	{
		printf("\nCircular LInked LIst Is EMpty\n");
	}
	else
	{
		t=head;
		while(t->next!=head)
		{
			printf("%d",t->data);
			t=t->next;
		}
	}
}

void remove(int e)
{
	struct node *t;
	if(head==NULL)
	{
		printf("Lnked list is empty");
	}
	else if(head->data==e && head->next==head)//first element with one element
	{
		head=NULL;
	}
	else if(head->data==e)//first element with several elements
	{
		t=head;
		while(t->next!=head)//traverse upto the last node
		{
			t=t->next;
		}
		t->next=head->next;//changin last node adress to adress of element next to head
		head=head->next;//make head as head next
	}
	else
	{
		t=head;
		while(t->next!=head && t->next->data!=e)
		{
			t=t->next;
		}
		if(t->next==head)
		{
			printf("Element NOt FOund");
		}
		else//deleting intermediate lastelement
		{
			t->next=t->next->next;
		}
		
	}
}

int main()
{

	disp();
	
	
}
