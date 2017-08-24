#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int>parent;
	vector<int>rank;
	int N;

	DSU(int n){
		parent =  vector<int>(n,0);
		rank =  vector<int>(n,0);
		N = n;
		for(int i=0;i<N;i++)
			parent[i]=i;
	}
	int find(int x){
		if(parent[x]==x)
			return x;
		else
			return parent[x] = find(parent[x]);
	}
	bool equal(int x,int y){
		return find(x)==find(y);
	}
	void join(int x,int y){
		int x1=find(x),x2=find(y);
		if(x1 == x2)return;
		if(rank[x1]==rank[x2])rank[x1]++;
		if(rank[x1]<rank[x2])swap(x1,x2);
		parent[x2]=parent[x1];
		N--;
	}
};
struct edge {
	int f, t, c;
	edge() { f = t = c = 0; }
	edge(int _f, int _t, int _c)
	: f(_f), t(_t), c(_c) { }
	bool operator < (const edge &e) const {
		return c > e.c;
	}
};
vector<edge>E;
int sum,n,m;
pair<int,int>MST(int n){
	int _sum=0,_max=0;
	DSU D(n);
	sort(E.begin(),E.end());
	for(int i=0;i<m;i++){
		int x=E[i].f;int y=E[i].t;
		if(D.equal(x,y)){
			_max=max(_max,E[i].c);
			_sum += E[i].c;
		}
		D.join(x,y);
	}
	return make_pair(_sum,_max);
}
int x,y,w;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y>>w;x--,y--;
		E.push_back(edge(x,y,w));
		sum += w;
	}
	pair<int,int>S=MST(n);
	cout<<S.first<<' '<<S.second<<"\n";
}
