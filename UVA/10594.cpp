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
struct edge{
	int from,to,cost;
	edge(int f=0,int t=0,int c=0):from(f),to(t),cost(c){};
}G[5900];
int n,m,D,K;
int main()
{
	while(scanf("%d%d",&n,&m)==2){
		MinCostMaxFlow mcm(2*n+10);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&G[i].from,&G[i].to,&G[i].cost);
		}
		scanf("%d%d",&D,&K);
		for(int i=1;i<=n;i++){
			mcm.AddEdge(i,i+n,INF,0);
			mcm.AddEdge(i+n,i,INF,0);
		}
		mcm.AddEdge(0,1,D,0);
		for(int i=0;i<m;i++){
			mcm.AddEdge(G[i].from+n,G[i].to,K,G[i].cost);
			mcm.AddEdge(G[i].to+n,G[i].from,K,G[i].cost);
		}
		mcm.AddEdge(2*n,2*n+1,INF,0);
		pair<L,L>Y=mcm.GetMaxFlow(0,2*n+1);

		if(Y.first!=D)puts("Impossible.");
		else printf("%lld\n",Y.second);
	}
	return 0;
}

