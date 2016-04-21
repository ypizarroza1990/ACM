#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#define i64 long long
using namespace std;
const int MAXN = 2*100000;
typedef pair<int,int>P;
int tree[MAXN+1],N;
P event[MAXN+1];
int inc[MAXN+1];

bool cmp(P a,P b){
	return a.second<b.second;
}
int query(int pos){
	int sum = 0;
	for(;pos>0;pos-=(pos&-pos))
		sum=max(sum,tree[pos]);
	return sum;
}

void update(int pos,int val){
	for(;pos<=MAXN;pos+=(pos&-pos))
		tree[pos]=max(tree[pos],val);
}
int cas;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>event[i].first;
			event[i].second = i;
		}
		sort(event,event+N);

		for(int i=0,j=0;i<N;j++){
			int e=i;
			while(event[i].first==event[e].first)e++;
			for(int k=i;k<e;k++)
				event[k].first=j;
			i=e;
		}
		sort(event,event+N,cmp);
		memset(tree,0,sizeof(tree));
		int ans = 0;
		inc[0]=1;
		for(int i=1;i<N;i++){
			if(event[i].first > event[i-1].first)inc[i]=inc[i-1]+1;
			else inc[i]=1;
		}
		for(int i=N-1,inc2=0;i>=0;i--){
			if(i<N-1 && event[i].first<event[i+1].first)inc2++;
			else inc2 =1;
			update(N-event[i].first,inc2);
			ans = max(ans,inc[i]+query(N-event[i].first-1));
		}
		cout<<ans<<"\n";
	}
	return 0;
}

