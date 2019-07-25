#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

// int binarySearch(int arr[], int l, int r, int x) 
// { 
//     if (r >= l) 
//     { 
//         int mid = l + (r - l) / 2; 
//         if (arr[mid] == x) 
//             return mid;  
//         if (arr[mid] > x) 
//             return binarySearch(arr, l, mid - 1, x); 

//         return binarySearch(arr, mid + 1, r, x); 
//     } 
//     return -1; 
// } 

// int main()
// {
// 	int n,k;
// 	scanf("%d",&n);
// 	int a[n];
// 	for(int i=0;i<n;i++)
// 		scanf("%d",&a[i]);
// 	scanf("%d",&k);
// 	int m = binarySearch(a,0,n-1,k);
// 	if(m==-1)
// 	{
// 		for(int i=0;i<n;i++)
// 		{
// 			if(a[i]<k && k<a[i+1])
// 			{
// 				printf("Sasuke %d",i+2);
// 				break;
// 			}
// 		}
// 	}
// 	else
// 		printf("Naruto %d",m+1);
// }

int main()
{
	int n,k;
	scanf("%d",&n);

	int a[n],f = 0,l = n-1;
	for (int i = 0; i < n; ++i) 
		scanf("%d",&a[i]);
	scanf("%d",&k);

	int middle = (f + l)/2;
	while (f<=l)
	{
		if(a[middle] == k) 
		{
			printf("Naruto %d\n",middle+1);
			return 0;
		}
		if(k < a[middle]) 
			l = middle-1;
		if(k > a[middle]) 
			f = middle+1;
		middle = (f+l)/2;
	}

	printf("Sasuke %d\n",middle+2);
	return 0;
}