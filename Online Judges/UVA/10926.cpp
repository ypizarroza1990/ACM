 #include<bits/stdc++.h>
#define MAX  209
#define EPS 1e-6
#define i64 long long
using namespace std;
int N,M,x;
vector<int>ady[MAX];
bool visit[MAX];
int levels[MAX];
int dfs(int u){
	visit[u]=1;
	int level=0;
	for(int i=0;i<ady[u].size();i++){
		int v=ady[u][i];
		if(!visit[v]){
			level++;
			level += dfs(v);
		}
	}
	return level;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(cin>>N,N){
		for(int i=1;i<=N;i++){
			ady[i].clear();
			cin>>M;
			for(int j=0;j<M;j++){
				cin>>x;
				ady[i].push_back(x);
			}
		}
		int max_l=0;
		for(int i=1;i<=N;i++){
			memset(visit,0,sizeof(visit));
			levels[i]= dfs(i);
			max_l = max(levels[i],max_l);

		}
		for(int i=1;i<=N;i++){
			if(levels[i]==max_l){
				cout<<i<<"\n";
				break;
			}
		}
	}
    return 0;
}
