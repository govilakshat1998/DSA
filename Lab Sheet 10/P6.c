#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[1<<20]={};
int size=0;
int maxi = -1;
int mini = 1<<20;

int max(int a, int b){
	return a>=b?a:b;
}

int min(int a, int b){
	return a<=b?a:b;
}

void swap(int i,int j,int a[]){
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}


int main(){
	int q;
	scanf("%d",&q);
	int c=0;
	while(q--){
		char s[10];
		scanf("%s",s);
		int x;
		if(s[0]=='P'){
			scanf("%d",&x );
			maxi = max(maxi,x);
			mini = min(mini,x);
			a[c++] = x;
		}
		else if(s[0]=='D'){
			if(maxi==-1 || mini==1<<20) printf("-1\n");
			else{
				printf("%d\n", maxi-mini );
				int maxidx= -1;
				int minidx=-1;
				for(int i=0;i<c ; ++i){
					if(maxi==a[i])maxidx=i;
					if(mini==a[i])minidx = i;
				}
				if(maxidx==minidx)c=0;
				else{
					swap(maxidx,c-1,a);
					swap(minidx,c-2,a);
					c-=2;
				}
			}

		}
		else if(s[5]=='H'){
			if(c==0) printf("-1\n");
			int countmax=0;
			for(int i=0;i<c ; ++i){
				if(maxi==a[i])countmax++;
			}
			if(c!=0) printf("%d\n",countmax );
		}
		else{
			if(c==0) printf("-1\n");
			int countmin=0;
			for(int i=0;i<c ; ++i){
				if(mini==a[i])countmin++;
			}
			if(c!=0) printf("%d\n",countmin );
		}
	}	
}