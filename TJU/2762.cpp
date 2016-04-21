#include <bits/stdc++.h>
using namespace std;
#define MAXC 50100
int A[MAXC],RMQ[MAXC][31],RMQ2[MAXC][31],N,Q;
void ProcessRMQ(){
	memset(RMQ,0,sizeof(RMQ));
	for(int i=0;i<N;i++)RMQ[i][0]=i;
	for(int j=1;(1<<j)<=N;j++)
		for(int i=0;i+(1<<j)-1<=N;i++)
			if(A[RMQ[i][j-1]]<=A[RMQ[i+(1<<(j-1))][j-1]])
				RMQ[i][j]=RMQ[i][j-1];
			else
				RMQ[i][j]=RMQ[i+(1<<(j-1))][j-1];
}
int Calcula_RMQ(int i,int j){
	int k=(int)(log((double)(j-i+1))/log (2.0));
	if(A[RMQ[i][k]]<=A[RMQ[j-(1<<k)+1][k]])
		return A[RMQ[i][k]];
	else
		return A[RMQ[j-(1<<k)+1][k]];
}
void ProcessRMQ2(){
	memset(RMQ2,0,sizeof(RMQ2));
	for(int i=0;i<N;i++)RMQ2[i][0]=i;
	for(int j=1;(1<<j)<=N;j++)
		for(int i=0;i+(1<<j)-1<=N;i++)
			if(A[RMQ2[i][j-1]]>A[RMQ2[i+(1<<(j-1))][j-1]])
				RMQ2[i][j]=RMQ2[i][j-1];
			else
				RMQ2[i][j]=RMQ2[i+(1<<(j-1))][j-1];
}
int Calcula_RMQ2(int i,int j){
	int k=(int)(log((double)(j-i+1))/log (2.0));
	if(A[RMQ2[i][k]]>A[RMQ2[j-(1<<k)+1][k]])
		return A[RMQ2[i][k]];
	else
		return A[RMQ2[j-(1<<k)+1][k]];
}
int i,j;
int main() {
	 scanf("%d%d",&N,&Q);
  for(int i=0;i<N;i++)
  scanf("%d",&A[i]);
  ProcessRMQ();
  ProcessRMQ2();
  while(Q--){
	  scanf("%d%d",&i,&j);
	  if(i>j)swap(i,j);
	 i--,j--;
	  printf("%d\n",Calcula_RMQ2(i,j)-Calcula_RMQ(i,j));
  }

    return 0;
}
