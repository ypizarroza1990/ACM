#include<bits/stdc++.h>
#define MAX  200001
#define i64 long long
using namespace std;
int N,K,cas,x,y;
string op;
i64 bit[MAX];
void update(int pos,int val){
	for(;pos<MAX;pos+=(pos&-pos))
		bit[pos]+=val;
}
i64 query(int pos){
	i64 sum=0;
	for(;pos>0;pos-=(pos&-pos))
		sum+=bit[pos];
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cas = 1;
	while(cin>>N,N){
		for(int i=1;i<=N;i++){
			cin>>K;
			update(i,K);
		}
		if(cas!=1)
			cout<<"\n";

		cout<<"Case "<<cas++<<":\n";
		while(cin>>op){
			if(op == "END")break;
			else if(op=="S"){
				cin>>x>>y;
				int temp = query(x)-query(x-1);
				update(x,-temp);
				update(x,y);
			}else{
				cin>>x>>y;
				cout<<query(y)-query(x-1)<<"\n";
			}
		}
		memset(bit,0,sizeof(bit));
	}
	return 0;
}
 
