#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
#define MAX 50000
typedef long long i64;
struct edge{
	int from,cost;
	edge(){};
	edge(int f,int c):from(f),cost(c){};
};
vector<vector<edge> >G;
bool visit[MAX+1];
int diameter;
int dfs(int u){
	visit[u]=1;
	int path=0;
	for(int i=0;i<(int)G[u].size();i++){
		if(!visit[G[u][i].from]){
			int tmp=dfs(G[u][i].from)+G[u][i].cost;
			diameter=max(diameter,tmp+path);
			path=max(tmp,path);
		}
	}
	return path;
}
int n,m,x,y,c;
int cas;
int main() {
	scanf("%d",&cas);
	while(cas--){
		scanf("%d",&n);
		G.clear();
		G.resize(n+10);
		memset(visit,0,sizeof(visit));
		diameter=0;
		for(int i=0;i<n-1;i++){
			scanf("%d %d %d",&x,&y,&c);
			G[x].push_back(edge(y,c));
			G[y].push_back(edge(x,c));
		}
		dfs(1);
		printf("%d\n",diameter);
	}
}

