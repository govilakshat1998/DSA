#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

int main()
{
	int n,s;
	scanf("%d %d",&n,&s);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	int b[n],c[n],j = 0,k;
	for(k=1;k<=n;k++)
	{
		for(int i=0;i<n;i++)
			b[i] = a[i]+((i+1)*k);

		int sum = 0;
		for(int i=0;i<k;i++)
			sum+=b[i];

		c[j++] = sum;
	}

	int flag = 0;
	for(int i=0;i<n;i++)
	{
		if(c[i]>s)
		{
			printf("%d %d",i,c[i-1]);
			flag = 0;
			break;
		}
		else
			flag = 1;
	}
	if(flag)
		printf("%d %d",n,c[n-1]);
}