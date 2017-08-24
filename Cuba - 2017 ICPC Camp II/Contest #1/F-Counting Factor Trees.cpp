#include <bits/stdc++.h>
using namespace std;
#define i64 long long
i64 C[40];
i64 catalan(int n){
	if(n==0)
		return 1;
	if(C[n])
		return C[n];
	i64 ans = (2*(2*n-1)*catalan(n-1))/(n+1);
	return C[n]=ans;
}
i64 nCr_rep(vector<int>v){
	i64 ans = 1LL;
	int cur=1;
	for(int i=0;i<(int)v.size();i++){
		for(int j=1;j<=v[i];j++){
			ans *=cur++;
			ans/=j;
		}
	}
	return ans;
}
vector<int>Factors(int n){
	int cont = 0;
	vector<int>v;
	while(n%2==0){
		cont++;
		n/=2;
	}
	if(cont)v.push_back(cont);
	int i=3;
	while(i*i<=n){
		if(n%i==0){
			cont=0;
			while(n%i==0){
				cont++;
				n/=i;
			}
			v.push_back(cont);
		}
		i+=2;
	}
	if(n>1)v.push_back(1);
	return v;
}
i64 solve(int n){
	vector<int>v=Factors(n);
	int s = 0;
	for(size_t i=0;i<v.size();i++){
		s+=v[i];
	}
	i64 ans = catalan(s-1)*nCr_rep(v);
	return ans;
}

int cas,n;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>n;
		cout<<solve(n)<<"\n";
	}
	return 0;
}
 
