#include<stdio.h>
#include<stdlib.h>

// Struct for graph nodes
typedef struct node
{
	int* neighbours;
	int deg;
} Node;

// Misc
void fillArray(int[], int, int);

// Functions for Graph
void createGraph(Node*, int);
void addEdge(Node*, int, int);
void dfs(Node*, int, int, int, int, int, int**, int* , int*);


int main()
{
	int N;
	scanf("%d", &N);

	Node* nodes = calloc(N, sizeof(Node));
	createGraph(nodes, N);

	for(int i=0;i<N-1;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		addEdge(nodes, a-1, b-1);
	}

	int x, y;
	scanf("%d %d", &x, &y);
	x--;
	y--;

	int visited[N];
	int** r = calloc(N, sizeof(int*));
	for(int i=0;i<N;i++)
	{
		r[i] = calloc(N, sizeof(int));
		for(int j=0;j<N;j++)
		{
			r[i][j] = 0;
		}
	}

	int flag;
	for(int i=0;i<N;i++)
	{
		fillArray(visited, N, 0);
		flag = 0;
		dfs(nodes, N, i, x, y, i, r, visited, &flag); 
	}

	int count = 0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			count += r[i][j];
		}
	}
	printf("%d\n", count-N);
	return 0;
}

void createGraph(Node* nodes, int N)
{
	for(int i=0;i<N;i++)
	{
		nodes[i].neighbours = calloc(N, sizeof(int));
		nodes[i].deg = 0;
	}
}

void addEdge(Node* nodes, int x, int y)
{
	nodes[x].neighbours[nodes[x].deg++] = y;
	nodes[y].neighbours[nodes[y].deg++] = x;
}

void fillArray(int arr[], int N, int val)
{
	for(int i=0;i<N;i++)
	{
		arr[i] = val;
	}
}

void dfs(Node* nodes, int N, int source, int x, int y, int curr, int** r, int* visited, int* flag)
{
	if(visited[curr])
	{
		return;
	}
	visited[curr] = 1;
	if(curr == x)
	{
		*flag = 1;
	}
	else if(curr == y && (*flag) == 1)
	{
		return;
	}
	r[source][curr] = 1;
	for(int i=0;i<nodes[curr].deg;i++)
	{
		int adj = nodes[curr].neighbours[i];
		if(!visited[adj])
		{
			dfs(nodes, N, source, x, y, adj, r, visited, flag);
		}
	}
	if(curr == x)
	{
		*flag = 0;
	}
}
