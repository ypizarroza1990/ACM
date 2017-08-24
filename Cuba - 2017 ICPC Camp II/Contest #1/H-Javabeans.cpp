#include <bits/stdc++.h>
using namespace std;
#define i64 long long int
int n,cas;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>n;
		cout<<31-__builtin_clz(n)+1<<"\n";
	}

}