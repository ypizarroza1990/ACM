#include <bits/stdc++.h>
#define MAX 10001
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
vector<int>coins;
i64 ans[10001];
void solve(){
	ans[0] = 1;
	for(int i=21;i>=0;i--){
		int val = coins[i];
		for(int j=val;j<MAX;j++)
			ans[j] += (ans[j-val]);
	}
}
int n;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<22;i++)
		coins.push_back(i*i*i);
	solve();
	while(cin>>n){
		cout<<ans[n]/2<<'\n';
	}
	return 0;
}
 
