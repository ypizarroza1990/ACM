//============================================================================
// Name        : Grundy_Cup.cpp
// Author      : BeCrazy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAXLOG 16
#define MAX    25000
using namespace std;
typedef long long i64;
i64 PER[1<<MAXLOG][MAXLOG],G[MAX];
i64 solve(int N,int K){

	//fill
	memset(PER,0,sizeof(PER));
	for(int i=0;i<N;i++)
		PER[1<<i][i]=1;
	//DP
	for(int mask=0;mask<(1<<N);mask++){
		for(int j=0;j<N;j++){
			if(mask&(1<<j)){
				for(int k=0;k<N;k++){
					if((mask&(1<<k))==0 && abs(G[j]-G[k])>K)
						PER[mask|(1<<k)][k]+=PER[mask][j];
				}
			}
		}
	}
	i64 ans=0;
	for(int i=0;i<N;i++)
		ans+=PER[(1<<N)-1][i];
	return ans;
}
int N,K;
int main() {
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++)
		scanf("%d",&G[i]);
	cout<<solve(N,K)<<endl;
	return 0;
}
