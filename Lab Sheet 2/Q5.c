#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int visited[1000];
int a[1000][1000];
int c[100][100];
int v;

void dfs(int i)
{
	int ct = 0;
	visited[i] = 1;
	for(int j=1;j<=v;j++)
	{
		if(visited[j]!=1 && a[i][j]!=0)
		{
			c[i][j] = 1;
			c[j][i] = 1;
			dfs(j);
		}
	}
}

int main()
{
	scanf("%d", &v);
	int f[v+1];
	for(int i=1;i<=v;i++)
		scanf("%d", &f[i]);

	int delta;
	scanf("%d", &delta);
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			if(abs(f[i]-f[j])>=delta)
			{
				a[i][j] = 1;
				a[j][i] = 1;
			}
		}
	}

	int cnt=0;
	for(int i=1;i<=v;i++)
	{
		if(visited[i]!=1)
		{
			dfs(i);
			for(int j=1;j<=v;j++)
			{
				for(int k=1;k<=v;k++){
					printf("%d ",c[j][k]);
					c[j][k]=0;
				}
				printf("\n");
			}
			printf("*********\n");
			cnt++;
		}
	}
	printf("%d\n", cnt);
}