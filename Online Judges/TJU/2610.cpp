//============================================================================
// Name        : 2610.cpp
// Author      : BeCrazy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 1120
using namespace std;
typedef long long i64;
int prime[MAX>>2],flag[MAX>>6],len;
int DP[MAX+9][15][188];
void criba(){
	int i,j,k;
	for(int i=3;i<40;i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
		}
	}
	prime[(k=0)++]=2;
	for(int i=3;i<MAX;i+=(i%6==1)?4:2){
		if(!ifc(i)){
			prime[k++]=i;
		}
	}
	len=k;
}
int solve(int n,int k,int m){
	if(n==0 && k==0)return 1;
	if(k==0)return 0;
	if(n<prime[m])return 0;
	if(m>=187)return 0;

	if(DP[n][k][m]!=-1)return DP[n][k][m];

	int t=solve(n-prime[m],k-1,m+1)+solve(n,k,m+1);

	DP[n][k][m]=t;

	return t;
}
int m,n;
int main() {
	criba();
	memset(DP,-1,sizeof(DP));
	while(scanf("%d %d",&n,&m),n+m){
		cout<<solve(n,m,0)<<endl;
	}
}
