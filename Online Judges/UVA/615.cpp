#include<vector>
#include <iostream>
#include <algorithm>
#include <map>
#define MAX 1000007
using namespace std;
typedef long long i64;
int n,cnt;
bool visit[MAX];
bool cycle;
vector<int>G[MAX];
int x,y,cas;
int In[MAX];
void dfs(int v){
	visit[v]=1;
	cnt++;
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(!visit[u])
			dfs(u);
		else
			cycle=1;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(true)
	{
		map<int,int>M;
		cycle=0;
		cas++;
		for(int i=0;i<=n;i++){
			G[i].clear();
			visit[i]=0;
			In[i]=0;
		}
		n=0;
		cnt=0;
		while(cin>>x>>y){
			if(x==0 && y==0)break;
			if(x==-1 && y==-1)return 0;
			if(!M[x]){M[x]=++n;}
			if(!M[y]){M[y]=++n;}
			In[M[y]]=1;
			G[M[x]].push_back(M[y]);
		}
		for(int i=1;i<=n;i++)if(!In[i]){dfs(i);break;}
		if(cnt==n && !cycle)cout<<"Case "<<cas<<" is a tree.\n";
		else cout<<"Case "<<cas<<" is not a tree.\n";

	}
	return 0;
}
 
