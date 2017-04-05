#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MOD 1000007
#define MAX 10000007
using namespace std;
typedef long long i64;
i64 GCD(i64 a,i64 b){
	while(b){
		a%=b;
		a^=b^=a^=b;
	}
	return a;
}
i64 comb(i64 n,i64 r){
	i64 i,j,g,k=(r>n-r)?r:n-r,m=n-k,lob=1,hob=1;
	for(i=k+1,j=m;i<=n&&j>0;i++,j--){
		lob*=i;
		hob*=j;
		g=GCD(lob,hob);
		lob/=g;
		hob/=g;
	}
	return lob;
}
int cas;
i64 n,m;
int main(){
	while(scanf("%lld%lld",&n,&m),n+m){
		printf("%lld\n",comb(n+m,m));
	}
}

