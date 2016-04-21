#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
int c,d,v,cas,N,M;
string v1,v2;
int G[509][509];
bool visit[509];
int pred[509];
bool dfs(int v){
	if(visit[v])return 0;
	visit[v]=1;
	for(int i=0;i<M;i++){
		if(G[v][i]&&(pred[i]==-1||dfs(pred[i]))){
			pred[i]=v;
			return 1;
		}
	}
	return 0;
}
int main(){
	 cin>>cas;
	 while(cas--){
		 cin>>c>>d>>v;
		 memset(G,0,sizeof(G));
		 vector<string>c1,c2,d1,d2;
		 for(int i=0;i<v;i++){
			 cin>>v1>>v2;
			 if(v1[0]=='C'){
				 c1.push_back(v1);
				 c2.push_back(v2);
			 }else{
				 d1.push_back(v1);
				 d2.push_back(v2);
			 }
		 }
		 N=c1.size();
		 M=d1.size();
		 for(int i=0;i<N;i++)
			 for(int j=0;j<M;j++){
				 if(c1[i]==d2[j]||d1[j]==c2[i])
					 G[i][j]=1;
			 }
		 memset(pred,-1,sizeof(pred));
		 int sol=0;
		 for(int i=0;i<N;i++){
			 memset(visit,0,sizeof(visit));
			 sol+=dfs(i);
		 }
		 cout<<v-sol<<endl;
	 }
}

