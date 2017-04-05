#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 1120
using namespace std;
typedef long long i64;
int flag[MAX>>6],prime[MAX>>2];
i64 dp[15][189][MAX+9];
void criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2)
		if(!ifc(i))
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
	prime[(k=0)++]=2;
	for(i=3;i<(MAX);i+=(i%6==1)?4:2)
		if(!ifc(i))
		prime[k++]=i;
}
i64 solve(int k,int p,int num){
	if(k==0 && num==0)
		return 1;
	if(k==0)
		return 0;
	if(p>=187)
		return 0;
	if(prime[p]>num)
		return 0;
	if(dp[k][p][num]!=-1)
		return dp[k][p][num];
	i64 res=solve(k-1,p+1,num-prime[p])+solve(k,p+1,num);
	return dp[k][p][num]=res;
}
int main()
{
	 criba();
     int a,b;
     memset(dp,-1,sizeof(dp));
     while(scanf("%d%d",&a,&b),a+b){
    	 printf("%lld\n",solve(b,0,a));
     }
}

