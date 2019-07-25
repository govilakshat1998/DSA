#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int n,**a,ans=99999;
void calc(int v[n][n],int i,int j,int time,int h);

void main()
{
	scanf("%d",&n);
	int v[n][n];
	a=(int**)calloc(n,sizeof(int**));
	for(int i=0;i<n;i++)
	{
		a[i]=(int*)calloc(n,sizeof(int*));
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			v[i][j]=0;
		}
	}

	calc(v,0,0,0,a[0][0]);
	printf("%d\n",ans+a[0][0]);
}

void calc(int v[n][n],int i,int j,int time,int h)
{
	int vis[n][n];
	for(int k=0;k<n;k++)
	{
		for(int l=0;l<n;l++)
			vis[l][k]=v[l][k];
	}
	vis[i][j]=1;
	if(i==n-1 && j==n-1)
	{
		if(time<ans)
			ans=time;
	}
	else
	{
		if(i!=0 && !vis[i-1][j])
		{
			if(h>a[i-1][j])
				calc(vis,i-1,j,time,h);
			else
				calc(vis,i-1,j,time+a[i-1][j]-h,a[i-1][j]);
		}

		if(i!=n-1 && !vis[i+1][j])
		{
			if(h>a[i+1][j])
				calc(vis,i+1,j,time,h);
			else
				calc(vis,i+1,j,time+a[i+1][j]-h,a[i+1][j]);
		}

		if(j!=0 && !vis[i][j-1])
		{
			if(h>a[i][j-1])
				calc(vis,i,j-1,time,h);
			else
				calc(vis,i,j-1,time+a[i][j-1]-h,a[i][j-1]);
		}

		if(j!=n-1 && !vis[i][j+1])
		{
			if(h>a[i][j+1])
				calc(vis,i,j+1,time,h);
			else
				calc(vis,i,j+1,time+a[i][j+1]-h,a[i][j+1]);
		}
	}
}
