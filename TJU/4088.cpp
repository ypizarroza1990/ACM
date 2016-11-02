#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 10000
using namespace std;
int flag[MAX>>6],prime[MAX>>2],len;
void criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2)
		if(!ifc(i))
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				isc(j);
	prime[(k=0)++]=2;
	for(i=3;i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			prime[k++]=i;
	len=k;
}
bool isPrime(int n){
	if(n<2)
		return 0;
	if(n==2)
		return 1;
	if((n&1)&&!ifc(n))
		return 1;
	return 0;
}
int a,b;
int main() {

	criba();
	while(scanf("%d%d",&a,&b)==2){
		int l=lower_bound(prime,prime+len,a)-prime;
		int h=upper_bound(prime,prime+len,b)-prime;
		isPrime(h-l)?puts("YES"):puts("NO");
	}

	return 0;
}

