#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,cost;

	edge(){};
	edge(int t,int c):to(t),cost(c){};
	bool operator<(const edge& N)const{
		return cost>N.cost;
	}
};
vector<edge>G[10009];
int distancia[2][10009];
void dijktra(int src,int ini){
	fill(distancia[src],distancia[src]+10009,-1);
	priority_queue<edge>Q;
	distancia[src][ini]=0;
	Q.push(edge(ini,0));
	while(!Q.empty()){
		int pos = Q.top().to;
		int dist = Q.top().cost;
		Q.pop();
		for(int i=0;i<G[pos].size();i++){
			int aux_to = G[pos].at(i).to;
			int aux_dist = G[pos][i].cost;
			if(distancia[src][aux_to]>dist+aux_dist || distancia[src][aux_to]==-1){
				distancia[src][aux_to]=dist+aux_dist;
				Q.push(edge(aux_to,distancia[src][aux_to]));
			}
		}
	}
}
int n,m,x,y,c;
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>m){
		for(int i=0;i<n;i++)
			G[i].clear();
		for(int i=0;i<m;i++){
			cin>>x>>y>>c;
			G[x].push_back(edge(y,c));
			G[y].push_back(edge(x,c));
		}
		dijktra(0,0);
		dijktra(1,n-1);
		long dist = distancia[1][0],ans=0;
		for(int i=0;i<n;i++){
			for(int j = 0;j<G[i].size();j++){
				if(distancia[0][i]==-1 || distancia[1][G[i][j].to]==-1)continue;
				long temp = distancia[0][i]+G[i][j].cost+distancia[1][G[i][j].to];
				if(temp == dist)ans+=G[i][j].cost;
			}
		}
		cout<<ans*2<<"\n";
	}
}
