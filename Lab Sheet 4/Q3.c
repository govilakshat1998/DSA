#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d",&n);

	int* a = (int*)calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	int* c = (int*)calloc(1000000,sizeof(int));
	for(int i=0;i<n;i++)
		c[a[i]]++;
	
	for(int i=0;i<1000000;i++)
	{
		if(c[i] == 1)
			printf("%d",i);
	}
}