#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s[100];
int ans[100][2];
int n;

int checkp(int l, int r)
{
	if(r-l==1 || r-l==0 || r>=n || r<=l) 
		return 0;
	while(l<r)
	{
		if(s[l]!=s[r]) 
			return 0;
		l++;
		r--;
	}
	return 1;
}

int max(int a ,int b)
{
	return (a>=b?a:b);
}

void substring(char s[], char tmp[], int l, int r)
{
	memset(tmp,'\0',strlen(tmp));
	int c = 0;
	while(l<=r)
		tmp[c++] = s[l++];
}

int main()
{
	scanf("%s",s);
	int l = strlen(s);
	n = l;
	int c = 0;
	for(int i=0;i<l;i++)
	{
		for(int j=i+1;j<l;j++)
		{
			if(s[j] >= s[j-1]) 
				continue;
			else if(checkp(i, i+2*(j-1-i)))
			{
				ans[c][0] = i;
				ans[c][1] = i+2*(j-1-i);
				c++;
			}
			else if(checkp(i, i+2*(j-1-i)-1))
			{
				ans[c][0] = i;
				ans[c][1] = i+2*(j-1-i)-1;
				c++;
			}
			else 
				break;
		}
	}

	int maxi = -1;
	int k = 0;
	char prev[100];
	char curr[100];
	memset(prev,'\0',strlen(prev));
	memset(curr,'\0',strlen(curr));
	for(int i=0;i<c;i++)
		maxi = max(maxi,ans[i][1]-ans[i][0]);

	if(c==0)
	{
		printf("-1");
		return 0;
	}

	// for(int i=0;i<c;i++)
	// 	for(int j=ans[i][0];j<=ans[i][1];j++)
	// 		printf("%c",s[j]);

	for(int i=0;i<c;i++)
	{
		if(ans[i][1]-ans[i][0] == maxi)
		{
			if(k<1) 
			{
				substring(s,prev,ans[i][0],ans[i][1]);
				k++;
				strcpy(curr,prev);
			}
			else
			{
				substring(s,prev,ans[i][0],ans[i][1]);
				if(strcmp(prev,curr)<0)
					strcpy(curr,prev);
			}
		}
	}
	for(int i=0;i<strlen(curr);i++)
	{
		if(curr[i]>=97 && curr[i]<=122)
			printf("%c",curr[i]);
	}
}