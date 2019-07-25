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

void sort(int a[],int n)
{
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]<a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main()
{
	int n,d;
	scanf("%d",&n);

	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,n);
	scanf("%d",&d);
	
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		int m = binarySearch(a,0,n-1,d+a[i]);
		if(m!=-1)
		{
			printf("%d",a[m]+a[i]);
			flag = 1;
			break;
		}
	}
	if(!flag)
		printf("-1");
}
