 
#include <bits/stdc++.h>
#define MAXV 1009
#define MAXV1 2*MAXV
using namespace std;
struct point{
	double x,y;
	point(double  _x=0,double _y=0):x(_x),y(_y){};
};
vector<int>ady[MAXV];
int D[MAXV1],Mx[MAXV],My[MAXV];
int N,M;
bool bfs(){
	int u,v,i,e;
	queue<int>cola;
	bool f=0;
	for(i=0;i<N+M;i++)D[i]=0;
	for(i=0;i<N;i++)if(Mx[i]==-1)cola.push(i);
	while(!cola.empty()){
		u=cola.front();cola.pop();
		for(e=ady[u].size()-1;e>=0;e--){
			v=ady[u][e];
			if(D[v+N])continue;
			D[v+N]=D[u]+1;
			if(My[v]!=-1){
				D[My[v]]=D[v+N]+1;
				cola.push(My[v]);
			}else f=1;
		}
	}
	return f;
}
int dfs(int u){
	for(int v,e=ady[u].size()-1;e>=0;e--){
		v=ady[u][e];
		if(D[v+N]!=D[u]+1)continue;
		D[v+N]=0;
		if(My[v]==-1||dfs(My[v])){
			Mx[u]=v;My[v]=u;return 1;
		}

	}
	return 0;
}
int hopcroft_karp(){
	int i,flow=0;
	for(i=max(N,M);i>=0;i--)Mx[i]=My[i]=-1;
	while(bfs()){
		for(i=0;i<N;i++)
			if(Mx[i]==-1 && dfs(i))
				flow++;
	}
	return flow;
}
double Dist(point a,point b){
	return hypot(a.x-b.x,a.y-b.y);
}
int cas,p,t,s,c;
point persons[409],taxicab[209];
int main() {

	while(scanf("%d%d%d%d",&p,&t,&s,&c)==4){
		N=p,M=t;
		for(int i=0;i<N;i++){
			ady[i].clear();
			scanf("%lf%lf",&persons[i].x,&persons[i].y);
		}
		for(int i=0;i<M;i++){
			scanf("%lf%lf",&taxicab[i].x,&taxicab[i].y);
		}
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++){
				if(Dist(persons[i],taxicab[j])<=(s*c)){
					ady[i].push_back(j);
				}
			}
		printf("%d\n",N-hopcroft_karp());
	}
}
