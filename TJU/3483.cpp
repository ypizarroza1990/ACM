#include <bits/stdc++.h>
#define MAX 46341
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define ALL(X)(X).begin(),(X).end()
using namespace std;
typedef long long i64;
int flag[MAX>>6],prime[MAX],len;
set<i64>S;
vector<int>R,L;
void criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
		}
	}
	prime[(k=0)++]=2;
	for(i=3;i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			prime[k++]=i;
	len=k;
}
vector<int>F(i64 n){
	vector<int>R;
	for(int i=0;prime[i]*prime[i]<=n && i<len;i++){
		if(n%prime[i]==0){
			while(n%prime[i]==0)R.push_back(prime[i]),n/=prime[i];
		}
	}
	if(n!=1)
		R.push_back(n);
	return R;
}
int solve(){
	vector<int>C;S.clear();
	C.resize(R.size()+L.size());
	vector<int>::iterator it=set_intersection(ALL(R),ALL(L),C.begin());
	C.resize(it-C.begin());
	int sz=C.size();i64 res;
	for(int mask=0;mask<(1<<sz);mask++){
		res=1;
		for(int j=0;j<sz;j++)
			if(mask&(1<<j)){
				res*=C[j];
			}
		S.insert(res);
	}
	return S.size();
}
int cas,x,y;
int main() {
	criba();
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d",&x,&y);
		R=F(x);
		L=F(y);
		printf("%d\n",solve());
	}
	return 0;
}
