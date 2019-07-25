#include <stdio.h>

void checkPrime(int,int);

int main()
{
	int a;
	int b;
	scanf("%d",&a);
	scanf("%d",&b);
	printf("\n");
	checkPrime(a,b);
}

void checkPrime(int a,int b)
{
	for(int i=a;i<=b;i++)
	{
		int flag = 0;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j == 0)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
			printf("%d\n",i);
	}
}
