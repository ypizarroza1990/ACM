#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#define INF 1e9
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
int cas,n,q,orig,k,x,y,val;
struct edge{
	int to,weight;
	edge();
	edge(int t,int w):to(t),weight(w){};
	bool operator <(const edge &that)const{
		return weight>that.weight;
	}
};
vector <vector<edge> >G;
vector<int>barrios;
int d[1010000];
int Dijktra(int origen,int n){
	for(int i=0;i<=n;i++){
		d[i]=INF;
	}
	d[origen]=0;
	priority_queue<edge>Q;
	Q.push(edge(origen,0));
	while(!Q.empty()){
		int nodo = Q.top().to;
		int dist=Q.top().weight;
		Q.pop();
		if(dist>d[nodo])continue;
		if(nodo==n)return dist;
		for(int i=0;i<(int)G[nodo].size();i++){
			int to = G[nodo][i].to;
			int weight_x = G[nodo][i].weight;
			if(dist+weight_x<d[to]){
				d[to]=dist+weight_x;
				Q.push(edge(to,d[to]));
			}
		}
	}
	return INF;
}
int main() {


		scanf("%d%d",&n,&q);
		G.resize(n*q+10);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=q;j++){
				scanf("%d",&val);
				barrios.push_back(val);
			}
		int from,to;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=q;j++){
				if(i<n){
					from=q*(i-1)+j,to=q*i+j;
					G[from].push_back(edge(to,barrios[to-1]));
					G[to].push_back(edge(from,barrios[from-1]));
				}if(j!= q){
					from=q*(i-1)+j;	to=q*(i-1)+j+1;
					G[from].push_back(edge(to,barrios[to-1]));
					G[to].push_back(edge(from,barrios[from-1]));
				}
	}
		int sol=Dijktra(1,n*q);
	printf("%d\n",sol+barrios[0]);
}


