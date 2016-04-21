#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 2<<16
using namespace std;
typedef long long i64;
int flag[MAX>>6],prime[MAX>>2],len;
void criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2)
		if(!ifc(i))
			for(int j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
	prime[(k=0)++]=2;
	for(int i=3;i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			prime[k++]=i;
	len=k;
}
int solve(int n){
	int div,phi,sz,aux;
	div=1,phi=n,aux=n;
	for(int i=0;prime[i]*prime[i]<=n && i<len;i++){
		sz=0;
		if(n%prime[i]==0){
			while(n%prime[i]==0){
				++sz;
				n/=prime[i];
			}
			div*=(sz+1);
			phi/=prime[i];phi*=(prime[i]-1);
		}
	}
	if(n>1){
		div*=2;
		phi/=n;
		phi*=(n-1);
	}
	div-=1;
	//printf("%d %d\n",div,phi);
	return aux-div-phi;
}
int N;
int main(){
	 criba();
	 while(scanf("%d",&N)==1){
	 printf("%d\n",solve(N));
	 }
}

