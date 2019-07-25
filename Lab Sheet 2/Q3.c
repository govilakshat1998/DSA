#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int q[1000];
int front = 0, rear = 0;
int n;

void push(int x)
{
	q[rear++] = x;
}

int pop()
{
	return q[front++];
}

bool Bipartite(int g[n][n])
{
	int source = 0;
	int colour[n];
	for(int i=0;i<n;i++)
		colour[i] = -1;
	colour[source] = 1;
	push(source);

	while(front<rear)
	{
		int val = pop();
		if(val == -1)
			break;
		else
		{
			if(g[val][val] == 1)
				return false;
			for(int i=0;i<n;i++)
			{
				if(g[val][i] == 1 && colour[i] == -1)
				{
					colour[i] = 1 - colour[val];
					push(i);
				}
				else if(g[val][i] == 1 && colour[val] == colour[i])
					return false;
			}

		}
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	int g[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d", &g[i][j]);
		}
	}

	if(Bipartite(g))
		printf("Bipartite\n");
	else
		printf("Not Bipartite\n");
}