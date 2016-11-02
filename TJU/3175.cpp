#include <bits/stdc++.h>
#define MAX 30009
using namespace std;
typedef long long i64;
vector<vector<int> >G;
bool mark[MAX];
int DFS(int u){
	if(mark[u])return 0;
	mark[u]=1;
	int cant=1;
	for(int i=0;i<G[u].size();i++)
		cant+=DFS(G[u][i]);
	return cant;
}
int N,P,R,x,y;
int main() {
	scanf("%d%d%d",&N,&P,&R);
	G.resize(N);
	for(int i=0;i<P;i++){
		scanf("%d%d",&x,&y);
		x--,y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=0;i<R;i++){
		scanf("%d",&x);
		x--;
		mark[x]=1;
		for(int i=G[x].size()-1;i>=0;i--){
			mark[G[x][i]]=1;
		}
	}
	printf("%d\n",N-DFS(0));
	return 0;
}
