#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 pop_count(i64 num){
	i64 ans,i,flag,T,mask;
	flag=1,i=0,T=ans=0;
	while(flag){
		mask=1LL<<i;
		flag=(T=num/mask)/2*mask;
		if(T&1)
			ans+=num%mask;
		ans+=flag;
		i++;
	}
	return ans;
}
i64 a,b;
int i=1;
int main() {
	  while(scanf("%lld %lld",&a,&b),a!=0 || b!=0){
		  printf("Case %d: %lld\n",i++,pop_count(b+1)-pop_count(a));
	  }
	return 0;
}
