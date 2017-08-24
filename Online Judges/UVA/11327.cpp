
#include <bits/stdc++.h>
#define MAX  200000 + 5
#define MAXF 91
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
i64 phi[MAX];
void criba(){
	for(int i=1;i<MAX;i++)
		phi[i]=i;
	for(int i=2;i<MAX;i++){
		if(phi[i]==i){
			for(int j=i;j<MAX;j+=i)
				phi[j] = phi[j]/(i)*(i-1);
		}
		phi[i]+=phi[i-1];
	}
}
i64 n;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	criba();
	while(cin>>n && n){
		n--;
		if(n ==0){
			cout<<0<<"/"<<1<<"\n";
			continue;
		}
		int lo = 0,hi = MAX;
		while (lo + 1 < hi){
			int mid = (lo + hi) >> 1;

			if (n <= phi[mid])
				hi = mid;
			else
				lo = mid;
		}
		n-=phi[lo];
		for(int i=1;i<=hi;i++){
			if(__gcd(i,hi)==1)
				n--;
			if(n ==0){
				cout<<i<<"/"<<hi<<"\n";
				break;
			}
		}
	}
	return 0;
}
 
