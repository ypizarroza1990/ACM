#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 1120
using namespace std;
typedef long long i64;
int c[10],pow_ten[6];
void count(int x){
	int *cnt=c,d,dcnt=0,r=0,rem0=0,v;
	while(x){
		 d=x%10;x/=10;
		if(dcnt){
			v=d*pow_ten[dcnt-1]*dcnt;
			for(int i=0;i<10;i++)cnt[i]+=v;
			if(!d)rem0+=pow_ten[dcnt]-1-r;
		}
		v=pow_ten[dcnt];
		for(int i=1;i<d;i++)cnt[i]+=v;
		if(d)cnt[d]+=r+1;
		r=pow_ten[dcnt++]*d+r;
	}
	cnt[0]-=rem0;
}
int main()
{
	  int cas,n;
	  scanf("%d",&cas);
	  pow_ten[0]=1;
	  for(int i=1;i<6;i++)pow_ten[i]=10*pow_ten[i-1];
	  while(cas--){
		  for(int i=0;i<10;i++)c[i]=0;
		  scanf("%d",&n);
		  count(n);
		  for(int i=0;i<10;i++){
			  if(i)putchar(' ');
			  printf("%d",c[i]);
		  }
		  putchar('\n');
	  }
}

