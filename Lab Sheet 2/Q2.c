#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int *q;
int *visited;
int **a;
int front = 0, rear = 0;
int dis[1000][1000];
int max = 0;
void push(int);
int pop();
void bfs(int, int, int);
void dfs(int, int, int, int[], int);

int main()
{
	int n,e;
	scanf("%d %d", &n, &e);
	visited = (int*)calloc(n,sizeof(int));
	a = (int **)calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
		a[i] = (int *)calloc(n,sizeof(int));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j] = 0;
			dis[i][j] = 0;
		}
	}

	for(int i=0;i<e;i++)
	{
		int u,v;
		scanf("%d %d", &u, &v);
		a[u][v] = 1;
		a[v][u] = 1;
	}

	for(int i=0;i<n;i++)
		bfs(i,i,n);
	
	int path[n];
	printf("Diameter - %d \n",max);
	for(int i=0;i<n;i++)
		dfs(max+1,i,n,path,0);
}

void push(int x)
{
	q[rear++] = x;
}

int pop()
{
	return q[front++];
}

void bfs(int curr,int src,int n)
{
	q = (int*)calloc(10*n,sizeof(int));
	for(int i=0;i<n;i++)
		visited[i] = 0;
	int v;
	push(src);
	visited[src] = 1;
	while(front<rear)
	{
		v = pop();
		for(int i=0;i<n;i++)
		{	
			if(a[v][i] == 1 && visited[i] == 0)
			{
				push(i);
				visited[i] = 1;
				dis[curr][i] = dis[curr][v] + 1;
			}
		}
	}

	// for(int i=0;i<n;i++)
	// 	printf("%d ", dis[curr][i]);
	// printf("\n");

	for(int i=0;i<n;i++)
	{
		if(dis[curr][i]>max)
			max = dis[curr][i];
	}
	printf("\n");
}

void dfs(int k, int curr, int n,int path[], int c)
{
	int p[n];
	for(int i=0;i<c;i++)
		p[i] = path[i];
	p[c++] = curr;
	k--;
	if(k<=0)
	{
		int start = p[0];
		int end = p[c-1];
		if(dis[start][end] == c-1)
		{
			for(int i=0;i<c;i++)
				printf("%d ", p[i]);
			printf("\n");
		}
		return;
	}

	for(int i=0;i<n;i++)
	{
		if(a[curr][i] == 1)
		{
			bool visited = false;
			for(int j=0;j<c;j++)
			{
				if(p[j] == i)
				{
					visited = true;
					break;
				}
			}
			if(!visited)
				dfs(k,i,n, p, c);
		}
	}
}