#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <stack>
#define MAXN 100050
using namespace std;
int m,n,cont=1;
int movx[]={-1,-1,-1,0,0,+1,+1,+1};
int movy[]={-1,0,+1,-1,+1,-1,0,+1};
char cad[150][150];
bool isVal(int x,int y){
	if(x>=0 && x<n && y>=0 && y<m)return true;
	return false;
}
int N(int x,int y){
	int res=0;
	for(int i=0;i<8;i++){
		int x1=x+movx[i],y1=y+movy[i];
		if(isVal(x1,y1)&&cad[x1][y1]=='*'){
			res++;
		}
	}
	return res;
}
int main(){
	//freopen("entrada.in","r",stdin);
	//freopen("salida.out","w",stdout);

	while(scanf("%d%d",&n,&m),n+m){
		if(cont>1)
			printf("\n");
		printf("Field #%d:\n",cont++);
		for(int i=0;i<n;i++)
			scanf("%s",cad[i]);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(cad[i][j]=='*')
					putchar(cad[i][j]);
				else
					printf("%d",N(i,j));
			}
			printf("\n");
		}
	}
	return 0;
}

