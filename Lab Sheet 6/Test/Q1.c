#include<stdio.h>
#include<stdlib.h>

void swap(int a[], int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

int main()
{
	int n;
	scanf("%d",&n);
	int p[n];
	for(int i=0;i<n;i++)
		scanf("%d",&p[i]);

	int a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}

	// for(int i=0;i<n;i++)
	// {
	// 	int min = p[i];
	// 	int index = i;
	// 	for(int j=i+1;j<n;j++)
	// 	{
	// 		if(p[j] < min)
	// 		{
	// 			min = p[j];
	// 			index = j;
	// 		}
	// 	}
	// 	for(int c=i;c<n;c++)
	// 	{
	// 		if(a[index][c]==1) 
	// 			swap(p,index,i);
	// 		break;
	// 	}
	// }

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[j] < p[i] && a[i][j] == 1)
				swap(p,j,i);
		}
	}

	for(int i=0;i<n;i++)
		printf("%d ",p[i]);
}

// 7
// 5 2 4 3 6 7 1
// 0 0 0 1 0 0 1
// 0 0 0 0 0 0 0
// 0 0 0 0 0 1 0
// 1 0 0 0 0 0 1
// 0 0 0 0 0 0 0
// 0 0 1 0 0 0 0
// 1 0 0 1 0 0 0