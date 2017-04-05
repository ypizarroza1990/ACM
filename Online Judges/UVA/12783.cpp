 
#include <bits/stdc++.h>
#define LENGTH(a) ((int)a.length())
#define SIZE(a) ((int)a.size())
using namespace std;
struct Bridge {
	static int const WHITE = -1;
	static int const BLACK = 1;
	static int const GREY = 0;

	vector<vector<int> > L;
	vector<int> low;
	vector<int> num;
	vector<int> parent;
	vector<bool> articulation;
	vector<pair<int, int> > bridges;
	int counter;
	int rootChildren;
	int root;

	Bridge(int n) {
		L = vector<vector<int> >(n);
	}

	void addEdge(int a, int b, bool undirected = false) {
		L[a].push_back(b);
		if (undirected)
			L[b].push_back(a);
	}

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
		counter = rootChildren = 0;
	}

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
				if (low[v] > num[u])
					bridges.push_back(make_pair(min(u,v),max(u,v)));
				low[u] = min(low[u], low[v]);
			} else if (v != parent[u]) {
				low[u] = min(low[u], num[v]);
			}
		}
	}
};
int N,M,x,y;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>N>>M){
		if(N+M==0)break;
		Bridge B(N);
		for(int i=0;i<M;i++){
			cin>>x>>y;
			B.addEdge(x,y,1);
		}
		B.detectBridges();
		sort(B.bridges.begin(),B.bridges.end());
		int n=B.bridges.size();
		cout<<n;
		for(int i=0;i<n;i++){
			if(i<n)cout<<" ";
			cout<<B.bridges[i].first<<" "<<B.bridges[i].second;
		}
		cout<<"\n";
	}
}
