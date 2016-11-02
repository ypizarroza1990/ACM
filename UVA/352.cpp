#include<cmath>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#include <iostream>
using namespace std;
typedef long long i64;
int N,cont,kases=1;
int movx[]={-1,-1,-1,0,0,+1,+1,+1};
int movy[]={-1,0,+1,-1,+1,-1,0,+1};
struct node{
	int x,y;
	node(int _x=0,int _y=0){
		x=_x,y=_y;
	}
};
bool visit[30][30];
char cad[30][30];
void BFS(node u){
	node v;
	queue<node>Q;
	Q.push(u);
	int x,y;
	while(!Q.empty()){
		v=Q.front();Q.pop();
		for(int i=0;i<8;i++){
			x=v.x+movx[i];
			y=v.y+movy[i];
			if(x>=0&&x<N&&y>=0&&y<N&&!visit[x][y]&&cad[x][y]=='1'){
				visit[x][y]=1;
				Q.push(node(x,y));
			}
		}
	}
}
void fill(int N){
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			visit[i][j]=0;
}
int main(){
	while(scanf("%d",&N)==1){
		cont=0;
		fill(N);
		for(int i=0;i<N;i++)
			scanf("%s",cad[i]);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				if(!visit[i][j]&&cad[i][j]=='1'){
					BFS(node(i,j));
					cont++;
				}
			}
		printf("Image number %d contains %d war eagles.\n",kases++,cont);
	}
	return 0;
}

