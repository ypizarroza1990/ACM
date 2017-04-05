#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int movx[]={-1,-1,-1,0,0,+1,+1,+1};
int movy[]={-1,0,+1,-1,+1,-1,0,+1};
int M[70][70],n,m,cont;
vector< vector<bool> >visit;
struct node{
	int x,y;
	node(){};
	node(int x,int y):x(x),y(y){};
};
void BFS(node u){
	queue<node>Q;
	Q.push(u);
	int x,y;
	while(!Q.empty()){
		node v=Q.front();
		Q.pop();
		x=y=0;
		for(int i=0;i<8;i++){
			x=v.x+movx[i];
			y=v.y+movy[i];
			if(x>=0&&x<n&&y>=0&&y<m&&!visit[x][y]&&M[x][y]==1)	{
				visit[x][y]=true;
				Q.push(node(x,y));
			}
		}
	}
}
int main()
{

	while(scanf("%d%d",&m,&n),n+m){
		cont=0;
		visit.clear();
		for(int i=0;i<n;i++){
			vector<bool>v;
			v.resize(m);
			v.reserve(m);
			visit.push_back(v);
			for(int j=0;j<m;j++)
				scanf("%d",&M[i][j]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
			if(M[i][j]==1&&!visit[i][j]){
				BFS(node(i,j));
				cont++;
			}
		}
		printf("%d\n",cont);
	}
	return 0;
}
