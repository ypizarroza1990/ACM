#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 100009
using namespace std;
typedef long long i64;
int diameter;
vector<int>G[MAX];
bool visit[MAX];
int dfs(int v){
	int path = 0,u;
	visit[v]=1;
	for(int i=0;i<(int)G[v].size();i++){
		u = G[v][i];
		if(!visit[u]){
			int tmp = dfs(u)+1;
			diameter = max(diameter,tmp+path);
			path = max(path,tmp);
		}
	}
	return path;
}
int cas,n,x,y;
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>n;
		for(int i=0;i<MAX;i++){
			G[i].clear();
			visit[i]=0;
		}
		for(int i=1;i<n;i++){
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		diameter = 0;
		dfs(0);
		cout<<(diameter+1)/2<<"\n";
	}

}

