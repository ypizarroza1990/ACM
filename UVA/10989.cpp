#include <bits/stdc++.h>
#define i64 long long
using namespace std;

typedef vector<int>VI;
typedef vector<VI>VVI;
const i64 INF =  (i64)1e12;
pair<int,VI>MinCut(VVI &pesos){
	int N = pesos.size();
	VI used(N),cut,best_cut;
	int best_weight = -1;
	for(int phase = N-1;phase>=0;phase--){
		VI w = pesos[0];
		VI added = used;
		int prev,last = 0;
		for(int i = 0;i<phase;i++){
			prev = last;
			last = -1;
			for(int j = 1;j<N;j++)
				if(!added[j]&&(last== -1 || w[j]>w[last]))last = j;
			if(i==phase-1){
				for(int j = 0;j<N;j++)
					pesos[prev][j]+=pesos[last][j];
				for(int j = 0;j<N;j++)
					pesos[j][prev]=pesos[prev][j];
				used[last] = true;
				cut.push_back(last);
				if(best_weight == -1 || w[last]<best_weight){
					best_cut=cut;
					best_weight = w[last];
				}
			}else{
				for(int j=0;j<N;j++)
					w[j]+=pesos[last][j];
				added[last]=true;
			}
		}
	}
	return make_pair(best_weight,best_cut);
}
int cas,n,m,x,y,w;
VVI M;
int main(){
	cin>>cas;
	for(int j=1;j<=cas;j++){
		cin>>n>>m;
		M.resize(n,vector<int>(n));
		for(int i=0;i<m;i++){
			cin>>x>>y>>w;
			x--,y--;
			M[x][y] +=w;
			M[y][x] +=w;
		}
		cout<<"Case #"<<j<<": "<<MinCut(M).first<<"\n";
		M.clear();
	}
	return 0;
}


