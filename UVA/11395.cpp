#include<bits/stdc++.h>
#define MAX 1000009
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef  long long i64;
int cas;//vx63xzy5
i64 flag[MAX>>6],prime[MAX>>3],len,vals[MAX<<1],lenval=0;
const i64 N=1000000000009LL;
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
void solve(int node,i64 cur){
	vals[lenval++]=cur;
	if(node>len)
		return;
	for(int i=node;i<len;i++){
		if(i==0){
			if(cur<=(N>>1))
				solve(node,cur<<1);
			else return;
		}else{
			i64 val=prime[i]*prime[i];
			if(cur<=(N/val))
				solve(i,cur*val);
			else return ;
		}

	}
}
i64 M;
int main(){
	criba();
	solve(0,1);
	vals[lenval++]=N+1;
	sort(vals,vals+lenval);
	while(scanf("%lld",&M),M){
		int len=upper_bound(vals,vals+lenval,M)-vals;
		printf("%lld\n",M-len);
	}
	return 0;
}

