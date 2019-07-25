#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n,time = 0,sum = 0,*t,*s,*v;

int find()
{
    int min = 99999,index = 99999;
    for(int i=0;i<n;i++)
    {
        if(!v[i] && t[i]<=time && s[i]<min)
        {
            index = i;
            min = s[i];
        }
    }
    if(index == 99999)
        return 99999;
    else
        return index;
}

int main()
{
    scanf("%d",&n);
    t = (int*)calloc(n,sizeof(int*));
    s = (int*)calloc(n,sizeof(int*));
    v = (int*)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++)
        scanf("%d %d",&t[i],&s[i]);
    int count = n;
    while(count>0)
    {
        int index = find();
        if(index == 99999)
            time++;
        else
        {
            v[index] = 1;
            count--;
            time+=s[index];
            sum+=time-t[index];
        }
    }
    printf("%0.1f",(double)sum/n);
}

