#include<bits/stdc++.h>
using namespace std;
#define i64 long long
bool solve(i64 N)
{
	N*=2;
	for(int d = 2;d*d<=N;d++){
		if(N%d==0){
			i64 a = N/d-d+1;
			if(a>=2 && a%2==0){
				a/=2;
				cout<<N/2<<" = "<<a;
				for(int i=1;i<d;i++){
					if(i)cout<<" + ";
					cout<<a+i;
				}
				cout<<"\n";
				return true;
			}
		}
	}
	return false;
}
int cas;
i64 N;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>N;
		if(!solve(N))
			cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
