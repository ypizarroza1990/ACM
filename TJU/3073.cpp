
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#define INF 1000000
using namespace std;
typedef long long i64;
struct edge{
	int from,to,cost;
	edge(){};
	edge(int x,int y,int c):from(x),to(y),cost(c){};
	bool operator<(const edge C)const{
		return cost<C.cost;
	}
};
struct DjoinSet{
	int* parent;
	int* rank;
	int setnumber;
	DjoinSet(int n){
		parent= new int[n+10];
		rank=new int[n+10];
		setnumber=n;
		for(int i=0;i<n;i++)
			parent[i]=i;
	}
	int find(int x){
		return parent[x]==x?x:parent[x]=find(parent[x]);
	}
	bool equals(int x,int y){
		return find(x)==find(y);
	}
	void join(int x,int y){
		int x1,x2;
		x1=find(x),x2=find(y);
		if(x1==x2)return;
		if(rank[x1]==rank[x2])
			++rank[x1];
		if(rank[x1]<rank[x2])
			swap(x1,x2);
		parent[x2]=x1;
		setnumber--;
	}
};
vector<edge>edgelist;
int MST(int n){
	DjoinSet S(n);
	sort(edgelist.begin(),edgelist.end());
	int res=0;
	int sz=edgelist.size();
	for(int i=0;i<sz;i++){
		int f=edgelist[i].from;
		int t=edgelist[i].to;
		if(!S.equals(f,t)){
			S.join(f,t);
			res+=edgelist[i].cost;
		}
	}
	return S.setnumber!=1?INF:res;
}
int cas,n,m,q,x,y,c;
int main() {
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d%d",&n,&m,&q);
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			x--,y--;
			edgelist.push_back(edge(x,y,0));
		}
		for(int i=0;i<q;i++){
			scanf("%d%d%d",&x,&y,&c);
			x--,y--;
			edgelist.push_back(edge(x,y,c));
		}
		int T=MST(n);
		T==INF?puts("-1"):printf("%d\n",T);
		edgelist.clear();
	}
	return 0;
}
