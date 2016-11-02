#include <bits/stdc++.h>
#define MAX 1000000
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
int flag[MAX>>6],prime[MAX>>2],len;
void Criba(){
	int i,j,k,root=sqrt(MAX);
	for(i=3;i<root;i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
		}
	}
	prime[(k=0)++]=2;
	for(i=3;i<MAX;i+=(i%6==1)?4:2){
		if(!ifc(i))
			prime[k++]=i;
	}
	len=k;
}
bool IsPrime(int p){
	if(p<2)return false;
	if(p==2)return true;
	if(p&1 &&(!ifc(p)))return true;
	return false;
}
int next(int p){
	if(p==31607)
		return -1;
	p++;
	 while(!IsPrime(p))
		 p++;
	 return p;
}
int sumD(i64 n){
	int sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int sumF(i64 n){
	 int k=n;
	 int p=2;
	 int sum=0;
	if(n<=31622 && IsPrime(n))
		return -1;
	while(p!=-1 && n!=1){
		int c=0;
		while(n%p==0 && n!=1){
			c++;
			n/=p;
		}
		sum+=c*sumD(p);
		p=next(p);
	}
	if(n==k)
		return -1;
	if(n!=1)
		sum+=sumD(n);
	return sum;
}
i64 num;
int main ()
{
	Criba();
	while(scanf("%lld",&num),num){
		num++;
		for(i64 i=num;;i++)
		if(sumD(i)==sumF(i)){
			printf("%lld\n",i);
			break;
		}
	}

	return 0;
}
