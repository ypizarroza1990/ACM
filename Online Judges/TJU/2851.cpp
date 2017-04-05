#include <bits/stdc++.h>
#define MAX 5009
using namespace std;
typedef long long i64;
int ans[MAX][2],t[MAX];
int cas,n,m,cost;
struct edge{
	int to,cost;
	edge(){};
	edge(int _to,i64 _cost):to(_to),cost(_cost){};
	bool operator >(const edge E)const{
		return cost > E.cost;
	}
};
vector<vector<edge> >G;
int V[5009];
int K_th(){
	priority_queue<edge,vector<edge>,greater<edge> >Q;
	Q.push(edge(0,0));
	while(!Q.empty()){
		edge v=Q.top();Q.pop();
		int p=v.to;
		int cost=v.cost;
		if(t[p]<2){
			ans[p][t[p]]=cost;
			t[p]++;
			for(int i=0;i<G[p].size();i++){
				if(t[G[p][i].to]<2)
					Q.push(edge(G[p][i].to,cost+G[p][i].cost));
			}
		}
	}
	return ans[n-1][1];

}
int main()
{

		 int x,y,c;
		 scanf("%d%d",&n,&m);
		 G.resize(n+1);
		 for(int i=0;i<m;i++){
			 scanf("%d%d%d",&x,&y,&c);
			 G[x-1].push_back(edge(y-1,c));
			 G[y-1].push_back(edge(x-1,c));
		 }
		 printf("%d\n",K_th());

}

