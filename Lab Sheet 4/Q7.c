#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) 
    { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid;  
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 

        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
} 

int main()
{
	int n,k,t;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);

	for(int i=0;i<n;i++)
	{
		if(a[i]>a[i+1])
		{
			t = a[i];
			a[i] = a[i+1];
			a[i+1] = t;
			t = i;
			break;
		}
	}
	int flag = 0;
	if(k == a[t+1])
		printf("%d",t+1);
	else if(k == a[t])
		printf("%d",t+2);
	else
	{
		int m = binarySearch(a,0,n-1,k);
		if(m!=-1)
		{
			printf("%d",m+1);
			flag = 1;
		}
		if(!flag)
			printf("-1");
	}
}