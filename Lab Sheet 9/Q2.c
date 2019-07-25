#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
    return a>=b?a:b;
}

int maxidx(int B[] ,int m ,int res)
{
    int lo = 0;
    int hi = m+1;
    int mid;
    while(lo<hi)
    {
        mid = (lo+hi)/2;
        if(lo==mid)
        	break;
        if(B[mid]>res) 
        	hi = mid-1;
        else 
        	lo=mid;
    } 
    if(B[hi]<=res && hi<=m)
    	lo = max(lo,hi);
    return lo;
}

int main()
{
    int n,m,x,ans=0;
    scanf("%d %d %d",&n,&m,&x);
    int A[n+1];
    int B[m+1];
    B[0]=0;A[0]=0;
    for(int i=1; i <= n ; ++i)
    {
        scanf("%d",&A[i]);
        A[i] += A[i-1];
    }
    for(int i=1; i <= m ; ++i)
    {
        scanf("%d",&B[i]);
        B[i] += B[i-1];
    }
    for(int i=1;i<=n ; ++i)
    {
        if(A[i]>x)
        	break;
        int res = x-A[i];
        ans = max(ans, i+maxidx(B,m,res));
    }
    printf("%d\n", ans); 
}