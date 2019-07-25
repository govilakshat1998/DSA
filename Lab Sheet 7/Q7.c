#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void* a, const void*b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int b[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	int store[n][2];
	int c=0;
	int ans=0;
	qsort(b,n,sizeof(int),cmpfunc);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(a[i]==b[j])
			{
				store[c][0]=i;
				store[c][1]=j;
				c++;
			}
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(store[i][1]>store[j][1])
				ans++;
		}
	}
	printf("%d\n",ans);
}