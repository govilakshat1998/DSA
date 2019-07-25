#include<stdio.h>

int a[100][1000] = {0};
int ans[1000][1000] = {0};
int p = 0;
int n, m, k;

void asc()
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<m;i++)
		{
			int temp = a[k][i];
			int ti, tj;
			for(int j=i;j<m;j++)
			{
				if(a[k][j]<a[k][i])
				{
					ti = i;
					tj = j;
					temp = a[k][j];
				}
			}
			if(temp!=a[k][i])
			{			
				temp = a[k][tj];
				a[k][tj] = a[k][ti];
				a[k][ti] = temp;
				if(ans[tj][ti] == 0)
					p++;
				ans[ti][tj] = 1;
			}
		}
	}
}

void desc()
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<m;i++)
		{
			int temp = a[k][i];
			int ti, tj;
			for(int j=i;j<m;j++)
			{
				if(a[k][j]>a[k][i])
				{
					ti = i;
					tj = j;
					temp = a[k][j];
				}
			}
			if(temp!=a[k][i])
			{
				temp = a[k][tj];
				a[k][tj] = a[k][ti];
				a[k][ti] = temp;
				if(ans[tj][ti] == 0)			
					p++;
				ans[tj][ti] = 1;
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			scanf("%d", &a[i][j]);
	}

	if(k==0)
		asc();
	else
		desc();

	printf("%d\n", p);

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(ans[i][j] == 1)
				printf("%d %d\n", i+1, j+1);
		}
	}
}