#include<stdio.h>
#include<string.h>
#define max 10
char stack[max];
int top=-1;
void push(char x)
{
	top++;
	stack[top]=x;
}

char pop()
{
	char y=stack[top];
	top--;
	return y;
}

int precedence(char k)
{
	if(k=='^')
	{
		return 3;
	}
	else if(k=='*'||k=='/')
	{
		return 2;
	}
	else if(k=='+'||k=='-')
	{
		return 1;
	}
	else
		return 0;
}

int conversion()
{
	char infix[max],postfix[max];
	printf("Enter The Infix Expression");
	scanf("%s",infix);
	push('#');
	int i=0,j=0;
	char temp, k;
	while(infix[i]!='\0')
	{
		temp=infix[i];
		switch(temp)
		{
			case'(':
				push(temp);
				break;
			case')':
			k=pop();
			while(k!='(')
			{
				postfix[j]=k;
				j++;
				k=pop();
			}
			break;
			case '^' :
			case '*':
			case '/':
			case'+':
			case'-':
				while(precedence(stack[top])>=precedence(temp))
				{
					postfix[j]=pop();
					j++;
				}
				push(temp);
				break;
			default:
			postfix[j]	=temp;
		}
		i++;
	}
	 postfix[j] = '\0';
	puts("Postfix exp :");
	puts(postfix);
}

int main()
{
	conversion();
}


