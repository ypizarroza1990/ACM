#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAXN 20009
using namespace std;
typedef long long i64;
bool visit[MAXN];
vector<vector<int> >G;
int d[MAXN], low[MAXN], scc[MAXN];
int in[MAXN],out[MAXN];
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc;
void init(){
	memset(d,-1,sizeof(d));
	memset(visit,0,sizeof(visit));
	ticks= current_scc=0;
	while(!s.empty())s.pop();
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
}
void tarjan(int u){
	d[u] = low[u] = ticks++;
	s.push(u);
	stacked[u] = true;
	const vector<int> &out = G[u];
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
void dfs(int u){
	visit[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(scc[u]!=scc[v]){
			in[scc[v]]++;
			out[scc[u]]++;
		}
		if(!visit[v])
			dfs(v);
	}
}
int solve(){
	if(current_scc==1)return 0;
	int mi=0,mo=0;
	for(int i=0;i<current_scc;i++){
		if(!in[i])mi++;
		if(!out[i])mo++;
	}
	return max(mi,mo);
}
int n,m,cas,x,y;
int main()
{
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&n,&m);
		init();
		G.clear();
		G.resize(n+10);
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			x--,y--;
			G[x].push_back(y);
		}
		for(int i=0;i<n;i++){
			if(d[i]==-1)
				tarjan(i);
		}
		for(int i=0;i<n;i++){
			if(!visit[i])
				dfs(i);
		}
		cout<<solve()<<endl;
	}

}

