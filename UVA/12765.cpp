#include <bits/stdc++.h>
#define MAX 100
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
#define forl(it,x)for(__typeof((x).begin())it=(x).begin();it!=(x).end();it++)
using namespace std;
int prime[MAX>>2],flag[MAX>>6],len;
void criba(){
	int i,j,k;
	for(i =3;i*i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
	prime[(k=0)++]=2;
	for(i =3;i<MAX;i+=(i%6==1)?4:2)
		if(!ifc(i))
			prime[k++]=i;
	len=k;
}
int N,M,x;
map<int,int>a,b;

int divpow(int a,int p){
	int res=0;
	while(a){
		res+=a/p;
		a/=p;
	}
	return res;
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	criba();
	while(cin>>N>>M){
		a.clear(),b.clear();
		if(N+M==0)break;
		for(int i=0;i<N;i++){
			cin>>x;
			for(int j=0;prime[j]<=x;j++){
				a[prime[j]]+=divpow(x,prime[j]);
			}
		}
		for(int i=0;i<M;i++){
			cin>>x;
			for(int j=0;prime[j]<=x;j++){
				b[prime[j]]+=divpow(x,prime[j]);
			}
		}
		bool ok=1;
		if(a.size()!=b.size())
			ok=0;
		forl(it,a){
			if(b[(*it).first]!=(*it).second){
				ok=0;
				break;
			}
		}
		ok?cout<<"YES\n":cout<<"NO\n";
	}
}
 
