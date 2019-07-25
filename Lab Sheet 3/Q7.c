#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char str[100];
	scanf("%s", &str);
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]>='x')
			str[i]-=23;
		else
			str[i]+=3;
		printf("%c", str[i]);
	}
}