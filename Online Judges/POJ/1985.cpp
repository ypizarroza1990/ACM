#include <stdio.h>
#include <vector>
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
			path=max(path,tmp);
		}
	}
	return path;
}
int n,m,x,y,c;
char dir;
int main() {
	 scanf("%d %d",&n,&m);
	 G.resize(n+10);
	 for(int i=0;i<m;i++){
		 scanf("%d %d %d %c",&x,&y,&c,&dir);
		 G[x].push_back(edge(y,c));
		 G[y].push_back(edge(x,c));
	 }
	 dfs(1);
	 printf("%d\n",diameter);
}

