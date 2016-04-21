#include<bits/stdc++.h>
#define MAX 1000009
using namespace std;
typedef pair<int,int>PI;
typedef vector<int>VI;
typedef vector<PI>VPI;
struct edge{
	int from,to,cost;
	edge(){};
	edge(int f,int c):from(f),cost(c){};
	edge(int f,int t,int c):from(f),to(t),cost(c){};
	bool operator<(const edge &E)const{
		return cost<E.cost;
	}
};
struct Djoinset{
	int*parent;
	int *rank;

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
		if(rank[x1]<rank[x2])
			swap(x1,x2);
		parent[x2]=x1;
	}
};
VPI query[MAX];
VI B[MAX];
PI A[MAX];
bool visit[MAX];
int ans[MAX],D[MAX],parent[MAX];
vector<edge>edgelist;
vector<vector<edge> >G;
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
void init(int n){
	G.clear();
	G.resize(n+10);
	edgelist.clear();
	for(int i=0;i<=n;i++){
		parent[i]=i;
		query[i].clear();
		B[i].clear();
	}
	memset(visit,0,sizeof(visit));
	memset(ans,0,sizeof(ans));
}
int find(int x){
	if(parent[x]==x)return x;
	int res=find(parent[x]);
	D[x]=max(D[x],D[parent[x]]);
	return parent[x]=res;
}
void tarjan(int u,int f){
	D[u]=0;
	for(int i=0;i<(int)G[u].size();i++){
		int v=G[u][i].from;
		if(v==f)continue;
		tarjan(v,u);
		D[v]=G[u][i].cost;
		parent[v]=u;
	}
	visit[u]=1;
	for(VPI::iterator it=query[u].begin();it!=query[u].end();it++)
		if(visit[it->first])B[find(it->first)].push_back(it->second);
	for(VI::iterator it=B[u].begin();it!=B[u].end();it++){
		int id=*it;
		int u=A[id].first,v=A[id].second;
		find(v),find(u);
		ans[id]=max(D[u],D[v]);
	}
}
int cas,n,m,q,x,y,c,t=1;
int main(){

	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&n,&m);
		init(n);
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
		printf("Case %d\n",t++);
		for(int i=1;i<=q;i++){
			printf("%d\n",ans[i]);
		}
		puts("");
	}

	return 0;
}

