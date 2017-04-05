//============================================================================
// Name        : UVA.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <stack>
#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof ((v).begin()) x = (v).begin();x!= (v).end() ; ++x)
#define MAXN 100050
using namespace std;
template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
typedef long long i64;
vector<int>::iterator v;
struct edge{
	int antecesor,peso;
	int color;
	i64 dist_raiz;
	vector<int>hijos;
	vector<int>g;
	edge(){};
	edge(int _antec,int _peso):antecesor(_antec),peso(_peso),color(0){};
	bool operator <(const edge E)const{
		return peso < E.peso;
	}
};
struct query{
	int A,B;
	int ans;
};

int p[MAXN],rank[MAXN];
void make(int x){p[x]=x,rank[x]=0;}
void link(int x,int y){
	if(rank[x]>rank[y])p[y]=x;
	else{
		p[x]=y;
		if(rank[x]==rank[y])++rank[y];
	}
}
int find(int x){
	return p[x]==x?x:p[x]=find(p[x]);
}
void merge(int x,int y){
	link(find(x),find(y));
}
vector<pair<int,int> >LCAnodes[MAXN];
edge G[MAXN];
query Q[MAXN];
void Tarjan(int u){
	make(u);
	G[u].antecesor=u;
	foreach(v,G[u].hijos){
		Tarjan(*v);
		merge(u,*v);
		G[find(*v)].antecesor=u;
	}
	G[u].color =0;
	int v;
	for(int i=0;i<G[u].g.size();i++){
		if(u==Q[G[u].g[i]].A)
			v=Q[G[u].g[i]].B;
		else if(u==Q[G[u].g[i]].B)
			v=Q[G[u].g[i]].A;
		else throw "Paila "+ toStr(u);
		if(G[v].color==0){
			Q[G[u].g[i]].ans = G[G[find(v)].antecesor].antecesor;
		}
	}
}
void fill(int n){
	for(int i=0;i<n+2;i++){
		G[i].hijos=vector<int>();
		G[i].g=vector<int>();
	}
}
int n,q,x,peso,y,m,t,raiz,cas=0;
char po;
map<int,int>tt;
map<int,int>::iterator it;
int main(){
	//freopen("entrada.in","r",stdin);
	while(scanf("%d",&n)==1){;
		fill(n);
		G[0].dist_raiz=0;
		for(int i=0;i<n;i++){
			scanf("%d:(%d)",&m,&t);
			if(i==0)raiz=m;
			for(int i=0;i<t;i++){
				scanf("%d",&x);
			G[x].color=0;
			G[x].antecesor=m;
			G[m].hijos.push_back(x);
			}
		}
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			cin>>po>>x>>y>>po;
			Q[i].A=x,Q[i].B=y;
			G[x].g.push_back(i);
			G[y].g.push_back(i);
		}
		try {
			Tarjan(raiz);
		} catch(string c){
			cout<<c<<endl;
		}
		for(int i=0;i<q;i++){
			tt[Q[i].ans]++;
		}
		for(it=tt.begin();it !=tt.end();it++)
			cout<<it->first<<":"<<it->second<<endl;
		tt.clear();
	}
	return 0;
}

