#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *left;
	struct node *right;
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
			if(p->data<e)
			{
				p=p->right;
			}
			else
			{
				p=p->left;
			}
		}
		
		if(x->data >e)
		{
			x->left=(tree*)malloc(sizeof (tree));
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
void delet(int e)
{
	tree *p,*x,*t;
	p=NULL;
	x=root;
        while(x!=NULL)
        {
            if(x->data == e)
            	break;
            else if(x->data > e)
            {
            	p=x;
            	x=x->left;
			} 
            else if(x->data < e)
            {
            	p=x;
				x=x->right;
			}      
        }
        if(x==NULL)
        	printf("Element not found\n");
        else 
        {
        	if(x->left == NULL && x->right == NULL) //Node with No children
        	{
        		if(x == root)
        			root=NULL;
        		else if(p->right == x)
        			p->right = NULL;
        		else
        			p->left = NULL;
			}
			else if(x->left == NULL || x->right == NULL) //Node with 1 child
			{
				if(x == root) //Root
				{
					root = (x->right != NULL) ?  x->right : x->left;
				}
				else if(p->left == x) 
				{
					if(x->left != NULL) //left left
						p->left=x->left;
					else					//left right
						p->left = x->right;
				}
				else
				{
					if(x->right!=NULL) //right right
						p->right=x->right;
					else						//right left
						p->right=x->left;
				}
			}
			else //node with two children
			{
				tree *t=x->right;
				while(t->left!=NULL)
					t=t->left;
				delet(t->data);
				x->data = t->data;
			}
			
		}
}
void inorder(tree *r)
{

if(r!=NULL)
{
	inorder(r->left);
	printf("%d\n",r->data);
	inorder(r->right);
}
}






int main()
{
	insert(10);
	insert(15);
	insert(30);
	insert(20);
	insert(50);
	insert(67);
	insert(79);
	insert(12);
	inorder(root);
	
	printf("\n\n\n\n\n");
	delet(79);
	inorder(root);
	
	return 0;
}
