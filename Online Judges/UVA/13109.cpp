#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
int cas;
i64 w[100009],m,x;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>m>>x;
		for(int i=0;i<m;i++){
			cin>>w[i];
		}
		sort(w,w+m);
		i64 ans = 0;
		int i=0;
		for(;i<m;i++){
			ans+=w[i];
			if(ans>x)break;
		}
		cout<<i<<"\n";
	}
}


