//============================================================================
// Name        : 294.cpp
// Author      : Anthrax
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
#define MAX 1000000
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
int flag[MAX>>6],prime[MAX>>2],len;
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
int divisor(int n){
	int ans=1,div;
	for(int i=0;prime[i]*prime[i]<=n;i++){
		if(n%prime[i]==0){
			div=0;
			while(n%prime[i]==0){div++;n=n/prime[i];}
			ans=(ans*(div+1));
		}
	}
	if(n>1){
		ans=ans*2;
	}
	return ans;
}
int l,r,ans,cas,num,t;
int main() {
	criba();
	scanf("%d",&cas);
	while(cas--){
		scanf("%d %d",&l,&r);
		ans=num=0;
		for(int i=l;i<=r;i++){
			t=divisor(i);
			if(ans<t){
				ans=t;
				num=i;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,r,num,ans);
	}
	return 0;
}
