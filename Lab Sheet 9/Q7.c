#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int am[1001][1001] = {};
int vis[1001]={};
int mincost = 1e9;

int min(int a,int b)
{
	return a<=b?a:b;
}

void dfs(int s , int e, int k ,int level ,int n, int cost)
{
	if(level>k+1)
		return;
	vis[s]=1;
	if(s==e)
	{
		mincost = min(mincost,cost );
		vis[s]=0;
		return;
	}
	for(int i=0;i<n ; ++i)
	{
		if(am[s][i]>0 && !vis[i]) 
			dfs(i,e,k,level+1,n,cost+am[s][i]);
	}
	vis[s] = 0;
}

int main()
{
	int n,m,t,k;
	scanf("%d %d",&n,&m);
	int s,e,c;
	for(int i=0;i<m;++i)
	{
		scanf("%d %d %d",&s,&e,&c);
		am[s][e] = c;
	}
	
	scanf("%d",&t);
	for(int i=0; i < t ; ++i)
	{
		scanf("%d %d %d",&s, &e , &k);
		dfs(s,e,k,0,n,0);
		if(mincost==1e9)
			mincost=-1;
		printf("%d\n",mincost);
		mincost = 1e9;
		memset(vis,0,sizeof(vis));
	}

}