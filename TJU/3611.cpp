#include <bits/stdc++.h>
#define MAX 31623
#define MOD 1000000007
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef long long i64;
typedef pair<int,int>pi;
int flag[MAX>>6],prime[MAX>>2],len;
void criba(){
	int i,j,k;
	for(i=3;i<sqrt(MAX);i+=(i%6==1)?4:2){
		if(!ifc(i)){
			for(j=i*i,k=(i<<1);j<MAX;j+=k)
				isc(j);
		}
	}
	prime[(k=0)++]=2;
	for(i=3;i<MAX;i+=(i%6==1)?4:2){
		if(!ifc(i))
			prime[k++]=i;
	}
	len=k;
}
vector<int>factoriza(i64 num){
	vector<int>res;
	for(int i=0;prime[i]*prime[i]<=num&&i<len;i++){
		if(num%prime[i]==0){
			res.push_back(prime[i]);
			while(num%prime[i]==0)num/=prime[i];
		}
	}
	if(num>1)res.push_back(num);
	return res;
}
vector<pi> dp(vector<int>res){
	int l=res.size();
	vector<pi>S;
	int sol,k;
	for(int mask=1;mask<(1<<l);mask++){
		sol=1;k=__builtin_popcount(mask);
		for(int j=0;j<l;j++){
			if(mask&(1<<j)){
				sol=(sol*res[j])/__gcd(sol,res[j]);
			}
		}
		S.push_back(make_pair(sol,k));
	}
	return S;
}
i64 mulmod(int a,i64 b,i64 c){
	i64 x=0,y=a%c;
	while(b>0){
		if(b&1)x=(x+y)%c;
		y=(y<<1)%c;
		b=b>>1;
	}
	return x;
}
i64 sumatoria(i64 num){
	i64 x=num,y=num+1;
	x&1?y/=2:x/=2;
	return mulmod(x,y,MOD);
}
i64 A,num;
int main() {
	criba();
	while(scanf("%lld",&num),num){
		vector<int>F=factoriza(num);
		i64 B=0,C;
		A=sumatoria(num-1);
		vector<pi>P=dp(F);
		num--;
		for(int i=0;i<(int)P.size();i++){
			if(P[i].second&1){
				C=sumatoria((num/P[i].first));
				B=(B+mulmod(C,P[i].first,MOD))%MOD;
			}else{
				C=sumatoria((num/P[i].first));
				B=(B-mulmod(C,P[i].first,MOD)+MOD)%MOD;
			}
		}
		cout<<B%MOD<<endl;
	}
	return 0;
}
