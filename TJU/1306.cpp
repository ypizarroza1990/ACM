#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
struct bipartie_graph{
	int V1,V2,*match;
	vector<int>*L;
	bool *visit;

	bipartie_graph(int m_V1,int m_V2){
		match=new int[m_V2];
		visit= new bool[m_V2];
		L=new vector<int>[m_V1];
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
		int res=0;
		fill(match,match+V2,-1);
		for(int i=0;i<V1;i++){
			fill(visit,visit+V2,0);
			res+=dfs(i);
		}
		return res;
	}
}G(20,20);
int R[10][10],C[10][10];
int N,V1,V2;
char cad[10][10];
int main(){

	while(scanf("%d",&N),N){
		V1=V2=0;
		for(int i=0;i<N;i++)
			scanf("%s",cad[i]);
		memset(R,-1,sizeof(R));
		memset(C,-1,sizeof(C));
		G.clear(20,20);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				if(cad[i][j]=='X')continue;
				if(j==0)
					R[i][j]=V1++;
				else{
					if(R[i][j-1]==-1)
						R[i][j]=V1++;
					else
						R[i][j]=R[i][j-1];
				}
				if(i==0)
					C[i][j]=V2++;
				else{
					if(C[i-1][j]==-1)
						C[i][j]=V2++;
					else
						C[i][j]=C[i-1][j];
				}
				G.add(R[i][j],C[i][j]);
			}
		printf("%d\n",G.matching());

	}

	return 0;
}

