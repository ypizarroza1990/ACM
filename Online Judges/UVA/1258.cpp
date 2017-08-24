#include <bits/stdc++.h>
#define MAX 5*1e18+1
#define MAXF 91
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
i64 fibo[100];
vector<i64>P,N;
void solve(i64 n){
	int pos = lower_bound(fibo,fibo+MAXF,n)-fibo;
	for(int i=pos;i>0;i--){
		if(n>=fibo[i]){
			n-=fibo[i];
			P.push_back(i);
			N.push_back(fibo[i]);
		}
	}
}
i64 n;
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fibo[2]=2LL;fibo[1]=1LL;
	for(int i=3;i<92;i++){
		fibo[i]=(fibo[i-1]+fibo[i-2]);
	}
	while(cin>>n){
		solve(n);
		cout<<n<<'\n';
		for(int i=0;i<P.size();i++){
			cout<<P[i]<<" ";
		}
		cout<<"\n";
		for(int i=0;i<N.size();i++){
			cout<<N[i]<<" ";
		}
		cout<<"\n\n";
		P.clear();N.clear();
	}
	return 0;
}
 
