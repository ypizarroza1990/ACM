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
#define POW(x)((x)*(x))
using namespace std;
typedef long long i64;
typedef pair<double,double>P;
double M[250][250];
int cont,n,m,cost,t=1;
double x,y;
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
			M[i][j]=1e9;
			if(i==j)
				M[i][j]=0;
		}
}

double dist(P a,P b){
	return sqrt(POW(a.first-b.first)+POW(a.second-b.second));
}
P a,b;
vector<P>V;
int main(){
	//freopen("entrada.in","r",stdin);
	//freopen("salida.out","w",stdout);
	while(scanf("%d",&n),n){
		fill(n);
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&x,&y);
			 V.push_back(make_pair(x,y));
		}
		int sz=V.size();
		for(int i=0;i<sz-1;i++)
			for(int j=i;j<sz;j++){
				M[i][j]=M[j][i]=dist(V[i],V[j]);
				//printf("%.3lf\n",M[i][j]);
			}
		Floyd(n);
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",t++,M[0][1]+1e-9);
		V.clear();
	}
	return 0;
}

