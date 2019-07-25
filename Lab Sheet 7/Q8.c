#include<stdio.h>
#include<stdlib.h>

int check(int n)
{
	int digits[100];
	int c=0;
	while(n>0)
	{
		digits[c++]= n%10;
		n/=10;
	}
	for(int i=0;i<c-1;++i)
	{
		if(abs(digits[i]-digits[i+1])!=1) 
			return 0;
	}
	return 1;
}

int main()
{
	int n;	
	scanf("%d",&n);
	
	for(int i=0;i<n;++i)
	{
		if(check(i)) 
			printf("%d ",i);
	}
}