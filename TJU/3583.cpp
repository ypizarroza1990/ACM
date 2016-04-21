#include <bits/stdc++.h>
#define MAX 50009
#define INF 100000000
using namespace std;
typedef long long i64;
struct edge{
	int x,cost;
	edge(){};
	edge(int _x,int _cost):x(_x),cost(_cost){};

	bool operator<(const edge E)const{
		return cost>E.cost;
	}
};
int d[MAX],fin;
vector<vector<edge> >G;
void Dijktra(int n,int ini){
	for(int i=0;i<n;i++)
		d[i]=INF;
	priority_queue<edge>Q;
	Q.push(edge(ini,0));
	d[ini]=0;
	while(!Q.empty()){
		edge aux=Q.top();Q.pop();
		int dist=aux.cost;
		int u=aux.x;
		if(d[u]>dist)continue;
		for(int i=0;i<G[u].size();i++){
			int d_aux=G[u][i].cost;
			int v=G[u][i].x;
			if(d[v]>d[u]+d_aux){
				d[v]=d[u]+d_aux;
				Q.push(edge(v,d[v]));
			}
		}
	}
}
int N,M,Q,x,y,c;
int main() {
	scanf("%d%d%d",&N,&M,&Q);
	G.resize(N);
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&x,&y,&c);
		x--,y--;
		G[x].push_back(edge(y,c));
		G[y].push_back(edge(x,c));
	}
	Dijktra(N,0);
	while(Q--){
		scanf("%d%d",&x,&y);
		x--,y--;
		printf("%d\n",d[x]+d[y]);
	}
	return 0;
}
