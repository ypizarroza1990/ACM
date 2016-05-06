#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
vector<pi>V;
int cas,n,x,y;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x>>y;
			V.push_back(make_pair(y,x));
		}
		sort(V.begin(),V.end());
		int tails=0;
		int last = -1;
		for(int i=0;i<n;i++){
			if(last<V[i].second){
				tails++;
				last=V[i].first;
			}
		}
		cout<<tails<<"\n";
		V.clear();
	}
	return 0;
}

