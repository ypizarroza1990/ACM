#include <bits/stdc++.h>
#define MAX 100
#define LOG(x)31-__builtin_clz(x);
using namespace std;
struct bipartie_graph{
	int V1,V2,*match;
	vector<int>*L;
	bool *visit;

	bipartie_graph(int M_v1,int M_v2){
		L=new vector<int>[M_v1];
		match=new int[M_v2];
		visit=new bool[M_v2];
	}

	void clear(int v1,int v2){
		V1=v1;V2=v2;
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
				if(match[v]==-1||dfs(match[v])){
					match[v]=u;
					return 1;
				}
			}
		}
		return 0;
	}

	int matching(){
		int sol=0;
		fill(match,match+V2,-1);
		for(int i=0;i<V1;i++){
			fill(visit,visit+V2,0);
			sol+=dfs(i);
		}
		return sol;
	}
}G(MAX*MAX,MAX*MAX);
int N,C[MAX+1][MAX+1],F[MAX+1][MAX+1],r,c;
int main() {

	while(cin>>N){
		vector<string>cad(N);
		for(int i=0;i<N;i++)
			cin>>cad[i];
		r=c=0;
		G.clear(MAX*MAX,MAX*MAX);
		memset(C,-1,sizeof(C));
		memset(F,-1,sizeof(F));
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				if(cad[i][j]=='X')continue;
				if(j==0)
					F[i][j]=r++;
				else{
					if(F[i][j-1]==-1)F[i][j]=r++;
					else F[i][j]=F[i][j-1];
				}
				if(i==0)
					C[i][j]=c++;
				else{
					if(C[i-1][j]==-1)C[i][j]=c++;
					else C[i][j]=C[i-1][j];
				}
				G.add(F[i][j],C[i][j]);
			}
		cout<<G.matching()<<endl;
	}
	return 0;
}

