//============================================================================
// Name        : 10236.cpp
// Author      : Anthrax
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
#define MAX 250000
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
i64 flag[MAX>>6],prime[MAX>>2],len;
bool overf=false;
double fibo[MAX];
void criba(){
	int i,j,k;
	for(i=3;i<=1000;i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<=MAX;j+=k)
				isc(j);
		}
	}
	prime[(k=0)++]=2;
	for(i=3;i<=MAX;i+=(i%6==1)?4:2){
		if(!ifc(i))
			prime[k++]=i;
	}
	len=k;
}
void fib(){
	fibo[1]=fibo[2]=1;
	for(int i=3;i<MAX;i++){
		if(overf){
			fibo[i]=fibo[i-1]+fibo[i-2]/10;
			overf=0;
		}
		else fibo[i]=fibo[i-1]+fibo[i-2];
		if(fibo[i]>1e9){
		fibo[i]/=10;
		overf=1;
		}
	}
	fibo[2]=2,fibo[3]=3;
}
int n;
int main() {
	criba();
	fib();
	while(scanf("%d",&n)==1){
		printf("%lld\n",(i64)fibo[prime[n-1]]);
	}
	return 0;
}
