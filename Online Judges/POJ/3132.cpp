#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include <stack>
#include <vector>
#define MAXN 1120
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
i64 DP[1129][15][188];
int flag[MAXN>>6],prime[MAXN>>2],len;
void criba(){
	int i,j,k;
	for( i=3;i<55;i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAXN;j+=k)
				isc(j);
		}
	}
	prime[(k=0)++]=2;
	for(i=3;i<(MAXN);i+=(i%6==1)?4:2){
		if(!ifc(i))
			prime[k++]=i;
	}
	len=k;
}
i64 solve(int n,int k,int p){
	if(n==0 && k==0)return 1;
	if(k==0)return 0;
	if(n<prime[p])return 0;
	if(p>=187)return 0;
	if(DP[n][k][p]!=-1)
		return DP[n][k][p];
	i64 res=solve(n-prime[p],k-1,p+1)+solve(n,k,p+1);
	DP[n][k][p]=res;
	return res;
}
int n,k;
int main(){
	criba();
	memset(DP,-1,sizeof(DP));
	while(scanf("%d %d",&n,&k),n+k){
		printf("%lld\n",solve(n,k,0));
	}
	return 0;
}



