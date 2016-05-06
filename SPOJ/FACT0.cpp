#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
#define  i64 long long
i64 ans[100],n;
int ansn;
inline i64 mod_mul(i64 x,i64 y,i64 n){
	if(!x)
		return 0;
	return (((x&1)*y)%n+(mod_mul(x>>1,y,n)<<1)%n)%n;
}
inline int rand32(){
	return (rand()|rand()<<16)&0x7fffffff;
}
inline i64 myrand(){
	return ((i64)rand32()|
			(i64)rand32()<<32)&0x7fffffffffffffffLL;
}
i64 mod_exp(i64 a,i64 x,i64 n){
	i64 ret=1;
	while(x){
		if(x&1) ret=mod_mul(ret,a,n);
		a=mod_mul(a,a,n);
		x>>=1;
	}
	return ret;
}
i64 gcd(i64 x,i64 y){
	i64 q;
	while(1){
		if(!y) return abs(x);
		q=x,x=y,y=q%y;
	}
}
int primes[]={2,3,5,7,11,13,17,19,23,29,31};
bool fermat(i64 N){
	if ( N < 2 || ( N > 2 && !( N % 2 ) ) )
	            return false;

	for(int i=0;i<11 && primes[i] < N;i++){
		if(mod_exp(primes[i],N-1,N)!= 1LL)
			return 0;
	}
	return 1;
}
i64 func(i64 x,i64 n){
	return (mod_mul(x,x,n)+1)%n;
}
i64 Pollard(i64 n){
	i64 i,x,y,p;
	if(fermat(n))
		return n;
	if(!(n&1))
		return 2;
	for(i=1;i<20;i++){
		x=i;
		y=func(x,n);
		p=gcd(y-x,n);
		while(p==1){
			x=func(x,n);
			y=func(func(y,n),n);
			p=gcd((y-x+n)%n,n)%n;
		}
		if(p==0||p==n)
			continue;
		return p;
	}
}
void factor(i64 n){
	i64 x;
	x=Pollard(n);
	if(x==n){
		ans[ansn++]=x;
		return;
	}
	factor(x);
	factor(n/x);
}
int main(){

	srand(0x12345);
		i64 num,n;
		while(scanf("%lld",&num),num){
			ansn=0;
			factor(num);
			sort(ans,ans+ansn);
			int i,j;
			bool firts=1;
			for(i=0;i<ansn;i++){
				n=ans[i];j=i;
				while(j<ansn && ans[j]==n)j++;
				if(firts)firts=0;
				else printf(" ");
				printf("%lld^%d",n,(j-i));
				i=j-1;

			}
			puts("");
		}
		return 0;
}

