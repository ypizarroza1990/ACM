#include <iostream>
#include <algorithm>

using namespace std;
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAXN 2000009
#define endl '\n'
typedef long long int i64;
int flag[MAXN>>6],primes[MAXN>>2];
int primelen;
void criba(){
	int i,j,k;
	for(i=3;i*i<MAXN;i+=2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAXN;j+=k)
				isc(j);
		}
	}
	primes[(k=0)++]=2LL;
	for(i=3;i<MAXN;i+=2){
		if(!ifc(i)){
			primes[k++]=i;
		}
	}
	primelen=k-1;
}

i64 factpow(int N, int prime){
	i64 sum = 0;
	while(N){
		sum += N/prime;
		N /= prime;
	}
	return sum;
}

int count_factors(int N){
	int ans = 0;
	for(int i=0;primes[i]<=N && i<=primelen; i++){
		ans += factpow(N,primes[i]);
	}
	return ans;
}

int solve(int n){
	int lo = 1,hi = *upper_bound(primes,primes+primelen,2*n),mid;
	while(lo <= hi){
		mid = (lo + hi)>>1;
		if(n >= count_factors(mid))
			lo = mid +1;
		else
			hi = mid-1;
	}
	return lo;
}
int N,n;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	criba();
	cin>>N;
	while(N--){
		cin>>n;
		cout<<solve(n)<<endl;
	}
	return 0;
}
