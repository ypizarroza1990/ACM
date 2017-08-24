#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;
#define i64 long long
int diameter;
bool visit[MAX];
vector<int>G[MAX];
int dfs(int u){
	visit[u]=true;
	int path = 0;
	for(int i =0;i<G[u].size();i++){
		int v = G[u][i];
		if(!visit[v]){
			int tmp = dfs(v)+1;
			diameter = max(diameter,tmp+path);
			path = max(path,tmp);
		}
	}
	return path;
}
int cas,n,a,b;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>n;
		for(int i=0;i<n;i++){
			visit[i]=false;
			G[i].clear();
		}
		for(int i=0;i<n-1;i++){
			cin>>a>>b;a--,b--;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs(0);
		cout<<diameter+1<<"\n";
		diameter=0;
	}
	return 0;
}