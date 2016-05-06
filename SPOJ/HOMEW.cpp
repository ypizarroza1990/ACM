#include <bits/stdc++.h>
#define i64 long long
#define MAX 1000009
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
int flag[MAX>>6],primes[MAX>>3],primelen;
i64 ans[164],pos;
inline int rand32(){
	return (rand()|rand()<<16)&0x7fffffff;
}
inline i64 myrand(){
	return ((i64)rand32()|
			(i64)rand32()<<32)&0x7fffffffffffffffLL;
}
inline i64 mod_mul(i64 x,i64 y,i64 n){
	if(!x)
		return 0;
	return (((x&1)*y)%n+(mod_mul(x>>1,y,n)<<1)%n)%n;
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
i64 _pow(i64 a,i64 b){
	i64 ret=1;
	while(b){
		if(b&1) ret*=a;
		a*=a;
		b>>=1;
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
i64 func(i64 x,i64 n){
	return (mod_mul(x,x,n)+1)%n;
}
bool Rabin_Miller(i64 n){
	i64 k=0,i,j,m,a;
	if(n<2)
		return 0;
	if(n==2)
		return 1;
	if(!(n&1))
		return 0;
	m=n-1;
	while(!(m&1))
		m>>=1,k++;
	for(i=0;i<20;i++){
		a=myrand()%(n-2)+2;
		a=mod_exp(a,m,n);
		if(a==1)
			continue;
		for(j=0;j<k;j++){
			if(a==n-1)
				break;
			a=mod_mul(a,a,n);
		}
		if(j<k)
			continue;
		return false;
	}
	return true;
}
i64 Pollard(i64 n){
	i64 i,x,y,p;
	if(Rabin_Miller(n)){
		return n;
	}
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
unordered_map<i64,int>M;
unordered_map<i64,int>::iterator it;
void factor(i64 n){
	i64 x;
	x=Pollard(n);
	if(x==n){
		M[x]++;
		return;
	}
	factor(x);
	factor(n/x);
}
i64 N,A,B;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>N){
		A=B=1LL;
		if(N<0)return 0;
		if(N>1){
			factor(N);
			for(it = M.begin();it!=M.end();it++){
				A*=_pow(it->first,it->second/2);
				B*=_pow(it->first,it->second%2);
			}
			M.clear();
		}
		cout<<A<<" "<<B<<"\n";
	}
	return 0;
}

