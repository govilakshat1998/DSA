#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,x;
int am[5001][5001] = {};
int visited[5001] = {};

int max(int a,int b)
{
	return a>=b?a:b;
}

int dist1[5001] = {};
int distx[5001] = {};

void dfs(int root, int dist[])
{
	visited[root] = 1;
	for(int i=1; i<=n ; ++i)
	{
		if(!visited[i] && am[root][i])
		{
			dist[i] = dist[root]+1;
			dfs(i,dist); 
		}
	}
}

int main()
{
	scanf("%d %d",&n , &x);
	int a,b;
	for(int i=0;i<n-1;++i)
	{
		scanf("%d %d",&a,&b);
		am[a][b] = 1;
		am[b][a] = 1;
	}

	dfs(1,dist1);
	memset(visited,0,sizeof(visited));
	dfs(x,distx);
	int ans = 0;
	for(int i=1;i<=n;++i)
	{
		if(dist1[i]>distx[i]) 
			ans = max(ans,2*dist1[i]);
	}
	printf("%d\n", ans);
}