#include <bits/stdc++.h>
#define MAX 800
using namespace std;
int movx[]={-1,-1,-1,0,0,1,1,1};
int movy[]={-1,0,1,-1,1,-1,0,1};
bool mark[MAX][MAX];
int n,m,ans=0;
vector<string>M;
struct node{
	int x,y;
	node(){};
	node(int _x,int _y):x(_x),y(_y){};
};
int BFS(node u){
	queue<node>Q;
	mark[u.x][u.y]=true;;
	int cont=0;
	Q.push(u);
	while(!Q.empty()){
		node v=Q.front();Q.pop();
		cont++;
		for(int i=0;i<8;i++){
			int x=v.x+movx[i];
			int y=v.y+movy[i];
			if(x>=0&&x<n&&y>=0&&y<m&&!mark[x][y]&&M[x][y]=='.'){
				mark[x][y]=true;
				Q.push(node(x,y));
			}
		}
	}
	return cont;
}
string cad;
int main() {
	 scanf("%d %d",&m,&n);
	 memset(mark,0,sizeof(mark));
	 for(int i=0;i<n;i++){
		 cin>>cad;
		 M.push_back(cad);
	 }
	 for(int i=0;i<n;i++){
		 for(int j=0;j<m;j++)
			 if(!mark[i][j]&&M[i][j]=='.'){
				 ans=max(ans,BFS(node(i,j)));
			 }
	 }
	 printf("%d\n",ans);
	return 0;
}

