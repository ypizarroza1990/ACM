#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 1000009
using namespace std;
typedef long long i64;
int flag[MAX>>6],prime[MAX>>1],len;
int cas,odd,even,N,B,last;
i64 P;
void criba(){
	int i,j,k;
	for(i = 3;i*i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			for(j=i*i,k=(j<<1);j<MAX;j+=k)
				isc(j);
	prime[(k=0)++]=2;
	for(i=3;i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			prime[k++]=i;
	len = k;
}
void factorize(int N){
	for(int i=0;prime[i]*prime[i]<=N && i<len;i++){
		int power = 0;
		if(N%prime[i]==0){
			while(N%prime[i]==0){
				power++;
				N/=prime[i];
			}
			power&1?odd++:even++;
		}
	}
	if(N>1)
		odd++;
}
i64 count_zero(i64 N)
{
	i64 sum = 0;
	while(N)
	{
		sum+=N/5;
		N/=5;
	}
	return sum;
}
int MODPOW(i64 b,i64 p){
	int res = 1;
	while(p){
		if(p&1)
			res = (b*res)%10;
		p>>=1;
		b = (b*b)%10;
	}
	return res;
}
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	criba();
	while(cas--){
		odd=even=0;
		cin>>N>>B>>P;
		N = count_zero(N);
		last = MODPOW(B,P);
		N = N*last;
		factorize(N);
		even>odd?puts("Psycho Number"):puts("Ordinary Number");
	}

}

