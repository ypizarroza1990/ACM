#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iostream>
#define P(x)(x)*(x)
using namespace std;
int matriz[200][200];
bool mark[30];
const long INF =(long)1e9;
void floy(int n){
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				matriz[i][j]=min(matriz[i][j],matriz[i][k]+matriz[k][j]);
			}
}
void fill(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(i==j)
				matriz[i][j]=0;
			else
				matriz[i][j]=INF;
	}
}
int val(char a){
	if(isupper(a))
		return a-'A';
	else
		return a-'a'+26;
}
int n,cost,x,y;
int best=INF;
char from,to,cow;
vector<int>V;
int main() {

	//freopen("salida.out","w",stdout);
	while(scanf("%d",&n)==1){
	fill(55);
	for(int i=0;i<n;i++){
		cin>>from>>to>>cost;
		x=val(from),y=val(to);
		matriz[y][x]=matriz[x][y]=min(cost,matriz[x][y]);
	}
	floy(55);
	best=INF;
	for(int i=0;i<25;i++){
		if(matriz[i][25]<best){
			cow=i+'A';
			best=matriz[i][25];
		}
	}
	printf("%c %ld\n",cow,best);
	}
	return 0;
}
