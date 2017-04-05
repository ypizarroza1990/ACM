#include<bits/stdc++.h>
#define MOD  1000000
#define i64 long long
using namespace std;
int dp[101][101];
int solve(int n,int k){
	if(k==1)
		return 1;

	if(dp[n][k]!=-1)
		return dp[n][k];

	int res = 0;

	for(int i=0;i<=n;i++)
		res = (res+solve(n-i,k-1))%MOD;
	return dp[n][k]=res;
}
int N,K;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp,-1,sizeof(dp));
	while(cin>>N>>K,N && K){
		cout<<solve(N,K)<<"\n";
	}
	return 0;
}

 
