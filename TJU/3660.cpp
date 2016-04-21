//============================================================================
// Name        : MPC-TLJ
// Author      : Antrhax
//============================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
vector<vector<int> >G;
bool visit[100009],flag;
int level[100009];
int n,m,x,y,ans,a;
void bfs(int n){
	queue<int>Q;
	Q.push(n);
	visit[n]=1;
	while(!Q.empty()){
		int v=Q.front();Q.pop();
		if(level[v]!=2){flag=0/*printf("%d ",v)*/;}
		for(int i=0;i<(int)G[v].size();i++){
			if(!visit[G[v][i]]){
				Q.push(G[v][i]);
				visit[G[v][i]]=1;
			}
		}
	}
}
int main() {
	while(scanf("%d%d",&n,&m)==2){
		G.clear();
		G.resize(n+10);
		memset(visit,0,sizeof(visit));
		memset(level,0,sizeof(level));
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
			level[x]++;
			level[y]++;
		}
		int a,b;a=b=0;
		for(int i=0;i<n;i++){
			if(!visit[i]){
				flag=1;
				a++;
				bfs(i);
				b+=flag;
			}
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}
