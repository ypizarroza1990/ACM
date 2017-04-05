#include <bits/stdc++.h>
#define MAX 100000
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define fort(i,V)for(__typeof(V.begin())i=V.begin();i!=V.end();i++)
using namespace std;
typedef long long i64;
int LCA[25][MAX],Level[MAX],n;
bool mark[MAX];
map<int,int>M;
vector<vector<int> >G;
int loga2(int p){
	int log;
	for(log=0;(1<<log)<=p;log++);
	log--;
	return log;
}
void DFS(int n){
	mark[n]=true;
	for(int i=0;i<G[n].size();i++){
		int v=G[n][i];
		if(!mark[v]){
			LCA[0][v]=n;
			Level[v]=Level[n]+1;
			int lg=loga2(Level[v]);
			for(int j=1;j<=lg;j++){
				if(LCA[j-1][v]!=-1){
					LCA[j][v]=LCA[j-1][LCA[j-1][v]];
				}
			}
			DFS(v);
		}
	}
}
int lca(int p,int q){
	if(Level[p]<Level[q])
		swap(p,q);
	int log,i;
	log=loga2(Level[p]);
	if(Level[p]!=Level[q]){
		for(i=log;i>=0;i--){
			if(Level[p]-(1<<i)>=Level[q]){
				p=LCA[i][p];
			}
		}
	}
	if(p==q)return p;
	for(i=log;i>=0;i--){
		if(LCA[i][p]!=-1 && LCA[i][p]!=LCA[i][q]){
			p=LCA[i][p];
			q=LCA[i][q];
		}
	}
	return LCA[0][p];
}
int x,y,v,c,q,t,k;
int main ()
{

	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	while(scanf("%d",&n)==1){
		G.clear();
		G.resize(n+10);
		M.clear();
		memset(LCA,-1,sizeof(LCA));
		memset(mark,0,sizeof(mark));
		for(int i=0;i<n;i++){
			scanf("%d:(%d)",&v,&c);
			if(i==0)
				k=v;
			for(int k=0;k<c;k++){
				scanf("%d",&x);
				G[v].push_back(x);
				G[x].push_back(v);
			}
		}
		DFS(k);
		scanf("%d\n",&q);
		char c;
		for(int i=0;i<q;i++){
			scanf("%c%d,%d%c",&c,&x,&y,&c);
			getchar();
			t=lca(x,y);
			M[t]++;
		}
		fort(i,M)
		printf("%d:%d\n",i->first,i->second);
	}
	return 0;
}
