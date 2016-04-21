#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 50009
using namespace std;
typedef long long i64;
int flag[MAX>>6],prime[MAX>>2],len;
void criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2){
		if(!ifc(i))
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
	}
	prime[(k=0)++]=2;
	for(i=3;i<(MAX);i+=(i%6==1)?4:2){
		if(!ifc(i))
			prime[k++]=i;
	}
	len=k;
}
int phi(int N){
	int ans=N;
	for(int i=0;prime[i]*prime[i]<=N && i<len;i++){
		if(N%prime[i]==0)ans-=ans/prime[i];
			while(N%prime[i]==0)N/=prime[i];
	}
	if(N>1)ans-=ans/N;
	return ans;
}
i64 dp[MAX],N;
void solve(){
	dp[1]=1;
	for(int i=2;i<MAX;i++)
		dp[i]=dp[i-1]+2*phi(i);
}
int main()
{
	 criba();
	 solve();
	 while(scanf("%d",&N),N){
		 printf("%lld\n",dp[N]);
	 }
	return 0;
}
