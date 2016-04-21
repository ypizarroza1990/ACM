#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 1000009
#define i64 long long
using namespace std;
int f[15];
int solve(int n){
	if(!n)
		return 0;
	for(int i=14;i>=0;i--){
		if(f[i]<=n){
			return solve(n-f[i])+1;
		}
	}
}
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	f[0]=1;
	for(int i=1;i<15;i++)
		f[i]=f[i-1]*i;
	int x;
	while(cin>>x){
		cout<<solve(x)<<"\n";
	}
	return 0;
}
