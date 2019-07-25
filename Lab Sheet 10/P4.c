#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int n;
void main()
{
	scanf("%d",&n);
	int a[n+1];
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

	int i=1;
	while(i<=n)
	{
		int l=i*2;
		int r=i*2+1;
		if(l<=n && a[l]<a[i])
		{
			printf("false\n");
			return;
		}
		if(r<=n && a[r]<a[i])
		{
			printf("false\n");
			return;
		}
		i++;
	}
	printf("true\n");
}