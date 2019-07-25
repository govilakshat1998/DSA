#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

int main()
{
	int n,k;
	scanf("%d %d", &n, &k);
	for(int v=1;;v++)
	{
		int j = v;
		int i = 1;
		int sum = 0;
		while(j!=0)
		{
			sum+=j;
			j = floor(v/pow(k,i));
			i++;
		}
		if(sum == n)
		{
			printf("%d",v);
			break;
		}
	}	
}