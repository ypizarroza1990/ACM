#include <bits/stdc++.h>
#define FOR(i,N)for(int i= 0;i<=N;i++)
#define FAB(i,A,B)for(int i=A;i<=B;i++)
#define MAXN 524288
using namespace std;
#define ll long long
typedef vector<ll>VL;
#define lowbit(x) (((x) ^ (x-1)) & (x))
typedef complex<long double> Complex;

void FFT(vector<Complex> &A, int s){
	int n = A.size();
	int p = __builtin_ctz(n);

	vector<Complex> a = A;

	for(int i = 0;i<n;++i){
		int rev = 0;
		for(int j = 0;j<p;++j){
			rev <<= 1;
			rev |= ((i >> j) & 1);
		}
		A[i] = a[rev];
	}

	Complex w,wn;

	for(int i = 1;i<=p;++i){
		int M = (1<<i), K = (M>>1);
		wn = Complex(cos(s*2.0*M_PI/(double)M), sin(s*2.0*M_PI/(double)M));

		for(int j = 0;j<n;j += M){
			w = Complex(1.0, 0.0);
			for(int l = j;l<K+j;++l){
				Complex t = w;
				t *= A[l + K];
				Complex u = A[l];
				A[l] += t;
				u -= t;
				A[l + K] = u;
				w *= wn;
			}
		}
	}

	if(s==-1){
		for(int i = 0;i<n;++i)
			A[i] /= (double)n;
	}
}

vector<Complex> FFT_Multiply(vector<Complex> P){
	int n = P.size();
	while(n!=lowbit(n)) n += lowbit(n);

	P.resize(n,Complex(0,0));

	FFT(P,1);

	vector<Complex> R;
	for(int i=0;i<n;i++) R.push_back(P[i]*P[i]);

	FFT(R,-1);

	return R;
}
vector<Complex> P,ans;
int cas,n,q,x;
int main() {

	//freopen("in.in","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n){
		P.clear();
		P.resize(MAXN,Complex(0,0));

		P[0]=Complex(1,0);
		for(int i=0;i<n;i++){
			cin>>x;
			P[x]=Complex(1,0);
		}
		ans = FFT_Multiply(P);
		int sol = 0;
		cin>>q;
		while(q--){
			cin>>x;
			if(real(ans[x])>0.5)
				sol++;
		}
		cout<<sol<<"\n";
	}
	return 0;

}
