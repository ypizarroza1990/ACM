#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 100000
#define P(x)(x)*(x)
using namespace std;
typedef pair<double,double>pi;
vector<pi>V;
double Distancia(pi a,pi b){
	return sqrt(P(a.first-b.first)+P(a.second-b.second));
}
struct edge {
	int f, t;
	double c;
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
		for (int i = 0; i < n; i++)
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
double mst(int nodes,int m) {
	disjoint_set s(nodes);
	sort(edge_list.begin(), edge_list.end());
	double  resul=-1e9;
	for (int i = 0; i < edge_list.size() && s.numSets>m; i++) {
		int f = edge_list[i].f;
		int t = edge_list[i].t;
		if (!s.equal(f, t)) {
			s.join(f, t);
			resul=max(edge_list[i].c,resul);
		}
	}
	return resul;
}
int n,cas,m;
vector<pi>C;
string N;
double x,y;
int main()
{
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&m,&n);
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&x,&y);
			C.push_back(make_pair(x,y));
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				edge_list.push_back(edge(i,j,Distancia(C[i],C[j])));
			}
		}
		printf("%.2lf\n",mst(n,m));
		C.clear();edge_list.clear();
	}
	return 0;
}
