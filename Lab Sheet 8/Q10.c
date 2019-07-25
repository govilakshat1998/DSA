#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int n,k,*a,ans=0;
void count();

void main()
{
	scanf("%d%d",&n,&k);
	a=(int*)calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
	{
		char c;
		scanf("%c",&c);
		if(c=='R')
			a[i]=1;
		else if(c=='Y')
			a[i]=2;
		else
			a[i]=0;
	}
	count();
	printf("%d\n",ans);
}

void count()
{
	int pos=0;
	while(pos<n)
	{
		if(a[pos]!=0)
		{
			int temp=3-a[pos];
			ans+=temp;
			for(int i=0;i<k;i++)
			{
				if((i+pos)==n)
					break;
				else
					a[pos+i]=(a[pos+i]+temp)%3;
			}
			printf("%d%d\n",temp,pos);
		}
		pos++;
	}
}