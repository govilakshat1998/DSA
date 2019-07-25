#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

// int main()
// {
// 	int n,m;
// 	scanf("%d %d", &n, &m);
	
// 	int a[n];
// 	for(int i=0;i<n;i++)
// 		scanf("%d",&a[i]);

// 	for(int v=0;;v++)
// 	{
// 		int sum = 0;
// 		for(int i=0;i<n;i++)
// 			sum+=v/a[i];
// 		if(sum == m)
// 		{
// 			printf("%d",v);
// 			break;
// 		}
// 	}
// }

int binary_search(int a[],int f,int l,int m,int n);
int noitems(int a[],int m,int n);

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n];
	for (int i = 0; i < n; ++i) 
		scanf("%d",&a[i]);
	printf("%d",binary_search(a,1,a[n-1]*m,m,n));
}

int binary_search(int a[],int l,int r,int m,int n)
{
	while(l<r)
	{
		int middle = (l+r)/2;
		int items = noitems(a,middle,n);
		if(items < m) 
			l = middle+1;
		else 
			r = middle;
	}
	return r;
}

int noitems(int a[],int m,int len)
{
	int sum=0;
	for (int i = 0; i < len; ++i) 
		sum+=m/a[i];
	return sum;
}