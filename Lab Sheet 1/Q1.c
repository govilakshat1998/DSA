#include<stdio.h>

void saddle(int);

int main(void)
{
  int n;
  scanf("%d",&n); 
  saddle(n);
}

void saddle(int n)
{
	int mat[n][n],p,q;
	int arr[n];
	int arc[n];
	int l = 0;
	int m = 0;

	printf("Enter your matrix\n");  
	for(p=0;p<n;p++)
	{
		for(q=0;q<n;q++)
	  		scanf("%d",&mat[p][q]);  
	}
	printf("\n");

	for(int i=0;i<n;i++) 
	{
		int sad1 = mat[i][0];
		for(int j=0;j<n;j++)
		{
	  		if(mat[i][j]<sad1)
	  			sad1 = mat[i][j];
		}
		arr[l++] = sad1;
	}

	for(int i=0;i<n;i++) 
	{
		int sad2 = mat[0][i];
		for(int k=0;k<n;k++)
		{
	  		if(mat[k][i]>sad2)
	    		sad2 = mat[k][i];
		}
		arc[m++] = sad2;
	}

	int c=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i] == arc[j])
			{
				printf("[ %d %d %c",i,j,']');
				c = 1;
			}
		}
	}
	if(c==0)
		printf("No saddle point.");
	printf("\n");
}

