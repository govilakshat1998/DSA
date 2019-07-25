#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int am[2001][2001];
int ds[2001];
int dt[2001];
int n,m,s,t;
int visited[2001];
int queue[2001];
int start = -1;
int end = 0;

void push(int data)
{
	if(end==0)
		start++;
	queue[end]=data;
	end++;
}

int pop()
{
	return queue[start++]; 
}

void bfs(int root,int d[])
{
	push(root);
	while(start<end)
	{
		int root = pop();
		visited[root]=1;
		for(int i=1;i<=n;++i)
		{
			if(!visited[i] && am[root][i])
			{
				if(d[i]==0)
					d[i] = d[root]+1;
				push(i);
			}
		}
	}
}

int main()
{
	scanf("%d %d %d %d",&n,&m,&s,&t);
	int a,b;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d",&a,&b);
		am[a][b]=1;
		am[b][a]=1;
	}

	bfs(s,ds);
	start = -1;
	end=0;
	memset(visited,0,sizeof(visited));
	memset(queue,0,sizeof(queue));
	bfs(t,dt);
	int D = ds[t];
	int ans =0;
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			if(ds[i]+dt[j]+1>=D && ds[j]+dt[i]+1>=D && am[i][j]!=1)
				ans++;
		}
	}
	printf("%d",ans);
}