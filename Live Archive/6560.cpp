#include <cstdio>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
const int MAV = 10000005;
int flag[MAV>>6],prime[MAV>>3],n,m,x,y,primelen;
void Criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAV);i+=2){
		if(!ifc(i)){
			for(j = i*i,k=(i<<1);j<MAV;j += k)
				isc(j);
		}
	}
	prime[(k=0)++]=2;
	for(i=3;i<MAV;i+=2)
		if(!ifc(i))
			prime[k++]=i;
	primelen = k;
}
int main() {
	Criba();
	bool ok = 0;
	while(scanf("%d%d",&x,&y)==2){
		if (ok)printf("\n");
		n=lower_bound(prime,prime+primelen,x)-prime;
		m=upper_bound(prime,prime+primelen,y)-prime;
		printf("%d\n",m-n);
		ok = 1;
	}
}

