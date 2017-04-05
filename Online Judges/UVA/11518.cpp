#include<iostream>
#include<string.h>
#include <cmath>
#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int> >ady;
int cas,total;
bool visit[10010];
void DFS(int v){
	visit[v]=true;
	for(int i=0;i<ady[v].size();++i){
		if(!visit[ady[v][i]]){
			DFS(ady[v][i]);
		}
	}
}
int N,Q,E,x,y,orig;
int main(){
      cin>>cas;
      while(cas--){
    	 cin>>N>>E>>Q;
    	 ady.clear();
    	 ady.assign(N+1,vector<int>());
    	 for(int i=0;i<E;i++){
    		 cin>>x>>y;
    		 ady[x].push_back(y);
    	 }
    	 total=0;
    	 memset(visit,0,sizeof(visit));
    	 while(Q--){
    		 cin>>orig;
    		 DFS(orig);
    	 }
    	 total=0;
    	 for(int i=1;i<=N;i++)
    		 total+=visit[i];
    	 cout<<total<<endl;
      }
    return 0;
}
 
