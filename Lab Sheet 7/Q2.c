#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INF 1000000007
#define ll long long
int am[5001][5001];
int visited[5001];
int amr[5001][5001];
int n,m;
int cost[5001];
int stk[5001];
int stkc = 0;
int costunique[1000000];

int min(int a,int b)
{
	return a<=b?a:b;
}

void dfs(int root)
{
	visited[root] =1;
	for(int i=1;i<=n;++i)
	{
		if(!visited[i] && am[root][i]) 
			dfs(i);
	}
	stk[stkc++] = root;
}

int ans = INF;

void dfs1(int root)
{
	ans = min(ans,cost[root]);
	costunique[cost[root]]++;
	visited[root] =1;
	for(int i=1;i<=n;++i)
	{
		if(!visited[i] && amr[root][i]) 
			dfs1(i);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&cost[i]);
	
	scanf("%d",&m);
	int a,b;
	for(int i=0;i<m;++i)
	{
		scanf("%d %d",&a,&b);
		am[a][b]=1;
		amr[b][a] =1;
	}

	for(int i=1;i<=n;++i)
	{
		if(!visited[i])
			dfs(i);
	}

	memset(visited,0,sizeof(visited));
	int l = stkc-1;
	int cost =0;
	int count =1;

	while(l>=0)
	{
		if(!visited[stk[l]])
		{
			dfs1(stk[l]);
			cost+=ans;
			count*=costunique[ans];
		}

		l--;
		ans=INF;
	}
	if(m==0)
		count =1;
	
	printf("%d %d\n",cost,count);
}