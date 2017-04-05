#include<bits/stdc++.h>
#define MAX  200001
#define i64 long long
using namespace std;
i64 tree[3*MAX];

void update(int node,int beg,int end,int pos,int val){
	if(beg>pos || pos>end)
		return;

	if(beg==end){
		tree[node]=val;
		return;
	}

	int mid = (beg+end)>>1;
	update(2*node,beg,mid,pos,val);

	update(2*node+1,mid+1,end,pos,val);

	tree[node]=tree[2*node]+tree[2*node+1];
}

i64 query(int node,int beg,int end,int a,int b){
	if(beg>b || end < a)
		return 0;
	if(beg>=a && end<=b)
		return tree[node];

	int mid = (beg+end)>>1;

	return query(2*node,beg,mid,a,b)+query(2*node+1,mid+1,end,a,b);

}
int cas,N,K,x,y;
string op;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cas = 1;
	while(cin>>N,N){
		for(int i=1;i<=N;i++){
			cin>>K;
			update(1,1,N,i,K);
		}
		if(cas!=1)
			cout<<"\n";

		cout<<"Case "<<cas++<<":\n";
		while(cin>>op){
			if(op == "END")break;
			else if(op=="S"){
				cin>>x>>y;
				update(1,1,N,x,y);
			}else{
				cin>>x>>y;
				cout<<query(1,1,N,x,y)<<"\n";
			}
		}
		memset(tree,0,sizeof(tree));
	}
	return 0;
}

 
