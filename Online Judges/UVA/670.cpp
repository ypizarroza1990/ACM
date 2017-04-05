#include<bits/stdc++.h>
#define MAX  209
#define EPS 1e-6
#define i64 long long
using namespace std;
int G[MAX][MAX],mx[MAX],my[MAX],g[MAX];
int X[MAX],Y[MAX],x[MAX],y[MAX];
bool visit[MAX];

int dfs(int now){
	for(int i=0;i<g[now];i++){
		int u = G[now][i];
		if(!visit[u]){
			visit[u]=true;
			if(my[u] == -1 ||dfs(my[u])){
				mx[now]=u;my[u]=now;
				return 1;
			}
		}
	}
	return 0;
}
double Distance(int i,int j,int i1,int j1){
	return hypot(x[i]-x[i1],y[j]-y[j1]);
}
int cas,N,M;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>N>>M;

		// read Bob points
		for(int i=1;i<=N;i++)
			cin>>x[i]>>y[i];

		// read Ralph points
		for(int i=1;i<=M;i++)
			cin>>X[i]>>Y[i];

		//clear data
		memset(g,0,sizeof(g));
		memset(mx,-1,sizeof(mx));
		memset(my,-1, sizeof(my));

		// find if Ralph can visit other point
		for(int i=1;i<N;i++){
			double dist = 2*Distance(i,i,i+1,i+1);
			for(int j=1;j<=M;j++){
				double dist1 = hypot(x[i]-X[j],y[i]-Y[j]);
				double dist2 = hypot(x[i+1]-X[j],y[i+1]-Y[j]);

				if(dist1+dist2<=dist){
					G[i][g[i]++]=j;
				}
			}

		}
		int match=0;
		for(int i=1;i<=N;i++){
			if(mx[i]==-1){
				memset(visit,0,sizeof(visit));
				match+=dfs(i);
			}
		}
		cout<<match+N<<"\n";
		for(int i=1;i<=N;i++){
			if(i!=1)
				cout<<" ";
			cout<<x[i]<<" "<<y[i];
			if(mx[i]!=-1)
				cout<<" "<<X[mx[i]]<<" "<<Y[mx[i]];
		}
		cout<<"\n";
		if(cas)cout<<"\n";

	}
    return 0;
}
