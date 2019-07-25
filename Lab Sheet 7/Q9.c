#include<stdio.h>
#include<stdlib.h>

int a[1000];

int max(int a,int b)
{
	return a>=b?a:b;
}

int cmpfunc(int n1 ,int n2)
{
	int s1=0,s2=0,c=0;
	int d1[100],d2[100];
	while(n1>0) 
	{
		d1[s1++]= n1%10;
		n1/=10;
	}
	while(n2>0)
	{
		d2[s2++]= n2%10;
		n2/=10;
	}
	int i=s1-1, j=s2-1;
	int maxi = max(s1,s2);
	while(c<maxi)
	{
		if(d1[i]>d2[j]) 
			return 0;
		else if(d1[i]<d2[j]) 
			return 1;
		i--;
		j--;
		c++;
		if(i==-1) 
			i=s1-1;
		if(j==-1) 
			j =s2-1;
	}
	return 0;
}

void swap(int i,int j)
{
	int tmp = a[i]; 
	a[i] = a[j]; 
	a[j] = tmp;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	
	for(int i=0;i<n;++i)
	{
		int m = a[i];
		int m_idx = i;
		for(int j=i+1;j<n;++j)
		{
			if(cmpfunc(m,a[j])) 
			{
				m = a[j];
				m_idx = j;
			}
		}
		if(m_idx!=i) 
			swap(i,m_idx);	
	}

	for(int i=0;i<n;++i)
		printf("%d",a[i]);
}	