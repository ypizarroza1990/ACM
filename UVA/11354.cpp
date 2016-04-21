#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAXN 100009
using namespace std;
typedef long long i64;
typedef vector<int>VI;
typedef pair<int,int>PI;
typedef vector<PI>VPI;
struct edge{
	int from,to,cost;
	edge(){};
	edge(int f,int t,int c):from(f),to(t),cost(c){};
	edge(int f,int c):from(f),cost(c){};
	bool operator<(const edge &E)const{
		return cost<E.cost;
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
	bool equals(int x,int y){
		return find(x)==find(y);
	}
	void join(int x,int y){
		int x1=find(x),x2=find(y);
		if(x1==x2)return;
		if(rank[x1]==rank[x2])++rank[x1];
		if(rank[x1]<rank[x2])swap(x1,x2);
		parent[x2]=x1;
	}
};
vector<vector<edge> >G;
PI A[MAXN];
VI B[MAXN];
VPI query[MAXN];
int array[MAXN],ans[MAXN];
int parent[MAXN];
bool visit[MAXN];
vector<edge>edgelist;
void init(int n){
	for(int i=0;i<=n;i++){
		parent[i]=i;
		query[i].clear();
		B[i].clear();
	}
	G.clear();
	G.resize(n+10);
	edgelist.clear();
	memset(array,0,sizeof(array));
	memset(visit,0,sizeof(visit));
}
int find(int x){
	if(parent[x]==x)return x;
	int res=find(parent[x]);
	array[x]=max(array[x],array[parent[x]]);
	return parent[x]=res;
}
void tarjan(int u,int f){
	array[u]=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i].from;
		if(v==f)continue;
		tarjan(v,u);
		array[v]=G[u][i].cost;
		parent[v]=u;
	}
	visit[u]=1;
	for(VPI::iterator it=query[u].begin();it!=query[u].end();it++)
		if(visit[it->first])B[find(it->first)].push_back(it->second);
	for(VI::iterator it=B[u].begin();it!=B[u].end();it++){
		int id=*it;
		int u=A[id].first,v=A[id].second;
		find(u),find(v);
		ans[id]=max(array[u],array[v]);
	}
}
void MST(int n){
	Djoinset S(n);
	sort(edgelist.begin(),edgelist.end());
	int sz=edgelist.size(),len=0;
	for(int i=0;i<sz&&len<n-1;i++){
		int f=edgelist[i].from;
		int t=edgelist[i].to;
		if(!S.equals(f,t)){
			len++;
			S.join(f,t);
			G[f].push_back(edge(t,edgelist[i].cost));
			G[t].push_back(edge(f,edgelist[i].cost));
		}
	}
}
int n,m,q,x,y,c,ok;
int main()
{
	while(scanf("%d%d",&n,&m)==2){
		init(n);
		if(ok)puts("");
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&c);
			edgelist.push_back(edge(x,y,c));
		}
		MST(n);
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			scanf("%d%d",&A[i].first,&A[i].second);
			query[A[i].first].push_back(make_pair(A[i].second,i));
			query[A[i].second].push_back(make_pair(A[i].first,i));
		}
		tarjan(1,0);
		for(int i=1;i<=q;i++){
			printf("%d\n",ans[i]);
		}
		ok=1;
	}


}

