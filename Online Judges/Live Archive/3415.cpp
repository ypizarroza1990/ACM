#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long i64;
const int MAXV = 50000;
const int MAXV1 = 2*MAXV;
int N, M;
vector<int> ady[MAXV];
int D[MAXV1], Mx[MAXV], My[MAXV];
struct student{
	int height;
	string sex,music,sport;
	student(){};
	student(int h,string S,string m,string s):height(h),
			sex(s),music(m),sport(s){};
};

bool check(student A,student B){
	return (abs(A.height-B.height) <= 40 &&
			A.music == B.music && A.sport != B.sport);
}

bool bfs(){
	int u, v, i, e;
	queue<int> cola;
	bool f = 0;
	for(i = 0; i < N+M; ++i) D[i] = 0;
	for(i = 0; i < N; ++i) if(Mx[i] == -1) cola.push(i);
	while(!cola.empty()){
		u = cola.front(); cola.pop();
		for(e = ady[u].size()-1; e >= 0; --e){
			v = ady[u][e];
			if(D[v+N]) continue;
			D[v+N] = D[u] + 1;
			if(My[v] != -1){
				D[My[v]] = D[v+N] + 1;
				cola.push(My[v]);
			}
			else
				f = 1;
		}
	}
	return f;
}

int DFS(int u){
	for(int v, e = ady[u].size()-1; e>=0; --e){
		v = ady[u][e];
		if(D[v+N] != D[u]+1) continue;
		D[v+N] = 0;
		if(My[v] == -1 || DFS(My[v])){
			Mx[u] = v; My[v] = u; return 1;
		}
	}
	return 0;
}

int Hopcroft_Karp(){
	int i, flow = 0;
	for(i = max(N,M); i >= 0; --i) Mx[i] = My[i] = -1;
	while(bfs())
		for(i = 0; i < N; ++i)
			if(Mx[i] == -1 &&  DFS(i)) ++flow;
	return flow;
}
int h,cas,n;
string S,s,m;
vector<student>V,H;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>h>>S>>m>>s;
			if(S == "M")
				V.push_back(student(h,S,m,s));
			else
				H.push_back(student(h,S,m,s));
		}
		N= V.size(),M=H.size();
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(check(V[i],H[j])){
					ady[i].push_back(j);
				}

		cout<<n-Hopcroft_Karp()<<"\n";

		for(int i=0;i<n;i++)
			ady[i].clear();

		H.clear();V.clear();
	}
	return 0;
}
 
