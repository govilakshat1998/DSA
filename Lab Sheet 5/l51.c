#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[211] = {};

void fill(int l , int r, int c){
	for(int i=l;i<=r;++i){
		a[i] =c;
	}
}
int check(int l, int r , int c){
	int ct = 0;
	int it = 0;
	for(int i=l;i<=r;++i){
		if(a[i]==-1) ct=1;
		if(a[i]==1) it=1;
	}
	if(ct==1 && it==1){
		return -2;
	}
	for(int i=l;i<=r;++i){
		if(a[i]==c) return -1;
	}
	return 0;
}

int main(){
	int t;
	scanf("%d",&t);
	int ca = 0; // -1
	int im = 0; // 1
	int l,r;
	int n;
	char s[205][2];
	while(t--){
		scanf("%d",&n);
		int c =0;
		ca =0;
		im =0;
		memset(a,0,sizeof(a));
		int n1 =n;
		while(n1--){

			scanf("%d %d", &l ,&r);
			if(check(l,r,1)==-2){
				printf("-1\n");
				break;
			}
			if(ca>=im){
				if(check(l,r,-1)==-1){
					ca++;
					strcpy(s[c],"CA");
					fill(l,r,-1);
				}
				else{
					im++;
					strcpy(s[c],"IM");
					fill(l,r,1);
				}
			}
			else{
				if(check(l,r,1)==-1){
					im++;
					strcpy(s[c],"IM");
					fill(l,r,1);
				}
				else{
					ca++;
					strcpy(s[c],"CA");
					fill(l,r,-1);
				}
			}
			c++;
		}
		if(check(l,r,1)==-2) continue;
		if(abs(ca-im)==n){
			printf("-1\n");
			continue;
		}
		
		for(int i=0;i<n;++i){
			printf("%c%c ",s[i][0],s[i][1]);
		}

		printf("\n");
	}
}