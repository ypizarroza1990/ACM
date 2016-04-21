#include <bits/stdc++.h>
#define MAX 100009
using namespace std;
typedef long long i64;
struct edge{
	int from,cost;
	edge(int _f=0,int _c=0){
		from=_f,cost=_c;
	}
};
int LCA[16][MAX],level[MAX];
i64 D[16][MAX];
bool mark[MAX];
vector<vector<edge> >G;
int LOG(int p){
	int log;
	for(log=0;(1<<log)<=p;log++);
		return log-1;
}
void dfs(int u){
	mark[u]=true;
	for(int i=0;i<(int)G[u].size();i++){
		int v=G[u][i].from;
		if(!mark[v]){
			LCA[0][v]=u;
			level[v]=level[u]+1;
			D[0][v]=G[u][i].cost;
			int lg=LOG(level[v]);
			for(int j=1;j<=lg;j++){
				if(LCA[j-1][v]!=-1){
					LCA[j][v]=LCA[j-1][LCA[j-1][v]];
					D[j][v]=D[j-1][v]+D[j-1][LCA[j-1][v]];
				}
			}
			dfs(v);
		}
	}
}
int lca(int p,int q){
	if(level[p]<level[q])
		swap(p,q);
	int lg=LOG(level[p]);

	if(level[p]!=level[q])
		for(int i=lg;i>=0;i--)
			if(level[p]-(1<<i)>=level[q])
				p=LCA[i][p];

	if(p==q)return p;

	for(int i=lg;i>=0;i--){
		if(LCA[i][p]!=-1 && LCA[i][p]!=LCA[i][q]){
			p=LCA[i][p];
			q=LCA[i][q];
		}
	}
	return LCA[0][p];
}
i64 Query(int p,int q){
	if(level[p]<level[q])
			swap(p,q);
	int lg=LOG(level[p]);
	i64 dist=0;
	for(int i=lg;i>=0;i--){
		if(level[p]-(1<<i)>=level[q]){
			dist+=D[i][p];
			p=LCA[i][p];
		}
	}
	return dist;
}
int cas,n,m,x,y,c,q,ok;
int main( ) {
	//freopen("ent.in","r",stdin);
	while(scanf("%d",&n),n){
		G.clear();ok=0;
		G.resize(n+10);
		memset(LCA,-1,sizeof(LCA));
		memset(D,0,sizeof(D));
		memset(mark,0,sizeof(mark));
		for(int i=1;i<n;i++){
			scanf("%d %d",&y,&c);
			G[i].push_back(edge(y,c));
			G[y].push_back(edge(i,c));
		}
		dfs(1);
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&x,&y);
			int pivot=lca(x,y);
			i64 dist=Query(x,pivot)+Query(y,pivot);
			if(ok)printf(" ");
			printf("%lld",dist);
			ok=1;
			}
		printf("\n");
		}
	return 0;
}
