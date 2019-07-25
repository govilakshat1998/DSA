#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}


int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1];
	a[0] = 0;
	int sum = 0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d", &a[i]);
		sum+=a[i];
	}

	qsort(a,n+1,sizeof(int),cmpfunc);
	int mr =0;
	int prev = 0;
	for(int i=1;i<=n;++i)
	{
		mr++;
		if(a[i]>prev)
			prev++;
	}
	mr += a[n]-prev;
	printf("%d",sum-mr);
}