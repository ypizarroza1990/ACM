#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define MAX 4000000
using namespace std;
typedef long long i64;
int Fden[MAX],Fnum[MAX],l;
void farey(int lnum=0,int lden=1,int rnum=1,int rden=1,int MAXD=0){
	int a=lnum+rnum,b=rden+lden;
	if(b>MAXD)return;

	farey(lnum,lden,a,b,MAXD);
	Fnum[l]=a;
	Fden[l++]=b;
	farey(a,b,rnum,rden,MAXD);
}
int N,K;
int main(){

	 while(scanf("%d%d",&N,&K)==2){
		 l=0;
		 farey(0,1,1,1,N);K--;
		 Fnum[l]=1;
		 Fden[l++]=1;
	 printf("%d/%d\n",Fnum[K],Fden[K]);
	 }
}

