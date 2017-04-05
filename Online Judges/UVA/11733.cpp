#include<bits/stdc++.h>
#define PW(x)(x)*(x)
#define INF 1e9
using namespace std;
typedef long long i64;
int x,y,n,cost,m,sum,airport,cas;
struct Djoinset{
	int* parent;
	int* rank;
	int setnumber;

	Djoinset(int n){
		parent = new int[n+10];
		rank = new int[n+10];
		setnumber =  n;
		for(int i=0;i<=n;i++)
			parent[i]=i;
	}
	int find(int x){
		return x==parent[x]?x:parent[x]=find(parent[x]);
	}
	bool equals(int x,int y){
		return find(x)==find(y);
	}
	void join(int x,int y){
		int x1=find(x),x2=find(y);
		if(x1==x2)
			return;
		if(rank[x1]==rank[x2])
			++rank[x1];
		if(rank[x1]<rank[x2])
			swap(x1,x2);
		parent[x2]=x1;
		setnumber--;
	}
};
struct edge{
	int from,to,cost;
	edge(int _f=0,int _t=0,int _c=0){
		from=_f,to=_t,cost=_c;
	}
	bool operator <(const edge &C)const{
		return cost<C.cost;
	}
};
vector<edge>edge_list;
pair<i64,int> MST(int nodes){
	Djoinset S(nodes);
	sort(edge_list.begin(),edge_list.end());
	i64 res=0;int sz=edge_list.size();
	for(int i=0;i<sz&&(edge_list[i].cost<airport);i++){
		int f=edge_list[i].from;
		int t=edge_list[i].to;
		if(!S.equals(f,t)){
			S.join(f,t);
			res+=edge_list[i].cost;
		}
	}
	int air=0;
	for(int i=0;i<nodes;i++){
		if(S.parent[i]==i){
			res+=airport;
			air++;
		}
	}
	return make_pair(res,air);
}
int main()
{
	//freopen("ff.in","r",stdin);
	cin>>cas;
	for(int i=1;i<=cas;i++){
		cin>>n>>m>>airport;
		for(int i=0;i<m;i++){
			cin>>x>>y>>cost;
			x--,y--;
			edge_list.push_back(edge(x,y,cost));
		}
		pair<i64,int> mst=MST(n);
		printf("Case #%d: %lld %d\n",i,mst.first,mst.second);
		edge_list.clear();
	}

	return 0;
}
