#include <bits/stdc++.h>
#define MAX 5*1e18+1
#define MAXF 91
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
i64 fibo[100];
vector<pair<int,int> >fact(int n){
	vector<pair<int,int> >f;
	int exp= 0;
	while(n%2==0 && n){
		exp++;
		n/=2;
	}
	f.push_back(make_pair(2,exp));
	int root = 3;
	while(root*root<=n){
		if(n%root==0){
			exp= 0;
			while(n%root==0){
				exp++;
				n/=root;
			}
			f.push_back(make_pair(root,exp));
		}
		root+=2;
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
bool solve(int n,int m){
	vector<pair<int,int> >f = fact(m);
	for(int i=0;i<f.size();i++){
		if(f[i].second>factpow(n,f[i].first))
			return false;
	}
	return true;
}

int n,m;
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>m){
		if(solve(n,m)){
			cout<<m<<" divides "<<n<<"!\n";
		}else{
			cout<<m<<" does not divide "<<n<<"!\n";
		}
	}
	return 0;
}
