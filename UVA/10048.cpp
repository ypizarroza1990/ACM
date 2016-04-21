/*-------Anthrax---------*/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstdlib>
#define INF 1e9
#define POW(x)((x)*(x))
using namespace std;
typedef long long i64;
typedef pair<double,double>P;
int M[150][150];
int cont,n,m,q,cost,t=1,x,y;
void Floyd(int n){
	for(int k=0;k<=n;k++)
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++){
				M[i][j]=min(M[i][j],max(M[i][k],M[k][j]));
			}
}
void fill(int n){
	for(int j=0;j<=n;j++)
		for(int i=0;i<=n;i++){
			M[i][j]= INF;
			if(i==j)
				M[i][j]=0;
		}
}

int main(){
	//freopen("entrada.in","r",stdin);
	//freopen("salida.out","w",stdout);
	while(scanf("%d%d%d",&n,&m,&q),n+m+q){
		fill(n);
		if(t>1)
			printf("\n");
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&cost);
			M[x][y]=M[y][x]=cost;
		}
		Floyd(n);
		printf("Case #%d\n",t++);
		while(q--){
			scanf("%d %d",&x,&y);
			M[x][y]==INF?puts("no path"):printf("%d\n",M[x][y]);
		}
	}
	return 0;
}

