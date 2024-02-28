#include<stdio.h>
struct polynomial{
	int coef;
	int exp;
};
void read_polynomial(struct polynomial p[],int d)
{
	int i,z;
	z=d;
	for(i=0;i<=d;i++,z--)
	{
		p[i].exp=z;
		printf("\ncoefficent of %d: ",z);
		scanf("%d",&p[i].coef);
		
	}
	printf("\n");
}
void display_polynomial(struct polynomial p[],int d)
{
	int i;
	printf("%dx^%d",p[0].coef,p[0].exp);
	for(i=1;i<=d;i++)
	{
		if(p[i].exp==0)
		{
			printf("+%d",p[i].coef);
		}else {
			
	        if(p[i].coef>0)
			{
	        	printf("+%dx^%d",p[i].coef,p[i].exp);	
			}else
			{
				printf("-%dx^%d",-p[i].coef,p[i].exp);
			}
    	}
    }
}
int mult_polynomial(struct polynomial p1[],int d1,struct polynomial p2[],int d2,struct polynomial res[])
{
	int i,j;
	int k=0;
	
	for(i=0;i<=d1;i++)
	{
		for(j=0;j<=d2;j++)
		{
			res[k].coef=p1[i].coef*p2[j].coef;
			res[k].exp=p1[i].exp+p2[j].exp;
			k++;
		}
	}
	sort(res,k);
	k=reduce(res,k);
	return k;
}
sort(struct polynomial p[],int n)
{
	int a,i,j;
	 for (i = 0; i < n; ++i)
        {
 
            for (j = i + 1; j < n; ++j)
            {
 
                if (p[i].exp < p[j].exp) 
                {
 
                    a =  p[i].exp;
                    p[i].exp = p[j].exp;
                    p[j].exp = a;
                    a =  p[i].coef;
                    p[i].coef = p[j].coef;
                    p[j].coef = a;
 
                }
 
            }
        }
 
}

int reduce(struct polynomial res[],int n)
{
	int i,j;
	int k=0;
	int coefsum;
	for(i=0;i<n;i=j)
	{
		coefsum=res[i].coef;
		for(j=i+1;j<=n && res[j].exp==res[i].exp;j++)
		{
			coefsum=coefsum+res[j].coef;
    	}
		res[k].coef=coefsum;
		res[k].exp=res[i].exp;
		k++;
		
		
	}
	return k;
}
int main()
{
	struct polynomial p1[10],p2[10],res[30];
	int d1,d2;
	int s;
	printf("enter the degree of first polynomial");
	scanf("%d",&d1);
	printf("enter the degree of second polynomial");
	scanf("%d",&d2);
	read_polynomial(p1,d1);
	printf("first polynomial:\n");
	display_polynomial(p1,d1);
	read_polynomial(p2,d2);
	printf("second polynomial:\n");
	display_polynomial(p2,d2);
	s=mult_polynomial(p1,d1,p2,d2,res);
	printf("\nresult is:\n");
	display_polynomial(res,s-1);
}

