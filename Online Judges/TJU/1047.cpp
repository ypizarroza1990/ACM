#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
const int MAXV = 1001;
const int MAXV1 = 2*MAXV;
int N,M;
vector<int> ady[MAXV],G[MAXV];
int D[MAXV1],Mx[MAXV], My[MAXV];
int color[MAXV];
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
int id,n,x;
int main(){

	while(scanf("%d",&N)==1){
		for(int i=0;i<N;i++){
			ady[i].clear();
			G[i].clear();
		}
		for(int i=0;i<N;i++){
			scanf("%d: (%d)",&id,&n);
			for(int j=0;j<n;j++){
				scanf("%d",&x);
				G[id].push_back(x);
			}
		}
		queue<int>Q;
		memset(color,-1,sizeof(color));
		for(int i=0;i<N;i++){
			if(color[i]!=-1)continue;
			Q.push(i);
			color[i]=0;
			while(!Q.empty()){
				int aux=Q.front();Q.pop();
				for(int j=G[aux].size()-1;j>=0;j--){
					int v=G[aux][j];
					if(color[v]==-1){
						color[v]=1-color[aux];
						Q.push(v);
					}
				}
			}
		}
		M=N;
		for(int i=0;i<N;i++){
			if(color[i]==1)continue;
			for(int j=G[i].size()-1;j>=0;j--){
				int v=G[i][j];
				ady[i].push_back(v);
			}
		}
		printf("%d\n",N-Hopcroft_Karp());

	}


	return 0;
}

