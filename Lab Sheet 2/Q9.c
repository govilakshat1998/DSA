#include<stdio.h>
#include<stdlib.h>

int a[100][100];
int sum = 0;

int maxSum(int m,int n)
{
		int maxs = 0;
		for(int i=0;i<n-m+1;i++)
		{
			for(int j=0;j<n-m+1;j++)
			{
				for(int k=i;k<m+i;k++)
				{
					for(int l=j;l<m+j;l++)
						sum += a[k][l];
				}
				if(sum>=maxs)
					maxs = sum;
				sum = 0;
			}
		}
		sum = 0;
	return maxs;
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
			scanf("%d", &a[i][j]);
	}

	int arr[n];
	for(int v=0;v<n;v++)
		arr[v] = maxSum(v+1,n);

	int maxi = arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i] > maxi)
			maxi = arr[i];
	}
	printf("%d\n", maxi);
}