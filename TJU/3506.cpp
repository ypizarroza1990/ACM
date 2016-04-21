//============================================================================
// Name        : Grundy_Cup.cpp
// Author      : BeCrazy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MOD 201004
using namespace std;
typedef long long i64;
int m_exp(int e,i64 &n){
	int ans=0;
	while(n%e==0){
		ans++;
		n/=e;
	}
	return ans;
}
i64 pw(i64 a,i64 b,i64 mod=MOD){
	 if(b==0)return 1;
	 if(b&1)return (a%MOD*pw(a,b-1)%MOD)%MOD;
	 return (pw(a,b/2)%MOD*pw(a,b/2)%MOD)%MOD;
}
i64 n,m,ans,x;
int main() {
	while(scanf("%lld %lld",&n,&m),n){
		ans=1;
		if(n%2==0){
		x=m_exp(2,n)*m;
			ans=pw(2,x-1);
		}
		for(int i=3;i*i<=n;i+=(i%6==1)?4:2){
			if(n%i==0){
				x=m_exp(i,n)*m;
				ans=((ans*pw(i,x-1)%MOD)*(i-1))%MOD;
			}
		}
		if(n>1){
			x=m-1;
			ans=((ans*pw(n,x)%MOD)*(n-1))%MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
