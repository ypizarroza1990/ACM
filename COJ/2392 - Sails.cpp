
#include <bits/stdc++.h>
#define i64 long long
using namespace std;
const int MAXN = 100000;
struct Event{
	int height,sail;
	bool operator<(const Event &E)const{
		if(height==E.height)
			return sail<E.sail;
		return height<E.height;
	}
};
int tree[MAXN+1],N,limit;
Event Events[MAXN+1];

int query(int pos){
	int sum = 0;
	for(;pos>0;pos-=(pos&-pos))
		sum+=tree[pos];
	return sum;
}

void update(int pos,int val){
	for(;pos<=limit;pos+=(pos&-pos))
		tree[pos]+=val;
}
int ultimo(int pos,int lo,int hi){
	int tmp = query(pos);
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(query(mid)==tmp)
			hi = mid-1;
		else
			lo = mid+1;
	}
	return hi+1;
}

int siguiente(int pos,int lo,int hi){
	int tmp = query(pos);
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(query(mid)==tmp)
			lo = mid+1;
		else
			hi = mid-1;
	}
	return lo-1;
}
int _next,_last;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>Events[i].height>>Events[i].sail;

	sort(Events,Events+N);

	limit = Events[N-1].height;

	for(int i=0;i<N;i++){

		int height=Events[i].height;
		int sail = Events[i].sail;
		int pos = height-sail+1;

		_last=ultimo(pos,1,pos);
		_next=siguiente(pos,pos,height);

		update(_next+1,1);
		update(height+1,-1);

		update(_last,1);
		update(_last+_next-pos+1,-1);
	}
	i64 sol=0,x;
	for(int i=1;i<=limit;i++){
		x=query(i);
		sol+=x*(x-1)/2;
	}
	cout<<sol<<"\n";

	return 0;
}



