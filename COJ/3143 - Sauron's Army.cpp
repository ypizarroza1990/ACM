#include <bits/stdc++.h>
using namespace std;;
typedef long long i64;

const i64 MOD = 1000000007;

i64 pascal[509][509];
i64 factorial[509];

void preprocess(){
	pascal[0][0]=pascal[1][1]=pascal[1][0]=1;
	factorial[0]=factorial[1]=1;
	for(int i=2;i<501;i++){
		pascal[i][0]=pascal[i][i]=1;
		factorial[i]=(factorial[i-1]*i)%MOD;
		for(int j=1;j<i;j++){
			pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j])%MOD;
		}
	}
}

int N;
int main() {

    preprocess();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    i64 sol=factorial[N];
    for(int i=1;i<N;i++){
    	i%2?sol-=((pascal[N-1][i]*factorial[N-i])%MOD):sol+=((pascal[N-1][i]*factorial[N-i])%MOD);
    	sol%=MOD;
    }
    sol+=MOD;
    cout<<sol%MOD<<endl;
    return 0;
}

