#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long Long;
struct GraphCC {
	VI vis, LOW, ID, AP;
	VVI adj, SCC, BCC, CC;
	stack<int> S;
	int N;
	bool directed;
	GraphCC(int N, bool directed = false){
		this->N = N;
		this->directed = directed;
		adj = VVI(N);
		vis = VI(N);
		LOW = VI(N);
		ID = VI(N);
	}
	void addEdge(int u, int v){
		adj[u].push_back(v);
		if(!directed)adj[v].push_back(u);
	}
	VI getArticPoints(){
		AP.clear();
		vis = vector<int>(N);
		for (int i = 0, IDX = 1; i < N; ++i, IDX = 1) {
			dfsArticPoints(i, -1, IDX);
		}
		sort(AP.begin(), AP.end());
		return AP;
	}
	void dfsArticPoints(int u, int p, int &IDX){
		if(vis[u])return;
		vis[u] = 1;
		int cnt = 0;
		ID[u] = LOW[u] = IDX++;
		bool isAp = false;
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i];
			if(v ==p)continue;
			if(!vis[v]){
				cnt++;
				dfsArticPoints(v, u, IDX);
				LOW[u] = min(LOW[u], LOW[v]);
				isAp = isAp || (LOW[v] >= ID[u]);
			}else{
				LOW[u] = min(LOW[u], ID[v]);
			}
		}
		if(cnt && isAp && (ID[u] > 1 || cnt > 1)){
			AP.push_back(u);
		}
	}
	
};

int ISA[100010];
int VIS[100010];
int ISAS[100010], SZ;

PII dfs(int u, VVI &adj){
	VIS[u] = 1;
	if(ISA[u]){
		ISAS[ SZ++ ] = u;
		return PII(0,1);
	}
	PII r(1,0);
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if(VIS[v])continue;
		PII t = dfs(v, adj);
		r.first += t.first;
		r.second += t.second;
	}
	return r;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M;
	for(int tc = 1; cin >> M && M != 0; ++tc){
		vector<PII> E(M);
		Long N = 0;
		for (int i = 0; i < M; ++i) {
			cin >> E[i].first >> E[i].second;
			N = max(N, (Long)E[i].first);
			N = max(N, (Long)E[i].second);
			E[i].first--;
			E[i].second--;
		}
		
		GraphCC G(N);
		for (int i = 0; i < M; ++i) {
			G.addEdge(E[i].first, E[i].second);
		}
		VI ap = G.getArticPoints();
		if(ap.size() == 0){
			cout << "Case " << tc << ": "<< 2 << " " << (N*(N-1))/2 << '\n';
		}else{
			Long ans = 1, cnt = 0;
			for (int i = 0; i < ap.size(); ++i) {
				ISA[ap[i]] = 1;
			}
			for (int i = 0; i < N; ++i) {
				if(!ISA[i] && !VIS[i]){
					PII t = dfs(i, G.adj);
					for (int j = 0; j < SZ; ++j) {
						VIS[ ISAS[j] ] = 0;
					}
					SZ = 0;
					if(t.second > 1)continue;
					cnt += 1;
					ans *= t.first;
				}
			}
			cout << "Case " << tc << ": "<< cnt << " " << ans << '\n';
		}
		for (int i = 0; i < N; ++i) {
			ISA[i] = 0;
			VIS[i] = 0;
		}
	}
	
	
}