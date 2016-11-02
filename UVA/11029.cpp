#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 multiply(i64 a,i64 b, i64 mod){
    i64 rx=0,sx=0;
    for (int bx=0; b>>bx>0; ++bx){
        sx+=(bx)?sx:a;
        while(sx>=mod) sx-=mod;
        rx+=((b>>bx)&1)?sx:0;
        while(rx>=mod) rx-=mod;
    }
    return rx;
}
i64 modpow(i64 a,i64 b, i64 mod){
    i64 rx=1,sx=0;
    for(int bx=0; b>>bx>0; ++bx){
        sx=(bx)?multiply(sx,sx,mod):a;
        rx=((b>>bx)&1)?multiply(rx,sx,mod):rx;
    }
    return rx%mod;
}
int n,k,cas;
i64 trail,lead;
double p,expo;
int main()
{
	 scanf("%d",&cas);
	 for(int i=1;i<=cas;i++){
		 scanf("%d %d",&n,&k);
		 trail=modpow(n,k,1000LL);
		 p=k*log10(n);
		 expo=p-floor(p);
		 lead=(i64)(pow(10,expo)*100);
		 printf("%03lld...%03lld\n",lead,trail);
	 }
	return 0;
}

