 
#include<bits/stdc++.h>
#define MAX 10000001
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef  long long i64;
double a[MAX];
int n,cas;
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	for(int i=1;i<MAX;i++){
		a[i]=a[i-1]+log10(i);
	}
	while(cas--){
		cin>>n;
		cout<<(int)a[n]+1<<"\n";
	}
	return 0;
}
