#include <bits/stdc++.h>
#define MAX 55100
using namespace std;
typedef long long i64;
int dp[MAX];
int N,H,p,c,ans;
int main ()
{
	cin>>N>>H;
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<N;i++){
		cin>>p>>c;
		for(int i=0;i<H;i++){
			if(dp[i]+c<dp[i+p])
				dp[i+p]=dp[i]+c;
		}
		ans=INT_MAX;
		for(int i=H;i<MAX;i++)
			ans=min(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
