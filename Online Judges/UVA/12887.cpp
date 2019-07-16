#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define LL long long
#define MOD 1000000007
const int MAXN = 5001;
LL catalan[MAXN];
LL mpow(LL a, LL b, LL mod){
	LL ans = 1LL;
	while(b){
		if(b&1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

LL invmul(LL n,LL mod){
	return mpow(n, mod-2, mod);
}

LL dp(int n){
	if(n <= 0)
		return 1LL;
	if(catalan[n] != -1)
		return catalan[n];
	LL ans =  ((2LL * (2LL*n - 1)) % MOD * dp(n-1)) % MOD;
	return catalan[n] = (ans * invmul(n + 1, MOD)) % MOD;
}
int cas;
LL n;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	memset(catalan,-1, sizeof(catalan));
	cin>>cas;
	while(cas--){
		cin>>n;
		cout<<dp(n)<<endl;
	}

	return 0;
}