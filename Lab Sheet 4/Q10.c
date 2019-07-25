#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void search(int *arr, int low, int high) 
{  
	if (low > high) 
       return; 
    if (low == high) 
    { 
        printf("%d", arr[low]); 
        return; 
    } 

    int mid = (low+high)/2; 
    if (mid%2 == 0) 
    { 
        if (arr[mid] == arr[mid+1]) 
            search(arr, mid+2, high); 
        else
            search(arr, low, mid); 
    } 
    else 
    { 
        if (arr[mid] == arr[mid-1]) 
            search(arr, mid+1, high); 
        else
            search(arr, low, mid-1); 
    } 
} 

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	search(a,0,n-1);
}