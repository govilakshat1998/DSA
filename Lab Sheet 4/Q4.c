#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n,*height,*cost;
int min_cost=9999,no_towers,ans_height,total_height=0;

int calculate(int temp_cost,int h,int temp_height,int count);
void main()
{
	scanf("%d",&n);
	height=(int*)calloc(n,sizeof(int*));
	cost=(int*)calloc(n,sizeof(int*));
	for(int i=0;i<n;i++)
		scanf("%d",&height[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&cost[i]);
	for(int i=0;i<n;i++)
		total_height+=height[i];
	for(int i=1;i<=total_height;i++)
		calculate(0,0,i,0);
	printf("%d %d %d\n",min_cost,no_towers,ans_height);
}

int calculate(int temp_cost,int h,int temp_height,int count)
{
	if(count==n)
	{
		if(h!=0)
			return 0;
		else
		{
			if(temp_cost<min_cost)
			{
				min_cost=temp_cost;
				ans_height=temp_height;
				no_towers=total_height/ans_height;
				return 0;
			}
		}
	}
	else
	{
		if(height[count]>temp_height)
		{
			int temp=temp_cost+(height[count]-temp_height)*cost[count];
			calculate(temp,h+(height[count]-temp_height),temp_height,count+1);
		}
		else if(height[count]<temp_height)
		{
			int temp=temp_cost+height[count]*cost[count];
			calculate(temp,h+height[count],temp_height,count+1);
			temp=temp_cost+(temp_height-height[count])*cost[count];
			calculate(temp,h-(temp_height-height[count]),temp_height,count+1);
		}
		else if(height[count]==temp_height)
			calculate(temp_cost,h,temp_height,count+1);
	}
}
