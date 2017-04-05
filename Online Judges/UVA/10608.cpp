//============================================================================
// Name        : UVA.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
struct Djoinset{
	int* parent;
	int* rank;
	int* size;
	Djoinset(int n){
		parent = new int[n+10];
		rank = new int[n+10];
		size = new int[n+10];
		for(int i=0;i<n;i++){
			parent[i]=i;
			size[i]=1;
		}
	}
	int find(int x){
		return parent[x]==x?x:parent[x]=find(parent[x]);
	}
	bool equal(int x,int y){
		return find(x)==find(y);
	}
	void join(int x,int y){
		int x1,x2;
		x1=find(x),x2=find(y);
		if(x1==x2)
			return;
		if(rank[x1]==rank[x2])
			++rank[x1];
		if(rank[x1]<rank[x2])
			swap(x1,x2);
		parent[x2]=x1;
		size[x1]+=size[x2];
	}
};
int cas,n,m,x,y,cont;
int main(){

	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&n,&m);
		Djoinset S(n);
		cont=0;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			x--,--y;
			if(!S.equal(x,y)){
				S.join(x,y);
				cont=max(cont,S.size[S.find(x)]);
			}
		}
		printf("%d\n",cont);
	}
	return 0;
}
