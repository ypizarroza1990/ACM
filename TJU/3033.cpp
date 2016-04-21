#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
struct node{
	int x,y;
	node(){};
	node(int xx,int yy):x(xx),y(yy){};
};
int dist[1009][1009],dist2[1009][1009];
int movx[]={1,-1,0,0},x,y;
int movy[]={0,0,1,-1},N,M,T,cas;
node ini,fin;
int dijkstra(int D){
	queue<node>Q;
	memset(dist2,-1,sizeof(dist2));
	Q.push(ini);
	dist2[ini.x][ini.y]=0;
	while(!Q.empty()){
		node v=Q.front();Q.pop();
		for(int i=0;i<4;i++){
			int x=v.x+movx[i];
			int y=v.y+movy[i];
			if(x>=0 && x < N && y>=0 && y < M && dist[x][y]>=D && dist2[x][y]==-1){
				dist2[x][y]=dist2[v.x][v.y]+1;
				Q.push(node(x,y));
			}
		}
	}
	return dist2[fin.x][fin.y];
}
int main(){

	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d%d",&T,&N,&M);
		queue<node>Q;
		memset(dist,-1,sizeof(dist));
		scanf("%d%d%d%d",&ini.x,&ini.y,&fin.x,&fin.y);
		for(int i=0;i<T;i++){
			scanf("%d%d",&x,&y);
			Q.push(node(x,y));
			dist[x][y]=0;
		}
		while(!Q.empty()){
			node v=Q.front();Q.pop();
			for(int i=0;i<4;i++){
				int x=v.x+movx[i];
				int y=v.y+movy[i];
				if(x>=0 && x < N && y>=0 && y < M && dist[x][y]==-1){
					dist[x][y]=dist[v.x][v.y]+1;
					Q.push(node(x,y));
				}
			}
		}
		int lo=0,hi=dist[ini.x][ini.y],mid;
		while(hi-lo>0){
			mid=(hi+lo+1)/2;
			if(dijkstra(mid)!=-1)
				lo=mid;
			else
				hi=mid-1;
		}
		printf("%d %d\n",lo,dijkstra(lo));
	}

	return 0;
}

