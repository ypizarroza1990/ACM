#include <bits/stdc++.h>
#define MAX 100019
#define LOG(x)31-__builtin_clz(x);
using namespace std;
typedef long long i64;
int RMQ[17][MAX],N;
i64 res=-1;
void preprocess(){
	int lg=LOG(N);
	for(int i=1;i<=lg;i++){
		for(int j=N-(1<<i);j>=0;j--)
			RMQ[i][j]=min(RMQ[i-1][j],RMQ[i-1][j+(1<<(i-1))]);
	}
}
int query(int lo,int hi){
	int lg=LOG(hi-lo+1);
	return min(RMQ[lg][lo],RMQ[lg][hi-(1<<lg)+1]);
}
int lower(int lo,int hi){
	int h=RMQ[0][hi],x=hi;
	while(lo<hi){
		int mid=(lo+hi)/2;
		if(query(mid,x)<h)
			lo=mid+1;
		else
			hi=mid;
	}
	return lo;
}
int upper(int lo,int hi){
	int h=RMQ[0][lo],x=lo;
	while(lo<hi){
		int mid=(lo+hi+1)/2;
		if(query(x,mid)<h)
			hi=mid-1;
		else
			lo=mid;
	}
	return hi;
}
int main() {

	while(scanf("%d",&N),N){
		for(int i=0;i<N;i++)
			scanf("%d",&RMQ[0][i]);
		preprocess();
		res=0;
		for(int i=0;i<N;i++){
			int lo,hi;
			lo=lower(0,i);
			hi=upper(i,N-1);
			res=max(res,((i64)(hi-lo+1)*(RMQ[0][i])));
		}
		printf("%lld\n",res);
	}
}
