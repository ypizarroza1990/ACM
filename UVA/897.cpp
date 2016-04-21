#include<bits/stdc++.h>
#define MAX 1009
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef  long long i64;
int cas;//vx63xzy5
int flag[MAX>>6],prime[MAX>>2],len;
int A[MAX>>3],lena=0;
void criba(){
	i64 i,j,k;
	for(i=3;i<=sqrt(MAX);i+=(i%6==1)?4:2)
		if(!ifc(i))
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				isc(j);
	prime[(k=0)++]=2;
	for(i=3;i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			prime[k++]=i;

	len=k;
}
bool isprime(int n){
	if(n<2)
		return false;
	if(n==2)
		return true;
	if((n&1)&& !ifc(n))
		return true;
	return false;
}
bool anagramatic(int N){
	char cad[20];
	sprintf(cad,"%d",N);
	int len=strlen(cad);
	sort(cad,cad+len);
	int val=atoi(cad);
	if(!isprime(val))return false;
	while(next_permutation(cad,cad+len)){
		val=atoi(cad);
		if(!isprime(val))return false;
	}
	return true;
}
int count(int N){
	int res=0;
	while(N){
		N/=10;
		res++;
	}
	return res;
}
int  solve(int N){

	int t=upper_bound(A,A+lena,N)-A;

	if(count(A[t])>count(N))
		return 0;

	else return A[t];

}
int N;
int main(){
	criba();
	for(int i=0;i<len;i++){
		if(anagramatic(prime[i])){
			A[lena++]=prime[i];
		}
	}

	while(scanf("%d",&N),N){
		printf("%d\n",solve(N));
	}

	return 0;
}

