#include <bits/stdc++.h>
#define MAX 100009
#define INF 100000000
using namespace std;
typedef long long i64;
int dp[MAX],cas,k;
void DP(){
	dp[0]=0;
	int monedas[]={6,5,3,1};
	for(int i=0;i<MAX;i++){
		for(int j=0;j<4;j++){
			int t=i+monedas[j];
			if(t>MAX)continue;
			dp[t]=min(dp[t],dp[i]+1);
		}
	}
}
int main() {
	 memset(dp,63,sizeof(dp));
	 scanf("%d",&cas);
	 DP();
	 for(int i=1;i<=cas;i++){
		 scanf("%d",&k);
		printf("Case %d: %d\n",i,dp[k]);
	 }
	return 0;
}
