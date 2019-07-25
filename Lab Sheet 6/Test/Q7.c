#include<stdio.h>
#include<stdlib.h>

int n,k,s,t;

int cmpfunc(const void *a, const void* b)
{
	return *(int*)a-*(int*)b ;
}

int check(int f, int g[])
{
	int time = 0;
	for(int i=0;i<k+1;i++)
	{
		int d = g[i+1]-g[i];
		if(d>f) 
			return 0;
		if(f>=2*d) 
			time += d;
		else 
			time += 2*d - (f-d);
	}
	if(time<=t) 
		return 1;

	return 0;
}
int min(int a,int b)
{
	return a<=b?a:b;
}

int main()
{
	scanf("%d %d %d %d",&n,&k,&s,&t);
	int car[n][2];
	int g[k+2];
	g[k] = 0;
	g[k+1] = s;

	for(int i=0;i<n;i++)
		scanf("%d %d",&car[i][0],&car[i][1]);

	for(int i=0;i<k;i++)
		scanf("%d",&g[i]);

	qsort(g,k+2,sizeof(int),cmpfunc);
	int lo = 1;
	int hi = 1e9+3;
	int mid;
	while(lo <= hi)
	{
		if(lo == hi)
			break;
		mid = (lo+hi)/2;
		if(check(mid,g)) 
			hi = mid;
		else 
			lo = mid+1;
	}
	//printf("%d\n",hi );
	int ans = 1e9+3;
	for(int i=0;i<n;i++)
	{
		if(car[i][1] >= hi) 
			ans = min(ans,car[i][0]);
	}
	if(ans==1e9+3)
	{
		printf("-1");
		return 0;
	}
	printf("%d\n",ans);
}