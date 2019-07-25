#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int g[1000][1000];
int vis[1000]; 
int n,m,ans = 0;
int a[1000];

int check(int src)
{
	for(int i=1;i<=n;i++)
	{
		if(g[src][i] == 1 && !vis[i]) 
			return 0;
	}
	return 1;
}

int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

void dfs(int src, int currc, int maxc)
{
	vis[src] = 1;
	if(a[src] == 1)
	{
		currc++; 
		maxc = max(maxc,currc);
	}
	else 
		currc = 0;

	if(check(src) && maxc <= m)
		ans++;
		
	for(int i=1;i<=n;i++)
	{
		if(!vis[i] && g[src][i]==1)
			dfs(i,currc,maxc);
	}
}

int main()
{
	scanf("%d %d",&n, &m);
	
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);

	int u,v;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&u,&v);
		g[u][v] = 1;
		g[v][u] = 1;
	}

	dfs(1,0,0);
	printf("%d",ans);
}