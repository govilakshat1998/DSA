#include <stdio.h>

void spiral(int);

int main()
{
	int n;
	scanf("%d",&n);
	spiral(n);
}

void spiral(int n)
{
	int e = n*n;
	int mat[n][n];
	int max = n-1;
	int min = 0;
	while(e > 0)
	{
		int r = max;
		int c = max;
		while(c>min)
			mat[r][c--] = e--;
		while(r>min)
			mat[r--][c] = e--;
		while(c<max)
			mat[r][c++] = e--;
		while(r<max)
			mat[r++][c] = e--;
		if(min==max)
			mat[r][c] = e--;
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


