#include<bits/stdc++.h>
#define MOD  1000000
#define i64 long long
using namespace std;
i64 table[201][201] = { 0 };
void pascal(){
	table[0][0] = 1;
	for(int i=1;i<=200;i++){
		table[i][0] = table[i][i] = 1;
		for(int j=1;j<i;j++)
			table[i][j] = (table[i-1][j]+table[i-1][j-1])%MOD;
	}
}
int N,K;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pascal();
	while(cin>>N>>K,N && K){
		cout<<table[N+K-1][K-1]<<"\n";
	}
	return 0;
}

 
