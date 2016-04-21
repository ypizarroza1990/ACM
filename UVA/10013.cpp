//============================================================================
// Name        : 10013.cpp
// Author      : Anthrax
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#define MAX 1000010
using namespace std;
int  A[MAX],B[MAX];
int cas,M,res,ok=0;
int main() {

	scanf("%d",&cas);
	while(cas--){
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		scanf("%d",&M);
		for(int i=0;i<M;i++){
			scanf("%d %d",&A[i],&B[i]);
		}
		res=0;
		for(int i=M-1;i>=0;i--){
			res+=(A[i]+B[i]);
			A[i]=res%10;
			res/=10;
		}
		if(ok)	printf("\n");
		for(int i=0;i<M;i++){
			printf("%d",A[i]);
		}
		printf("\n");
		ok=1;
	}
	return 0;
}
