#include <bits/stdc++.h>
#define MAXV 100009
#define MAXV1 2*MAXV
using namespace std;
vector<int>ady[MAXV];
int D[MAXV1],Mx[MAXV1],My[MAXV1];
int N,M,x,y;
bool bfs(){
	int u,v,i,e;
	queue<int>cola;
	bool f=0;
	for(i=0;i<N+M;i++)D[i]=0;
	for(i=0;i<N;i++)if(Mx[i]==-1)cola.push(i);
	while(!cola.empty()){
		u=cola.front();cola.pop();
		for(e=ady[u].size()-1;e>=0;e--){
			v=ady[u][e];
			if(D[v+N])continue;
			D[v+N]=D[u]+1;
			if(My[v]!=-1){
				D[My[v]]=D[v+N]+1;
				cola.push(My[v]);
			}else f=1;
		}
	}
	return f;
}
int dfs(int u){
	for(int v,e=ady[u].size()-1;e>=0;e--){
		v=ady[u][e];
		if(D[v+N]!=D[u]+1)continue;
		D[v+N]=0;
		if(My[v]==-1||dfs(My[v])){
			Mx[u]=v;My[v]=u;return 1;
		}

	}
	return 0;
}
int hopcroft_karp(){
	int i,flow=0;
	for(i=max(N,M);i>=0;i--)Mx[i]=My[i]=-1;
	while(bfs()){
		for(i=0;i<N;i++)
			if(Mx[i]==-1 && dfs(i))
				flow++;
	}
	return flow;
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>N>>M){
		for(int i=0;i<M;i++){
			cin>>x>>y;
			ady[x].push_back(y);
		}
		printf("%s\n",hopcroft_karp()==N?"YES":"NO");
		for(int i=0;i<=N;i++)
			ady[i].clear();
	}
}
