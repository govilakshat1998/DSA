#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct 
{
	int beg;
	int length;
}gap;

void maxheapify(int i);
void insert(int b,int l);
void r();

int n,k,size=0,*ans;
char *p;
gap *h;
void main()
{
	scanf("%d%d",&n,&k);
	h=(gap*)calloc(n+1,sizeof(gap*));
	p=(char*)calloc(k,sizeof(char*));
	ans=(int*)calloc(n,sizeof(int*));
	scanf("%s",p);
	for(int i=(n+1)/2;i>0;i--)
	{
		maxheapify(i);
	}
	insert(0,n);
	gap t;
	for(int i=1;i<=k;i++)
	{
		t=h[1];
		r();
		if(t.length%2==0)
		{
			if(p[i-1]=='R')
			{
				insert(t.beg,t.length/2);
				insert(t.beg+t.length/2+1,t.length/2-1);
				ans[t.beg+t.length/2]=i;
			}
			else
			{
				insert(t.beg,t.length/2-1);
				insert(t.beg+t.length/2,t.length/2);
				ans[t.beg+t.length/2-1]=i;
			}
		}
		else
		{
			insert(t.beg,t.length/2);
			insert(t.beg+t.length/2+1,t.length/2);
			ans[t.beg+t.length/2]=i;
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);


}
void maxheapify(int i)
{
	int largest=i;
	int l=2*i;
	int r=2*i+1;
	if(l<=size)
	{
		if(h[l].length>h[i].length)
			largest=l;
		else if(h[l].length==h[i].length && h[l].beg<h[i].beg)
			largest=l;
	}
	if(r<=size)
	{
		if(h[r].length>h[largest].length)
			largest=r;
		else if(h[r].length==h[largest].length && h[r].beg<h[largest].beg)
			largest=r;
	}
	if(largest!=i)
	{
		gap t=h[largest];
		h[largest]=h[i];
		h[i]=t;
		maxheapify(largest);
	}
}
void insert(int b,int l)
{
	h[++size].beg=b;
	h[size].length=l;
	int i=size;
	while(h[i].length>h[i/2].length && i>1)
	{
		gap t=h[i];
		h[i]=h[i/2];
		h[i/2]=t;
		i=i/2;
	}
}
void r()
{
	h[1]=h[size--];
	maxheapify(1);
}