#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 10000
using namespace std;
int dp[100009],N,K;
int main() {

	 cin>>N>>K;
	 for(int i=0;i<=N;i++)
		 if(i<=K)
			 dp[i]=i+1;
		 else
			 dp[i]=(dp[i-1]+dp[i-K-1])%5000011;
	 cout<<dp[N]<<endl;
	return 0;
}

