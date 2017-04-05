#include <bits/stdc++.h>
#define SIZE(L)(int)L.size()
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
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
		L = vector<vector<int> >(n);
	}

	void addEdge(int a, int b, bool undirected = false){
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
					bridges.push_back(make_pair(u, v));
				low[u] = min(low[u], low[v]);
			} else if (v != parent[u]) {
				low[u] = min(low[u], num[v]);
			}
		}
	}
};
int N,x,y,ans;
string line,c;
int main ()
{
	while(scanf("%d",&N),N){
		Bridge B(N);
		ans=0;
		getchar();
		while(getline(cin,line)){
			if(line=="0")break;
			stringstream ss(line);
			ss>>c;
			x=atoi(c.c_str());
			x--;
			while(ss>>c){
				y=atoi(c.c_str());
				y--;
				B.addEdge(x,y,true);
			}
		}
		B.detectBridges();
		for(int i=0;i<SIZE(B.articulation);i++)
			if(B.articulation[i])
				ans++;
		printf("%d\n",ans);
	}

	return 0;
}
