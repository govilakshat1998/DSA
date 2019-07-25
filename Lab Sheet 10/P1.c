#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int n,*maxh,*a,*b,k,size=0;
int max();
void maxheapify(int i);
void r();
void main()
{
	scanf("%d%d",&n,&k);
	a=(int*)calloc(n,sizeof(int*));
	b=(int*)calloc(n,sizeof(int*));
	maxh=(int*)calloc(n*k+1,sizeof(int*));
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(int i=0;i<k;i++)
	{
		int t=max();
		for(int j=0;j<n;j++)
		{
			maxh[++size]=a[t]+b[j];
		}
		a[t]=-1;
	}
	for(int i=size/2;i>0;i--)
		maxheapify(i);
	for(int i=0;i<k;i++)
	{
		printf("%d\n",maxh[1]);
		r();
		for(int i=1;i<=size;i++)
			printf("%d ",maxh[i]);
		printf("\n");
	}

}
int max()
{
	int m=-1,index=-1;
	for(int i=0;i<n;i++)
	{
		if(a[i]>m)
		{
			m=a[i];
			index=i;
		}
	}
	return index;
}
void maxheapify(int i)
{
	int l=2*i;
	int r=2*i+1;
	int largest=i;
	if(l<=size && maxh[i]<maxh[l])
		largest=l;
	if(r<=size && maxh[r]>maxh[largest])
		largest=r;
	if(largest!=i)
	{
		int t=maxh[largest];
		maxh[largest]=maxh[i];
		maxh[i]=t;
		maxheapify(largest);
	}
}
void r()
{
	maxh[1]=maxh[size--];
	maxheapify(1);
}