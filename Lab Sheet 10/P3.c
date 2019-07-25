#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int n,*minh,*maxh,*a;
int size_max=0,size_min=0;

void insert_min(int k);
void insert_max(int k);
void maxheap(int i);
void minheap(int i);
void remove_min();
void remove_max();


int left(int i)
{
	return 2*i;
}
int right(int i)
{
	return 2*i+1;
}
int parent(int i)
{
	return i/2;
}

void main()
{
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int*));
	minh=(int*)calloc(n+1,sizeof(int*));
	maxh=(int*)calloc(n+1,sizeof(int*));
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int i=0;
	double median=0;
	while(i<n)
	{
		if(size_min<size_max)
		{
			if(a[i]>median)
			{
				insert_min(a[i]);
			}
			else
			{
				insert_min(maxh[1]);
				remove_max();
				insert_max(a[i]);
			}
			median=(maxh[1]+minh[1])/2;
		}
		else if(size_min>size_max)
		{
			if(a[i]>median)
			{
				insert_max(minh[1]);
				remove_min();
				insert_min(a[i]);
			}
			else
			{
				insert_max(a[i]);
			}
			median=(maxh[1]+minh[1])/2;
		}
		else
		{
			if(a[i]<median)
			{
				insert_max(a[i]);
				median=maxh[1];
			}
			else
			{
				insert_min(a[i]);
				median=minh[1];
			}
		}
		i++;
		printf("%f ",median);

	}

}
void insert_min(int k)
{
	minh[++size_min]=k;
	int i=size_min;
	while(minh[i]<minh[parent(i)] &&  i>1)
	{
		int t=minh[i];
		minh[i]=minh[parent(i)];
		minh[parent(i)]=t;
		i=parent(i);
	}
}
void insert_max(int k)
{
	maxh[++size_max]=k;
	int i=size_max;
	while(maxh[i]>maxh[parent(i)] && i>1)
	{
		int t=maxh[i];
		maxh[i]=maxh[parent(i)];
		maxh[parent(i)]=t;
		i=parent(i);
	}
}

void maxheap(int i)
{
	int l=left(i);
	int r=right(i);
	int largest=i;
	if(l<=size_max && maxh[i]<maxh[l])
		largest=l;
	if(r<=size_max && maxh[largest]<maxh[r])
		largest=r;
	if(largest!=i)
	{
		int t=maxh[largest];
		maxh[largest]=maxh[i];
		maxh[i]=t;
		maxheap(largest);
	}
}
void minheap(int i)
{
	int l=left(i);
	int r=right(i);
	int smallest=i;
	if(l<=size_max && minh[i]>minh[l])
		smallest=l;
	if(r<=size_max && minh[smallest]>minh[r])
		smallest=r;
	if(smallest!=i)
	{
		int t=minh[smallest];
		minh[smallest]=minh[i];
		minh[i]=t;
		minheap(smallest);
	}
}
void remove_min()
{
	minh[1]=minh[size_min--];
	minheap(1);
}
void remove_max()
{
	maxh[1]=maxh[size_min--];
	maxheap(1);
}