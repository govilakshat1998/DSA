#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int q[1000];
int visited[1000];
int n;
int front = 0, rear = 0;
int dis[1000];

void push(int x)
{
	q[rear++] = x;
}

int pop()
{
	return q[front++];
}

void bfs(int curr,int a[n][n],int n)
{
	push(curr);
	visited[curr] = 1;
	while(front<rear)
	{
		curr = pop();
		for(int i=0;i<n;i++)
		{	
			if(a[curr][i] == 1 && visited[i] == 0)
			{
				push(i);
				visited[i] = 1;
				dis[i] = dis[curr] + 1;
			}
		}
	}
	printf("\n");
}

int main()
{
	scanf("%d", &n);
	int a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			a[i][j] = 0;
	}
	
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d %d", &u, &v);
		a[u][v] = 1;
		a[v][u] = 1;
	}
	
	int m;
	scanf("%d", &m);
	int cities[m];
	for(int i=0;i<n;i++)
		cities[i] = 0;
	
	for(int i=0;i<m;i++)
	{
		int val;
		scanf("%d", &val);
		cities[val] = 1; 
	}
	
	for(int i=0;i<n;i++)
	{
		visited[i] = 0;
		dis[i] = 0;
	}

	bfs(0,a,n);
	int min = n;
	int city = 1;
	for(int i=0;i<n;i++)
		printf("%d\n", cities[i]);
	
	for(int i=1;i<n;i++)
	{
		if(cities[i]==1 &&  dis[i]<min)
		{
			min = dis[i];
			city = i;
		}
	}
	printf("%d", city);
}