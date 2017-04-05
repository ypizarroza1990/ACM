#include<bits/stdc++.h>
#define MAXNODES 51000
using namespace std;
typedef long long i64;
struct edge{
	int from,to;
	i64 cost;
	edge(){};
	edge(int _from,int _to,i64 _cost):from(_from),to(_to),cost(_cost){};
	bool operator <(const edge E)const{
		return cost < E.cost;
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
		return x==parent[x]?x:parent[x]=find(parent[x]);
	}
	bool equals(int x,int y){
		return find(x)==find(y);
	}
	void join(int x,int y){

		int x1=find(x),x2= find(y);
		if(x1==x2)
			return;
		if(rank[x1]==rank[x2])
			rank[x1]++;
		if(rank[x1]<rank[x2])
			swap(x1,x2);
		parent[x2]=x1;
	}
};
vector<edge>edgelist;
i64 MST(int n){
	Djoinset S(n);
	sort(edgelist.begin(),edgelist.end());
	i64 ans=(i64)1e-9;int sz=edgelist.size(),aux=0;
	for(int i=0;i<sz && aux<n-1;i++){
		int f=edgelist[i].from;
		int t=edgelist[i].to;
		if(!S.equals(f,t)){
			S.join(f,t);
			ans=max(edgelist[i].cost,ans);
			aux++;
		}
	}
	return aux==n-1?ans:-1;
}
int n,m,x,y;
i64 c;
int main(){
	while(scanf("%d %d",&n,&m),n != 0 || m != 0){
		for(int i=0;i<m;i++){
			scanf("%d %d %lld",&x,&y,&c);
			edgelist.push_back(edge(x,y,c));
		}
		if(n==0)puts("0");
		else{
		i64 ans=MST(n);
		ans==-1?puts("IMPOSSIBLE"):printf("%lld\n",ans);
		edgelist.clear();
		}
	}
	return 0;
}
