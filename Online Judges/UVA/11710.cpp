#include<bits/stdc++.h>
#define PW(x)(x)*(x)
#define INF 1e9
using namespace std;
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
int MST(int nodes){
	Djoinset S(nodes);
	sort(edge_list.begin(),edge_list.end());
	int res=0,sz=edge_list.size();
	for(int i=0;i<sz;i++){
		int f=edge_list[i].from;
		int t=edge_list[i].to;
		if(!S.equals(f,t)){
			S.join(f,t);
			res+=edge_list[i].cost;
		}
	}
	return S.setnumber==1?res:INF;
}
map<string,int>M;
int cas,n,t,cost,m;
string cad,cad2;
int findS(string cad){
	if(M[cad])
		return M[cad];
}
int main()
{
	//freopen("ff.in","r",stdin);
	cin>>n>>m;
	while(1){
		if(m+n==0)break;

		for(int i=0;i<n;i++){
			cin>>cad;
			M[cad]=i;
		}
		for(int i=0;i<m;i++){
			cin>>cad>>cad2>>cost;
			int f=findS(cad),t=findS(cad2);
			edge_list.push_back(edge(f,t,cost));
		}
		cin>>cad;
		int mst=MST(n);
		mst==INF?puts("Impossible"):printf("%d\n",mst);
		edge_list.clear();
		M.clear();
		cin>>n>>m;
	}

	return 0;
}
