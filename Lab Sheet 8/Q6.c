#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int **a,min=99999,top=-1;
char* s;
void push(int t);
int pop();

void main()
{
	a=(int**)calloc(100,sizeof(int*));
	for(int i=0;i<100;i++)
		a[i]=(int*)calloc(2,sizeof(int*));
	s=(char*)calloc(4,sizeof(int*));
	while(s[0]!='e')
	{
		scanf("%s",s);
		if(s[0]=='p' && s[1]=='u')
		{
			int a;
			scanf("%d",&a);
			push(a);
		}
		else if(s[0]=='p' && s[1]=='o')
		{
			if(top==-1)
			{
				printf("stack empty\n");
				min=9999;
			}
			
			{
				printf("\n%d\n",pop());
				if(top!=-1)
					min=a[top][1];
			}
		}
		else if(s[0]=='m')
		{
			printf("\n%d\n",a[top][1]);
		}
		for(int i=0;i<=top;i++)
			printf("%d %d\n",a[i][0],a[i][1]);
	}
}

void push(int t)
{
	a[++top][0]=t;
	if(min>t)
	{
		a[top][1]=t;
		min=t;
	}
	else
		a[top][1]=min;
}

int pop()
{
	return a[top--][0];
}
