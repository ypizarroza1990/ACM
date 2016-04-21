#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include<iostream>
#include<map>
#include<sstream>
using namespace std;
typedef unsigned long long  i64;
int movx[]={-2,-1,+1,+2,+2,+1,-1,-2};
int movy[]={-1,-2,-2,-1,+1,+2,+2,+1};
int N,cas,x,y,x2,y2;
struct node{
	int x,y,cont;
	node(int _x,int _y,int _cont){
		x=_x,y=_y,cont=_cont;
	}
};
vector< vector<bool> >visit;
int BFS(node u,node v){
	queue<node>Q;
	Q.push(u);
	int x,y;
	while(!Q.empty()){
		node V=Q.front();Q.pop();
		if(V.x==v.x&&V.y==v.y)
			return V.cont;
		for(int i=0;i<8;i++){
			x=V.x+movx[i];
			y=V.y+movy[i];
			if(x>=0&&x<N&&y>=0&&y<N&&!visit[x][y]){
				visit[x][y]=1;
				Q.push(node(x,y,V.cont+1));
			}
		}
	}
}
int main(){
	scanf("%d",&cas);
	while(cas--){
		scanf("%d",&N);
		visit.clear();
		for(int i=0;i<N;i++){
			vector<bool>c;
			c.resize(N,false);
			c.reserve(N);
			visit.push_back(c);
		}
		scanf("%d%d%d%d",&x,&y,&x2,&y2);
		node a=node(x,y,0);
		node b=node(x2,y2,0);
		printf("%d\n",BFS(a,b));
	}
	return 0;
}

