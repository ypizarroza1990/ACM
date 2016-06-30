#include <bits/stdc++.h>
using namespace std;
#define i64 long long
typedef pair<int,int>pi;
vector<int>V;
int cas;
string n,k;
int numero(string cad)
{
	int val = 0;
	for(int i=0;cad[i];i++){
		val = (val*10+(cad[i]-'0'))%60;
	}
	return val;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>cas;
	while(cas--){
		cin>>n>>k;
		int K = k[k.size()-1]-'0';
		V.push_back(0);
		V.push_back(K);
		for(int i=2;i<61;i++)
			V.push_back((V[i-1]+V[i-2])%10);
		cout<<V[numero(n)]<<'\n';
		V.clear();

	}
	return 0;
}

