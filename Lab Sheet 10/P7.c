#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int n,*a,ans=0;
void main()
{
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=a[j];
			if((sum*2)==(j-i+1) && j!=i)
			{
				ans++;
				printf("%d%d\n",i,j);
			}

		}
	}
	printf("%d\n",ans);
}