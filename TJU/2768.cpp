//============================================================================
// Name        : 2768.cpp
// Author      : BeCrazy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
int n,q,k,x,y,val;
typedef pair<int,int>pi;
int coins[20],MAX,N,dp[10000];
int main() {
	memset(dp,63,sizeof(dp));
	 scanf("%d %d",&MAX,&N);
	  for(int i=0;i<N;i++){
		  scanf("%d",&coins[i]);
		  dp[coins[i]]=1;
	  }
	  for(int i=1;i<=MAX+1;i++){
		  for(int j=0;j<N;j++){
			  int t=i+coins[j];
			  if(t>MAX)continue;
			  dp[t]=min(dp[t],dp[i]+1);
		  }
	  }
	  printf("%d\n",dp[MAX]);
}
