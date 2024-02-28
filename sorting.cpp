#include<stdio.h>
int arr[20];


void sort()
{
	int i,j,t;
	for(i=0;i<5-1;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(arr[i]>arr[j])
			{
				t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;
			}
		}
	}
}
void disp()
{
	
	for(int i=0;i<5;i++)
	{
		printf("%d\n\n",arr[i]);
	}
}

int main()
{

printf("Enter Elements");
for(int i=0;i<5;i++)
{
	scanf("%d",&arr[i]);
}

sort();
disp();


}
