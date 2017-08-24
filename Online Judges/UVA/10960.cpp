#include<bits/stdc++.h>
#define MAX 1000009
using namespace std;
int dp[MAX],mark[MAX];
void compute(){
	for(int i=0;i<MAX;i++)
		mark[i]=1;
	for(int i=2;i<MAX;i++){
		mark[i]++;
		for(int j=2*i;j<MAX;j+=i)
			mark[j]++;
	}
	dp[1]=1;
	for(int i=2;i<MAX;i++)
		if(mark[i]>=mark[dp[i-1]])
			dp[i]=i;
		else
			dp[i]=dp[i-1];

}
int cas,n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	compute();
	cin>>cas;
	while(cas--){
		cin>>n;
		cout<<dp[n]<<"\n";
	}
	return 0;
}
 
