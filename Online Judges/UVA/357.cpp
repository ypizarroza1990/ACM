#include <cstdio>
#include <cmath>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
typedef  long long u64;
int coins[]={50,25,10,5,1};
i64 dp[30009];
void fill(){
	dp[0]=1;
	for(int i=0;i<5;i++){
		for(int j=coins[i];j<30009;j++)
			dp[j]+=dp[j-coins[i]];
	}
}
int main() {
	 fill();
	 int n;
	 while(scanf("%d",&n)==1){
		 i64 res=dp[n];
		 res==1?printf("There is only 1 way to produce %d cents change.\n",n):
				 printf("There are %lld ways to produce %d cents change.\n",res,n);
	 }
}

