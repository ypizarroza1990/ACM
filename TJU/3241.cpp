//============================================================================
// Name        : 3241.cpp
// Author      : BeCrazy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 1000000
using namespace std;
typedef long long i64;
int prime[MAX>>2],flag[MAX>>6];
set<int>S;
set<int>::iterator it;
void criba(){
	int i,j,k;
	for(int i=3;i<1001;i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
		}
	}
}
bool is_prime(int n){
	if(n<2)return false;
	if(n==2)return true;
	if(n&1 && (!ifc(n)))return true;
	return false;
}
int cas,n;
bool ok;
int main() {
	criba();
	scanf("%d",&cas);
	while(cas--){
		ok=true;
		scanf("%d",&n);
		if((n&3)==1 && n!=1){
			int t=(int)round(sqrt(n-4));
			if(t*t!=n-4 ||!is_prime(t))ok=false;
		}else ok=false;
		printf("%s\n",ok?"yes":"no");
	}
}
