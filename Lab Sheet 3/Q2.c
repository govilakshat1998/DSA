#include<stdio.h>
#include<stdlib.h>

int main()
{
	char str[1000];
	scanf("%s", str);
	
	int m;
	scanf("%d", &m);
	while(m--)
	{
		int f, r, k;
		scanf("%d %d %d", &f, &r, &k);
		f--;
		r--;
		k = k%(r-f+1);
		char temp[k];

		for(int i=k-1;i>=0;i--)
			temp[k-1-i] = str[r-i];

		for(int i=r-k;i>=f;i--)
			str[i+k] = str[i];
		
		for(int i=0;i<k;i++)
			str[f+i] = temp[i];
	}
	printf("%s", str);
}