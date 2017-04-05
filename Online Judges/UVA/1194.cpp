#include <bits/stdc++.h>
#define MAX 309
using namespace std;
typedef long long i64;
struct bipatie_graph{
	vector<int>*L;
	int V1,V2,*match;
	bool* visit;

	bipatie_graph(int M_V1,int M_V2){
		L=new vector<int>[M_V1];
		match=new int[M_V2];
		visit=new bool[M_V2];
	}
	void clear(int v1,int v2){
		V1=v1,V2=v2;
		for(int i=0;i<V1;i++)
			L[i].clear();
	}
	void add(int x,int y){
		L[x].push_back(y);
	}
	bool dfs(int u){
		for(int i=L[u].size()-1;i>=0;i--){
			int v=L[u][i];
			if(!visit[v]){
				visit[v]=1;
				if(match[v]==-1 ||dfs(match[v])){
					match[v]=u;
					return 1;
				}
			}
		}
		return 0;
	}
	int matching(){
		int ans=0;
		fill(match,match+V2,-1);
		for(int i=0;i<V1;i++){
			fill(visit,visit+V2,0);
			ans+=dfs(i);
		}
		return ans;
	}
}G(MAX*MAX,MAX*MAX);
int n,m,k,u,v,id;
int main() {
	 while(scanf("%d",&n),n){
		 scanf("%d%d",&m,&k);
		 G.clear(MAX,MAX);
		 for(int i=0;i<k;i++){
			 scanf("%d%d%d",&id,&u,&v);
			 if(u*v==0)continue;
			 G.add(u,v);
		 }
		 printf("%d\n",G.matching());
	 }
}

