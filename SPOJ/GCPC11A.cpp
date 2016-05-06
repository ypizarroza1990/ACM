#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 1000009
using namespace std;
typedef long long i64;
typedef pair<i64,int>pi;
int flag[MAX>>6],prime[MAX>>1],len;
int cas;
void criba(){
	int i,j,k;
	for(i = 3;i*i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			for(j=i*i,k=(j<<1);j<MAX;j+=k)
				isc(j);
	prime[(k=0)++]=2;
	for(i=3;i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			prime[k++]=i;
	len = k;
}
vector<pi> factorize(i64 N){
	vector<pi>factors;
	for(i64 i=0;prime[i]*prime[i]<=N && i<len;i++){
		if(N%prime[i]==0){
			int c = 0;
			while(N%prime[i]==0){
				N/=prime[i];
				c++;
			}
			factors.push_back(make_pair(prime[i],c));
		}
	}
	if(N>1)
		factors.push_back(make_pair(N,1));
	return factors;
}
i64 facpow(i64 N,i64 K)
{
	i64 sum = 0;
	while(N)
	{
		sum+=N/K;
		N/=K;
	}
	return sum;
}
i64 n,k;
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	criba();
	while(cas--){
		cin>>n>>k;
		vector<pi>f=factorize(k);
		i64 ans = LLONG_MAX;
		for(int i=0;i<f.size();i++){
			ans = min(ans,facpow(n,f[i].first)/f[i].second);
		}
		cout<<ans<<'\n';
	}

}

