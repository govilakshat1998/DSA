#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int c[100][100];
int visited[100];
int res[100][100];

void dfs(int i,int e)
{
	int ct = 0;
	visited[i] = 1;
	for(int j=1;j<=e;j++)
	{
		if(visited[j]<1 && res[i][j]!=0)
		{
			c[i][j] = 1;
			c[j][i] = 1;
			dfs(j,e);
		}
	}
}

int main()
{
	int n,e;
	scanf("%d %d", &n, &e);
	int a[n][n];
	// int res[e+1][e+1];
	int ct = 1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j] = 0;
		}
	}
	
	for(int i=1;i<=e;i++)
	{
		for(int j=1;j<=e;j++)
		{
			res[i][j] = 0;
		}
	}
	
	for(int i=0;i<e;i++)
	{
		int u,v;
		scanf("%d %d", &u, &v);
		a[u][v] = ct;
		a[v][u] = ct;
		ct++;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]>0)
			{
				for(int k=j+1;k<n;k++)
				{
					if(a[i][k]>0)
					{
						res[a[i][j]][a[i][k]] = 1;
						res[a[i][k]][a[i][j]] = 1;
					}
				}
			}
		}
	}

	for(int i=1;i<=e;i++)
	{
		for(int j=1;j<=e;j++)
		{
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}

	printf("***********\n");
	bool flag = false;
	for(int j=1;j<=e;j++)
		visited[j] = 0;
	int cnt=0;
	for(int row=1;row<=e;row++)
	{
		visited[row] = 1;
		for(int i=1;i<=e;i++)
		{
			if(visited[i]!=1)
			{
				dfs(i,e);
				cnt++;
			}
		}	
		if(cnt>=2)
		{	
			for(int j=1;j<=e;j++)
				visited[j] = 0;
			visited[row] = 1;
			for(int i=1;i<=e;i++)
			{
				if(visited[i] != 1)
				{
					dfs(i,e);
					for(int j=1;j<=e;j++)
					{
						for(int k=1;k<=e;k++)
						{
							printf("%d ", c[j][k]);
							c[j][k] = 0;
						}
						printf("\n");
					}
					printf("\n********\n");
				}
			}
			flag = true;
			printf("%d Cut vertex with connected components %d\n", row,cnt);
		}
		for(int i=1;i<=e;i++)
			visited[i] = 0;
		cnt = 0;					
	}
	if(!flag)
		printf("No Cut vertex");
}