#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int *a,*e,thresh,*t,n,time=0,*v,ans=0;
void calc();
int find(int i);

void main()
{
	scanf("%d %d",&n,&thresh);
	a=(int*)calloc(n,sizeof(int*));
	e=(int*)calloc(n,sizeof(int*));
	t=(int*)calloc(n,sizeof(int*));
	v=(int*)calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&e[i]);
		t[i]=e[i];
	}
	calc();
	printf("%f\n",(double)ans/n);
}

void calc()
{
	int i=0;
	while(true)
	{
		int index=find(i);
		//printf("%d",index);
		if(index==-1)
			time++;
		else if(index==-2)
			break;
		else
		{
			if(thresh>=t[index])
			{
				v[index]=1;
				time+=t[index];
				t[index]=0;
				ans+=time-e[index];
			}
			else
			{
				time+=thresh;
				t[index]-=thresh;
			}
		}
		i=(index+1)%n;
	}
}

int find(int i)
{
	int temp=i,count=0;
	while(count<n)
	{
		if(a[temp]<=time && !v[temp])
			return temp;
		temp=(temp+1)%n;
		count++;
	}
	for(int i=0;i<n;i++)
	{
		if(v[i]==0)
			return -1;
	}
	return -2;
}