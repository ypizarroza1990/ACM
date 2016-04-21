#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long i64;
const int INF = 1000000000;
const int MAXE = 1009;
const int MAXT = 109;
const int LOG = 20;

int dist[LOG][MAXT][MAXT],change[MAXE];
int V,N,T,S,E,best[MAXE],best2[MAXE];
void check(int &ind){
	if(change[ind]==-1)
		change[ind]=V++;

	ind=change[ind];
}
int main()
{
	memset(change,-1,sizeof(change));
	memset(dist,63,sizeof(dist));
	memset(best,63,sizeof(best));

	int x,y,c;
	scanf("%d%d%d%d",&N,&T,&S,&E);
		check(S);
		check(E);
	for(int i=0;i<T;i++){
		scanf("%d%d%d",&c,&x,&y);
		check(x);
		check(y);
		dist[0][x][y]=min(dist[0][x][y],c);
		dist[0][y][x]=min(dist[0][y][x],c);
	}
	//divide en pow 2^p
	 for(int p=1;(1<<p)<=N;p++){
		 for(int i=0;i<V;i++)
			 for(int j=0;j<V;j++)
				 if(dist[p-1][i][j]<INF){
					 for(int k=0;k<V;k++)
						 dist[p][i][k]=min( dist[p][i][k], dist[p-1][i][j]+ dist[p-1][j][k]);
				 }
	 	 }
	// join  distance
	 best[S]=0;
	for(int p=0;(1<<p)<=N;p++){
		if(N & (1<<p)){
			memset(best2,63,sizeof(best2));
			for(int i=0;i<V;i++)
				if(best[i]<INF)
				for(int j=0;j<V;j++)
					if(best[i]<INF)
					best2[j]=min(best2[j],best[i]+dist[p][i][j]);
			memcpy(best,best2,sizeof(best2));
		}
	}
	printf("%d\n",best[E]);
	return 0;
}
