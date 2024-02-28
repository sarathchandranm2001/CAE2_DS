#include<stdio.h>
#include<string.h>
char stack[20],top=-1;
void push(char a)
{
	if(top+1==20)
	{
		printf("stack Is Full");
	}
	else
	{
		stack[++top]=a;
	}
}

void pop()
{
	if(top==-1)
	{
		printf("stack is empty");
	}
	else
	{
		printf("%c",stack[top--]);
	}
}

int main()
{
	char name[20];
	int i;
	printf("Enter a string");
	fgets(name,sizeof(name),stdin);
	for(i=0;i<strlen(name);i++)
	{
		push(name[i]);
	}
	for(i=0;top!=-1;i--)
	{
		pop();
	}
	return 0;
}
