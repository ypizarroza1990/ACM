#include <bits/stdc++.h>
#define MAX 100019
#define LOG(x)31-__builtin_clz(x);
using namespace std;
typedef long long i64;
const int INF = 2000000000;
struct Edge{
	int from,to,cap,flow,index;
	Edge(int _from,int _to,int _cap,int _flow,int _index):from(_from),
			to(_to),cap(_cap),flow(_flow),index(_index){};

};
struct Dinic{
	int N;
	vector<vector< Edge> >G;
	vector<Edge*> dad;
	vector<int> Q;

	Dinic(int _N):N(_N),G(_N),dad(_N),Q(_N){};

	void AddEdge(int from,int to,int cap){
		G[from].push_back(Edge(from,to,cap,0,G[to].size()));
		if(from==to)G[from].back().index++;
		G[to].push_back(Edge(to,from,0,0,G[from].size()-1));
	}

	i64 BlokingFlow(int s,int t){
		fill(dad.begin(),dad.end(),(Edge*)NULL);
		dad[s]=&G[0][0]-1;
		int head =0,tail=0;
		Q[tail++]=s;
		while(head<tail){
			int x=Q[head++];
			for(int i=0;i<G[x].size();i++){
				Edge &e=G[x][i];
				if(!dad[e.to] && e.cap-e.flow>0){
					dad[e.to]=&G[x][i];
					Q[tail++]=e.to;
				}
			}
		}
		if(!dad[t])return 0;
		i64 totflow=0;
		for(int i=0;i<G[t].size();i++){
			Edge* start=&G[G[t][i].to][G[t][i].index];
			int amt=INF;
			for(Edge* e=start;amt && e!=dad[s];e=dad[e->from]){
				if(!e){
					amt=0;
					break;
				}
				amt=min(amt,e->cap-e->flow);
			}
			if(amt==0)continue;
			for(Edge* e=start;amt && e!=dad[s];e=dad[e->from]){
				e->flow+=amt;
				G[e->to][e->index].flow-=amt;
			}
			totflow+=amt;
		}
		return totflow;
	}
	i64 maxFlow(int s,int t){
		i64 totflow=0;
		while(i64 flow=BlokingFlow(s,t))
			totflow+=flow;
		return totflow;
	}
};
int n,m,x,y,c;
int main() {
	while(scanf("%d %d",&n,&m),n+m){
		Dinic D(2*n+10);
		for(int i=0;i<n-2;i++){
			scanf("%d %d",&x,&c);
			D.AddEdge(x,x+n,c);
		}
		D.AddEdge(1,n+1,INF);
		D.AddEdge(n,2*n,INF);
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&x,&y,&c);
			D.AddEdge(x+n,y,c);
			D.AddEdge(y+n,x,c);
		}
		printf("%d\n",D.maxFlow(1,2*n));
	}
	return 0;
}
