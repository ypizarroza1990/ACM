#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
long double n;
int main() {
	while(cin>>n){
		 long double c=(sqrtl(8*n+1));
		 long long p=(long long)c;
		 if(p==c){
			 printf("%lld\n",p/2);
		 }else{
			 puts("bad");
		 }
	}

}
