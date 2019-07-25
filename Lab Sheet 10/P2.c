#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int n,k,*a;
int max();
void main()
{
	scanf("%d%d",&n,&k);
	a=(int*)calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	while(k>0)
	{
		int m=max();
		ans+=a[m];
		a[m]=a[m]/2;
		k--;
	}
	printf("%d\n",ans);
}
int max()
{
	int m=-1,index=-1;
	for(int i=0;i<n;i++)
	{
		if(m<a[i])
		{
			m=a[i];
			index=i;
		}
	}
	return index;
}