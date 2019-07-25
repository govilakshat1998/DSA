#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

void encode(char [],int);
void decode(char [],int);
char* reverse(char [],int);

int main() 
{ 
   char str[255];
   printf("enter string to encode/decode \n"); 
   scanf("%[^\n]s",str);
   int l = 0;
   while(str[l]!=0)
   	l++;
   printf("Encoded String \n"); 
   encode(str,l);
   printf("Decoded String \n"); 
   decode(str,l);
} 

void encode(char str[],int l)
{
	int c = 0;
	for(int i=0;i<l;i++)
	{
		if(str[i] != ' ')
		{
			if(c%2==0)
				str[i]+=3;
			c++;
		}
		else
			continue;
	}

	printf("%s \n",reverse(str,l));
}

void decode(char str[],int l)
{
	char* ans = (char*) calloc(l, sizeof(char));
	ans = reverse(str,l);
	int c = 0;
	for(int i=0;i<l;i++)
	{
		if(ans[i] != ' ')
		{
			if(c%2==0)
				ans[i]-=3;
			c++;
		}
		else
			continue;
	}
	printf("%s",ans);
}

char* reverse(char str[],int l)
{
	int c1 = 0;int c2 = 0;int i = 0;int p = 0;
	char* a = (char*) calloc(l, sizeof(char)); 
	while(str[i]!=0)
	{
		if(str[i]==' ')
		{
			c2 = i;
			for(int j=c2-1;j>=c1;j--)
				a[p++] = str[j];
			a[p++] = ' ';
			c1 = c2+1;
		}
		i++;
	}
	for(int k=l-1;k>=c1;k--)
			a[p++] = str[k];
	return a;
}
