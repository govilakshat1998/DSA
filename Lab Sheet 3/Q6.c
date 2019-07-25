#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool ispalindrome(char str[])
{
	int* count = (int*) calloc(256,sizeof(int));
	for(int i=0;str[i];i++)
		count[str[i]]++;
	int odd = 0;
	for(int i=0;i<256;i++)
	{
		if(count[i] & 1)
			odd++;
		if(odd>1)
			return false;
	}
	return true;
}

int main()
{
	char str[10];
	scanf("%s", &str);
	if(ispalindrome(str))
		printf("YES");
	else
		printf("NO");
}