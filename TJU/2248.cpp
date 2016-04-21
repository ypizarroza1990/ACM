#include <bits/stdc++.h>
#define MAX 1000
#define INF INT_MAX
using namespace std;
typedef long long i64;
int G[MAX][MAX];
bool adj[MAX][MAX];
int prev[MAX],V,root,M;
bool visit[MAX],cycle[MAX];
int MCA;

void add_edge(int u,int v,int c){
	if(adj[u][v])G[u][v]=min(c,G[u][v]);
	else G[u][v]=c;
	adj[u][v]=true;
}
void dfs(int v){
	visit[v]=true;
	for(int i=0;i<V;i++){
		if(!visit[i] && adj[v][i])
			dfs(i);
	}
}
bool check(){
	memset(visit,0,sizeof(visit));

	dfs(root);

	for(int i=0;i<V;i++){
		if(!visit[i])
			return false;
	}
	return true;
}
int exit_cycle(){

	prev[root]=root;

	for(int i=0;i<V;i++){
		if(!cycle[i] && i!=root){
			prev[i]=i; G[i][i]=INF;

			for(int j=0;j<V;j++){
				if(!cycle[j] && adj[j][i] && G[j][i]<G[prev[i]][i])
					prev[i]=j;
			}
		}
	}
	for(int i=0,j;i<V;i++){
		if(cycle[i])continue;
		memset(visit,0,sizeof(visit));
		j=i;
		while(!visit[j]){
			visit[j]=true;
			j=prev[j];
		}
		if(j==root)continue;
		return j;
	}
	return -1;
}
void update(int v){

	MCA+=G[prev[v]][v];

	for(int i=prev[v];i!=v;i=prev[i]){
		MCA+=G[prev[i]][i];
		cycle[i]=true;
	}

	for(int i=0;i<V;i++){
		if(!cycle[i] && adj[i][v])
			G[i][v]-=G[prev[v]][v];
	}

	for(int j=prev[v];j!=v;j=prev[j]){
		for(int i=0;i<V;i++){
			if(cycle[i])continue;

			if(adj[i][j]){
				if(adj[i][v])G[i][v]=min(G[i][v],G[i][j]-G[prev[j]][j]);
				else G[i][v]=G[i][j]-G[prev[j]][j];
				adj[i][v]=true;
			}
			if(adj[j][i]){
				if(adj[v][i])G[v][i]=min(G[v][i],G[j][i]);
				else G[v][i]=G[j][i];
				adj[v][i]=true;
			}
		}
	}
}

bool min_costarborecent(int _root){

	root = _root;
	if(!check())return false;

	memset(cycle,0,sizeof(cycle));
	MCA=0;

	int v;

	while((v=exit_cycle())!=-1)
		update(v);
	for(int i=0;i<V;i++){
		if(i!=root && !cycle[i])
			MCA+=G[prev[i]][i];
	}
	return true;
}
int x,y,c;
int main() {

	while(scanf("%d%d",&V,&M),V){

		memset(adj,0,sizeof(adj));
		for(int i=0;i<M;i++){
			scanf("%d%d%d",&x,&y,&c);
			x--,y--;
			add_edge(x,y,c);
		}
		if(!min_costarborecent(0))puts("impossible");
		else printf("%d\n",MCA);
	}
}
