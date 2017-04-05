 
#include<bits/stdc++.h>
#define MAX 509
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef  long long i64;
int prev[MAX];
bool visit[MAX],G[MAX][MAX];
int cas,N,M,x,y;
int dfs(int v)
{
	if(visit[v])return 0;
	visit[v]=1;
	for(int i=1;i<=N;i++){
		if(G[v][i] && (prev[i]==-1 || dfs(prev[i]))){
			prev[i]=v;
			return 1;
		}
	}
	return 0;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>N>>M;
		memset(G,0,sizeof(G));
		for(int i=0;i<M;i++){
			cin>>x>>y;
			G[x][y]=1;
		}
		memset(prev,-1,sizeof(prev));
		int sol=0;
		for(int j=1;j<=N;j++){
			memset(visit,0,sizeof(visit));
			sol+=dfs(j);
		}
		cout<<N-sol<<"\n";
	}
	return 0;
}
