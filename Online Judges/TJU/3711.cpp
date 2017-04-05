#include <bits/stdc++.h>
#define MAX 1000
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
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
int power(int a,int b){
	if(b==0)
		return 1;
	if(b&1)
		return a*power(a,b-1);
	return power(a,b/2)*power(a,b/2);
}
int sum_div(int N){
	int res=1,cont,n=N;
	for(int i=0;prime[i]*prime[i]<=N && i<len;i++){
		cont=0;
		if(N%prime[i]==0){
			while(N%prime[i]==0){
				cont++;
				N/=prime[i];
			}
			res=res*((power(prime[i],cont+1)-1)/(prime[i]-1));
		}
	}
	if(N>1)
		res=(res*((power(N,2)-1)/(N-1)));
	return res-n;
}
int N,one;
int main() {

	criba();
	scanf("%d",&N);
	for(;;N++){
		one=sum_div(N);
		if(N==one)continue;
		if(sum_div(one)==N){
			printf("%d %d\n",N,one);
			return 0;
		}
	}
}


