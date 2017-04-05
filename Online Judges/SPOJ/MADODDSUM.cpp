#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MOD 1000007
#define MAX 10000007
using namespace std;
typedef long long i64;
i64 n,m;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		cin>>n>>m;n--;
		n = n/2+(n%2==1);
		m = (m/2)+(m%2==1);
		cout<<(m*m - n*n)<<"\n";
}

