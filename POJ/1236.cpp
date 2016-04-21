#include <vector>
#include <stack>
#include <cstring>
#include <cstdio>
#include <iostream>
#define MAXN 599
using namespace std;
vector<vector<int> >g;
int d[MAXN], low[MAXN], scc[MAXN],in[MAXN],out[MAXN];
bool stacked[MAXN],visit[MAXN];
stack<int> s;
int ticks, current_scc;
void tarjan(int u){
	d[u] = low[u] = ticks++;
	s.push(u);
	stacked[u] = true;
	const vector<int> &out = g[u];
	for (int k=0, m=out.size(); k<m; ++k){
		const int &v = out[k];
		if (d[v] == -1){
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}else if (stacked[v]){
			low[u] = min(low[u], low[v]);
		}
	}
	if (d[u] == low[u]){
		int v;
		do{
			v = s.top();
			s.pop();
			stacked[v] = false;
			scc[v] = current_scc;
		}while (u != v);
		current_scc++;
	}
}
void fill(){
	while(!s.empty())s.pop();
	memset(d,-1,sizeof(d));
	memset(stacked,0,sizeof(stacked));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	memset(visit,0,sizeof(visit));
	ticks=current_scc=0;
}
void DFS(int u){
	visit[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(scc[u]!=scc[v]){
			in[scc[v]]++;
			out[scc[u]]++;
		}
		if(!visit[v])
			DFS(v);
	}
}
void  solve(){
	int min,mout;
	min=mout=0;
	for(int i=0;i<current_scc;i++){
		if(!in[i])min++;
		if(!out[i])mout++;
	}
	if(current_scc==1)
		cout<<1<<"\n"<<0<<"\n";
	else
		cout<<min<<"\n"<<max(min,mout)<<"\n";
}
int cas,n,m,x,y,a;
int main(){
	fill();a=0;
	cin>>n;
	g.clear();
	g.resize(n+10);
	for(int i=0;i<n;i++){
		while(scanf("%d",&x),x){
			x--;
			g[i].push_back(x);
		}
	}
	for(int i=0;i<n;i++){
		if(d[i]==-1)
			tarjan(i);
	}
	for(int i=0;i<n;i++)
		if(!visit[i]){
			DFS(i);
		}
	solve();
}
 
