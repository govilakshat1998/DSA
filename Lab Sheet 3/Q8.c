#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int* neighbours;
	int deg;
} Node;

void dfs(Node* nodes, int N, int source, int curr, bool* visited, bool** reachable)
{
	if(visited[curr])
		return;

	visited[curr] = true;
	reachable[source][curr] = true;

	for(int i=0;i<nodes[curr].deg;i++)
	{
		int adj = nodes[curr].neighbours[i];
		if(!visited[adj])
			dfs(nodes, N, source, adj, visited, reachable);
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	Node* nodes = calloc(N, sizeof(Node));
	for(int i=0;i<N;i++)
	{
		nodes[i].neighbours = calloc(N, sizeof(int));
		nodes[i].deg = 0;
	}

	for(int i=0;i<M;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		nodes[a-1].neighbours[nodes[a-1].deg++] = b-1;
	}

	bool** reachable = calloc(N, sizeof(bool*));
	for(int i=0;i<N;i++)
		reachable[i] = calloc(N, sizeof(bool));

	for(int i=0;i<N;i++)
	{
		bool* visited = calloc(N, sizeof(bool));
		dfs(nodes, N, i, i, visited, reachable);
	}

	int t;
	scanf("%d", &t);
	while(t--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(reachable[x-1][y-1])
			printf("Yes.\n");
		else
			printf("No.\n");
	}	
}