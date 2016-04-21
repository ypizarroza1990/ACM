#include <bits/stdc++.h>
#define MAX 1000009
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define P(x)(x)*(x)
using namespace std;
typedef long long i64;
int flag[MAX>>6],prime[MAX>>2],len;
void criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
		}
	}
	prime[(k=0)++]=2;
	for(i=3;i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			prime[k++]=i;
	len=k;
}
int factoriza(i64 n){
	int res=0;
	for(int i=0;prime[i]*prime[i]<=n && i<len;i++){
		if(n%prime[i]==0){
			res++;
			while(n%prime[i]==0)n/=prime[i];
		}
	}
	if(n>1)++res;
	return res;
}
i64 n;
int main() {
	 criba();
	 while(scanf("%lld",&n),n){
		 printf("%lld : %d\n",n,factoriza(n));
	 }
	return 0;
}
