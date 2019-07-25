#include <stdio.h>
#include <string.h>

int main()
{
	char str[50];
	scanf("%[^\n]s",str);
	printf("%d",strlen(str));
}