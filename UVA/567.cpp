//============================================================================
// Name        : COJ.cpp
// Author      : Anthrax
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;
int M[30][30],x,y,m,q,t=1;;
#define INF 1e9
void floyd(int n){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
}
void fill(int n){
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++){
			M[i][j]=INF;
			if(i==j)
				M[i][j]=0;
		}
}
int main() {
	//freopen("en.in","r",stdin);
	while(scanf("%d",&x)==1){
		fill(20);
		for(int i=0;i<x;i++){
			scanf("%d",&y);
			M[1][y]=M[y][1]=1;
		}
		for(int i=2;i<20;i++){
			scanf("%d",&x);
			for(int j=0;j<x;j++){
				scanf("%d",&y);
				M[i][y]=M[y][i]=1;
			}
		}
		floyd(20);
		printf("Test Set #%d\n",t++);
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&x,&y);
			printf("%2d to %2d: %d\n",x,y,M[x][y]);
		}
		printf("\n");
	}
	return 0;
}

