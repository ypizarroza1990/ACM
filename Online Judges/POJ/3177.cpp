#include <vector>
#include <stdio.h>
#include <set>
#include <queue>
#include <string.h>
#define SIZE(L)((int)L.size())
#define MAX 10009
using namespace std;
set<int>G[MAX];
int degree[MAX],scc[MAX];
int cur_scc,cas,N,M;
bool visit[MAX];
struct Bridge {
	static int const WHITE = -1;
	static int const BLACK = 1;
	static int const GREY = 0;

	vector<vector<int> > L;
	vector<int> low ;
	vector<int> num ;
	vector<int> parent;
	vector<bool> articulation;
	vector<pair<int, int> > bridges;
	int counter;
	int rootChildren;
	int root;

	Bridge(int n) {
		L = vector<vector<int> >(n);	}

	void addEdge(int a, int b, bool undirected = false){
		L[a].push_back(b);
		if (undirected)
			L[b].push_back(a);	}

	void detectBridges() {
		initForBridges();
		for (int i = 0; i < SIZE(L); ++i)
			if (num[i] == WHITE) {
				this->root = i;
				this->rootChildren = 0;
				markBridges(i);
				articulation[root] = rootChildren > 1;
			}
	}

	void initForBridges() {
		num = vector<int>(SIZE(L), WHITE);
		low = vector<int>(SIZE(L), GREY);
		parent = vector<int>(SIZE(L), GREY);
		articulation = vector<bool>(SIZE(L), false);
		bridges.clear();
		counter = rootChildren = 0;}

	void markBridges(int u) {
		low[u] = num[u] = counter++;
		for (int i = 0; i < SIZE(L[u]); ++i) {
			int v = L[u][i];
			if (num[v] == WHITE) {
				parent[v] = u;
				if (u == root) ++rootChildren;
				markBridges(v);
				if (low[v] >= num[u])
					articulation[u] = true;
				if (low[v] > num[u]){
					bridges.push_back(make_pair(min(u,v),max(u, v)));
					G[u].erase(v);
					G[v].erase(u);
				}
				low[u] = min(low[u], low[v]);
			} else if (v != parent[u]) {
				low[u] = min(low[u], num[v]);
			}
		}
	}
};

int main(){

		scanf("%d %d",&N,&M);
		Bridge B(N+1);
		int x,y;

		for(int i=0;i<=N;i++){
			G[i].clear();
		}
		for(int i=0;i<M;i++){
			scanf("%d %d",&x,&y);
			B.addEdge(x,y,true);
			G[x].insert(y);
			G[y].insert(x);
		}
		B.detectBridges();
		memset(visit,0,sizeof(visit));
		memset(degree,0,sizeof(degree));
		memset(scc,0,sizeof(scc));
		cur_scc=0;
		for(int i=0;i<N;i++){

			if(visit[i])continue;

			queue<int>Q;
			Q.push(i);

			while(!Q.empty()){
				int act=Q.front();Q.pop();
				if(visit[act])continue;
				visit[act]=true;
				scc[act]=cur_scc;
				for(set<int>::iterator x=G[act].begin();x!=G[act].end();x++){
					Q.push(*x);
				}
			}
			cur_scc++;
		}
		for(int i=0;i<(int)B.bridges.size();i++){
			degree[scc[B.bridges[i].first]]++;
			degree[scc[B.bridges[i].second]]++;
		}
		int sol=0;
		for(int i=0;i<cur_scc;i++){
			if(degree[i]==1)sol++;
		}
		printf("%d\n",(sol+1)/2);
}
 
