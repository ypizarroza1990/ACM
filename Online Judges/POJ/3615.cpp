#include <vector>
#include <stdio.h>
#include <string.h>
#define MAX 509
using namespace std;
typedef long long i64;
int Matriz[MAX][MAX];
int N,M,T,x,y,c;
int main() {
	  scanf("%d %d %d",&N,&M,&T);
	  memset(Matriz,60,sizeof(Matriz));
	  for(int i=0;i<M;i++){
		  scanf("%d %d %d",&x,&y,&c);
		  Matriz[x][y]=min(Matriz[x][y],c);
	  }
	  for(int k=1;k<=N;k++)
		  for(int i=1;i<=N;i++)
			  for(int j=1;j<=N;j++)
				  Matriz[i][j]=max(min(Matriz[i][j],Matriz[i][k]),min(Matriz[i][j],Matriz[k][j]));
	  for(int i=1;i<=T;i++){
		  scanf("%d %d",&x,&y);
		  printf("%d\n",Matriz[x][y]==1010580540?-1:Matriz[x][y]);
	  }

}
