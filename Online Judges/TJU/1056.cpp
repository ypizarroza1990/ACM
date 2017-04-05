#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
struct node{
	int x,y,dist;
	node(){};
	node(int xx,int yy,int d):x(xx),y(yy),dist(d){};
};
char cad[1009][1009];
bool visit[1009][1009];
int movx[]={1,-1,0,0};
int movy[]={0,0,1,-1},N,M;
node bfs(node u){
	memset(visit,0,sizeof(visit));
	queue<node>Q;
	Q.push(node(u.x,u.y,0));
	node ans;
	visit[u.x][u.y]=1;
	while(!Q.empty()){
		node v=Q.front();Q.pop();
		ans=v;
		for(int i=0;i<4;i++){
			int x=v.x+movx[i];
			int y=v.y+movy[i];
			if(x>=0 && x<N && y>=0 && y<M && !visit[x][y] && cad[x][y]!='#'){
				visit[x][y]=1;
				Q.push(node(x,y,v.dist+1));
			}
		}
	}
	return ans;
}
int cas,ok;
int main(){

	 scanf("%d",&cas);
	 while(cas--){
		 node inicio;
		 ok=0;
		 scanf("%d%d",&M,&N);
		 for(int i=0;i<N;i++)
			 scanf("%s",cad[i]);
		 for(int i=0;i<N&&!ok;i++){
			 for(int j=0;j<M;j++)
				 if(cad[i][j]!='#'){
					 inicio= node(i,j,0);
					 ok=1;
					 break;
				 }
		 }
		 node far= bfs(inicio);
		 printf("Maximum rope length is %d.\n",bfs(far).dist);

	 }

	return 0;
}

