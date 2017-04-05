#include <bits/stdc++.h>
#define MAX 100009
#define f first
#define s second
using namespace std;
typedef pair<int,int>PI;
typedef vector<PI>VPI;
typedef vector<int>VI;
PI A[MAX];
VPI query[MAX];
int parent[MAX],ans[MAX],d[MAX];
VI B[MAX];
bool visit[MAX];
struct edge{
	int from,to,cost;
	edge(){};
	edge(int _f,int _t,int _c):from(_f),to(_t),cost(_c){};
	edge(int _f,int _c):from(_f),cost(_c){};

	bool operator<(const edge E)const{
		return cost>E.cost;
	}
};
struct Djoiset{
	int* parent;
	int* rank;

	Djoiset(int n){
		parent = new int[n+10];
		rank = new int[n+10];

		for(int i=0;i<=n;i++){
			parent[i]=i;
			rank[i]=0;
		}
	}
	int find(int x){
		return parent[x]==x?x:parent[x]=find(parent[x]);
	}
	bool equals(int x,int y){
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
vector<vector<edge> >G;
void MST(int n){
	Djoiset S(n);
	sort(edge_list.begin(),edge_list.end());
	int sz=edge_list.size(),T=0;
	for(int i=0;i<sz&&T<n-1;i++){
		int f=edge_list[i].from;
		int t=edge_list[i].to;
		if(!S.equals(f,t)){
			S.join(f,t);
			G[f].push_back(edge(t,edge_list[i].cost));
			G[t].push_back(edge(f,edge_list[i].cost));
			//printf("%d %d %d\n",f,t,edge_list[i].cost);
			T++;
		}
	}
}
void init(int n){
	memset(visit,0,sizeof(visit));
	memset(d,0,sizeof(d));
	memset(ans,0,sizeof(ans));
	G.clear();
	G.resize(n+10);
	edge_list.clear();
	for(int i=0;i<=n;i++){
		parent[i]=i;
		B[i].clear();
		query[i].clear();
	}
}
int find(int x){
	if(x==parent[x])
		return x;
	int ret=find(parent[x]);
	d[x]=min(d[x],d[parent[x]]);
	return parent[x]=ret;
}
void TarjanLCA(int u,int f){
	d[u]=(int)1e9;
	for(int i=0;i<(int)G[u].size();i++){
		int v=G[u][i].from;
		if(v==f)continue;
		TarjanLCA(v,u);
		d[v]=G[u][i].cost;
		parent[v]=u;
	}
	visit[u]=true;
	for(VPI::iterator it=query[u].begin();it!=query[u].end();it++)
		if(visit[it->first])B[find(it->first)].push_back(it->second);
	for(VI::iterator it=B[u].begin();it!=B[u].end();it++){
		int id=*it,u=A[id].f,v=A[id].s;
		find(u),find(v);
		ans[id]=min(d[u],d[v]);
	}
}
int cas,N,M,Q,x,y,c;
int main() {


		while(scanf("%d %d %d",&N,&M,&Q)==3){
		init(N);
		for(int j=0;j<M;j++){
			scanf("%d %d %d",&x,&y,&c);
			edge_list.push_back(edge(x,y,c));
		}
		MST(N);
		//scanf("%d",&Q);
		for(int j=1;j<=Q;j++){
			scanf("%d %d",&A[j].f,&A[j].s);
			query[A[j].f].push_back(make_pair(A[j].s,j));
			query[A[j].s].push_back(make_pair(A[j].f,j));
		}
		TarjanLCA(1,0);
		for(int j=1;j<=Q;j++){
			printf("%d\n",ans[j]);
		}
	}
	return 0;
}
