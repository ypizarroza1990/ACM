#include <bits/stdc++.h>
#define MAX 1000000
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
struct Djoinset{
	int*parent;
	int*rank;
	int*size;

	Djoinset(int n){
		parent=new int[n+10];
		rank=new int[n+10];
		size=new int[n+10];

		for(int i=0;i<=n;i++){
			parent[i]=i;
			rank[i]=0;
			size[i]=1;
		}
	}

	int find(int x){
		return parent[x]==x?x:parent[x]=find(parent[x]);
	}
	int equals(int x,int y){
		return find(x)==find(y);
	}
	void join(int x,int y){
		int x1=find(x),x2=find(y);
		if(x1==x2)return;
		if(rank[x1]==rank[x2])++rank[x1];
		if(rank[x1]<rank[x2])swap(x1,x2);
		parent[x2]=x1;
		size[x1]+=size[x2];
	}
};
map<string,int>M;
int l;
int find(string S){
	if(M[S])
		return M[S];
	else{
		return M[S]=l++;
	}
}
int main() {

	int cas,n;
	string a,b;
	cin>>cas;
	while(cas--){
		M.clear();l=1;
		cin>>n;
		Djoinset D(n+10);
		while(n--){
			cin>>a>>b;
			int ia=find(a),ib=find(b);
			D.join(ia,ib);
			cout<<D.size[D.find(ia)]<<endl;

		}
	}
	return 0;
}
