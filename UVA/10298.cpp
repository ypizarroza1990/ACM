#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define N 1000010
using namespace std;
typedef long long i64;
int f[N];
void prefixFunction(string P){
    int n = P.size(), k = 0;
    f[0] = 0;

    for(int i=1;i<n;++i){
        while(k>0 && P[k]!=P[i]) k = f[k-1];
        if(P[k]==P[i]) ++k;
        f[i] = k;
    }
}
string cad;
int main() {
	while(cin>>cad){
		if(cad==".")
			break;
		prefixFunction(cad);
		int L=cad.size(),ans=1;
		int s=L-f[L-1];
		if(s<L&&L%s==0)ans=L/s;
		printf("%d\n",ans);
	}
	return 0;
}
