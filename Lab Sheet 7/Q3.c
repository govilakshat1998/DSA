#include<stdio.h>
#include<stdlib.h>

int a[10000];
int vis[10000];

int main()
{
	int n;
	scanf("%d",&n);
	int t,m,j=0,pos=-1,ans=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]==i) 
			pos=i;
	}

    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=0)
            continue;
        int u=i;
        j++;
        vis[u]=j;
        while(vis[a[u]]==0)
        {
            u=a[u];
            vis[u]=j;
        }
        if(vis[a[u]]==j)
        {
            if(pos==-1)
                pos=u;
            if(a[u]!=pos)
            {
                ans++;
                a[u]=pos;
            }
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
}
