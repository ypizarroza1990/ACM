#include<bits/stdc++.h>
#define MAX 10009
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef  long long i64;
int cas;
i64 flag[MAX>>6],prime[MAX>>3],len;
void criba(){
	i64 i,j,k;
	for(i=3;i<=sqrt(MAX);i+=(i%6==1)?4:2)
		if(!ifc(i))
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				isc(j);
	prime[(k=0)++]=2;
	for(i=3;i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			prime[k++]=i;

	len=k;
}
i64 aux(i64 N,i64 dig){
	i64 res=0,d=dig;
	while(N>=d){
		res+=N/d;
		d*=dig;
	}
	return res;
}
i64 solve(i64 n,int b){
	map<int,int>M;
	for(int i=0;prime[i]*prime[i]<=b&&i<len;i++){
		if(b%prime[i]==0){
			while(b%prime[i]==0){
				++M[prime[i]];
				b/=prime[i];
			}
		}
	}
	if(b>1)++M[b];
	i64 res=n;
	for(map<int,int>::iterator it=M.begin();it!=M.end();it++){
		res=min(res,aux(n,it->first)/it->second);
	}
	return res;
}
i64 M;
int main(){
	criba();
	int b;
	i64 a,zeros;
	while(scanf("%lld %d",&a,&b)==2){
		zeros=solve(a,b);
		double digitos = 0.0;
		for (int i=1; i<=a; i++)
		{
			digitos += log( i ) / log( b );
		}
		printf("%lld %d\n",zeros,(int)floor(digitos + 1e-9)+1);

	}
	return 0;
}

