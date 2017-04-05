#include <bits/stdc++.h>
#define MOD 1000003
using namespace std;
typedef long long i64;
int M[101][101];
int n,m;
bool V[101][101];
int mx[]={1,-1,0,0};
int my[]={0,0,1,-1};
struct node{
	int x,y,cost;
	node(){};
	node(int _x,int _y):x(_x),y(_y){};
};
int BFS(node ini){
	queue<node>Q;
	Q.push(ini);
	int ans=0;
	V[ini.x][ini.y]=1;
	while(!Q.empty()){
		node v=Q.front();Q.pop();
		ans+=M[v.x][v.y];
		for(int i=0;i<4;i++){
			int x=v.x+mx[i];
			int y=v.y+my[i];
			if(x>=0&&x<n&&y>=0&&y<n&&!V[x][y]&&(M[x][y])){
				V[x][y]=1;
				Q.push(node(x,y));
			}
		}
	}
	return ans;
}
int cas,ans=0;
node ini;
int main() {
	scanf("%d",&cas);
	while(cas--){
		ans=0;
		memset(V,0,sizeof(V));
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				scanf("%d",&M[i][j]);
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(!V[i][j]&&M[i][j]){
					int t=BFS(node(i,j));
					ans=max(ans,t);
				}
		printf("%d\n",ans);
	}
	return 0;
}
