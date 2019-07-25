#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int n,m,k,c = 0;
	scanf("%d %d %d",&n,&m,&k);
	int a[n][m],p[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=j+1;k<m;k++)
			{
				int x = n,flag = 0;
				if(a[i][j]>a[i][k])
				{
					while(x--)
					{
						if(a[x][j]>a[x][k])
						{
							swap(&a[x][j],&a[x][k]);
							flag = 1;
						}
					}
					// swap(&a[i][j],&a[i][k]);
				}
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<m;j++)
						printf("%d ",a[i][j]);
					printf("\n");
				}
				printf("*************\n");
				if(flag)
				{
					p[c][0] = j;
					p[c][1] = k;
					c++;
				}
			}
		}
	}
	printf("%d\n",c);
	for(int i=0;i<c;i++)
		printf("%d %d\n",p[i][0]+1,p[i][1]+1);
}