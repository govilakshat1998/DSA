#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,m,k;
	scanf("%d %d %d", &n, &m, &k);

	int a;
	for(int i=0;i<n*m;i++)
		scanf("%d",&a);

	printf("%d\n",(m*(m-1))/2);
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(k==0) 
				printf("%d %d\n",i,j);
			else 
				printf("%d %d\n",j,i);
		}
	}

}