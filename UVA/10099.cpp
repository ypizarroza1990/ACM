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
using namespace std;
typedef long long i64;
int M[250][250],cont,n,m,cost,x,y,t=1;
char one[100],two[100];
map<string,int>name;
int findS(string N){
	if(name[N])return name[N];
	else{
		cont++;
		name[N]=cont;
		return cont;
	}
}
void Floyd(int n){
	for(int k=0;k<=n;k++)
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				M[i][j]=max(M[i][j],min(M[i][k],M[k][j]));
}
void fill(int n){
	for(int i=0;i<=n;i++){
		memset(M[i],-1,sizeof(M[i]));
		M[i][i]=0;
	}
}
int main(){
	//freopen("entrada.in","r",stdin);
	//freopen("salida.out","w",stdout);
	while(scanf("%d%d",&n,&m),n+m){
		fill(n);cont=0;
		for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&cost);
		M[x][y]=cost;M[y][x]=cost;
		}
		Floyd(n);
		scanf("%d%d%d",&x,&y,&cost);
		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",t++,(int)ceil((double) cost/(double)(M[x][y]-1)));
	}
	return 0;
}

