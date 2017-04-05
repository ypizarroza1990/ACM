#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 100001000
#define mp(x,y) make_pair(x,y)
#define f first
#define s second
using namespace std;
typedef long long i64;
int flag[MAX>>6],primes[MAX>>2],len,t;
void Criba(){
	int i,j,k;
	for(i=3;i<=10010;i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
		}
	}
	primes[(k=0)++]=2;
	for(i=3;i<MAX;i+=(i%6==1)?4:2){
		if(!ifc(i))
			primes[k++]=i;
	}
	len=k;
}
bool isprime(i64 num){
	if(num<2)return 0;
	if(num==2)return 1;
	if((num&1)&&(!ifc(num)))return 1;
	return 0;
}

i64 num;
int i,a,b,ok;
int main(){
	Criba();
	while(scanf("%lld",&num)==1){
		if(num>=8){
			if(num&1){
				printf("2 3 ");
				num-=5;
			}
			else{
				printf("2 2 ");
				num-=4;
			}
			for(i=0;i<len;i++)
				if(isprime(num-primes[i])){
					printf("%d %lld\n",primes[i],num-primes[i]);
					break;
				}

		}else
			printf("Impossible.\n");
	}
	return 0;
}
