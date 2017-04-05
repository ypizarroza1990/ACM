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
const int MAV = 1000005;
int flag[MAV>>6],prime[MAV>>3],n,m,x,y,primelen,cas;
int sum_d(int n){
	int res=0;
	while(n){
		res+=n%10;
		n/=10;
	}
	return res;
}
bool isprime(int n){
	if(n<2)return 0;
	if(n==2)return 1;
	if((n&1)&&(!ifc(n)))return 1;
	return 0;
}
void Criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAV);i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j = i*i,k=(i<<1);j<MAV;j += k)
				isc(j);
		}
	}
	prime[(k=0)++]=2;
	for(i=3;i<MAV;i+=(i%6==1)?4:2)
		if(!ifc(i)){
			if(isprime(sum_d(i)))
			  prime[k++]=i;
		}
	primelen = k;
}
int main() {
	Criba();
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&x,&y);
		n=lower_bound(prime,prime+primelen,x)-prime;
		m=upper_bound(prime,prime+primelen,y)-prime;
		printf("%d\n",m-n);
	}

}
