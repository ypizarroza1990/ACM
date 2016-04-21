#include <bits/stdc++.h>
#define MAX_V 1500
using namespace std;
typedef long long i64;
typedef int edge_cost;
edge_cost INF =INT_MAX;
int V,root,prev[MAX_V],M;
bool adj[MAX_V][MAX_V];
edge_cost G[MAX_V][MAX_V],MCA;
bool visit[MAX_V],cycle[MAX_V];

void add_edge(int u,int v,edge_cost c){
	if(adj[u][v])G[u][v]=min(G[u][v],c);
	else G[u][v]=c;
	adj[u][v]=1;
}
void dfs(int v){
	visit[v]=1;

	for(int i=0;i<V;i++){
		if(!visit[i] && adj[v][i])
			dfs(i);
	}
}

bool check(){
	memset(visit,0,sizeof(visit));
	dfs(root);

	for(int i=0;i<V;i++)
		if(!visit[i])
			return 0;
	return 1;
}

int exist_cycle(){
	prev[root]=root;

	for(int i=0;i<V;i++){
		if(!cycle[i] && i!=root){
			prev[i]=i;G[i][i]=INF;

			for(int j=0;j<V;j++)
				if(!cycle[j] && adj[j][i] && G[j][i]<G[prev[i]][i])
					prev[i]=j;
		}
	}

	for(int i=0,j;i<V;i++){
		if(cycle[i])continue;
		memset(visit,0,sizeof(visit));

		j=i;

		while(!visit[j]){
			visit[j]=1;
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
		cycle[i]=1;
	}

	for(int i=0;i<V;i++){
		if(!cycle[i] &&adj[i][v])
			G[i][v]-=G[prev[v]][v];
	}
	for(int j=prev[v];j!=v;j=prev[j]){
		for(int i=0;i<V;i++){
			if(cycle[i])continue;

			if(adj[i][j]){
				if(adj[i][v])G[i][v]=min(G[i][v],G[i][j]-G[prev[j]][j]);
				else G[i][v]=G[i][j]-G[prev[j]][j];
				adj[i][v]=1;
			}

			if(adj[j][i]){
				if(adj[v][i])G[v][i]=min(G[v][i],G[j][i]);
				else G[v][i]=G[j][i];
				adj[v][i]=1;
			}
		}
	}
}
bool min_cost(int _root){
	root=_root;
	if(!check())return false;

	memset(cycle,0,sizeof(cycle));
	MCA=0;

	int v;
	while((v=exist_cycle())!=-1)
		update(v);

	for(int i=0;i<V;i++)
		if(i!=root && !cycle[i])
			MCA+=G[prev[i]][i];
	return 1;
}
void init(){
	for(int i=0;i<=V;i++){
		visit[i]=prev[i]=cycle[i]=0;
		for(int j=0;j<V;j++){
			adj[i][j]=G[i][j]=0;
		}

	}
}
int main()
{
	int cas,x,y,c;
	scanf("%d",&cas);
	for(int i=0;i<cas;i++){
		scanf("%d%d",&V,&M);
		init();
		for(int j=0;j<M;j++){
			scanf("%d%d%d",&x,&y,&c);
			add_edge(x,y,c);
		}
		printf("Case #%d: ",i+1);
		if(min_cost(0)==0)puts("Possums!");
		else printf("%d\n",MCA);
	}
	return 0;
}
