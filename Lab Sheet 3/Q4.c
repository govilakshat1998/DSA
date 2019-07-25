#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int* neighbours;
	int deg;
} Node;

void fillArray(int arr[], int N, int val)
{
	for(int i=0;i<N;i++)
		arr[i] = val;
}

int subTreeCount(int node, int subtree[], int N)
{
	int count = 0;
	for(int i=0;i<N;i++)
	{
		if(subtree[i] == node)
			count++;
	}
	return count;
}

void dfs(Node* nodes, int N, int curr, int other, int subtree[], int* visited)
{
	if(visited[curr])
		return;

	visited[curr] = 1;
	if(curr == other)
		subtree[curr] = other;
	
	for(int i=0;i<nodes[curr].deg;i++)
	{
		int adj = nodes[curr].neighbours[i];
		if(!visited[adj])
		{
			subtree[adj] = subtree[curr];
			dfs(nodes, N, adj, other, subtree, visited);
		}
	}
}

int main()
{
	int N;
	int x, y;
	scanf("%d %d %d", &N, &x, &y);
	x--;
	y--;

	Node* nodes = calloc(N, sizeof(Node));
	for(int i=0;i<N;i++)
	{
		nodes[i].neighbours = calloc(N, sizeof(int));
		nodes[i].deg = 0;
	}

	for(int i=0;i<N-1;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		nodes[a-1].neighbours[nodes[a-1].deg++] = b-1;
		nodes[b-1].neighbours[nodes[b-1].deg++] = a-1;
	}

	int visited[N];
	int subtree[N];

	fillArray(subtree, N, -1);
	fillArray(visited, N, 0);
	dfs(nodes, N, y, x, subtree, visited);
	int xTree = subTreeCount(x, subtree, N);

	fillArray(subtree, N, -1);
	fillArray(visited, N, 0);
	dfs(nodes, N, x, y, subtree, visited);
	int yTree = subTreeCount(y, subtree, N);

	printf("%d\n", N*(N-1) - xTree*yTree);
}