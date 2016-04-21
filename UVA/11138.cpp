#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int MAXV = 1001;
const int MAXV1 = 2*MAXV;
int N,M;
vector<vector<int> >ady;
int D[MAXV1],Mx[MAXV], My[MAXV];
bool BFS(){
	int u, v, i, e;
	queue<int> cola;
	bool f = 0;
	for (i = 0; i < N+M; i++) D[i] = 0;
	for (i = 0; i < N; i++) if (Mx[i] == -1) cola.push(i);
	while (!cola.empty()){
		u = cola.front(); cola.pop();
		for (e = ady[u].size()-1; e >= 0; e--) {
			v = ady[u][e];
			if (D[v + N]) continue;
			D[v + N] = D[u] + 1;
			if (My[v] != -1){
				D[My[v]] = D[v + N] + 1;
				cola.push(My[v]);
			}else f = 1;
		}
	}
	return f;
}
int DFS(int u){
	for (int v, e = ady[u].size()-1; e >=0; e--){
		v = ady[u][e];
		if (D[v+N] != D[u]+1) continue;
		D[v+N] = 0;
		if (My[v] == -1 || DFS(My[v])){
			Mx[u] = v; My[v] = u; return 1;
		}
	}
	return 0;
}
int Hopcroft_Karp(){
	int i, flow = 0;
	for (i = max(N,M); i >=0; i--) Mx[i] = My[i] = -1;
	while (BFS())
		for (i = 0; i < N; i++)
			if (Mx[i] == -1 && DFS(i)) ++flow;
	return flow;
}
int main(){
	int cas,x;
	scanf("%d",&cas);
	for(int k=0;k<cas;k++){
		ady.clear();
		ady.resize(MAXV);
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				scanf("%d",&x);
				if(x)ady[i].push_back(j);
			}
		}
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",k+1,Hopcroft_Karp());
	}
	return 0;
}
