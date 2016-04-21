#include <bits/stdc++.h>
using namespace std;
struct Djoinset{
	int* parent;
	int* rank;
	Djoinset(int n){
		parent = new int[n+10];
		rank =new int[n+10];
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
struct edge{
	int from,to;
	double cost;
	edge(){};
	edge(int _f,int _t,double _c):from(_f),to(_t),cost(_c){};
	bool operator <(const edge E)const{
		return cost<E.cost;
	}
};
vector<edge>edge_list;
double MST(int n){
	Djoinset S(n);
	double ans=0;
	int T=0;
	sort(edge_list.begin(),edge_list.end());
	int sz=edge_list.size();
	for(int i=0;i<sz&&T<n-1;i++){
		int f=edge_list[i].from;
		int t=edge_list[i].to;
		if(!S.equals(f,t)){
			S.join(f,t);
			ans+=edge_list[i].cost;
			T++;
		}
	}
	return T==n-1?ans:-1;
}
int n,m;
double cable,d;
string name,nam;
map<string,int>M;
int main() {
	scanf("%lf",&cable);
	scanf("%d",&n);
		for(int i=0;i<n;i++){
		 cin>>name;
		 M[name]=i;
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			cin>>nam>>name>>d;
			int f=M[nam],t=M[name];
			edge_list.push_back(edge(f,t,d));
		}
		double ans=MST(n);
	  if(ans>cable || ans==-1)
			puts("Not enough cable");
		else printf("Need %.1lf miles of cable\n",ans+1e-9);
		edge_list.clear();
	return 0;
}

