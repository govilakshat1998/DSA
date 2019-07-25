#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	int r[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&r[i][j]);
	}

	for(int t=0;t<n;t++)
	{
		for(int i=0;i<n;i++)
		{	
			int temp = a[i];
			int ti,tj;
			for(int j=i;j<n;j++)
			{
				if(a[j] < a[i] && r[i][j])
				{
					ti = i;
					tj = j;
					temp = a[j];
				}
			}
			if(temp != a[i])
			{
				a[tj] = a[ti];
				a[ti] = temp;
			}
		}
	}

	for(int i=0;i<n;i++)
		printf("%d ",a[i]);	
}
		


// 7
// 5 2 4 3 6 7 1
// 0 1 1 1 1 1 1  
// 1 0 1 1 1 1 1  
// 1 1 0 1 1 1 1  
// 1 1 1 0 1 1 1  
// 1 1 1 1 0 1 1  
// 1 1 1 1 1 0 1  
// 1 1 1 1 1 1 0  
