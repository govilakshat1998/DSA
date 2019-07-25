#include<stdio.h>
#include<stdlib.h>

int a[100];

int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

void check(int n)
{
	for(int j=1;j<=6;j++)
		a[j] = j;
	for(int i=7;i<=n;i++)
	{
		int val = max(3*a[i-4],4*a[i-5]);
		a[i] = max(2*a[i-3],val);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	check(n);
	printf("%d",a[n]);
}