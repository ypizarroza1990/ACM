#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;
int N, M;
vector<int> G[MAXN+1];
int P[MAXN+1][17], T[MAXN+1], L[MAXN+1];
bool mark[MAXN+1];
void dfs(int v){
	mark[v] = 1;
	int i, M = G[v].size(), ady;
	for(i = 0; i < M; ++i){
		ady = G[v][i];
		if(!mark[ady]){
			T[ady] = v; L[ady] = L[v] + 1;
			dfs(ady);
		}
	}
}
void process3(){
	int i, j;
	for(i = 1; i <= N; ++i)
		for(j = 0; 1 << j <= N; ++j) P[i][j] = -1;
	for(i = 2; i <= N; ++i) P[i][0] = T[i];
	for(j = 1; 1 << j <= N; ++j)
		for(i = 2; i <= N; ++i)
			if(P[i][j-1] != -1)
				P[i][j] = P[P[i][j-1]][j-1];
}
int LCA(int p, int q){
	int i,log;
	if(L[p] < L[q]) swap(p,q);
	for(log = 1; 1 << log <= L[p]; ++log);
	log--;
	for(i = log; i >= 0; --i)
		if(L[p]-(1<<i) >= L[q]) p = P[p][i];
	if(p==q) return p;
	for(i = log; i >= 0; --i)
		if(P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i];
	return T[p];
}
int ancester(int u,int depth){
	int log;
	for(log = 1; 1 << log <= L[u]; ++log);
	log--;
	for(int i=log;i>=0;i--){
		if(depth-(1<<i)>=0){
			depth-=(1<<i);
			u = P[u][i];
		}
	}
	return u;
}
void solve(int u,int v){
	if(L[u]<L[v])swap(u,v);
	int path = L[u]+L[v]-2*L[LCA(u,v)];
	if(path&1){ //forever
		u = ancester(u,path>>1);
		v = T[u];
		if(u>v)swap(u,v);
		cout<<"The fleas jump forever between "<<u<<" and "<<v<<".\n";
	}else{
		cout<<"The fleas meet at "<<ancester(u,path>>1)<<".\n";
	}
}
int n,q,x,y;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>N,N){
		for(int i=0;i<=N;i++){
			G[i].clear();
			mark[i]=false;
			L[i]=T[i]=0;
		}
		memset(P,-1,sizeof(P));
		for(int i=0;i<N-1;i++){
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1);
		process3();
		cin>>q;
		while(q--){
			cin>>x>>y;
			solve(x,y);
		}
	}
	return 0;
}
 
