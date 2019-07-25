#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int* neighbours;
	int deg;
} Node;

void dfs(Node* nodes, int N, int curr, bool* visited)
{
	if(visited[curr])
		return;

	visited[curr] = true;
	for(int i=0;i<nodes[curr].deg;i++)
	{
		int adj = nodes[curr].neighbours[i];
		if(!visited[adj])
			dfs(nodes, N, adj, visited);
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

	bool* reachable = calloc(N, sizeof(bool));
	bool exists = false;

	for(int i=0;i<N;i++)
	{
		bool* visited = calloc(N, sizeof(bool));
		dfs(nodes, N, i, visited);
		int count = 0;
		for(int j=0;j<N;j++)
			count += visited[j];
		if(count == N)
		{
			reachable[i] = true;
			exists = true;
		}
	}

	if(exists)
	{
		printf("Yes.\n");
		for(int i=0;i<N;i++)
		{
			if(reachable[i])
				printf("%d ", i+1);
		}
		printf("\n");
	}	
	else
		printf("No such vertex exists.\n");
}
