#include <stdio.h>

void prspiral(int);

int main()
{
	int n;
	scanf("%d",&n);
	prspiral(n);
}

void prspiral(int n)
{
	int arr[n*n];
	arr[0] = 2;
	int c = 1;
	int t = 3;
	while(c<=(n*n))
	{
		int flag = 0;
		for(int i=2;i*i<=t;i++)
		{
			if(t%i==0)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
			arr[c++] = t;
		t++;
	}

	int e = (n*n)-1;
	int mat[n][n];
	int max = n-1;
	int min = 0;
	while(e >= 0)
	{
		int r = max;
		int c = max;
		while(c>min)
			mat[r][c--] = arr[e--];
		while(r>min)
			mat[r--][c] = arr[e--];
		while(c<max)
			mat[r][c++] = arr[e--];
		while(r<max)
			mat[r++][c] = arr[e--];
		if(min==max)
			mat[r][c] = arr[e--];
		max--;
		min++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
}

