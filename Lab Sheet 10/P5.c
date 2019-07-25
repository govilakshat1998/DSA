#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int n,*maxh,size=0;
void maxheapify(int i);
void main()
{
	scanf("%d",&n);
	size=n+1;
	maxh=(int*)calloc(n+1,sizeof(int*));
	for(int i=1;i<=n;i++)
		scanf("%d",&maxh[i]);
	for(int i=n/2;i>0;i--)
		maxheapify(i);
	for(int i=1;i<=n;i++)
		printf("%d ",maxh[i]);
	printf("\n");
}
void maxheapify(int i)
{
	int l=i*2;
	int r=i*2+1;
	int largest=i;
	if(l<=size && maxh[l]>maxh[i])
		largest=l;
	if(r<=size && maxh[r]>maxh[largest])
		largest=r;
	if(largest!=i)
	{
		int t=maxh[i];
		maxh[i]=maxh[largest];
		maxh[largest]=t;
		maxheapify(largest);
	}
}
