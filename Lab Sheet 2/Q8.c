#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int *q;
int *visited;
int *dis;
int **a;
int front = 0, rear = 0;
void push(int);
int pop();
int bfs(int,int,int);

int main()
{
	int n,e;
	scanf("%d %d", &n, &e);
	visited = (int*)calloc(n,sizeof(int));
	dis = (int*)calloc(n,sizeof(int));
	a = (int **)calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
		a[i] = (int *)calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			a[i][j] = 0;
	}
	for(int i=0;i<e;i++)
	{
		int u,v;
		scanf("%d %d", &u, &v);
		a[u][v] = 1;
		a[v][u] = 1;
	}
	int t;
	scanf("%d", &t);
	int res = 0;
	for(int i=0;i<n;i++)
		res = res+bfs(i,n,t);
	printf("%d\n", res/2);
}

void push(int x)
{
	q[rear++] = x;
}

int pop()
{
	return q[front++];
}

int bfs(int val,int n,int t)
{
	int ct = 0;
	q = (int*)calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
	{
		dis[i] = 0;
		visited[i] = 0;
	}
	int v;
	push(val);
	visited[val] = 1;
	while(front<rear)
	{
		v = pop();
		for(int i=0;i<n;i++)
		{	
			if(a[v][i] == 1 && visited[i] == 0)
			{
				push(i);
				visited[i] = 1;
				dis[i] = dis[v] + 1;
			}
		}
	}
	// for(int i = 0;i<n;i++)
	// 	printf("%d ", dis[i]);
	// printf("\n");
	for(int i = 0;i<n;i++)
	{
		if(dis[i] == t)
			ct++;
	}
	return ct;
}
