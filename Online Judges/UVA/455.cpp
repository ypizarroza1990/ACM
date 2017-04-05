 
#include<bits/stdc++.h>
#define MAX 10000001
#define ifc(x)(flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x)(flag[x>>6]|=(1<<((x>>1)&31)))
using namespace std;
typedef  long long i64;
string cad;
int f[150];
void preKMP(string C)
{
	int n=C.size(),k=0;
	f[0]=0;
	for(int i=1;i<n;i++){
		while(k>0 && C[k]!=C[i])k=f[k-1];
		if(C[i]==C[k])k++;
		f[i]=k;
	}
}
int cas,ans;
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>cas;
	while(cas--){
		cin>>cad;
		preKMP(cad);
		int len=cad.size();
		int sol=len-f[len-1];
		ans=1;
		if(len>sol && len%sol==0)ans=len/sol;
		cout<<len/ans<<"\n";
		if(cas)cout<<"\n";
	}
	return 0;
}
