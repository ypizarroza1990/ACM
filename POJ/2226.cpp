#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long i64;
struct bipartie_graph{
	int V1,V2,*match;
	vector<int>*L;
	bool *visit;

	bipartie_graph(int m_V1,int m_V2){
		visit=new bool[m_V2];
		match=new int[m_V2];
		L=new vector<int>[m_V1];
	}
	void clear(int v1,int v2){
		V1=v1,V2=v2;
		for(int i=0;i<V1;i++)
			L[i].clear();
	}
	void add(int v1,int v2){
		L[v1].push_back(v2);
	}
	bool dfs(int v){
		for(int i=L[v].size()-1;i>=0;i--){
			int u=L[v][i];
			if(!visit[u]){
				visit[u]=1;
				if(match[u]==-1 ||(dfs(match[u]))){
					match[u]=v;
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
}G(3000,3000);
int n,m;
char cad[60][60];
int F[60][60],C[60][60],V1,V2;
int main()
{
	scanf("%d%d",&n,&m);
	V1=V2=0;
	for(int i=0;i<n;i++)
		scanf("%s",cad[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(cad[i][j]=='*'){
				if(j==0 || cad[i][j-1]!='*')
					F[i][j]=V1++;
				else
					F[i][j]=F[i][j-1];
				if(i==0 || cad[i-1][j]!='*')
					C[i][j]=V2++;
				else
					C[i][j]=C[i-1][j];
			}
		}
	if(V1==0){
		puts("0");
		return 0;
	}
	G.clear(V1,V2);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(cad[i][j]=='*')
				G.add(F[i][j],C[i][j]);

	printf("%d\n",G.matching());
	return 0;
}

