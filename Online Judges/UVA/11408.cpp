#include <bits/stdc++.h>
#define MAX 5000001
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long I64;
bool prime[MAX];
int sum[MAX],acum[MAX];
void criba(){
	for(int i=2;i<MAX;i++){
		if(!prime[i]){
			sum[i] = i;
			for(int j=2*i;j<MAX;j+=i){
				prime[j]=1;
				sum[j] += i;
			}
		}
	}

}
int a,b;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	criba();
	for(int i=1;i<MAX;i++){
		acum[i] = !(prime[sum[i]])+acum[i-1];
	}
	while(1){
		cin>>a;
		if(!a)break;
		cin>>b;
		cout<<acum[b]-acum[a-1]<<"\n";
	}
	return 0;
}


