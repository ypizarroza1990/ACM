#include <bits/stdc++.h>

using namespace std;
const int MAX=100009;
vector<int>G[MAX];
bool mark[MAX],state[MAX];;
int subtree[MAX];
priority_queue< pair<int,int> >Q[MAX];
int nodes,lca[20][MAX];
int level[MAX],ant[MAX];
int LOG(int p){
	int log;
	for(log=0;(1<<log)<=p;log++);
	return log-1;
}

void dfs0(int node){
	mark[node]=true;
	for(auto v:G[node]){
		if(!mark[v]){
			lca[0][v]=node;
			level[v]=level[node]+1;
			int log=LOG(level[v]);
			for(int i = 1;i<=log;i++)
				if(lca[i-i][v]!=-1)
					lca[i][v] = lca[i-1][lca[i-1][v]];
			dfs0(v);
		}
	}
}

int lowest_ant(int p,int q){
	if(level[p]<level[q])
		swap(p,q);
	int log = LOG(level[p]);
	if(level[p]!=level[q])
		for(int i=log;i>=0;i--){
			if(level[p]-(1<<i)>=level[q])
				p=lca[i][p];
		}
	if(p==q)
		return p;
	for(int i=log;i>=0;i--){
		if(lca[i][p]!=lca[i][q] && lca[i][p]!=-1){
			p=lca[i][p];
			q=lca[i][q];
		}
	}
	return lca[0][p];
}

int dist(int a,int b){
	return level[a]+level[b]-2*level[lowest_ant(a,b)];
}
/* Descomposition Part*/
int dfs(int node,int parent=-1){
	subtree[node]=1;
	nodes++;
	for(auto v:G[node]){
		if(!mark[v] && v!=parent)
			subtree[node]+=dfs(v,node);
	}
	return subtree[node];
}

int dfs2(int node,int parent=-1){
	for(auto v:G[node]){
		if(!mark[v] && parent!=v && subtree[v]>nodes/2)
			return dfs2(v,node);
	}
	return node;
}

void descomposition(int node,int parent=-1){
	nodes = 0;
	dfs(node,parent);
	int centroid = dfs2(node,parent);
	mark[centroid]=true;
	ant[centroid]=parent;
	for(auto v:G[centroid]){
		if(!mark[v])
			descomposition(v,centroid);
	}

}
int White(int node){
	priority_queue<pair<int,int> > &q = Q[node];

	while(!q.empty()){
		pair<int,int> cur = q.top();

		if(!state[cur.second]){
			q.pop();
		}else{
			return -cur.first;
		}
	}

	return 1e9;
}

int N,x,y,q;
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	for(auto i = 1;i<N;i++){
		cin>>x>>y;
		G[x-1].push_back(y-1);
		G[y-1].push_back(x-1);
	}
	memset(lca,-1,sizeof(lca));
	dfs0(0);
	memset(mark,false,sizeof(mark));
	descomposition(0,-1);
	cin>>q;
	int cur;
	while(q--){
		cin>>x>>y;y--;
		if(x==0){
			state[y]=!state[y];
			if(state[y]){
				cur = y;
				while(cur != -1){
					Q[cur].push(make_pair(-dist(cur,y),y));
					cur = ant[cur];
				}
			}
		}
		else{
			int res = 1e9;cur=y;
			while(cur != -1){
				res = min(res,dist(cur,y)+White(cur));
				cur = ant[cur];
			}
			cout<<(res==1e9?-1:res)<<"\n";
		}
	}
	return 0;
} 
