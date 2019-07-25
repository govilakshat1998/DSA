#include<stdio.h>
#include<stdlib.h>
#define mini -10000000

int main()
{
	int k,W,N;
	scanf("%d %d %d",&k, &W , &N);
	int p[N];
	int c[N];
	for (int i = 0; i < N; ++i)
		scanf("%d",&p[i]);
	
	for (int i = 0; i < N; ++i)
		scanf("%d",&c[i]);
	

	for (int i = 0; i < k; ++i) 
	{
      int best_j = -1;
      int best_profit = 0;
      for (int j = 0; j < N; ++j) 
      {
        if (c[j] <= W && p[j] > best_profit) 
        {
          best_j = j;
          best_profit = p[j];
        }
      }
      if (best_profit == 0) 
      	break;
      W += p[best_j];
      p[best_j] = mini;
    }
    printf("%d\n",W);
}