#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
using namespace std;
struct pt{
	double x,y;
	pt(double a=0,double b=0):x(a),y(b){};
};
const int MAXV = 1001;
const int MAXV1 = 2*MAXV;
int N,M;
vector<int> ady[MAXV];
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
int  A[MAXV],B[MAXV];

int main() {
	while(scanf("%d%d",&N,&M),N+M){
		for(int i=0;i<N;i++)
			ady[i].clear();
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	for(int i=0;i<M;i++)
			scanf("%d",&B[i]);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			if(__gcd(A[i],B[j])!=1)
				ady[i].push_back(j);
		}
	printf("%d\n",Hopcroft_Karp());
	}
	return 0;
}

