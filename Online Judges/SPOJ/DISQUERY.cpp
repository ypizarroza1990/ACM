#include <bits/stdc++.h>
#define MAX 100009
#define LOG(x)31-__builtin_clz(x);
using namespace std;
bool visit[MAX];
int LCA[20][MAX],L[MAX];
pair<int,int>D[20][MAX];
struct edge{
	int from,to,cost;
	edge(){};
	edge(int _f,int _t,int _c):from(_f),to(_t),cost(_c){};
	edge(int _f,int _c):from(_f),cost(_c){};

	bool operator<(const edge E)const{
		return cost>E.cost;
	}
};
vector<vector<edge> >G;
void init(int n){
	memset(visit,0,sizeof(visit));
	G.resize(n+10);
}
void dfs(int v){
	visit[v]=1;
	for(int i=0;i<(int)G[v].size();i++){
		int ady=G[v][i].from;
		if(!visit[ady]){
			LCA[0][ady]=v;
			L[ady]=L[v]+1;
			D[0][ady].first=G[v][i].cost;
			D[0][ady].second=G[v][i].cost;
			int log=LOG(L[ady]);
			for(int j=1;j<=log;j++){
				if(LCA[j-1][ady]!=-1){
					LCA[j][ady]=LCA[j-1][LCA[j-1][ady]];
					D[j][ady].first=min(D[j-1][ady].first,D[j-1][LCA[j-1][ady]].first);
					D[j][ady].second=max(D[j-1][ady].second,D[j-1][LCA[j-1][ady]].second);
				}
			}
			dfs(ady);
		}
	}
}
int lca(int p,int q){
	if(L[p]<L[q])
		swap(p,q);
	int lg=LOG(L[p]);
	if(L[p]!=L[q]){
		for(int j=lg;j>=0;j--){
			if(L[p]-(1<<j)>=L[q])
				p=LCA[j][p];
		}
	}
	if(p==q)
		return p;
	for(int j=lg;j>=0;j--){
		if(LCA[j][p]!=LCA[j][q]&&LCA[j][p]!=-1){
			p=LCA[j][p];
			q=LCA[j][q];
		}
	}
	return LCA[0][p];
}
pair<int,int> distanceq(int p,int q){
	pair<int,int> ans;
	ans.first=INT_MAX;ans.second=-INT_MAX;
	if(L[p]<L[q])
		swap(p,q);
	int lg=LOG(L[p]);
	for(int j=lg;j>=0;j--){
		if(L[p]-(1<<j)>=L[q]){
			ans.first=min(ans.first,D[j][p].first);
			ans.second=max(ans.second,D[j][p].second);
			p=LCA[j][p];
		}
	}
	return ans;
}
int cas,N,M,Q,x,y,c;
int main() {

	scanf("%d",&N);
		init(N);
		for(int j=0;j<N-1;j++){
			scanf("%d %d %d",&x,&y,&c);
			G[x].push_back(edge(y,c));
			G[y].push_back(edge(x,c));
		}
		dfs(1);
		int u,v,lc;
		scanf("%d",&Q);
		for(int j=1;j<=Q;j++){
			scanf("%d %d",&u,&v);
			lc=lca(u,v);
			pair<int,int> one=distanceq(u,lc);
			pair<int,int> two=distanceq(lc,v);
			printf("%d ",min(one.first,two.first));
			printf("%d\n",max(one.second,two.second));
		}
	return 0;
}

