#include <bits/stdc++.h>
#define MAX 1000001
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
int flag[MAX>>6],primelen;
int prime[MAX>>1],reversed[MAX>>1];
string tostr(int n){
	stringstream ss;
	ss<<n;
	return ss.str();
}
int toint(string c){
	stringstream ss(c);
	int n;
	ss>>n;
	return n;
}
void criba(){
	int i,j,k;
	for(i=3;i*i<MAX;i+=2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
		}
	}
	prime[(k=0)++]=2LL;
	reversed[k-1] = toint(tostr(2)+string(7-tostr(2).size(),'0'));
			for(i=3;i<MAX;i+=2){
				if(!ifc(i)){
					prime[k++]=i;
					string a = tostr(i);
					reverse(a.begin(),a.end());
					reversed[k-1]=toint(a+string(7-tostr(i).size(),'0'));
				}
			}
	primelen=k;
}
int factorize(int N){
	int size = 0;
	for(int i=0;prime[i]*prime[i]<=N;i++){
		if(N%prime[i]==0){
			while(N%prime[i]==0){
				size++;
				N/=prime[i];
			}
		}
	}
	if(N>1)size++;
	return size;
}
vector<int>M;
map<int,int>Mapa;
i64 sum[MAX];
void update(int pos,int val){
	for(int i=pos;i<MAX;i+=i&-i)
		sum[i]+=val;
}
i64 query(int pos){
	i64 suma =0;
	for(int i=pos;i;i-=i&-i)
		suma +=sum[i];
	return suma;
}
string op;
int x,del;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	criba();
	M.push_back(0);
	sort(reversed,reversed+primelen);
	for(int i=0;i<primelen;i++){
		M.push_back(reversed[i]);
		Mapa[reversed[i]]=i+1;
		update(i+1,factorize(reversed[i]));
	}
	while(cin>>op>>x){
		if(op == "q"){
			x = M[x+1];
			x = lower_bound(M.begin(),M.end(),x)-M.begin();
			x = Mapa[M[x]];
			cout<<query(x)-query(0)<<"\n";
		}else{
			vector<int>::iterator it = lower_bound(M.begin(),M.end(),x);
			x = it-M.begin();
			x = Mapa[M[x]];
			int s = query(x)-query(x-1);
			update(x,-s);
			M.erase(it);
			del++;
		}
	}
	return 0;
}

