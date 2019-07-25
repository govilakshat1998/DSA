#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n,*a,k;
int findMiddle();
void findValue(int v,int m);
void main()
{
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);
	int middle=findMiddle();
	printf("%d\n",middle);
	findValue(k,middle);
}
int findMiddle()
{
	int l=0,h=n-1;
	int m=(l+h)/2;
	while(l<h)
	{
		if(a[m]>a[l])
			l=m+1;
		else if(a[m]<a[h])
			h=m;	
		m=(l+h)/2;
	}
	return m;
}
void findValue(int v,int m)
{
	int l,h;
	if(v>a[n-1])
	{
		l=0;
		h=m-1;
	}
	else
	{
		l=m;
		h=n-1;
	}
	while(a[m]!=v)
	{
		m=(l+h)/2;
		if(a[m]<v)
			l=m+1;
		else if(a[m]>v)
			h=m-1;
	}
	printf("%d\n",m+1);
}