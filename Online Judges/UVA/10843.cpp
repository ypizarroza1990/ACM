#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include <iostream>
using namespace std;
typedef long long i64;
#define power(x)((x)*(x))
#define MOD  2000000011
i64 modpow(int a,int b,i64 mod){
	if(b==0)
		return 1;
	if(b%2==0)return power(modpow(a,b/2,mod))%mod;
	return (a%mod*modpow(a,b-1,mod))%mod;
}
int cas,n;
i64 ans;
int main(){
	scanf("%d",&cas);
	for(int i=1;i<=cas;i++){
		scanf("%d",&n);
		if(n==1)
			ans=1;
		else
			ans=modpow(n,n-2,MOD);

		printf("Case #%d: %lld\n",i,ans);
	}
	return 0;
}

