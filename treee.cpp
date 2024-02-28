#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node * left;
	struct node * right;	
};

typedef struct node tree;
tree *root=NULL;
void insert(int e)
{
	tree *p,*x;
	if(root==NULL)
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
			if(p->data >e)
			{
				p=p->left;
			}
			else
			{
				p=p->right;
			}
			
			if(x->data<e)
			{
				x->right=(tree*)malloc(sizeof(tree));
				x->right->data=e;
				x->right->left=NULL;
				x->right->right=NULL;
			}
			else
			{
				x->left=(tree*)malloc(sizeof(tree));
				x->left->data=e;
				x->left->left=NULL;
				x->left->right=NULL;
			}
		}
	}
}


void inorder(tree *r)
{
	if(r!=NULL)
	{
		inorder(r->left);
		printf("%d",r->data);
		inorder(r->right);
	}
}
void preorder(tree *r)
{
	printf("%d",r->data);
	preorder(r->left);
	preorder(r->right);
}
void postorder(tree *r)
{
	preorder(r->left);
	preorder(r->right);
	printf("%d",r->data);
}
int main()
{
	insert(50);
	insert(60);
	insert(70);
	insert(40);
	insert(30);
	inorder(root);
	preorder(root);
}

