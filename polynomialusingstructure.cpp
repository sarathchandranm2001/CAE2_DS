#include<stdio.h>
struct poly
{
	int cof;
};
int i;
void read(struct poly p[],int deg)
{
	for(i=deg;i>=0;i--)
	{
		printf("Enter %d term :",i);
		scanf("%d",&p[i].cof);
	}
}

void disp(struct poly p[],int deg)
{
	for(i=deg;i>=0;i--)
	{
		if(p[i].cof!=0)
		{
			if(i==deg)
			{
				printf("%dX^%d",p[i].cof,i);
			}
			else if(i==1)
			{
				printf("%+dX",p[i].cof);
			}
			else if(i==0)
			{
				printf("%+d",p[i].cof);
			}
			else
			{
				printf("%+dX%d",p[i].cof,i);
			}
		}
	}
}

int main()
{
	int deg;
	struct poly p[20];
	printf("Enter Degreee of the polynomial :\n");
	scanf("%d",&deg);
	read(p,deg);
	disp(p,deg);
	return 0;
}
