//============================================================================
// Name        : 2870.cpp
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
int M[201][201];
vector<pi>V;
void floyd(int n){
	for(int k=0;k<=n;k++)
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
}
void clear(int n){
	for(int i=0;i<=n;i++){
		memset(M[i],63,sizeof(M[i]));
		M[i][i]=0;
	}
}
int main() {
	while(scanf("%d",&n),n){
		scanf("%d",&q);
		clear(n);
		for(int i=0;i<q;i++){
			scanf("%d%d%d",&x,&y,&val);
			M[x][y]=val;
			M[y][x]=val;
		}
		floyd(n);
		scanf("%d",&k);
		for(int i=1;i<=n;i++){
			V.push_back(make_pair(M[0][i],i));
		}
		sort(V.begin(),V.end());
		printf("%d\n",V[k-1].second);
		V.clear();
	}
}
