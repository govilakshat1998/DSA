#include<stdio.h>
#include<stdlib.h>

int truckTour(int pp[][2],int n) 
{
    int ans=0;
    int p=0;
    for(int i=0;i < n ; ++i)
    {
        p+= pp[i][0];
        int d = pp[i][1];
        if(p>=d) 
        	p-=d;
        else
        {
            ans = i+1;
            p=0;
        }
    }
    return ans;
} 

int main()
{
    int n;
    scanf("%d",&n);
    int pp[n][2];
    for(int i=0 ; i < n ;++i)
        scanf("%d %d",&pp[i][0], &pp[i][1]);
    
    printf("%d\n",truckTour(pp,n) );
}