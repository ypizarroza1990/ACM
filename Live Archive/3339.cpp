#include <bits/stdc++.h>
#define MAXN 10000
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
int flag[MAXN>>6],prime[MAXN>>2],lenp,lens;
set<int>S;
int sum[MAXN>>2];
void criba(){
	sum[(lens=1)++]=0;
	S.insert(2);
	sum[lens++]=2;
	int i,j,k;
	for(i=3;i<sqrt(MAXN);i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAXN;j+=k)
				isc(j);
		}
	}
	prime[(k=1)++]=2;
	int suma=2;
	for(i=3;i<MAXN;i+=(i%6==1)?4:2){
		if(!ifc(i)){
			suma+=i;
			sum[lens++]=suma;
			prime[k++]=i;
			S.insert(suma);
		}
	}
	lenp=k;
}
int n;
int main() {

	criba();
	while(scanf("%d",&n),n){
		int cont=0;
		for(int i=1;prime[i]<=n&&i<lenp;i++){
			if(S.find(n+sum[i])!=S.end())
				cont++;
		}
		printf("%d\n",cont);
	}
	return 0;
}

