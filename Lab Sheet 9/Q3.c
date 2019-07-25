#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dp[1000001] = {};

int main()
{
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=2 ; i<=1000000 ; ++i)
    {
        if(dp[i]==-1 || dp[i] > dp[i-1] + 1) 
        	dp[i]= dp[i-1]+1;
        for(int j=1;j<=i && j*i < 1000001; ++j)
        {
            if(dp[i*j]==-1 || dp[i*j] > dp[i]+1)
            	dp[i*j] = dp[i] +1;
        }
    }

    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }

}