#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 10007
#define P(x)(x)*(x)
using namespace std;
struct edge{
	int to,cost;
	edge(int t,int c):to(t),cost(c){};
};
int diameter;
vector<edge>G[10009];
bool visit[MAX];
char cad[500];
int dfs(int v){
	int path=0;
	visit[v]=1;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i].to;
		if(!visit[u]){
			int tmp=G[v][i].cost+dfs(u);
			diameter=max(diameter,tmp+path);
			path=max(path,tmp);
		}
	}
	return path;
}
int x,y,c,nodes;
int main()
{
	//freopen("A.in","r",stdin);
	bool ok=1;
	while(ok){
		nodes=0;
		while(1){
			if(gets(cad)==NULL){
				ok=0;
				break;
			}
			else if(cad[0]){
				sscanf(cad,"%d %d %d",&x,&y,&c);
				G[x].push_back(edge(y,c));
				G[y].push_back(edge(x,c));
				nodes=max(nodes,max(x,y));
			}
			else break;
		}
		diameter=0;
		dfs(1);
		cout<<diameter<<"\n";
		for(int i=0;i<=nodes;i++){
			G[i].clear();
			visit[i]=0;
		}
	}
	return 0;
}
 
