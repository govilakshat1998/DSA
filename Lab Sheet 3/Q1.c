#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool check(char t[], char p[], int n)
{
	int v = 0;
	for(int i=0;i<n;i++)
	{
		if(t[i] == p[v])
			v++;
	}
	if(p[v] == '\0')
		return true;
	else
		return false;
}

int main()
{
	char t[1000], p[1000];
	scanf("%s", &t);
	scanf("%s", &p);

	int n;
	scanf("%d", &n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);

	bool ok;
	int i;
	for(i=0;i<n;i++)
	{
		t[a[i]-1] = ' ';
		ok = check(t, p, n);
		if(!ok)
			break;
	}
	printf("%d\n", i);
}