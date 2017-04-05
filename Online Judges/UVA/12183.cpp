#include <bits/stdc++.h>
#define FOR(i,N)for(int i= 0;i<=N;i++)
#define FAB(i,A,B)for(int i=A;i<=B;i++)
using namespace std;
#define ll long long
typedef vector<ll>VL;
int N,cas;
ll MOD;
VL multiply(VL A,VL B){
	VL res(N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			res[i]=(res[i]+ A[j]* B[(i+N-j)%N])%MOD;
	return res;
}
VL MODPOW(VL A,ll K){
	VL res(N);
	res[0]=1;
	while(K){
		if(K&1)
			res = multiply(A,res);
		K>>=1;
		A = multiply(A,A);
	}
	return res;
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int S,L,R,X;
	cin >> cas;
	while(cas--){
		cin>>N>>S>>L>>R>>X;
		VL msg(N);
		for (int i=0 ; i<N ; i++)
			cin >> msg[i];
		MOD = (ll)pow(10,X);

		VL mat(N);
		mat[0] = 1;
		mat[1] = R;
		mat[N-1] = L;
		mat = MODPOW(mat, S);
		for (int i=0 ; i<N ; i++) {
			ll sum = 0;
			for (int j=0 ; j<N ; j++)
				sum = (sum + mat[(j+N-i)%N] * msg[j]) % MOD;
			cout << sum << (i<N-1 ? ' ' : '\n');
		}
	}
	return 0;

}

