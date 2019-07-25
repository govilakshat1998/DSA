#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,m;
char a[100][100];
int ans = 0;

void dfs(int r, int c, char str[], int level, int t)
{
	if(level == t-1 && a[r][c]==str[t-1]) 
	{
		ans = 1;
		return;
	}
	if(a[r][c] != str[level]) 
		return;
	if(r+1<n) 
		dfs(r+1,c,str,level+1,t);
	if(c+1<m) 
		dfs(r,c+1,str,level+1,t);
	if(r-1>=0) 
		dfs(r-1,c,str,level+1,t);
	if(c-1>=0) 
		dfs(r,c-1,str,level+1,t);
}

int main()
{
	scanf("%d %d",&n,&m);
	char s[100];
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		strcpy(a[i],s);
	}
	int q;
	scanf("%d",&q);
	
	while(q--)
	{
		char str[100];
		scanf("%s",str);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				dfs(i,j,str,0,strlen(str));
		}
		if(ans) 
			printf("YES\n");
		else 
			printf("NO\n");
		ans = 0;
	}
}