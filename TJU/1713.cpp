#include <bits/stdc++.h>
#define MAX 100019
#define LOG(x)31-__builtin_clz(x);
using namespace std;
typedef long long i64;
typedef pair<int,int>PI;
typedef vector<PI>VPI;
typedef vector<int>VI;
struct edge{
	int from,to,cost;
	edge(){};
	edge(int f,int t,int c):from(f),to(t),cost(c){};
	edge(int f,int c):from(f),cost(c){};
	bool operator<(const edge E)const{
		return cost>E.cost;
	}
};
struct Djoinset{
	int* parent;
	int* rank;

	Djoinset(int n){
		parent=new int[n+10];
		rank=new int[n+10];

		for(int i=0;i<=n;i++){
			parent[i]=i;
			rank[i]=0;
		}
	}
	int find(int x){
		return parent[x]==x?x:parent[x]=find(parent[x]);
	}
	bool equal(int x,int y){
		return find(x)==find(y);
	}
	void join(int x,int y){
		int x1=find(x),x2=find(y);
		if(x1==x2)return;

		if(rank[x1]==rank[x2])++rank[x1];
		if(rank[x1]<rank[x2])
			swap(x1,x2);

		parent[x2]=x1;
	}
};
vector<edge>edge_list;
VPI query[1009];
VI B[1009];
PI A[1009];
int parent[1009],D[1009],ans[1009];
bool visit[1009];
vector<vector<edge> >G;
void init(int n){
	G.clear();
	G.resize(n+10);
	edge_list.clear();
	memset(visit,0,sizeof(visit));
	memset(D,0,sizeof(D));
	for(int i=0;i<=n;i++){
		parent[i]=i;
		B[i].clear();
		query[i].clear();
		ans[i]=0;
	}
}
int find(int x){
	if(parent[x]==x)return x;
	int res=find(parent[x]);
	D[x]=min(D[x],D[parent[x]]);
	return parent[x]=res;
}
void MST(int nodes){
	Djoinset D(nodes);
	sort(edge_list.begin(),edge_list.end());
	int sz=edge_list.size(),aux=0;
	for(int i=0;i<sz&&aux<nodes-1;i++){
		int f=edge_list[i].from;
		int t=edge_list[i].to;
		if(!D.equal(f,t)){
			D.join(f,t);
			aux++;
			G[f].push_back(edge(t,edge_list[i].cost));
			G[t].push_back(edge(f,edge_list[i].cost));
		}
	}
}
void tarjan(int u,int f){
	D[u]=1<<30;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i].from;
		if(v==f)continue;
		tarjan(v,u);
		D[v]=G[u][i].cost;
		parent[v]=u;
	}
	visit[u]=1;
	for(VPI::iterator it=query[u].begin();it!=query[u].end();it++)
		if(visit[it->first]){B[find(it->first)].push_back(it->second);}
	for(VI::iterator it=B[u].begin();it!=B[u].end();it++){
		int id=*it;
		int u=A[id].first,v=A[id].second;
		find(u),find(v);
		ans[id]=min(D[u],D[v]);
	}

}
int cas,n,m,x,y,c,ok=0;
int main() {
	scanf("%d",&cas);
	for(int i=1;i<=cas;i++){
		scanf("%d%d",&n,&m);
		init(n);
		for(int j=0;j<m;j++){
			scanf("%d%d%d",&x,&y,&c);
			edge_list.push_back(edge(x,y,c));
		}
		A[1].first=1,A[1].second=n;
		query[A[1].first].push_back(make_pair(A[1].second,1));
		query[A[1].second].push_back(make_pair(A[1].first,1));
		MST(n);
		tarjan(1,0);
		for(int j=1;j<=1;j++)
			printf("Scenario #%d:\n%d\n\n",i,ans[j]);

	}

}

