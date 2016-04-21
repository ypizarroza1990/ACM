#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
struct edge{
	int from,to,cost;
	edge(){};
	edge(int f,int t,int c):from(f),to(t),cost(c){};
	bool operator<(const edge E)const{
		return cost<E.cost;
	}
};
struct Djoinset{
	int* parent;
	int* rank;
	int size;
	Djoinset(int n){
		parent=new int[n+10];
		rank=new int[n+10];
		size=n;
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
		int x1=find(x),x2=find(y);
		if(x1==x2)return;
		if(rank[x1]==rank[x2])
			rank[x1]++;
		if(rank[x1]<rank[x2])
			swap(x1,x2);
		parent[x2]=x1;
		size--;
	}
};
vector<edge>edgelist;
int MST(int nodes){
	Djoinset n(nodes);
	sort(edgelist.begin(),edgelist.end());
	int mst=0,sz=edgelist.size();
	for(int i=0;i<sz;i++){
		int f=edgelist[i].from;
		int t=edgelist[i].to;
		if(!n.equals(f,t)){
			n.join(f,t);
			mst+=edgelist[i].cost;
		}
	}
	return mst;
}
int n,m,f,t,c;
int main(){
	 while(scanf("%d",&n),n){
		 scanf("%d",&m);
		 edgelist.clear();
		 for(int i=0;i<m;i++){
			 scanf("%d %d %d",&f,&t,&c);
			 f--,t--;
			 edgelist.push_back(edge(f,t,c));
		 }
		 int ans=MST(n);
		 printf("%d\n",ans);
	 }
}
