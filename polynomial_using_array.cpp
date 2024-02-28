#include<stdio.h>
int cof[20],i,deg;
void read()
{
 for(i=deg;i>=0;i--)	
 {
 	printf("Enter Coefficient for degree %d : ",i);
 	scanf("%d",&cof[i]);
 }
}
void disp()
{
	int i;
	for(i=deg;i>=0;i--)
	{
		if (cof[i] != 0) {
            if (i == deg)
                printf("%dx^%d ", cof[i], i);
            else if (i == 1)
                printf("%+dx ", cof[i]);
            else if (i == 0)
                printf("%+d ", cof[i]);
            else
                printf("%+dx^%d ", cof[i], i);
        }
    }
    printf("\n");
}
	
int main()
{
	printf("Enter Degree Of Polynomial :");
	scanf("%d",&deg);
	read();
	disp();
	return 0;
}
