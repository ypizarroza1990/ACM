#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAXN 1000009
#define LIMIT i64(1e12)
#define endl '\n'
typedef long long int i64;
int flag[MAXN>>6],primes[MAXN>>2];
int primelen;
vector<i64> almost;
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
int cas,lo,hi;
i64 a,b;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	criba();
	i64 tmp;
	for(int i=0;i<=primelen;i++){
		tmp = (i64(primes[i])*primes[i]);
		while(tmp <= LIMIT ){
			almost.push_back(tmp);
			tmp *= primes[i];
		}
	}
	sort(almost.begin(), almost.end());
	cin>>cas;
	while(cas--){
		cin>>a>>b;
		lo = lower_bound(almost.begin(), almost.end(),a)-almost.begin();
		hi = upper_bound(almost.begin(),almost.end(),b)-almost.begin();
		cout<<hi-lo<<endl;
	}
	return 0;
}