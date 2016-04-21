//============================================================================
// Name        : Grundy_Cup.cpp
// Author      : BeCrazy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
int parent[10100],rank[10100];
void make(int i){
	parent[i]=i;
	rank[i]=1;
}
int find(int x){
	return x==parent[x]?x:parent[x]=find(parent[x]);
}
void join(int x,int y){
	int x1=find(x),x2=find(y);
	if(x1==x2)return;
	if(rank[x1]==rank[x2])rank[x1]++;
	if(rank[x1]<rank[x2])swap(x1,x2);
	parent[x2]=x1;
}
int n,m,k,x,y;
int main() {
	 while(scanf("%d %d %d",&n,&m,&k)==3){
		 for(int i=0;i<n;i++)
			 make(i);
		 for(int i=0;i<m;i++){
			 scanf("%d %d",&x,&y);
			 join(x,y);
		 }
		 while(k--){
			 scanf("%d %d",&x,&y);
			 find(x)==find(y)?puts("YES"):puts("NO");
		 }
	 }
	return 0;
}
