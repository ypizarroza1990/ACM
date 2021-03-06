#include <stdio.h>
#include <vector>
#include <string.h>
#define MAX 50000
using namespace std;
typedef long long i64;
i64 Level[MAX+1],LCA[20][MAX+1],D[20][MAX+1],N,M,Q;
bool visit[MAX+1];
struct edge{
	int to,cost;
	edge(){};
	edge(int t,int c):to(t),cost(c){};
};
int LOG(int x){
	int i;
	for(i=0;(1<<i)<=x;i++);
		i--;
	return i;
}
vector<vector<edge> >G;
void dfs(int u){
	visit[u]=1;
	for(int i=0;i<(int)G[u].size();i++){
		int v=G[u][i].to;
		if(!visit[v]){
			LCA[0][v]=u;
			Level[v]=Level[u]+1;
			D[0][v]=G[u][i].cost;
			int lg=LOG(Level[v]);
	//preprocess
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
	if(Level[p]<Level[q])
		swap(p,q);
	int lg=LOG(Level[p]);
	if(Level[p]!=Level[q]){
		for(int j=lg;j>=0;j--){
			if(Level[p]-(1<<j)>=Level[q])
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
i64 distanceq(int p,int q){
	i64 ans=0;
	if(Level[p]<Level[q])
		swap(p,q);
	int lg=LOG(Level[p]);
	for(int j=lg;j>=0;j--){
		if(Level[p]-(1<<j)>=Level[q]){
			ans+=D[j][p];
			p=LCA[j][p];
		}
	}
	return ans;
}
int x,y,c;
char dir;
int main() {
	scanf("%d %d",&N,&M);
	G.resize(N+10);
	for(int i=0;i<M;i++){
		scanf("%d %d %d %c",&x,&y,&c,&dir);
		G[x].push_back(edge(y,c));
		G[y].push_back(edge(x,c));
	}
	memset(LCA,-1,sizeof(LCA));
	memset(visit,0,sizeof(visit));
	dfs(1);
	scanf("%d",&Q);
	while(Q--){
		scanf("%d %d",&x,&y);
		int ant=lca(x,y);
		printf("%lld\n",distanceq(x,ant)+distanceq(y,ant));
	}
	return 0;
}