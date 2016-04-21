#include<bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 5000007
using namespace std;
#define i64 long long 
#define MOD 1000000007;
int N;
bool noprime[MAX];
vector<int>primes;
void criba()
{
	primes.push_back(2);

	    for(int i = 3;i < 5000000;i+=(i%6==1)?4:2){
	        if(!noprime[i]){
	            primes.push_back(i);

	            if(i <= 2236)
	                for(int j = i * i;j < 5000000;j += i)
	                    noprime[j] = true;
	        }
	    }

}
i64 POW(i64 a,int b)
{
	i64 res=1LL;
	while(b){
		if(b&1)
			res=(res*a)%MOD;
		b>>=1;
		a=(a*a)%MOD;
	}
	return  res;
}
int POWFACT(int N,int b){
	int res=0;
	while(N)
	{
		res+=N/b;
		N/=b;
	}
	return res;
}
int main(){
    criba();
    int len = primes.size();
	i64 sol;
	int aux;
    while(scanf("%d",&N),N){
    	sol=1;
    	for(int i=0;primes[i]<=N/2 && i<len;i++){
    		aux=POWFACT(N,primes[i]);
    		aux=aux&1?aux-1:aux;
    		sol=(sol*POW((i64)primes[i],aux))%MOD;
    	}
    	printf("%lld\n",sol);
    }
    return 0;
}
