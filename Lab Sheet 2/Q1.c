#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n,min = 9999;

void dfs(int g[n][n],int visited[n+1],int s,int src,int path[n+1],int c,int dist,bool print)
{
	int *p=(int*)calloc(n+1,sizeof(int*));
	int *v=(int*)calloc(n+1,sizeof(int*));
	if(src!=s)
		visited[src]=1;
	for(int i=0;i<n+1;i++)
	{
		p[i]=path[i];
		v[i]=visited[i];
	}

	if(p[c-1] == s && c!=1)
	{
		if(dist<=min)
		{
			min = dist;
			if(print)
			{
				for(int i=0;i<c;i++)
					printf("%d ",p[i]);
				printf("\n");
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		if(g[src][i]>0 && !v[i])
		{
			p[c]=i;
			dfs(g,v,s,i,p,c+1,dist+g[src][i],print);
		}
	}
}

void main()
{
	scanf("%d",&n);
	int g[n][n];
	int *a,*b,*p;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	}
	
	for(int i=0;i<n;i++)
	{
		a=(int*)calloc(n+1,sizeof(int*));
		b=(int*)calloc(n+1,sizeof(int*));
		b[0]=i;
		dfs(g,a,i,i,b,1,0,false);	
	}
	printf("%d\n",min);

	for(int i=0;i<n;i++)
	{
		a=(int*)calloc(n+1,sizeof(int*));
		b=(int*)calloc(n+1,sizeof(int*));
		b[0]=i;
		dfs(g,a,i,i,b,1,0,true);
		for(int j=0;j<n;j++)
		{
			g[i][j]=0;
			g[j][i]=0;
		}
	}
}

