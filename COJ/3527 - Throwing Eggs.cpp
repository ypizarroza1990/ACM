#include <bits/stdc++.h>
using namespace std;
#define i64 long long
i64 _pow2[75];
int cas,K,N;
i64 S;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	_pow2[0]=1;
	for(int i=1;i<61;i++)
		_pow2[i]=_pow2[i-1]*2;
	cin>>cas;
	while(cas--){
		cin>>K>>S>>N;
		if(N>60){
			cout<<K<<"\n";
			continue;
		}else{
			int ans=0;
			i64 cost_all_eggs = _pow2[N];
			int _log = 63-__builtin_clzll(S);
			for(int i=0;i<=_log+1;i++){
				if(S & (1LL<<i)){
					if(cost_all_eggs>=(_pow2[i])){
						cost_all_eggs-=_pow2[i];
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
}

