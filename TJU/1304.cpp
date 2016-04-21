#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 1<<22
#define i64 long long
using namespace std;
int flag[MAX>>6],prime[MAX>>2],len;
map<int,i64>factor;
void criba()
{
	int i,j,k;
	for(i=3;i*i<MAX;i+=2)
		if(!ifc(i))
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				isc(j);
	prime[(k=0)++]=2;
	for(i=3;i<MAX;i+=2)
		if(!ifc(i))
			prime[k++]=i;
	len = k;
}
bool factorize(int N){
	for(int i=0;prime[i]*prime[i]<=N && i<len;i++){
		while(N%prime[i]==0){
			factor[prime[i]]--;
			N/=prime[i];
		}
		if(factor[prime[i]]<0)
			return false;
	}
	if(N>1){
		factor[N]--;
		if(factor[N]<0)
			return false;
	}
	return true;
}
void factpow(int N){
	for(int i=0;prime[i]<=N && i<len;i++){
		int temp = N;
		while(temp){
			factor[prime[i]]+= temp/prime[i];
			temp/=prime[i];
		}
	}
}
int N,P;
int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	criba();
	while(cin>>N>>P){
		if(P==0){
			cout<<P<<" does not divide "<<N<<"!\n";
			continue;
		}
		if(N>=P){
			cout<<P<<" divides "<<N<<"!\n";
			continue;
		}
		factpow(N);
		factorize(P)?cout<<P<<" divides "<<N<<"!\n":cout<<P<<" does not divide "<<N<<"!\n";
		factor.clear();
	}
	return 0;
}
