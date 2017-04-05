#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int MAXV = 2001;
const int MAXV1 = 2*MAXV;
int N,M;
vector<vector<int> >ady;
int D[MAXV1],Mx[MAXV], My[MAXV],Fact[MAXV],Mul[MAXV];
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
	int cas;
	scanf("%d",&cas);
	for(int k=1;k<=cas;k++){
		ady.clear();
		scanf("%d",&N);
		ady.resize(N);
		for(int i=0;i<N;i++)
			scanf("%d",&Fact[i]);
		scanf("%d",&M);
		for(int i=0;i<M;i++)
			scanf("%d",&Mul[i]);
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if((Fact[i]!=0 && Mul[j]%Fact[i]==0)||Mul[j]==0)
					ady[i].push_back(j);
			}
		}
		printf("Case %d: %d\n",k,Hopcroft_Karp());
	}
	return 0;
}

