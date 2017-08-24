#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 100000
#define P(x)(x)*(x)
using namespace std;
typedef pair<int,int>pi;
vector<pi>V;

struct edge {
	int f, t;
	int c;
	edge() { f = t = c = 0; }
	edge(int _f, int _t, double _c)
	: f(_f), t(_t), c(_c) { }
	bool operator < (const edge &e) const {
		return c < e.c;
	}
};

struct disjoint_set {
	int* parent;
	int* rank;
	int* setSize;
	int numSets;

	disjoint_set(int n) {
		parent = new int[n+9];
		rank = new int[n+9];
		setSize = new int[n+9];
		numSets = n;
		memset(setSize,1,sizeof(setSize));
		for (int i = 0; i <= n; i++)
			parent[i] = i;
	}

	int find(int setNum) {
		return parent[setNum] == setNum ? setNum :parent[setNum] = find(parent[setNum]);
	}

	bool equal(int s1, int s2) {
		return find(s1) == find(s2);
	}

	void join(int s1, int s2) {
		int p1 = find(s1);
		int p2 = find(s2);
		if (p1 == p2) return;
		if (rank[p1] == rank[p2])
			++rank[p1];
		if (rank[p1] < rank[p2])
			swap(p1, p2);
		parent[p2] = p1;
		setSize[p1] += setSize[p2];
		--numSets;
	}
};

vector<edge> edge_list;
int mst(int nodes) {
	disjoint_set s(nodes);
	int  resul=0;
	for (int i = 0; i < edge_list.size(); i++) {
		int f = edge_list[i].f;
		int t = edge_list[i].t;
		if (s.equal(f, t)) {
			resul++;
		}
		s.join(f, t);
	}
	return resul;
}
int n,cas,m;
vector<pi>C;
string N;
int x,y;
int main()
{
	while(cin>>x){
		if(x == -1){
			cout<<mst(n)<<'\n';
			edge_list.clear();n = 0;
		}
		else{
			cin>>y;
			n = max(n,max(x,y));
			edge_list.push_back(edge(x,y,1));
		}
	}
	return 0;
}
 
