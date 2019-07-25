#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define scan1(a) scanf("%d",&a)
#define scan2(b,c) scanf("%d %d", &b, &c)
#define scan4(d,e,f,g) scanf("%d %d %d %d", &d, &e, &f, &g)
#define print1(a) printf("%d", a)
#define loop(i,n) for(int i=0;i<n;i++)

int f[100];
int k, s, t;
int ans = 9999;
int va[100];	

void func(int c,int val,int time, int fuel,int pos)
{
	if(fuel<0 || pos>s || time>t || c > ans)
		return;
	if(s==pos && time<=t)
	{
		if(c<ans)
			ans = c;
		return;
	}
	else
	{
		if(va[pos] == 1)
			fuel = val;
		func(c,val,time+1,fuel-2,pos+1);
		func(c,val,time+2,fuel-1,pos+1);
	}
}	
int main()
{
	int n;
	scan4(n,k,s,t);
	int c[n],v[n];
	loop(i,n)
		scan2(c[i],v[i]);
	
	loop(i,k)
		scan1(f[i]);
	
	loop(i,s+1)
		va[i] = 0;

	for(int i=0;i<k;i++)
		va[f[i]] = 1;	
	
	loop(i,n)
		func(c[i],v[i],0,v[i],0);
	
	print1(ans);
}
		