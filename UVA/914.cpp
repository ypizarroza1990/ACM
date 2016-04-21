#include<bits/stdc++.h>
#define MAX 1000009
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef  long long i64;
int cas;//vx63xzy5
i64 flag[MAX>>6],prime[MAX>>3],len;
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
int  solve(int a,int b){
	 map<int,int>M;
	 int lo=lower_bound(prime,prime+len,a)-prime;
	 int hi=upper_bound(prime,prime+len,b)-prime;
	 for(int i=lo+1;i<hi;i++){
		  int val=abs(prime[i]-prime[i-1]);
		  M[val]++;
	 }
	 int sol=-1,maxi=0;
	 for( map<int,int>::iterator it=M.begin();it!=M.end();it++){
		 if(it->second==maxi){
			 maxi=it->second;
			 sol=-1;
		 }else if(it->second>maxi){
			 sol=it->first;
			 maxi=it->second;
		 }
	 }
	 return sol;
}
i64 M;
int main(){
	criba();
	int cas,a,b;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d %d",&a,&b);
		int ans=solve(a,b);
		ans==-1?puts("No jumping champion"):printf("The jumping champion is %d\n",ans);
	}
	 	return 0;
}
