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
	Djoinset(int n){
		parent = new int[n+10];
		rank = new int[n+10];
		for(int i=0;i<n;i++)
			parent[i]=i;
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
	}
};
int cas,n,x,y,cont;
string cad;
char c;
map<int,int>M;
int main(){

	scanf("%d",&cas);
	while(cas--){
		cin>>c;
		n=c-'A'+1;
		M.clear();
		Djoinset s(n);
		getline(cin,cad);
		while(getline(cin,cad)&&cad!=""){
			x=cad[0]-'A',y=cad[1]-'A';
			if(!s.equal(x,y)){
				s.join(x,y);
			}
		}
		for(int i=0;i<n;i++){
			 ++M[s.find(i)];
		}
		cout<<M.size()<<endl;
		if(cas)
			printf("\n");
	}
	return 0;
}
