#include <bits/stdc++.h>
#define MAX 1000
#define MAXF 91
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
int flag[MAX>>6],prime[MAX>>2],len;
void criba(){
	int i,j,k;
	for(i=3;i*i<MAX;i+=2)
		if(!ifc(i))
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				isc(j);
	prime[(k=0)++]=2;
	for(i=3;i<MAX;i+=2)
		if(!ifc(i))prime[k++]=i;
	len =k;
}
vector<pair<int,int> >fact(int n){
	vector<pair<int,int> >f;
	int exp= 0;
	for(int i=0;prime[i]*prime[i]<=n && i<len;i++){
		if(n%prime[i]==0){
			exp=0;
			while(n%prime[i]==0){
				exp++;
				n/=prime[i];
			}
			f.push_back(make_pair(prime[i],exp));
		}
	}
	if(n>1)
		f.push_back(make_pair(n,1));
	return f;
}
int factpow(int n,int p){
	int res=0;
	while(n){
		res+=n/p;
		n/=p;
	}
	return res;
}
i64 solve(int n,int m){
	i64 sol = 1;
	vector<pair<int,int> >f = fact(abs(m));
	if(f.size())
		if(f[f.size()-1].first>n)return 0;
	vector<int>R = vector<int>(100,0);
	for(int i=0;i<f.size();i++)
		R[f[i].first]-=f[i].second;

	for(int i=0;prime[i]<=n;i++){
		R[prime[i]]+=factpow(n,prime[i]);
		if(R[prime[i]]<0)
			return 0;
		sol *= (R[prime[i]]+1);
	}
	return sol;
}

int n,m,i,cas;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	criba();
	while(cin>>n>>m,m||n){
		cout<<solve(n,abs(m))<<"\n";
	}
	return 0;
}
 
