#include <bits/stdc++.h>
using namespace std;
int cas,n,sol,x;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>n;
		while(n--){
			cin>>x;
			sol+=(x==1);
		}
		cout<<sol<<"\n";
		sol = 0;
	}
	return 0;
}

