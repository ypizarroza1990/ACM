#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include <iostream>
#include <map>
using namespace std;
typedef long long i64;
int n,m,cont,cas;
int movx[]={0,0,-1,+1};
int movy[]={-1,+1,0,0};
struct language{
	char id;
	int n;
	language(char _id=' ',int _n=0){
		id=_id,n=_n;
	}
	bool operator<(const language L)const{
		if(n==L.n)
			return id<L.id;
		return n>L.n;
	}
};
struct node{
	int x,y;
	node(int _x=0,int _y=0){
		x=_x,y=_y;
	}
};
map<char,int>M;
map<char,int>::iterator it;
vector<string>cad;
vector<vector<bool> >visit;
void BFS(node u,char c){
	node v;
	queue<node>Q;
	Q.push(u);
	int x,y;
	while(!Q.empty()){
		v=Q.front();Q.pop();
		for(int i=0;i<4;i++){
			x=v.x+movx[i];
			y=v.y+movy[i];
			if(x>=0&&x<n&&y>=0&&y<m&&!visit[x][y]&&cad[x][y]==c){
				visit[x][y]=1;
				Q.push(node(x,y));
			}
		}
	}
}
vector<language>V;
string S;
int main(){
	scanf("%d",&cas);
	for(int i=1;i<=cas;i++){
		scanf("%d%d",&n,&m);
		V.clear();
		visit.clear();
		M.clear();
		cad.clear();
		for(int j=0;j<n;j++){
			cin>>S;
			cad.push_back(S);
			vector<bool>B;
			B.resize(m);
			B.reserve(m);
			visit.push_back(B);
		}
		for(int j=0;j<n;j++)
			for(int k=0;k<m;k++){
				if(!visit[j][k]){
					++M[cad[j][k]];
					BFS(node(j,k),cad[j][k]);
				}
			}
		for(it=M.begin();it!=M.end();it++)
			V.push_back(language(it->first,it->second));
		sort(V.begin(),V.end());
		printf("World #%d\n",i);
		for(int i=0;i<V.size();i++){
			printf("%c: %d\n",V[i].id,V[i].n);
		}
	}
	return 0;
}

