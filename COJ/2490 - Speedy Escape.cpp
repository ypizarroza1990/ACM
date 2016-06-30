#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define VI vector<double>
#define INF 0x77777777
struct edge{
	int to;
	double cost;
	edge(){};
	edge(int t,double c):to(t),cost(c){};
	bool operator<(const edge &e)const{
		return cost>e.cost;
	}
};
vector<edge>G[101];
bool visit[101],can_use[101];
set<int> exist;
VI brother,police;
int n,m,e,ini,fin;
double cost;
VI Dijktra(int begin){
	VI dist(n,INF);
	dist[begin]= 0;
	priority_queue<edge>Q;
	Q.push(edge(begin,0));
	while(!Q.empty()){
		int to = Q.top().to;
		int peso = Q.top().cost;
		Q.pop();
		for(int i=0;i<(int)G[to].size();i++){
			if(peso+G[to][i].cost<dist[G[to][i].to]){
				dist[G[to][i].to] = peso+G[to][i].cost;
				Q.push(edge(G[to][i].to,dist[G[to][i].to]));
			}
		}
	}
	return dist;
}
bool exist_camino(){
	memset(visit,0,sizeof(visit));
	queue<int>Q;
	Q.push(ini);
	visit[ini];
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		for(int i=0;i<G[cur].size();i++){
			int next = G[cur][i].to;
			if(can_use[next]&& !visit[next]){
				if(exist.count(next))
					return true;
				visit[next]=true;
				Q.push(next);
			}
		}
	}
	return false;
}
double solve()
{
	if(exist.count(ini))return 0;
	if(e==1 && exist.count(fin))return -1;
	double ini = 0;
	double fin = INF;

	while(ini<fin && fin-ini>1e-9){
		double speed = (ini+fin)/2;
		memset(can_use,1,sizeof(can_use));

		for(int i=0;i<n;i++){
			double time_bro = brother[i]/speed;
			double time_pol = police[i]/160;
			if(time_pol <= time_bro)
				can_use[i] = false;
		}
		if(exist_camino())
			fin = speed;
		else
			ini = speed;
	}
	return (ini<INF-1)?ini:-1;
}
int cas;
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>m>>e){
		for(int i=0;i<101;i++)
			G[i].clear();
		exist.clear();
		for(int i=0;i<m;i++){
			cin>>ini>>fin>>cost;
			ini--;fin--;
			G[ini].push_back(edge(fin,cost));
			G[fin].push_back(edge(ini,cost));
		}
		for(int i=0;i<e;i++){
			cin>>ini;
			ini--;
			exist.insert(ini);
		}
		cin>>ini>>fin;
		ini--;fin--;
		brother = Dijktra(ini);
		police = Dijktra(fin);

		double res = solve();
		if(res<0.0)
			cout<<"IMPOSSIBLE\n";
		else
			cout<<setprecision(9)<<fixed<<res<<"\n";
	}
	return 0;
}

