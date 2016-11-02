#include <bits/stdc++.h>
#define MAX 1009
using namespace std;
vector<vector<int> >G;
int scc[MAX],d[MAX],low[MAX],tick,curscc;
bool stacked[MAX];
stack<int>S;
void clear(){
	G.clear();
	memset(d,-1,sizeof(d));
	memset(stacked,0,sizeof(stacked));
	tick=curscc=0;
	while(!S.empty())S.pop();
}
void tarjan(int u){
	low[u]=d[u]=tick++;
	S.push(u);stacked[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(d[v]==-1){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(stacked[v]){
			low[u]=min(low[u],low[v]);
		}
	}
	if(d[u]==low[u]){
		int w;
		do{
			w=S.top();S.pop();
			stacked[w]=0;
			scc[w]=curscc;
		}while(u!= w);
		curscc++;
	}
}
int cas,n,m,k,x,y;
int main() {
	 scanf("%d",&cas);
	 while(cas--){
		 scanf("%d%d",&n,&m);
		 clear();
		 G.resize(n);
		 for(int i=0;i<m;i++){
			 scanf("%d%d",&x,&y);
			 x--,y--;
			 G[x].push_back(y);
		 }
		 for(int i=0;i<n;i++)
			 if(d[i]==-1)tarjan(i);
		 scanf("%d",&n);
		 printf("%d\n",curscc);
	 }
	return 0;
}
