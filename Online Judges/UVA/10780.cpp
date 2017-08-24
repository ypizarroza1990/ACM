
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
	if(!(n&1)){
		while(n%2==0 && n){
			exp++;
			n/=2;
		}
		f.push_back(make_pair(2,exp));
	}
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
int solve(int n,int m){
	int sol = INT_MAX;
	vector<pair<int,int> >f = fact(m);
	for(int i=0;i<f.size();i++){
		sol = min(sol,factpow(n,f[i].first)/f[i].second);
	}
	return sol;
}

int n,m,i,cas;
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	i = 1;
	cin>>cas;
	while(cas--){
		cin>>m>>n;
		cout<<"Case "<<i++<<":\n";
		int ans = solve(n,m);
		if(!ans)
			cout<<"Impossible to divide\n";
		else{
			cout<<ans<<"\n";
		}
	}
	return 0;
}
 
