#include <bits/stdc++.h>
using namespace std;
#define i64 long long
typedef pair<int,int>pi;
vector<pi>V;
int cas;
string a,b;
int numero(string cad)
{
	int val = 0;
	for(int i=0;cad[i];i++){
		val = (val*7+(cad[i]-'0'))%24;
	}
	return val;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>a>>b;
		int k = b[b.size()-1]-'0';
		if(a=="0"){
			cout<<1<<"\n";
			continue;
		}
		if(k==0){
			cout<<0<<"\n";
			continue;
		}
		V.push_back(make_pair(1,k));
		for(int i=1;i<26;i++){
			int x = V[i-1].first;
			int y = V[i-1].second;
			int z = x*y%7;
			V.push_back(make_pair(y,z));
		}
		cout<<V[numero(a)].first<<'\n';
		V.clear();
	}
	return 0;
}
