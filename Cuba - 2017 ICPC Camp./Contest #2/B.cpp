#include<bits/stdc++.h>
#define MAX_N  200009
#define LOG(x) 31-__builtin_clz(x)
using namespace std;
struct node{
	int _last,_next,level;
}versions[MAX_N];

int lca[21][MAX_N],N;
int op,v,x,vals[MAX_N];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("data.in","r",stdin);
	cin>>N;

	for(int j=0;(1<<j)<=N;j++)
		for(int i=0;i<=N;i++)
			lca[j][i]=-1;

	versions[0] = {0,0,0};
	for(int i=1;i<=N;i++){
		cin>>op>>v;
		if(op == 1){
			cin>>x;
			vals[i]=x;
			lca[0][i] = versions[v]._next;

			for(int j=1;(1<<j)<=N;j++)
				if(lca[j-1][i] != -1)
					lca[j][i] = lca[j-1][lca[j-1][i]];

			versions[i]._last = versions[v]._last;
			versions[i]._next = i;
			versions[i].level = versions[lca[0][i]].level+1;
		}else{
			versions[i]=versions[v];
			int anc = versions[i]._next;

			for(int j=LOG(N);j>=0;j--){
				if(lca[j][anc]!=-1 && versions[lca[j][anc]].level>versions[versions[i]._last].level)
					anc = lca[j][anc];
			}
			cout<<vals[anc]<<"\n";
			versions[i]._last = anc;
		}
	}
    return 0;
}
