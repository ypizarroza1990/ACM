#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 pow1[16],dp[16][140],A,B,min_val,S;
void fill(){
	pow1[0]=1;
	for(int i=1;i<16;i++)
		pow1[i]=pow1[i-1]*10;

	memset(dp,-1,sizeof(dp));
	min_val=-1;
}
i64 solve(i64 V,int k,int sum){

	if(sum<0)return 0;
	i64 low=V;
	i64 uper=V+pow1[k]-1;

	if(low>B || uper<A)
			return 0;
	if(k==0){
		if(sum>0)
			return 0;
		if(min_val==-1)min_val=V;
		return 1;
	}
	bool range(low>=A && uper<=B);

	if(range && dp[k][sum]!=-1)return dp[k][sum];

	i64 res=0;
	for(int i=0;i<10;i++){
		res+=solve(V+i*pow1[k-1],k-1,sum-i);
	}
	if(range)dp[k][sum]=res;
	return res;
}

int main(void){
	fill();
	cin>>A>>B>>S;
	cout<<solve(0,15,S)<<endl;
	cout<<min_val<<endl;
    return 0;
}
