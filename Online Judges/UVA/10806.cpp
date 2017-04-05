
#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef vector < int > VI;
typedef vector < VI > VVI;
typedef long long L;
typedef vector < L > VL;
typedef vector < VL > VVL;
typedef pair < int, int > PII;
typedef vector < PII > VPII;

const L INF = numeric_limits < L > ::max() / 4;

struct MinCostMaxFlow {
	int N;
	VVL cap, flow, cost;
	VI found;
	VL dist, pi, width;
	VPII dad;
	MinCostMaxFlow(int N): N(N),
			cap(N, VL(N)),
			flow(N, VL(N)),
			cost(N, VL(N)),
			found(N),
			dist(N),
			pi(N),
			width(N),
			dad(N) {}
	void AddEdge(int from, int to, L cap, L cost) {
		this -> cap[from][to] = cap;
		this -> cost[from][to] = cost;
	}
	void Relax(int s, int k, L cap, L cost, int dir) {
		L val = dist[s] + pi[s] - pi[k] + cost;
		if (cap && val < dist[k]) {
			dist[k] = val;
			dad[k] = make_pair(s, dir);
			width[k] = min(cap, width[s]);
		}
	}
	L Dijkstra(int s, int t) {
		fill(found.begin(), found.end(), false);
		fill(dist.begin(), dist.end(), INF);
		fill(width.begin(), width.end(), 0);
		dist[s] = 0;
		width[s] = INF;
		while (s != -1) {
			int best = -1;
			found[s] = true;
			for (int k = 0; k < N; k++) {
				if (found[k]) continue;
				Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
				Relax(s, k, flow[k][s], -cost[k][s], -1);
				if (best == -1 || dist[k] < dist[best]) best = k;
			}
			s = best;
		}
		for (int k = 0; k < N; k++)
			pi[k] = min(pi[k] + dist[k], INF);
		return width[t];
	}
	pair < L, L > GetMaxFlow(int s, int t) {
		L totflow = 0, totcost = 0;
		while (L amt = Dijkstra(s, t)) {
			totflow += amt;
			for (int x = t; x != s; x = dad[x].first) {
				if (dad[x].second == 1) {
					flow[dad[x].first][x] += amt;
					totcost += amt * cost[dad[x].first][x];
				} else {
					flow[x][dad[x].first] -= amt;
					totcost -= amt * cost[x][dad[x].first];
				}
			}
		}
		return make_pair(totflow, totcost);
	}
};
int n,m,x,y,c;
int main(){

	while(cin>>n){
		if(!n)break;
		cin>>m;
		MinCostMaxFlow mcm(2*n+10);
		mcm.AddEdge(0,1,2,0);
		for(int i=1;i<=n;i++){
			mcm.AddEdge(i,i+n,INF,0);
			mcm.AddEdge(i+n,i,INF,0);
		}
		for(int i=0;i<m;i++){
			cin>>x>>y>>c;
			mcm.AddEdge(x+n,y,1,c);
			mcm.AddEdge(y+n,x,1,c);
		}
		mcm.AddEdge(2*n,2*n+1,1000,0);
		pair<L,L>Y=mcm.GetMaxFlow(0,2*n+1);
		if(Y.first!=2)puts("Back to jail");
		else cout<<Y.second<<endl;
	}
}

