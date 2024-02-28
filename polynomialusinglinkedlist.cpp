#include<stdio.h>
#include<malloc.h>
struct node 
{
	int c;
	int e;
	struct node *next;
};
typedef struct node poly;
poly *head=NULL;
void insert(int c,int e)
{
	poly *t;
	if(head==NULL)
	{
		head=(poly*)malloc(sizeof(poly));
		head->c=c;
		head->e=e;
		head->next=NULL;
	}
	else
	{
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(poly*)malloc(sizeof(poly));
		t->next->c=c;
		t->next->e=e;
		t->next->next=NULL;
	}
}
void disp()
{	poly *t;
	if(head==NULL)
	{
		printf("Polynomial is empty :");
	}
	else
	{
		t=head;
		while(t!=NULL)
		{
			printf("%dX^%d",t->c,t->e);
			if(t->next!=NULL)
			{
				if(t->c < 0)
				{
					printf("+");
				}
				else
				{
					printf("");
				}
			}
			t=t->next;
		}
		
		
	}
}

int main()
{
	insert(2,3);
	insert(-3,1);
	insert(4,5);
	disp();
	
}
