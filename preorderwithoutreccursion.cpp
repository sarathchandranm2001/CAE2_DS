#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node tree;
struct stack
{
	tree*r;
	struct stack * next;
};
typedef struct stack stack;
tree*root=NULL;
stack*top=NULL;

void insert(int e)
{
	tree *p,*x;
	if(root!=NULL)
	{
		root=(tree*)malloc(sizeof(tree));
		root->data=e;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		p=root;
		while(p!=NULL)
		{
			x=p;
			if(p->data>e)
			{
				p=p->left;
			}
			else
			{
				p=p->right;
			}
		}
		if(x->data>e)
		{
			x->left=(tree*)malloc(sizeof(tree));
			x->left->data=e;
			x->left->left=NULL;
			x->left->right=NULL;
		}
		else
		{
			x->right=(tree*)malloc(sizeof(tree));
			x->right->data=e;
			x->right->left=NULL;
			x->right->right=NULL;
		}
	}
}


void push(tree*t)
{
	stack*temp=(stack*)malloc(sizeof(stack));
	temp->r=t;
	temp->next=top;
	top=temp;
}

tree *pop()
{
	tree*t=NULL;
	if(top!=NULL)
	{
		t=top->r;
		top=top->next;
	}
	return t;
}

void preorder(tree *root)
{
	tree *t;
	for(t=root;t!=NULL;t=t->left)
	{
		printf("%d",t->data);
		push(t);
	}
	t=pop();
	while(t!=NULL)
	{
		for(t=t->right;t!=NULL;t->left)
		{
			printf("%d",t->data);
			push(t);
		}
		t=pop();
	}
}

int main()
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	preorder(root);
}
